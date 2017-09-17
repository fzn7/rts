#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ProjectileFunctors.h"
#include "Projectile.h"

bool
ProjectileDistanceComparator::operator()(const CProjectile* arg1,
                                         const CProjectile* arg2) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
