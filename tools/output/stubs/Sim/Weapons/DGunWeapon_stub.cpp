#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DGunWeapon.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "WeaponDef.h"

CR_BIND_DERIVED(CDGunWeapon, CWeapon, (NULL, NULL))
CR_REG_METADATA(CDGunWeapon, )

CDGunWeapon::CDGunWeapon(CUnit* owner, const WeaponDef* def)
  : CWeapon(owner, def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDGunWeapon::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDGunWeapon::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
