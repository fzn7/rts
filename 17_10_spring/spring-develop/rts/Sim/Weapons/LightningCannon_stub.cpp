#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LightningCannon.h"
#include "Game/GameHelper.h"
#include "Game/TraceRay.h"
#include "PlasmaRepulser.h"
#include "Sim/Misc/CollisionHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "WeaponDef.h"

#include <vector>

CR_BIND_DERIVED(CLightningCannon, CWeapon, (NULL, NULL))

CR_REG_METADATA(CLightningCannon, (CR_MEMBER(color)))

CLightningCannon::CLightningCannon(CUnit* owner, const WeaponDef* def)
  : CWeapon(owner, def)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CLightningCannon::GetPredictedImpactTime(float3 p) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLightningCannon::FireImpl(const bool scriptCall)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
