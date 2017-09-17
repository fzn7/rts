/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameHelper.h"

#include "Camera.h"
#include "GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Lua/LuaUI.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Map/ReadMap.h"
#include "Rendering/Models/3DModel.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Misc/BuildingMaskMap.h"
#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/MoveMath/MoveMath.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/ExplosionListener.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Units/CommandAI/MobileCAI.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "System/EventHandler.h"
#include "System/myMath.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"

#define NUM_WAITING_DAMAGE_LISTS 128

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGameHelper* helper;


CGameHelper::CGameHelper()
{
    //stub method
}

CGameHelper::~CGameHelper()
{
    //stub method
}



//////////////////////////////////////////////////////////////////////
// Explosions/Damage
//////////////////////////////////////////////////////////////////////

float CGameHelper::CalcImpulseScale(const DamageArray& damages, const float expDistanceMod)
{
    //stub method
}

void CGameHelper::DoExplosionDamage(
	CUnit* unit,
	CUnit* owner,
	const float3& expPos,
	const float expRadius,
	const float expSpeed,
	const float expEdgeEffect,
	const bool ignoreOwner,
	const DamageArray& damages,
	const int weaponDefID,
	const int projectileID
) {
	assert(unit != NULL);

	if (ignoreOwner && (unit == owner))
		return;

	const LocalModelPiece* lhp = unit->GetLastHitPiece(gs->frameNum);
	const CollisionVolume* vol = unit->GetCollisionVolume(lhp);

	const float3& lhpPos = (lhp != NULL && vol == lhp->GetCollisionVolume())? lhp->GetAbsolutePos(): ZeroVector;
	const float3& volPos = vol->GetWorldSpacePos(unit, lhpPos);

	// linear damage falloff with distance
	const float expDist = (expRadius != 0.0f) ? vol->GetPointSurfaceDistance(unit, lhp, expPos) : 0.0f;
	const float expRim = expDist * expEdgeEffect;

	// return early if (distance > radius)
	if (expDist > expRadius)
		return;

	// expEdgeEffect should be in [0, 1], so expRadius >= expDist >= expDist*expEdgeEffect
	assert(expRadius >= expRim);

	// expMod will also be in [0, 1], no negatives
	// TODO: damage attenuation for underwater units from surface explosions?
	const float expDistanceMod = (expRadius + 0.001f - expDist) / (expRadius + 0.001f - expRim);
	const float modImpulseScale = CalcImpulseScale(damages, expDistanceMod);

	// NOTE: if an explosion occurs right underneath a
	// unit's map footprint, it might cause damage even
	// if the unit's collision volume is greatly offset
	// (because CQuadField coverage is based exclusively
	// on unit->radius, so the DoDamage() iteration will
	// include units that should not be touched)

	const float3 impulseDir = (volPos - expPos).SafeNormalize();
	const float3 expImpulse = impulseDir * modImpulseScale;

	const DamageArray expDamages = damages * expDistanceMod;

	if (expDist < (expSpeed * DIRECT_EXPLOSION_DAMAGE_SPEED_SCALE)) {
		// damage directly
		unit->DoDamage(expDamages, expImpulse, owner, weaponDefID, projectileID);
	} else {
		// damage later
		waitingDamageLists[(gs->frameNum + int(expDist / expSpeed) - 3) & 127].emplace_back((owner? owner->id: -1), unit->id, expDamages, expImpulse, weaponDefID, projectileID);
	}
}

