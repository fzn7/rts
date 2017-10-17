#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "WeaponProjectileFactory.h"
#include "BeamLaserProjectile.h"
#include "EmgProjectile.h"
#include "ExplosiveProjectile.h"
#include "FireBallProjectile.h"
#include "FlameProjectile.h"
#include "LargeBeamLaserProjectile.h"
#include "LaserProjectile.h"
#include "LightningProjectile.h"
#include "MissileProjectile.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Weapons/WeaponDef.h"
#include "StarburstProjectile.h"
#include "TorpedoProjectile.h"

unsigned int
WeaponProjectileFactory::LoadProjectile(const ProjectileParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
