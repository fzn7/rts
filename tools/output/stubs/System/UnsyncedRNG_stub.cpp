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
}


void UnsyncedRNG::operator=(const UnsyncedRNG& urng)
{
    //stub method
}


void UnsyncedRNG::Seed(unsigned seed)
{
    //stub method
}

int UnsyncedRNG::RandInt()
{
    //stub method
}

float UnsyncedRNG::RandFloat()
{
    //stub method
}

float3 UnsyncedRNG::RandVector()
{
    //stub method
}

float3 UnsyncedRNG::RandVector2D()
{
    //stub method
}

int UnsyncedRNG::operator()(int n)
{
    //stub method
}