void CGameHelper::DoExplosionDamage(
	CFeature* feature,
	CUnit* owner,
	const float3& expPos,
	const float expRadius,
	const float expEdgeEffect,
	const DamageArray& damages,
	const int weaponDefID,
	const int projectileID
) {
	assert(feature != NULL);

	const LocalModelPiece* lhp = feature->GetLastHitPiece(gs->frameNum);
	const CollisionVolume* vol = feature->GetCollisionVolume(lhp);

	const float3& lhpPos = (lhp != NULL && vol == lhp->GetCollisionVolume())? lhp->GetAbsolutePos(): ZeroVector;
	const float3& volPos = vol->GetWorldSpacePos(feature, lhpPos);

	const float expDist = (expRadius != 0.0f) ? vol->GetPointSurfaceDistance(feature, NULL, expPos) : 0.0f;
	const float expRim = expDist * expEdgeEffect;

	if (expDist > expRadius)
		return;

	assert(expRadius >= expRim);

	const float expDistanceMod = (expRadius + 0.001f - expDist) / (expRadius + 0.001f - expRim);
	const float modImpulseScale = CalcImpulseScale(damages, expDistanceMod);

	const float3 impulseDir = (volPos - expPos).SafeNormalize();
	const float3 expImpulse = impulseDir * modImpulseScale;

	feature->DoDamage(damages * expDistanceMod, expImpulse, owner, weaponDefID, projectileID);
}



void CGameHelper::DamageObjectsInExplosionRadius(
	const CExplosionParams& params,
	const float expRad,
	const int weaponDefID
) {
	static std::vector<CUnit*> unitCache;
	static std::vector<CFeature*> featureCache;

	const unsigned int oldNumUnits = unitCache.size();
	const unsigned int oldNumFeatures = featureCache.size();

	quadField->GetUnitsAndFeaturesColVol(params.pos, expRad, unitCache, featureCache);

	const unsigned int newNumUnits = unitCache.size();
	const unsigned int newNumFeatures = featureCache.size();

	// damage all units within the explosion radius
	// NOTE:
	//   this can recursively trigger ::Explosion() again
	//   which would overwrite our object cache if we did
	//   not keep track of end-markers --> certain objects
	//   would not be damaged AT ALL (!)
	for (unsigned int n = oldNumUnits; n < newNumUnits; n++)
		DoExplosionDamage(unitCache[n], params.owner, params.pos, expRad, params.explosionSpeed, params.edgeEffectiveness, params.ignoreOwner, params.damages, weaponDefID, params.projectileID);

	unitCache.resize(oldNumUnits);

	// damage all features within the explosion radius
	for (unsigned int n = oldNumFeatures; n < newNumFeatures; n++)
		DoExplosionDamage(featureCache[n], params.owner, params.pos, expRad, params.edgeEffectiveness, params.damages, weaponDefID, params.projectileID);

	featureCache.resize(oldNumFeatures);
}

