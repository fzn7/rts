#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SimObjectIDPool.h"
#include "GlobalSynced.h"
#include "Sim/Objects/SolidObject.h"
#include "System/creg/STL_Map.h"

CR_BIND(SimObjectIDPool, )
CR_REG_METADATA(SimObjectIDPool,
                (CR_MEMBER(liveIdentIndexMap),
                 CR_MEMBER(liveIndexIdentMap),
                 CR_MEMBER(tempIndexIdentMap)))

void
SimObjectIDPool::Expand(unsigned int baseID, unsigned int numIDs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SimObjectIDPool::AssignID(CSolidObject* object)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
SimObjectIDPool::ExtractID()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SimObjectIDPool::ReserveID(unsigned int id)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SimObjectIDPool::FreeID(unsigned int id, bool delayed)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SimObjectIDPool::RecycleIDs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SimObjectIDPool::HasID(unsigned int id) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
