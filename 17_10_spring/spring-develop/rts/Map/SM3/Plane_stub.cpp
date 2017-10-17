#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cassert>

#include "Plane.h"

void
Plane::MakePlane(const Vector3& v1, const Vector3& v2, const Vector3& v3)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
Plane::operator==(const Plane& pln) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
Plane::EpsilonCompare(const Plane& pln, float epsilon)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