void CGameHelper::Explosion(const CExplosionParams& params) {
	const DamageArray& damages = params.damages;

	// if weaponDef is NULL, this is a piece-explosion
	// (implicit damage-type -DAMAGE_EXPLOSION_DEBRIS)
	const WeaponDef* weaponDef = params.weaponDef;

	const int weaponDefID = (weaponDef != NULL)? weaponDef->id: -CSolidObject::DAMAGE_EXPLOSION_DEBRIS;
	const int explosionID = (weaponDef != NULL)? weaponDef->impactExplosionGeneratorID: CExplosionGeneratorHandler::EXPGEN_ID_STANDARD;


	const float craterAOE = std::max(1.0f, params.craterAreaOfEffect);
	const float damageAOE = std::max(1.0f, params.damageAreaOfEffect);

	const float realHeight = CGround::GetHeightReal(params.pos);
	const float altitude = (params.pos).y - realHeight;

	// NOTE: event triggers before damage is applied to objects
	const bool noGfx = eventHandler.Explosion(weaponDefID, params.projectileID, params.pos, params.owner);

	if (luaUI != NULL) {
		if (weaponDef != NULL && weaponDef->cameraShake > 0.0f) {
			luaUI->ShockFront(params.pos, weaponDef->cameraShake, damageAOE);
		}
	}

	if (params.impactOnly) {
		if (params.hitUnit != NULL) {
			DoExplosionDamage(
				params.hitUnit,
				params.owner,
				params.pos,
				0.0f,
				params.explosionSpeed,
				params.edgeEffectiveness,
				params.ignoreOwner,
				params.damages,
				weaponDefID,
				params.projectileID
			);
		}

		if (params.hitFeature != NULL) {
			DoExplosionDamage(
				params.hitFeature,
				params.owner,
				params.pos,
				0.0f,
				params.edgeEffectiveness,
				params.damages,
				weaponDefID,
				params.projectileID
			);
		}
	} else {
		DamageObjectsInExplosionRadius(params, damageAOE, weaponDefID);

		// deform the map if the explosion was above-ground
		// (but had large enough radius to touch the ground)
		if (altitude >= -1.0f) {
			if (params.damageGround && !mapDamage->disabled && (craterAOE > altitude) && (damages.craterMult > 0.0f)) {
				// limit the depth somewhat
				const float craterDepth = damages.GetDefault() * (1.0f - (altitude / craterAOE));
				const float damageDepth = std::min(craterAOE * 10.0f, craterDepth);
				const float craterStrength = (damageDepth + damages.craterBoost) * damages.craterMult;
				const float craterRadius = craterAOE - altitude;

				mapDamage->Explosion(params.pos, craterStrength, craterRadius);
			}
		}
	}

	if (!noGfx) {
		explGenHandler->GenExplosion(
			explosionID,
			params.pos,
			params.dir,
			damages.GetDefault(),
			damageAOE,
			params.gfxMod,
			params.owner,
			params.hitUnit
		);
	}

	CExplosionCreator::FireExplosionEvent(params);

	if (weaponDef != NULL) {
		const GuiSoundSet& soundSet = weaponDef->hitSound;

		const unsigned int soundFlags = CCustomExplosionGenerator::GetFlagsFromHeight(params.pos.y, realHeight);
		const unsigned int soundMask = CCustomExplosionGenerator::SPW_WATER | CCustomExplosionGenerator::SPW_UNDERWATER;

		const int soundNum = ((soundFlags & soundMask) != 0);
		const int soundID = soundSet.getID(soundNum);

		if (soundID > 0) {
			Channels::Battle->PlaySample(soundID, params.pos, soundSet.getVolume(soundNum));
		}
	}
}



//////////////////////////////////////////////////////////////////////
// Spatial unit queries
//////////////////////////////////////////////////////////////////////

/**
 * @brief Generic spatial unit query.
 *
 * Filter should implement two methods:
 *  - bool Team(int allyTeam): returns true if this allyteam should be considered
 *  - bool Unit(const CUnit*): returns true if the unit should be returned
 *
 * Query should implement three methods:
 *  - float3 GetPos(): returns the center of the (circular) search area
 *  - float GetRadius(): returns the radius of the search area
 *  - void AddUnit(const CUnit*): add the unit to the result
 *
 * The area as returned by Query is approximate; exact circular filtering
 * should be implemented in the Query object if desired.
 * (It isn't necessary for e.g. GetClosest** methods.)
 */
template<typename TFilter, typename TQuery>
static inline void QueryUnits(TFilter filter, TQuery& query)
{
    //stub method
}


namespace {
	namespace Filter {

		/**
		 * Base class for Filter::Friendly and Filter::Enemy.
		 */
		struct Base
		{
			const int searchAllyteam;
			Base(int at) : searchAllyteam(at) {}
		};

		/**
		 * Look for friendly units only.
		 * All units are included by default.
		 */
		struct Friendly : public Base
		{
		public:
			Friendly(const CUnit* exclUnit, int allyTeam) : Base(allyTeam), excludeUnit(exclUnit) {}
			bool Team(int allyTeam) { return teamHandler->Ally(searchAllyteam, allyTeam); }
			bool Unit(const CUnit* unit) { return (unit != excludeUnit); }
		protected:
			const CUnit* excludeUnit;
		};

		/**
		 * Look for enemy units only.
		 * All units are included by default.
		 */
		struct Enemy : public Base
		{
		public:
			Enemy(const CUnit* exclUnit, int allyTeam) : Base(allyTeam), excludeUnit(exclUnit) {}
			bool Team(int allyTeam) { return !teamHandler->Ally(searchAllyteam, allyTeam); }
			bool Unit(const CUnit* unit) { return (unit != excludeUnit && !unit->IsNeutral()); }
		protected:
			const CUnit* excludeUnit;
		};

