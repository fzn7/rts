/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MissileLauncher.h"
#include "WeaponDef.h"
#include "Game/TraceRay.h"
#include "Map/Ground.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"

CR_BIND_DERIVED(CMissileLauncher, CWeapon, (NULL, NULL))
CR_REG_METADATA(CMissileLauncher, )

CMissileLauncher::CMissileLauncher(CUnit* owner, const WeaponDef* def): CWeapon(owner, def)
{
    //stub method
}


void CMissileLauncher::UpdateWantedDir()
{
    //stub method
}

void CMissileLauncher::FireImpl(const bool scriptCall)
{
    //stub method
}

bool CMissileLauncher::HaveFreeLineOfFire(const float3 pos, const SWeaponTarget& trg, bool useMuzzle) const
{
    //stub method
}
