/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstdlib>

#include "PathFinderDef.h"
#include "Sim/MoveTypes/MoveDefHandler.h"


CPathFinderDef::CPathFinderDef(const float3& goalCenter, float goalRadius, float sqGoalDistance)
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
}

// returns true when the goal is within our defined range
bool CPathFinderDef::IsGoal(unsigned int xSquare, unsigned int zSquare) const {
	return (SquareToFloat3(xSquare, zSquare).SqDistance2D(goal) <= sqGoalRadius);
}

// returns distance to goal center in heightmap-squares
float CPathFinderDef::Heuristic(unsigned int xSquare, unsigned int zSquare) const
{
    //stub method
}


// returns if the goal is inaccessable: this is
// true if the goal area is "small" and blocked
bool CPathFinderDef::IsGoalBlocked(const MoveDef& moveDef, const CMoveMath::BlockType& blockMask, const CSolidObject* owner) const {
	const float r0 = SQUARE_SIZE * SQUARE_SIZE * 4.0f; // same as (SQUARE_SIZE*2)^2
	const float r1 = ((moveDef.xsize * SQUARE_SIZE) >> 1) * ((moveDef.zsize * SQUARE_SIZE) >> 1) * 1.5f;

	if (sqGoalRadius >= r0 && sqGoalRadius > r1)
		return false;

	return ((CMoveMath::IsBlocked(moveDef, goal, owner) & blockMask) != 0);
}

int2 CPathFinderDef::GoalSquareOffset(unsigned int blockSize) const {
	const unsigned int blockPixelSize = blockSize * SQUARE_SIZE;

	int2 offset;
		offset.x = (unsigned(goal.x) % blockPixelSize) / SQUARE_SIZE;
		offset.y = (unsigned(goal.z) % blockPixelSize) / SQUARE_SIZE;

	return offset;
}






CCircularSearchConstraint::CCircularSearchConstraint(
	const float3& start,
	const float3& goal,
	float goalRadius,
	float searchSize,
	unsigned int extraSize
): CPathFinderDef(goal, goalRadius, start.SqDistance2D(goal))
{
    //stub method
}



CRectangularSearchConstraint::CRectangularSearchConstraint(
	const float3 startPos,
	const float3 goalPos,
	float sqRadius,
	unsigned int blockSize
): CPathFinderDef(goalPos, 0.0f, startPos.SqDistance2D(goalPos))
{
    //stub method
}