		/**
		 * Look for enemy units which are in LOS/Radar only.
		 */
		struct Enemy_InLos : public Enemy
		{
			Enemy_InLos(const CUnit* exclUnit, int allyTeam) : Enemy(exclUnit, allyTeam) {}
			bool Unit(const CUnit* u) {
				return (u->losStatus[searchAllyteam] & (LOS_INLOS | LOS_INRADAR) && Enemy::Unit(u));
			}
		};

		/**
		 * Look for enemy aircraft which are in LOS/Radar only.
		 */
		struct EnemyAircraft : public Enemy_InLos
		{
			EnemyAircraft(const CUnit* exclUnit, int allyTeam) : Enemy_InLos(exclUnit, allyTeam) {}
			bool Unit(const CUnit* u) {
				return (u->unitDef->canfly && !u->IsCrashing() && Enemy_InLos::Unit(u));
			}
		};

		/**
		 * Look for units of any team. Enemy units must be in LOS/Radar.
		 *
		 * NOT SYNCED
		 */
		struct Friendly_All_Plus_Enemy_InLos_NOT_SYNCED
		{
			bool Team(int) const { return true; }
			bool Unit(const CUnit* u) const {
				return (u->allyteam == gu->myAllyTeam) ||
					   (u->losStatus[gu->myAllyTeam] & (LOS_INLOS | LOS_INRADAR)) ||
					   gu->spectatingFullView;
			}
		};

		/**
		 * Delegates filtering to CMobileCAI::IsValidTarget.
		 *
		 * This is necessary in CMobileCAI and CAirCAI so they can select the closest
		 * enemy unit which they consider a valid target.
		 *
		 * Without the valid target condition, units don't attack anything if an
		 * the nearest enemy is an invalid target. (e.g. noChaseCategory)
		 */
		struct Enemy_InLos_ValidTarget : public Enemy_InLos
		{
			const CMobileCAI* const cai;

			Enemy_InLos_ValidTarget(int at, const CMobileCAI* cai) :
				Enemy_InLos(NULL, at), cai(cai) {}

			bool Unit(const CUnit* u) {
				return Enemy_InLos::Unit(u) && cai->IsValidTarget(u);
			}
		};

	} // end of namespace Filter


	namespace Query {

		/**
		 * Base class for Query objects, containing the basic methods needed by
		 * QueryUnits which defined the search area.
		 */
		struct Base
		{
			const float3& pos;
			const float radius;
			const float sqRadius;
			Base(const float3& pos, float searchRadius) :
				pos(pos), radius(searchRadius), sqRadius(searchRadius * searchRadius) {}
		};

		/**
		 * Return the closest unit.
		 */
		struct ClosestUnit : public Base
		{
		protected:
			float closeSqDist;
			CUnit* closeUnit;

		public:
			ClosestUnit(const float3& pos, float searchRadius) :
				Base(pos, searchRadius), closeSqDist(sqRadius), closeUnit(NULL) {}

			void AddUnit(CUnit* u) {
				const float sqDist = (pos - u->midPos).SqLength2D();
				if (sqDist <= closeSqDist) {
					closeSqDist = sqDist;
					closeUnit = u;
				}
			}

			CUnit* GetClosestUnit() const { return closeUnit; }
		};

		/**
		 * Return the closest unit, using GetUnitErrorPos
		 * instead of the unit's actual position.
		 *
		 * NOT SYNCED
		 */
		struct ClosestUnit_ErrorPos_NOT_SYNCED : public ClosestUnit
		{
			ClosestUnit_ErrorPos_NOT_SYNCED(const float3& pos, float searchRadius) :
				ClosestUnit(pos, searchRadius) {}

