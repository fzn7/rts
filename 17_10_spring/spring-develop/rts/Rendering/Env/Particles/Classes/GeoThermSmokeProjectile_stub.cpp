#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GeoThermSmokeProjectile.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/Wind.h"
#include "Sim/Projectiles/ProjectileHandler.h"

CR_BIND_DERIVED(CGeoThermSmokeProjectile, CSmokeProjectile, )

CR_REG_METADATA(CGeoThermSmokeProjectile, (CR_MEMBER(geo)))

CGeoThermSmokeProjectile::CGeoThermSmokeProjectile(const float3& pos,
                                                   const float3& spd,
                                                   int ttl,
                                                   const CFeature* geo)
  : CSmokeProjectile(NULL, pos, spd, ttl, 6, 0.35f, 0.8f)
  , geo(geo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void CGeoThermSmokeProjectile::Update()
{
	 //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGeoThermSmokeProjectile::UpdateDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGeoThermSmokeProjectile::GeoThermDestroyed(const CFeature* geo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
