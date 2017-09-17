/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TorpedoLauncher.h"
#include "WeaponDef.h"
#include "Map/Ground.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/Unit.h"

CR_BIND_DERIVED(CTorpedoLauncher, CWeapon, (NULL, NULL))

CR_REG_METADATA(CTorpedoLauncher,(
	CR_MEMBER(tracking)
))

CTorpedoLauncher::CTorpedoLauncher(CUnit* owner, const WeaponDef* def): CWeapon(owner, def)
{
    //stub method
}


bool CTorpedoLauncher::TestTarget(const float3 pos, const SWeaponTarget& trg) const
{
    //stub method
}

void CTorpedoLauncher::FireImpl(const bool scriptCall)
{
    //stub method
}
