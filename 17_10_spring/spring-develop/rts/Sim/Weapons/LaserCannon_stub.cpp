#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LaserCannon.h"
#include "Map/Ground.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/myMath.h"
#include "WeaponDef.h"

CR_BIND_DERIVED(CLaserCannon, CWeapon, (NULL, NULL))

CR_REG_METADATA(CLaserCannon, (CR_MEMBER(color)))

CLaserCannon::CLaserCannon(CUnit* owner, const WeaponDef* def)
  : CWeapon(owner, def)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLaserCannon::UpdateRange(const float val)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLaserCannon::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
