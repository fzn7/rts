#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BeamLaser.h"
#include "Game/GameHelper.h"
#include "Game/TraceRay.h"
#include "Map/Ground.h"
#include "PlasmaRepulser.h"
#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/StrafeAirMoveType.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"
#include "WeaponDef.h"

#include <vector>

#define SWEEPFIRE_ENABLED 1

CR_BIND_DERIVED(CBeamLaser, CWeapon, (NULL, NULL))

CR_REG_METADATA(CBeamLaser,
                (CR_MEMBER(color),
                 CR_MEMBER(oldDir),

                 CR_MEMBER(salvoDamageMult),
                 CR_MEMBER(sweepFireState)))

CR_BIND(CBeamLaser::SweepFireState, )
CR_REG_METADATA_SUB(CBeamLaser,
                    SweepFireState,
                    (CR_MEMBER(sweepInitPos),
                     CR_MEMBER(sweepGoalPos),
                     CR_MEMBER(sweepInitDir),
                     CR_MEMBER(sweepGoalDir),
                     CR_MEMBER(sweepCurrDir),
                     CR_MEMBER(sweepTempDir),
                     CR_MEMBER(sweepInitDst),
                     CR_MEMBER(sweepGoalDst),
                     CR_MEMBER(sweepCurrDst),
                     CR_MEMBER(sweepStartAngle),
                     CR_MEMBER(sweepFiring)))

void
CBeamLaser::SweepFireState::Init(const float3& newTargetPos,
                                 const float3& muzzlePos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CBeamLaser::SweepFireState::GetTargetDist2D() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBeamLaser::CBeamLaser(CUnit* owner, const WeaponDef* def)
  : CWeapon(owner, def)
  , salvoDamageMult(1.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBeamLaser::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBeamLaser::UpdatePosAndMuzzlePos()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CBeamLaser::GetPredictedImpactTime(float3 p) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBeamLaser::UpdateSweep()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBeamLaser::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CBeamLaser::GetFireDir(bool sweepFire, bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBeamLaser::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBeamLaser::FireInternal(float3 curDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
