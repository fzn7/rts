#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Feature.h"
#include "FeatureDef.h"
#include "FeatureDefHandler.h"
#include "FeatureHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Rendering/Env/Particles/Classes/GeoThermSmokeProjectile.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/FireProjectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/creg/DefTypes.h"
#include "System/myMath.h"
#include <assert.h>

CR_BIND_DERIVED(CFeature, CSolidObject, )

CR_REG_METADATA(CFeature,
                (CR_MEMBER(isRepairingBeforeResurrect),
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
                 CR_POSTLOAD(PostLoad)))

CR_BIND(CFeature::MoveCtrl, )

CR_REG_METADATA_SUB(CFeature,
                    MoveCtrl,
                    (CR_MEMBER(enabled),

                     CR_MEMBER(movementMask),
                     CR_MEMBER(velocityMask),
                     CR_MEMBER(impulseMask),

                     CR_MEMBER(velVector),
                     CR_MEMBER(accVector)))

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
    std::cout << __FUNCTION__ << std::endl;
}

CFeature::~CFeature()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::ChangeTeam(int newTeam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeature::IsInLosForAllyTeam(int argAllyTeam) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::Initialize(const FeatureLoadParams& params)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeature::AddBuildPower(CUnit* builder, float amount)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::DoDamage(const DamageArray& damages,
                   const float3& impulse,
                   CUnit* attacker,
                   int weaponDefID,
                   int projectileID)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::DependentDied(CObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::SetVelocity(const float3& v)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::ForcedMove(const float3& newPos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::ForcedSpin(const float3& newDir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::UpdateTransformAndPhysState()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::UpdateQuadFieldPosition(const float3& moveVec)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeature::UpdateVelocity(const float3& dragAccel,
                         const float3& gravAccel,
                         const float3& movMask,
                         const float3& velMask)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeature::UpdatePosition()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeature::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::StartFire()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeature::EmitGeoSmoke()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CFeature::ChunkNumber(float f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// note: this is not actually used by GroundBlockingObjectMap anymore, just
// to distinguish unit and feature ID's (values >= MaxUnits() correspond to
// features in object commands)
int
CFeature::GetBlockingMapID() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
