#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "WeaponTarget.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Units/Unit.h"

CR_BIND(SWeaponTarget, )
CR_REG_METADATA(SWeaponTarget,
                (CR_MEMBER(isUserTarget),
                 CR_MEMBER(isManualFire),
                 CR_MEMBER(type),
                 CR_MEMBER(unit),
                 CR_MEMBER(intercept),
                 CR_MEMBER(groundPos)))

SWeaponTarget::SWeaponTarget()
  : type(Target_None)
  , isUserTarget(false)
  , isManualFire(false)
  , unit(nullptr)
  , intercept(nullptr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
