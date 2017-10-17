#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PathHeatMap.hpp"
#include "PathConstants.h"
#include "PathManager.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Objects/SolidObject.h"

// not extern'ed, so static
static PathHeatMap* gPathHeatMap = NULL;

PathHeatMap*
PathHeatMap::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
PathHeatMap::FreeInstance(PathHeatMap* phm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

PathHeatMap::PathHeatMap(unsigned int scalex, unsigned int scalez)
  : enabled(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

PathHeatMap::~PathHeatMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
PathHeatMap::GetHeatMapIndex(unsigned int hmx, unsigned int hmz) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
PathHeatMap::AddHeat(const CSolidObject* owner,
                     const CPathManager* pm,
                     unsigned int pathID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
PathHeatMap::UpdateHeatValue(unsigned int x,
                             unsigned int y,
                             unsigned int value,
                             unsigned int ownerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
PathHeatMap::GetHeatCost(unsigned int x,
                         unsigned int z,
                         const MoveDef& md,
                         unsigned int ownerID) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
