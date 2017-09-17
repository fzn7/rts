#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "EmgCannon.h"
#include "WeaponDef.h"
#include "Sim/Misc/Team.h"
#include "Map/Ground.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "System/Sync/SyncTracer.h"

CR_BIND_DERIVED(CEmgCannon, CWeapon, (NULL, NULL))
CR_REG_METADATA(CEmgCannon, )

CEmgCannon::CEmgCannon(CUnit* owner, const WeaponDef* def): CWeapon(owner, def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEmgCannon::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