			void AddUnit(CUnit* u) {
				float3 unitPos;
				if (gu->spectatingFullView) {
					unitPos = u->midPos;
				} else {
					unitPos = u->GetErrorPos(gu->myAllyTeam);
				}
				const float sqDist = (pos - unitPos).SqLength2D();
				if (sqDist <= closeSqDist) {
					closeSqDist = sqDist;
					closeUnit = u;
				}
			}
		};

		/**
		 * Returns the closest unit (3D) which may have LOS on the search position.
		 * LOS is spherical in the context of this query. Whether the unit actually has
		 * LOS depends on nearby obstacles.
		 *
		 * Search area just needs to touch the unit's radius: this query includes the
		 * target unit's radius.
		 *
		 * If canBeBlind is true then the LOS test is skipped.
		 */
		struct ClosestUnit_InLos : public Base
		{
		protected:
			float closeDist;
			CUnit* closeUnit;
			const bool canBeBlind;

		public:
			ClosestUnit_InLos(const float3& pos, float searchRadius, bool canBeBlind) :
				Base(pos, searchRadius + unitHandler->MaxUnitRadius()),
				closeDist(searchRadius), closeUnit(NULL), canBeBlind(canBeBlind) {}

			void AddUnit(CUnit* u) {
				// FIXME: use volumeBoundingRadius?
				// (more for consistency than need)
				const float dist = pos.distance(u->midPos) - u->radius;

				if (dist <= closeDist &&
					(canBeBlind || (u->losRadius > dist))
				) {
					closeDist = dist;
					closeUnit = u;
				}
			}

			CUnit* GetClosestUnit() const { return closeUnit; }
		};

		/**
		 * Returns the closest unit (2D) which may have LOS on the search position.
		 * Whether it actually has LOS depends on nearby obstacles.
		 *
		 * If canBeBlind is true then the LOS test is skipped.
		 */
		struct ClosestUnit_InLos_Cylinder : public ClosestUnit
		{
			const bool canBeBlind;

			ClosestUnit_InLos_Cylinder(const float3& pos, float searchRadius, bool canBeBlind) :
				ClosestUnit(pos, searchRadius), canBeBlind(canBeBlind) {}

			void AddUnit(CUnit* u) {
				const float sqDist = (pos - u->midPos).SqLength2D();

				if (sqDist <= closeSqDist &&
					(canBeBlind || Square(u->losRadius) > sqDist)
				) {
					closeSqDist = sqDist;
					closeUnit = u;
				}
			}
		};

		/**
		 * Return the unitIDs of all units exactly within the search area.
		 */
		struct AllUnitsById : public Base
		{
		protected:
			vector<int>& found;

		public:
			AllUnitsById(const float3& pos, float searchRadius, vector<int>& found) :
				Base(pos, searchRadius), found(found) {}

			void AddUnit(CUnit* u) {
				if ((pos - u->midPos).SqLength2D() <= sqRadius) {
					found.push_back(u->id);
				}
			}
		};

	} // end of namespace Query
} // end of namespace


void CGameHelper::GenerateWeaponTargets(const CWeapon* weapon, const CUnit* avoidUnit, std::multimap<float, CUnit*>& targets)
{
    //stub method
}

CUnit* CGameHelper::GetClosestUnit(const float3& pos, float searchRadius)
{
    //stub method
}

CUnit* CGameHelper::GetClosestEnemyUnit(const CUnit* excludeUnit, const float3& pos, float searchRadius, int searchAllyteam)
{
    //stub method
}

CUnit* CGameHelper::GetClosestValidTarget(const float3& pos, float searchRadius, int searchAllyteam, const CMobileCAI* cai)
{
    //stub method
}

CUnit* CGameHelper::GetClosestEnemyUnitNoLosTest(
	const CUnit* excludeUnit,
	const float3& pos,
	float searchRadius,
	int searchAllyteam,
	bool sphere,
	bool canBeBlind
) {
	if (sphere) {
		// includes target radius
		Query::ClosestUnit_InLos q(pos, searchRadius, canBeBlind);
		QueryUnits(Filter::Enemy(excludeUnit, searchAllyteam), q);
		return q.GetClosestUnit();
	} else {
		// cylinder (doesn't include target radius)
		Query::ClosestUnit_InLos_Cylinder q(pos, searchRadius, canBeBlind);
		QueryUnits(Filter::Enemy(excludeUnit, searchAllyteam), q);
		return q.GetClosestUnit();
	}
}

