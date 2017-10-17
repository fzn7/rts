#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <assert.h>

#include "GlobalConstants.h"
#include "GroundBlockingObjectMap.h"
#include "Map/ReadMap.h"
#include "Sim/Path/IPathManager.h"
#include "System/Sync/HsiehHash.h"
#include "System/Util.h"
#include "System/creg/STL_Map.h"

CGroundBlockingObjectMap* groundBlockingObjectMap = nullptr;

CR_BIND(CGroundBlockingObjectMap, (1))
CR_REG_METADATA(CGroundBlockingObjectMap, (CR_MEMBER(groundBlockingMap)))

void
CGroundBlockingObjectMap::AddGroundBlockingObject(CSolidObject* object)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundBlockingObjectMap::AddGroundBlockingObject(CSolidObject* object,
                                                  const YardMapStatus& mask)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroundBlockingObjectMap::RemoveGroundBlockingObject(CSolidObject* object)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSolidObject*
CGroundBlockingObjectMap::GroundBlocked(int x, int z) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSolidObject*
CGroundBlockingObjectMap::GroundBlocked(const float3& pos) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundBlockingObjectMap::GroundBlocked(int x,
                                        int z,
                                        const CSolidObject* ignoreObj) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundBlockingObjectMap::GroundBlocked(const float3& pos,
                                        const CSolidObject* ignoreObj) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Opens up a yard in a blocked area.
 * When a factory opens up, for example.
 */
void
CGroundBlockingObjectMap::OpenBlockingYard(CSolidObject* object)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////
///
///

/**
 * Closes a yard, blocking the area.
 * When a factory closes, for example.
 */
void
CGroundBlockingObjectMap::CloseBlockingYard(CSolidObject* object)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline bool
CGroundBlockingObjectMap::CheckYard(CSolidObject* yardUnit,
                                    const YardMapStatus& mask) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundBlockingObjectMap::CanOpenYard(CSolidObject* yardUnit) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroundBlockingObjectMap::CanCloseYard(CSolidObject* yardUnit) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

unsigned int
CGroundBlockingObjectMap::CalcChecksum() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
