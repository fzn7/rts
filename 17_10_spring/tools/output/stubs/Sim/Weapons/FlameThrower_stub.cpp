#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FlameThrower.h"
#include "Map/Ground.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "WeaponDef.h"

CR_BIND_DERIVED(CFlameThrower, CWeapon, (NULL, NULL))

CR_REG_METADATA(CFlameThrower, (CR_MEMBER(color), CR_MEMBER(color2)))

CFlameThrower::CFlameThrower(CUnit* owner, const WeaponDef* def)
  : CWeapon(owner, def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
