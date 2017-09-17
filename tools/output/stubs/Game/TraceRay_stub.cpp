#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "TraceRay.h"
#include "Camera.h"
#include "GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/myMath.h"

#include <algorithm>
#include <vector>

//////////////////////////////////////////////////////////////////////
// Local/Helper functions
//////////////////////////////////////////////////////////////////////

/**
 * helper for TestCone
 * @return true if object <o> is in the firing cone, false otherwise
 */
inline static bool TestConeHelper(
	const float3& pos3D,
	const float3& dir3D,
	const float length,
	const float spread,
	const CSolidObject* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * helper for TestTrajectoryCone
 * @return true if object <o> is in the firing trajectory, false otherwise
 */
inline static bool TestTrajectoryConeHelper(
	const float3& pos3D,
	const float3& dir2D,
	float length,
	float linear,
	float quadratic,
	float spread,
	float baseSize,
	const CSolidObject* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



//////////////////////////////////////////////////////////////////////
// Raytracing
//////////////////////////////////////////////////////////////////////

namespace TraceRay {

// called by {CRifle, CBeamLaser, CLightningCannon}::Fire(), CWeapon::HaveFreeLineOfFire(), and Skirmish AIs
float TraceRay(
	const float3& start,
	const float3& dir,
	float length,
	int avoidFlags,
	const CUnit* owner,
	CUnit*& hitUnit,
	CFeature*& hitFeature,
	CollisionQuery* hitColQuery
) {
	const bool ignoreEnemies  = ((avoidFlags & Collision::NOENEMIES   ) != 0);
	const bool ignoreAllies   = ((avoidFlags & Collision::NOFRIENDLIES) != 0);
	const bool ignoreFeatures = ((avoidFlags & Collision::NOFEATURES  ) != 0);
	const bool ignoreNeutrals = ((avoidFlags & Collision::NONEUTRALS  ) != 0);
	const bool ignoreGround   = ((avoidFlags & Collision::NOGROUND    ) != 0);
	const bool ignoreCloaked  = ((avoidFlags & Collision::NOCLOAKED   ) != 0);

	const bool ignoreUnits = ignoreEnemies && ignoreAllies && ignoreNeutrals;

	hitFeature = NULL;
	hitUnit = NULL;

	if (dir == ZeroVector)
		return -1.0f;

	if (!ignoreFeatures || !ignoreUnits) {
		CollisionQuery cq;

		const auto& quads = quadField->GetQuadsOnRay(start, dir, length);

		// locally point somewhere non-NULL; we cannot pass hitColQuery
		// to DetectHit directly because each call resets it internally
		if (hitColQuery == NULL)
			hitColQuery = &cq;

		// feature intersection
		if (!ignoreFeatures) {
			for (const int quadIdx: quads) {
				const CQuadField::Quad& quad = quadField->GetQuad(quadIdx);

				for (CFeature* f: quad.features) {
					// NOTE:
					//     if f is non-blocking, ProjectileHandler will not test
					//     for collisions with projectiles so we can skip it here
					if (!f->HasCollidableStateBit(CSolidObject::CSTATE_BIT_QUADMAPRAYS))
						continue;

					if (CCollisionHandler::DetectHit(f, f->GetTransformMatrix(true), start, start + dir * length, &cq, true)) {
						const float len = cq.GetHitPosDist(start, dir);

						// we want the closest feature (intersection point) on the ray
						if (len < length) {
							length = len;
							hitFeature = f;
							*hitColQuery = cq;
						}
					}
				}
			}
		}

		// unit intersection
		if (!ignoreUnits) {
			for (const int quadIdx: quads) {
				const CQuadField::Quad& quad = quadField->GetQuad(quadIdx);

				for (CUnit* u: quad.units) {
					if (u == owner)
						continue;
					if (!u->HasCollidableStateBit(CSolidObject::CSTATE_BIT_QUADMAPRAYS))
						continue;
					if (ignoreAllies && u->allyteam == owner->allyteam)
						continue;
					if (ignoreEnemies && u->allyteam != owner->allyteam)
						continue;
					if (ignoreNeutrals && u->IsNeutral())
						continue;
					if (ignoreCloaked && u->IsCloaked())
						continue;

					if (CCollisionHandler::DetectHit(u, u->GetTransformMatrix(true), start, start + dir * length, &cq, true)) {
						const float len = cq.GetHitPosDist(start, dir);

						// we want the closest unit (intersection point) on the ray
						if (len < length) {
							length = len;
							hitUnit = u;
							*hitColQuery = cq;
						}
					}
				}
			}

			if (hitUnit != NULL) {
				hitFeature = NULL;
			}
		}
	}

	if (!ignoreGround) {
		// ground intersection
		const float groundLength = CGround::LineGroundCol(start, start + dir * length);

		if (length > groundLength && groundLength > 0.0f) {
			length = groundLength;
			hitUnit = NULL;
			hitFeature = NULL;
		}
	}

	return length;
}


void TraceRayShields(
	const CWeapon* emitter,
	const float3& start,
	const float3& dir,
	float length,
	std::vector<SShieldDist>& hitShields
) {
	CollisionQuery cq;

	const auto& quads = quadField->GetQuadsOnRay(start, dir, length);
	for (const int quadIdx: quads) {
		const CQuadField::Quad& quad = quadField->GetQuad(quadIdx);

		for (CPlasmaRepulser* r: quad.repulsers) {
			if (!r->CanIntercept(emitter->weaponDef->interceptedByShieldType, emitter->owner->allyteam))
				continue;

			if (CCollisionHandler::DetectHit(r->owner, &r->collisionVolume, r->owner->GetTransformMatrix(true), start, start + dir * length, &cq, true)) {
				if (cq.InsideHit() && r->weaponDef->exteriorShield)
					continue;

				const float len = cq.GetHitPosDist(start, dir);
				if (len <= 0.0f)
					continue;

				const auto hitCmp = [](const float a, const SShieldDist& b) { return (a < b.dist); };
				const auto insPos = std::upper_bound(hitShields.begin(), hitShields.end(), len, hitCmp);

				hitShields.insert(insPos, {r, len});
			}
		}
	}
}


float GuiTraceRay(
	const float3& start,
	const float3& dir,
	const float length,
	const CUnit* exclude,
	const CUnit*& hitUnit,
	const CFeature*& hitFeature,
	bool useRadar,
	bool groundOnly,
	bool ignoreWater
) {
	hitUnit = nullptr;
	hitFeature = nullptr;

	if (dir == ZeroVector)
		return -1.0f;

	// ground and water-plane intersection
	const float    guiRayLength = length;
	const float groundRayLength = CGround::LineGroundCol(start, dir, guiRayLength, false);
	const float  waterRayLength = CGround::LinePlaneCol(start, dir, guiRayLength, 0.0f);

	float minRayLength = groundRayLength;
	float minIngressDist = length;
	float minEgressDist = length;

	bool hitFactory = false;

	// if ray cares about water, take minimum
	// of distance to ground and water surface
	if (!ignoreWater)
		minRayLength = std::min(groundRayLength, waterRayLength);
	if (groundOnly)
		return minRayLength;

	CollisionQuery cq;

	const auto& quads = quadField->GetQuadsOnRay(start, dir, length);
	for (const int quadIdx: quads) {
		const CQuadField::Quad& quad = quadField->GetQuad(quadIdx);

		// Unit Intersection
		for (const CUnit* u: quad.units) {
			const bool unitIsEnemy = !teamHandler->Ally(u->allyteam, gu->myAllyTeam);
			const bool unitOnRadar = (useRadar && losHandler->InRadar(u, gu->myAllyTeam));
			const bool unitInSight = (u->losStatus[gu->myAllyTeam] & (LOS_INLOS | LOS_CONTRADAR));
			const bool unitVisible = !unitIsEnemy || unitOnRadar || unitInSight || gu->spectatingFullView;

			if (u == exclude)
				continue;
			// test this bit only in synced traces, rely on noSelect here
			if (false && !u->HasCollidableStateBit(CSolidObject::CSTATE_BIT_QUADMAPRAYS))
				continue;
			if (u->noSelect)
				continue;
			if (!unitVisible)
				continue;

			CollisionVolume cv = u->collisionVolume;

			if (u->isIcon || (!unitInSight && unitOnRadar && unitIsEnemy)) {
				// for iconified units, just pretend the collision
				// volume is a sphere of radius <unit->IconRadius>
				// (count radar blips as such too)
				cv.InitSphere(u->iconRadius);
			}

			if (CCollisionHandler::MouseHit(u, u->GetTransformMatrix(false), start, start + dir * guiRayLength, &cv, &cq)) {
				// get the distance to the ray-volume ingress point
				// (not likely to generate inside-hit special cases)
				const float ingressDist = cq.GetIngressPosDist(start, dir);
				const float  egressDist = cq.GetEgressPosDist(start, dir);

				const bool factoryUnderCursor = u->unitDef->IsFactoryUnit();
				const bool factoryHitBeforeUnit = ((hitFactory && ingressDist < minIngressDist) || (!hitFactory &&  egressDist < minIngressDist));
				const bool unitHitInsideFactory = ((hitFactory && ingressDist <  minEgressDist) || (!hitFactory && ingressDist < minIngressDist));

				// give units in a factory higher priority than the factory itself
				if (hitUnit == nullptr || (factoryUnderCursor && factoryHitBeforeUnit) || (!factoryUnderCursor && unitHitInsideFactory)) {
					hitFactory = factoryUnderCursor;
					minIngressDist = ingressDist;
					minEgressDist = egressDist;

					hitUnit = u;
					hitFeature = nullptr;
				}
			}
		}

		// Feature Intersection
		for (const CFeature* f: quad.features) {
			if (!gu->spectatingFullView && !f->IsInLosForAllyTeam(gu->myAllyTeam))
				continue;
			// test this bit only in synced traces, rely on noSelect here
			if (false && !f->HasCollidableStateBit(CSolidObject::CSTATE_BIT_QUADMAPRAYS))
				continue;
			if (f->noSelect)
				continue;

			CollisionVolume cv = f->collisionVolume;

			if (CCollisionHandler::MouseHit(f, f->GetTransformMatrix(false), start, start + dir * guiRayLength, &cv, &cq)) {
				const float hitDist = cq.GetHitPosDist(start, dir);

				const bool factoryHitBeforeUnit = ( hitFactory && hitDist <  minEgressDist);
				const bool unitHitInsideFactory = (!hitFactory && hitDist < minIngressDist);

				// we want the closest feature (intersection point) on the ray
				// give features in a factory (?) higher priority than the factory itself
				if (hitUnit == nullptr || factoryHitBeforeUnit || unitHitInsideFactory) {
					hitFactory = false;
					minIngressDist = hitDist;

					hitFeature = f;
					hitUnit = nullptr;
				}
			}
		}
	}

	if ((minRayLength > 0.0f) && ((minRayLength + 200.0f) < minIngressDist)) {
		minIngressDist = minRayLength;

		hitUnit    = nullptr;
		hitFeature = nullptr;
	}

	return minIngressDist;
}


bool TestCone(
	const float3& from,
	const float3& dir,
	float length,
	float spread,
	int allyteam,
	int avoidFlags,
	CUnit* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool TestTrajectoryCone(
	const float3& from,
	const float3& dir,
	float length,
	float linear,
	float quadratic,
	float spread,
	int allyteam,
	int avoidFlags,
	CUnit* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



} //namespace TraceRay