CUnit* CGameHelper::GetClosestFriendlyUnit(const CUnit* excludeUnit, const float3& pos, float searchRadius, int searchAllyteam)
{
    //stub method
}

CUnit* CGameHelper::GetClosestEnemyAircraft(const CUnit* excludeUnit, const float3& pos, float searchRadius, int searchAllyteam)
{
    //stub method
}

void CGameHelper::GetEnemyUnits(const float3& pos, float searchRadius, int searchAllyteam, vector<int> &found)
{
    //stub method
}

void CGameHelper::GetEnemyUnitsNoLosTest(const float3& pos, float searchRadius, int searchAllyteam, vector<int> &found)
{
    //stub method
}


//////////////////////////////////////////////////////////////////////
// Miscellaneous (i.e. not yet categorized)
//////////////////////////////////////////////////////////////////////

void CGameHelper::BuggerOff(float3 pos, float radius, bool spherical, bool forced, int teamId, CUnit* excludeUnit)
{
    //stub method
}


float3 CGameHelper::Pos2BuildPos(const BuildInfo& buildInfo, bool synced)
{
    //stub method
}


struct SearchOffset {
	int dx,dy;
	int qdist; // dx*dx+dy*dy
};
static bool SearchOffsetComparator (const SearchOffset& a, const SearchOffset& b)
{
    //stub method
}
static const vector<SearchOffset>& GetSearchOffsetTable (int radius)
{
    //stub method
}

//! only used by the AI callback of the same name
float3 CGameHelper::ClosestBuildSite(int team, const UnitDef* unitDef, float3 pos, float searchRadius, int minDist, int facing)
{
    //stub method
}

// find the reference height for a build-position
// against which to compare all footprint squares
float CGameHelper::GetBuildHeight(const float3& pos, const UnitDef* unitdef, bool synced)
{
    //stub method
}


CGameHelper::BuildSquareStatus CGameHelper::TestUnitBuildSquare(
	const BuildInfo& buildInfo,
	CFeature*& feature,
	int allyteam,
	bool synced,
	std::vector<float3>* canbuildpos,
	std::vector<float3>* featurepos,
	std::vector<float3>* nobuildpos,
	const std::vector<Command>* commands)
{
    //stub method
}

