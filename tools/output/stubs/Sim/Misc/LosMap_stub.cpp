#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LosMap.h"
#include "LosHandler.h"
#include "Map/ReadMap.h"
#include "System/Log/ILog.h"
#include "System/ThreadPool.h"
#include "System/Threading/SpringMutex.h"
#include "System/Util.h"
#include "System/float3.h"
#include "System/myMath.h"
#ifdef USE_UNSYNCED_HEIGHTMAP
#include "Game/GlobalUnsynced.h" // for myAllyTeam
#endif
#include <algorithm>
#include <array>

constexpr float LOS_BONUS_HEIGHT = 5.f;

static spring::shared_spinlock mutex;
static std::array<std::vector<float>, ThreadPool::MAX_THREADS> isqrt_table;

static float
isqrt_lookup(unsigned r, int threadNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Midpoint circle algorithm
// func() only get called for the lower top right octant.
// The others need to get by mirroring.
template<typename F>
void
MidpointCircleAlgo(int radius, F func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Calls func(half_line_width, y) for each line of the filled circle.
template<typename F>
void
MidpointCircleAlgoPerLine(int radius, F func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// CLosTables precalc helper

class CLosTables
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CLosTables::CLosTables()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Precalcs the rays for LineOfSight raytracing.
 * In LoS we raytrace all squares in a radius if they are in view
 * or obstructed by the heightmap. To do so we cast rays with the
 * given radius to the LoS circle's surface. But cause those rays
 * have no width, it happens that squares are missed inside of the
 * circle. So these squares get their own rays with length < radius.
 *
 * Note: We only return the rays for the upper right sector, the
 * others can be constructed by mirroring.
 */
CLosTables::LosTable
CLosTables::GetLosRays(const int radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief returns the surface coords of a 2d circle.
 * Note, we only return the upper right part, the other 3 are generated via
 * mirroring.
 */
std::vector<int2>
CLosTables::GetCircleSurface(const int radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Makes sure all squares in the radius are checked & adds rays to
 * missing ones.
 */
void
CLosTables::AddMissing(LosTable& losRays,
                       const std::vector<int2>& circlePoints,
                       const int radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief returns line coords of a ray with zero width to the coords (xf,yf)
 */
CLosTables::LosLine
CLosTables::GetRay(int xf, int yf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLosTables::Debug(const LosTable& losRays,
                  const std::vector<int2>& points,
                  int radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// CLosMap implementation

void
CLosMap::AddCircle(SLosInstance* instance, int amount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLosMap::AddRaycast(SLosInstance* instance, int amount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLosMap::PrepareRaycast(SLosInstance* instance) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define MAP_SQUARE(pos) ((pos).y * size.x + (pos).x)

void
CLosMap::LosAdd(SLosInstance* li) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline static constexpr size_t
ToAngleMapIdx(const int2 p, const int radius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
CastLos(float* prevAng,
        float* maxAng,
        const int2& off,
        std::vector<bool>& squaresMap,
        std::vector<float>& anglesMap,
        int radius,
        int threadNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLosMap::AddSquaresToInstance(SLosInstance* li,
                              const std::vector<bool>& squaresMap) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLosMap::UnsafeLosAdd(SLosInstance* li) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLosMap::SafeLosAdd(SLosInstance* li) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
