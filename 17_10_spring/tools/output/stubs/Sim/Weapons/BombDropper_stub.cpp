#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BombDropper.h"
#include "Game/GameHelper.h"
#include "Map/MapInfo.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/Team.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "WeaponDef.h"

CR_BIND_DERIVED(CBombDropper, CWeapon, (NULL, NULL, false))

CR_REG_METADATA(CBombDropper,
                (CR_MEMBER(dropTorpedoes),
                 CR_MEMBER(torpMoveRange),
                 CR_MEMBER(tracking)))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBombDropper::CBombDropper(CUnit* owner, const WeaponDef* def, bool useTorps)
  : CWeapon(owner, def)
  , dropTorpedoes(useTorps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CBombDropper::GetPredictedImpactTime(float3 impactPos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBombDropper::TestTarget(const float3 pos, const SWeaponTarget& trg) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBombDropper::HaveFreeLineOfFire(const float3 pos,
                                 const SWeaponTarget& trg,
                                 bool useMuzzle) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBombDropper::TestRange(const float3 pos, const SWeaponTarget& trg) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBombDropper::CanFire(bool ignoreAngleGood,
                      bool ignoreTargetType,
                      bool ignoreRequestedDir) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBombDropper::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
