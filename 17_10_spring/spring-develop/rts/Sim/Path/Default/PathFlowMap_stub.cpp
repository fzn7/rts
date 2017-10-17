#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PathFlowMap.hpp"
#include "Map/ReadMap.h"
#include "PathConstants.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Objects/SolidObject.h"
#include "System/myMath.h"

#define FLOW_EPSILON 0.01f
#define FLOW_DECAY_ENABLED 0
#define FLOW_DECAY_FACTOR 0.86f
#define FLOW_COST_MULT 32.00f
#define FLOW_NGB_PROJECTION 0

// not extern'ed, so static
static PathFlowMap* gPathFlowMap = NULL;

PathFlowMap*
PathFlowMap::GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
PathFlowMap::FreeInstance(PathFlowMap* pfm)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

PathFlowMap::PathFlowMap(unsigned int scalex, unsigned int scalez)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

PathFlowMap::~PathFlowMap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
PathFlowMap::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
PathFlowMap::AddFlow(const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
PathFlowMap::GetCellIdx(const CSolidObject* o) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const float3&
PathFlowMap::GetFlowVec(unsigned int hmx, unsigned int hmz) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
PathFlowMap::GetFlowCost(unsigned int x,
                         unsigned int z,
                         const MoveDef& md,
                         unsigned int pathOpt) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
