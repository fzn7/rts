#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstring>
#include <deque>
#include <ostream>

#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "PathFinder.h"
#include "PathFinderDef.h"
#include "PathFlowMap.hpp"
#include "PathHeatMap.hpp"
#include "PathLog.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/MoveTypes/MoveDefHandler.h"

#define PATHDEBUG 0

using namespace Bitwise;

const CMoveMath::BlockType squareMobileBlockBits =
  (CMoveMath::BLOCK_MOBILE | CMoveMath::BLOCK_MOVING |
   CMoveMath::BLOCK_MOBILE_BUSY);

// indexed by PATHOPT* bitmasks
static float3 PF_DIRECTION_VECTORS_3D[PATH_DIRECTIONS << 1];
static float PF_DIRECTION_COSTS[PATH_DIRECTIONS << 1];

CPathFinder::CPathFinder()
  : IPathFinder(1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPathFinder::InitDirectionCostsTable()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const int2*
CPathFinder::GetDirectionVectorsTable2D()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const float3*
CPathFinder::GetDirectionVectorsTable3D()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IPath::SearchResult
CPathFinder::DoSearch(const MoveDef& moveDef,
                      const CPathFinderDef& pfDef,
                      const CSolidObject* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPathFinder::TestNeighborSquares(const MoveDef& moveDef,
                                 const CPathFinderDef& pfDef,
                                 const PathNode* square,
                                 const CSolidObject* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CPathFinder::TestBlock(const MoveDef& moveDef,
                       const CPathFinderDef& pfDef,
                       const PathNode* parentSquare,
                       const CSolidObject* owner,
                       const unsigned int pathOptDir,
                       const unsigned int blockStatus,
                       float speedMod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IPath::SearchResult
CPathFinder::FinishSearch(const MoveDef& moveDef,
                          const CPathFinderDef& pfDef,
                          IPath::Path& foundPath) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** Helper function for AdjustFoundPath */
static inline void
FixupPath3Pts(const MoveDef& moveDef,
              const float3 p1,
              float3& p2,
              const float3 p3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPathFinder::SmoothMidWaypoint(const int2 testsqr,
                               const int2 prevsqr,
                               const MoveDef& moveDef,
                               IPath::Path& foundPath,
                               const float3 nextPoint) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
 * This function takes the current & the last 2 waypoints and detects when they
 * form a "soft" curve. And if so, it takes the mid waypoint of those 3 and
 * smooths it between the one before and the current waypoint (so the soft curve
 * gets even smoother). Hint: hard curves (e.g. `move North then West`) can't
 * and will not smoothed. Only soft ones like `move North then North-West` can.
 */
void
CPathFinder::AdjustFoundPath(const MoveDef& moveDef,
                             IPath::Path& foundPath,
                             const float3 nextPoint,
                             std::deque<int2>& previous,
                             int2 curquare) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
