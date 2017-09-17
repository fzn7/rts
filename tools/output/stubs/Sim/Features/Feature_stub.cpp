#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Feature.h"
#include "FeatureDef.h"
#include "FeatureDefHandler.h"
#include "FeatureHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/FireProjectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/GeoThermSmokeProjectile.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "System/EventHandler.h"
#include "System/myMath.h"
#include "System/creg/DefTypes.h"
#include "System/Log/ILog.h"
#include <assert.h>


CR_BIND_DERIVED(CFeature, CSolidObject, )

CR_REG_METADATA(CFeature, (
	CR_MEMBER(isRepairingBeforeResurrect),
	CR_MEMBER(inUpdateQue),
	CR_MEMBER(deleteMe),
	CR_MEMBER(resurrectProgress),
	CR_MEMBER(reclaimLeft),
	CR_MEMBER(resources),
	CR_MEMBER(lastReclaim),
	CR_MEMBER(drawQuad),
	CR_MEMBER(drawFlag),
	CR_MEMBER(drawAlpha),
	CR_MEMBER(alphaFade),
	CR_MEMBER(fireTime),
	CR_MEMBER(smokeTime),
	CR_MEMBER(def),
	CR_MEMBER(udef),
	CR_MEMBER(moveCtrl),
	CR_MEMBER(myFire),
	CR_MEMBER(solidOnTop),
	CR_MEMBER(transMatrix),
	CR_POSTLOAD(PostLoad)
))

CR_BIND(CFeature::MoveCtrl,)

CR_REG_METADATA_SUB(CFeature,MoveCtrl,(
	CR_MEMBER(enabled),

	CR_MEMBER(movementMask),
	CR_MEMBER(velocityMask),
	CR_MEMBER(impulseMask),

	CR_MEMBER(velVector),
	CR_MEMBER(accVector)
))


CFeature::CFeature()
: CSolidObject()
, isRepairingBeforeResurrect(false)
, inUpdateQue(false)
, deleteMe(false)
, resurrectProgress(0.0f)
, reclaimLeft(1.0f)
, lastReclaim(0)
, resources(0.0f, 1.0f)

, drawQuad(-2)
, drawFlag(-1)

, drawAlpha(1.0f)
, alphaFade(true)

, fireTime(0)
, smokeTime(0)
, def(NULL)
, udef(NULL)
, myFire(NULL)
, solidOnTop(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CFeature::~CFeature()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::ChangeTeam(int newTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CFeature::IsInLosForAllyTeam(int argAllyTeam) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::Initialize(const FeatureLoadParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CFeature::AddBuildPower(CUnit* builder, float amount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::DoDamage(
	const DamageArray& damages,
	const float3& impulse,
	CUnit* attacker,
	int weaponDefID,
	int projectileID
) {
	// paralyzers do not damage features
	if (damages.paralyzeDamageTime)
		return;
	if (IsInVoid())
		return;

	// features have no armor-type, so use default damage
	float baseDamage = damages.GetDefault();
	float impulseMult = float((def->drawType >= DRAWTYPE_TREE) || (udef != NULL && !udef->IsImmobileUnit()));

	if (eventHandler.FeaturePreDamaged(this, attacker, baseDamage, weaponDefID, projectileID, &baseDamage, &impulseMult))
		return;

	// NOTE:
	//   for trees, impulse is used to drive their falling animation
	//   this also calls our SetVelocity, which puts us in the update
	//   queue
	ApplyImpulse((impulse * moveCtrl.impulseMask * impulseMult) / mass);

	// clamp in case Lua-modified damage is negative
	health -= baseDamage;
	health = std::min(health, def->health);

	eventHandler.FeatureDamaged(this, attacker, baseDamage, weaponDefID, projectileID);

	if (health <= 0.0f && def->destructable) {
		FeatureLoadParams params = {featureDefHandler->GetFeatureDefByID(def->deathFeatureDefID), NULL, pos, speed, -1, team, -1, heading, buildFacing, 0};
		CFeature* deathFeature = featureHandler->CreateWreckage(params, 0, false);

		if (deathFeature != NULL) {
			// if a partially reclaimed corpse got blasted,
			// ensure its wreck is not worth the full amount
			// (which might be more than the amount remaining)
			deathFeature->resources.metal  *= (def->metal != 0.0f)  ? resources.metal  / def->metal  : 1.0f;
			deathFeature->resources.energy *= (def->energy != 0.0f) ? resources.energy / def->energy : 1.0f;
		}

		featureHandler->DeleteFeature(this);
		blockHeightChanges = false;
	}
}



void CFeature::DependentDied(CObject *o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::SetVelocity(const float3& v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::ForcedMove(const float3& newPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::ForcedSpin(const float3& newDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::UpdateTransformAndPhysState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CFeature::UpdateQuadFieldPosition(const float3& moveVec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CFeature::UpdateVelocity(
	const float3& dragAccel,
	const float3& gravAccel,
	const float3& movMask,
	const float3& velMask
) {
	// apply drag and gravity to speed; leave more advanced physics (water
	// buoyancy, etc) to Lua
	// NOTE:
	//   all these calls use the base-class because FeatureHandler::Update
	//   iterates over updateFeatures and our ::SetVelocity will insert us
	//   into that
	//
	// drag is only valid for current speed, needs to be applied first
	CWorldObject::SetVelocity((speed + dragAccel) * velMask);

	if (!IsInWater()) {
		// quadratic downward acceleration if not in water
		CWorldObject::SetVelocity(((speed * OnesVector) + gravAccel) * velMask);
	} else {
		// constant downward speed otherwise, unless floating
		CWorldObject::SetVelocity(((speed *   XZVector) + gravAccel * (1 - def->floating)) * velMask);
	}

	const float oldGroundHeight = CGround::GetHeightReal(pos        );
	const float newGroundHeight = CGround::GetHeightReal(pos + speed);

	// adjust vertical speed so we do not sink into the ground
	if ((pos.y + speed.y) <= newGroundHeight) {
		speed.y  = std::min(newGroundHeight - pos.y, math::fabs(newGroundHeight - oldGroundHeight));
		speed.y *= moveCtrl.velocityMask.y;
	}

	// indicates whether to update quadfield position
	return ((speed.x * movMask.x) != 0.0f || (speed.z * movMask.z) != 0.0f);
}

bool CFeature::UpdatePosition()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CFeature::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::StartFire()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CFeature::EmitGeoSmoke()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CFeature::ChunkNumber(float f) { return int(math::ceil(f * modInfo.reclaimMethod)); }

// note: this is not actually used by GroundBlockingObjectMap anymore, just
// to distinguish unit and feature ID's (values >= MaxUnits() correspond to
// features in object commands)
int CFeature::GetBlockingMapID() const { return (id + unitHandler->MaxUnits()); }

