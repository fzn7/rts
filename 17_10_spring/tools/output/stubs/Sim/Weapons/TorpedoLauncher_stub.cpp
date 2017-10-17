#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TorpedoLauncher.h"
#include "Map/Ground.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "WeaponDef.h"

CR_BIND_DERIVED(CTorpedoLauncher, CWeapon, (NULL, NULL))

CR_REG_METADATA(CTorpedoLauncher, (CR_MEMBER(tracking)))

CTorpedoLauncher::CTorpedoLauncher(CUnit* owner, const WeaponDef* def)
  : CWeapon(owner, def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CTorpedoLauncher::TestTarget(const float3 pos, const SWeaponTarget& trg) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CTorpedoLauncher::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