CGameHelper::BuildSquareStatus CGameHelper::TestBuildSquare(
	const float3& pos,
	const int2& xrange,
	const int2& zrange,
	const UnitDef* unitDef,
	const MoveDef* moveDef,
	CFeature*& feature,
	int allyteam,
	boost::uint16_t mask,
	bool synced
) {
	assert(pos.IsInBounds());

	const int sqx = unsigned(pos.x) / SQUARE_SIZE;
	const int sqz = unsigned(pos.z) / SQUARE_SIZE;
	const float groundHeight = CGround::GetApproximateHeightUnsafe(sqx, sqz, synced);

	if (!unitDef->CheckTerrainConstraints(moveDef, groundHeight))
		return BUILDSQUARE_BLOCKED;

	if (!buildingMaskMap->TestTileMaskUnsafe(sqx >> 1, sqz >> 1, mask))
		return BUILDSQUARE_BLOCKED;
	

	// check maxHeightDif constraint (structures only)
	//
	// if we are capable of floating, only test local
	// height difference IF terrain is above sea-level
	if (unitDef->IsImmobileUnit()) {
		if (!unitDef->floatOnWater || groundHeight > 0.0f) {
			if (std::abs(pos.y - groundHeight) > unitDef->maxHeightDif) {
				return BUILDSQUARE_BLOCKED;
			}
		}
	}

	BuildSquareStatus ret = BUILDSQUARE_OPEN;
	const int yardxpos = unsigned(pos.x + (SQUARE_SIZE >> 1)) / SQUARE_SIZE;
	const int yardypos = unsigned(pos.z + (SQUARE_SIZE >> 1)) / SQUARE_SIZE;
	CSolidObject* so = groundBlockingObjectMap->GroundBlocked(yardxpos, yardypos);
	if (so != NULL) {
		CFeature* f = dynamic_cast<CFeature*>(so);
		CUnit* u = dynamic_cast<CUnit*>(so);

		// blocking-map can lag behind because it is not updated every frame
		assert(true || (so->pos.x >= xrange.x && so->pos.x <= xrange.y));
		assert(true || (so->pos.z >= zrange.x && so->pos.z <= zrange.y));

		if (f != NULL) {
			if ((allyteam < 0) || f->IsInLosForAllyTeam(allyteam)) {
				if (!f->def->reclaimable) {
					ret = BUILDSQUARE_BLOCKED;
				} else {
					ret = BUILDSQUARE_RECLAIMABLE;
					feature = f;
				}
			}
		} else {
			assert(u);
			if ((allyteam < 0) || (u->losStatus[allyteam] & LOS_INLOS)) {
				if (so->immobile) {
					ret = BUILDSQUARE_BLOCKED;
				} else {
					ret = BUILDSQUARE_OCCUPIED;
				}
			}
		}

		if (ret == BUILDSQUARE_BLOCKED || ret == BUILDSQUARE_OCCUPIED) {
			// if the to-be-buildee has a MoveDef, test if <so> would block it
			// note:
			//   <so> might be another new buildee and if that happens to be located
			//   on sloped ground, then so->pos.y will equal Builder::StartBuild -->
			//   ::Pos2BuildPos --> ::GetBuildHeight which can differ from the actual
			//   ground height at so->pos (s.t. !so->IsOnGround() and the object will
			//   be non-blocking)
			//   fixed: no longer true for mobile units
			#if 0
			if (synced) {
				so->PushPhysicalStateBit(CSolidObject::PSTATE_BIT_ONGROUND);
				so->UpdatePhysicalStateBit(CSolidObject::PSTATE_BIT_ONGROUND, (math::fabs(so->pos.y - groundHeight) <= 0.5f));
			}
			#endif

			if (moveDef != NULL && CMoveMath::IsNonBlocking(*moveDef, so, NULL)) {
				ret = BUILDSQUARE_OPEN;
			}

			#if 0
			if (synced) {
				so->PopPhysicalStateBit(CSolidObject::PSTATE_BIT_ONGROUND);
			}
			#endif
		}

		if (ret == BUILDSQUARE_BLOCKED) {
			return ret;
		}
	}

	return ret;
}

/**
 * Returns a build Command that intersects the ray described by pos and dir from
 * the command queues of the units 'units' on team number 'team'.
 * @brief returns a build Command that intersects the ray described by pos and dir
 * @return the build Command, or a Command with id 0 if none is found
 */
Command CGameHelper::GetBuildCommand(const float3& pos, const float3& dir) {
	float3 tempF1 = pos;

	CCommandQueue::iterator ci;


	for (CUnit *unit: unitHandler->activeUnits) {

		if (unit->team != gu->myTeam) {
			continue;
		}

		ci = unit->commandAI->commandQue.begin();

		for (; ci != unit->commandAI->commandQue.end(); ++ci) {
			const Command& cmd = *ci;

			if (cmd.GetID() < 0 && cmd.params.size() >= 3) {
				BuildInfo bi(cmd);
				tempF1 = pos + dir * ((bi.pos.y - pos.y) / dir.y) - bi.pos;

				if (bi.def && (bi.GetXSize() / 2) * SQUARE_SIZE > math::fabs(tempF1.x) && (bi.GetZSize() / 2) * SQUARE_SIZE > math::fabs(tempF1.z)) {
					return cmd;
				}
			}
		}
	}

	Command c(CMD_STOP);
	return c;
}




void CGameHelper::Update()
{
    //stub method
}

