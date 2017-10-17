#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstdlib>

#include "PathFinderDef.h"
#include "Sim/MoveTypes/MoveDefHandler.h"

CPathFinderDef::CPathFinderDef(const float3& goalCenter,
                               float goalRadius,
                               float sqGoalDistance)
  : goal(goalCenter)
  , sqGoalRadius(goalRadius * goalRadius)
  , constraintDisabled(false)
  , testMobile(true)
  , needPath(true)
  , exactPath(true)
  , dirIndependent(false)
  , synced(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// returns true when the goal is within our defined range
bool
CPathFinderDef::IsGoal(unsigned int xSquare, unsigned int zSquare) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// returns distance to goal center in heightmap-squares
float
CPathFinderDef::Heuristic(unsigned int xSquare, unsigned int zSquare) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// returns if the goal is inaccessable: this is
// true if the goal area is "small" and blocked
bool
CPathFinderDef::IsGoalBlocked(const MoveDef& moveDef,
                              const CMoveMath::BlockType& blockMask,
                              const CSolidObject* owner) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int2
CPathFinderDef::GoalSquareOffset(unsigned int blockSize) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCircularSearchConstraint::CCircularSearchConstraint(const float3& start,
                                                     const float3& goal,
                                                     float goalRadius,
                                                     float searchSize,
                                                     unsigned int extraSize)
  : CPathFinderDef(goal, goalRadius, start.SqDistance2D(goal))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CRectangularSearchConstraint::CRectangularSearchConstraint(
  const float3 startPos,
  const float3 goalPos,
  float sqRadius,
  unsigned int blockSize)
  : CPathFinderDef(goalPos, 0.0f, startPos.SqDistance2D(goalPos))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
