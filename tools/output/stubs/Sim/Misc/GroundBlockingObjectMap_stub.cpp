#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <assert.h>

#include "GroundBlockingObjectMap.h"
#include "GlobalConstants.h"
#include "Map/ReadMap.h"
#include "Sim/Path/IPathManager.h"
#include "System/creg/STL_Map.h"
#include "System/Sync/HsiehHash.h"
#include "System/Util.h"

CGroundBlockingObjectMap* groundBlockingObjectMap = nullptr;

CR_BIND(CGroundBlockingObjectMap, (1))
CR_REG_METADATA(CGroundBlockingObjectMap, (
	CR_MEMBER(groundBlockingMap)
))



void CGroundBlockingObjectMap::AddGroundBlockingObject(CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGroundBlockingObjectMap::AddGroundBlockingObject(CSolidObject* object, const YardMapStatus& mask)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CGroundBlockingObjectMap::RemoveGroundBlockingObject(CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



CSolidObject* CGroundBlockingObjectMap::GroundBlocked(int x, int z) const {
	if (x < 0 || x >= mapDims.mapx || z < 0 || z >= mapDims.mapy)
		return nullptr;

	return (GroundBlockedUnsafe(x + z * mapDims.mapx));
}


CSolidObject* CGroundBlockingObjectMap::GroundBlocked(const float3& pos) const {
	const int xSqr = int(pos.x / SQUARE_SIZE);
	const int zSqr = int(pos.z / SQUARE_SIZE);
	return (GroundBlocked(xSqr, zSqr));
}


bool CGroundBlockingObjectMap::GroundBlocked(int x, int z, const CSolidObject* ignoreObj) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CGroundBlockingObjectMap::GroundBlocked(const float3& pos, const CSolidObject* ignoreObj) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/**
  * Opens up a yard in a blocked area.
  * When a factory opens up, for example.
  */
void CGroundBlockingObjectMap::OpenBlockingYard(CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////
///
///

/**
  * Closes a yard, blocking the area.
  * When a factory closes, for example.
  */
void CGroundBlockingObjectMap::CloseBlockingYard(CSolidObject* object)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


inline bool CGroundBlockingObjectMap::CheckYard(CSolidObject* yardUnit, const YardMapStatus& mask) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CGroundBlockingObjectMap::CanOpenYard(CSolidObject* yardUnit) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CGroundBlockingObjectMap::CanCloseYard(CSolidObject* yardUnit) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned int CGroundBlockingObjectMap::CalcChecksum() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
