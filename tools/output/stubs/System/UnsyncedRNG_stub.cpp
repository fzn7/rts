#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/UnsyncedRNG.h"
#include "Sim/Misc/GlobalConstants.h"

#include <limits.h>

UnsyncedRNG::UnsyncedRNG()
  : randSeed(0)
#ifdef USE_BOOST_RNG
  , distInt(0, RANDINT_MAX)
  , distSphere(3)
  , gen01(rng, dist01)
  , genInt(rng, distInt)
  , genSphere(rng, distSphere)
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnsyncedRNG::Seed(unsigned seed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
UnsyncedRNG::RandInt()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
UnsyncedRNG::RandFloat()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
UnsyncedRNG::RandVector()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
UnsyncedRNG::RandVector2D()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
UnsyncedRNG::operator()(int n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
