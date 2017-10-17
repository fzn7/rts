#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifdef USE_VALGRIND
#include <valgrind/valgrind.h>
#endif

#include "System/myMath.h"
#include "Sim/Units/Scripts/CobInstance.h" // for TAANG2RAD (ugh)
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Sync/FPUCheck.h"

#undef far
#undef near

float2 CMyMath::headingToVectorTable[NUM_HEADINGS];

void
CMyMath::Init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
GetVectorFromHAndPExact(const short int heading, const short int pitch)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
LinePointDist(const float3 l1, const float3 l2, const float3 p)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief calculate closest point on linepiece from l1 to l2
 * Note, this clamps the returned point to a position between l1 and l2.
 */
float3
ClosestPointOnLine(const float3 l1, const float3 l2, const float3 p)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * How does it works?
 * We calculate the two intersection points ON the
 * ray as multiple of `dir` starting from `start`.
 * So we get 2 scalars, whereupon `near` defines the
 * new startpoint and `far` defines the new endpoint.
 *
 * credits:
 * http://ompf.org/ray/ray_box.html
 */
std::pair<float, float>
GetMapBoundaryIntersectionPoints(const float3 start, const float3 dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ClampLineInMap(float3& start, float3& end)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ClampRayInMap(const float3 start, float3& end)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
smoothstep(const float edge0, const float edge1, const float value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
smoothstep(const float edge0, const float edge1, float3 vec)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
linearstep(const float edge0, const float edge1, const float value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
hs2rgb(float h, float s)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
