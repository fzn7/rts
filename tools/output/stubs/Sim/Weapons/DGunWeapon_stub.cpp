/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DGunWeapon.h"
#include "WeaponDef.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"

CR_BIND_DERIVED(CDGunWeapon, CWeapon, (NULL, NULL))
CR_REG_METADATA(CDGunWeapon, )

CDGunWeapon::CDGunWeapon(CUnit* owner, const WeaponDef* def): CWeapon(owner, def)
{
    //stub method
}


float CDGunWeapon::GetPredictedImpactTime(float3 p) const
{
    //stub method
}


void CDGunWeapon::FireImpl(const bool scriptCall)
{
    //stub method
}


void CDGunWeapon::Init()
{
    //stub method
}
