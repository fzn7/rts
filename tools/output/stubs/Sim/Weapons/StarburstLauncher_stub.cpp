/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "StarburstLauncher.h"
#include "WeaponDef.h"
#include "Game/TraceRay.h"
#include "Map/Ground.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Units/Unit.h"

CR_BIND_DERIVED(CStarburstLauncher, CWeapon, (NULL, NULL))

CR_REG_METADATA(CStarburstLauncher, (
	CR_MEMBER(uptime),
	CR_MEMBER(tracking)
))

CStarburstLauncher::CStarburstLauncher(CUnit* owner, const WeaponDef* def): CWeapon(owner, def)
{
    //stub method
}


void CStarburstLauncher::FireImpl(const bool scriptCall)
{
    //stub method
}

bool CStarburstLauncher::HaveFreeLineOfFire(const float3 pos, const SWeaponTarget& trg, bool useMuzzle) const
{
    //stub method
}

float CStarburstLauncher::GetRange2D(const float yDiff) const
{
    //stub method
}
