#include <iostream>
#include "BuildingMaskMap.h"
#include "GlobalConstants.h"

BuildingMaskMap* buildingMaskMap = nullptr;

CR_BIND(BuildingMaskMap, ())
CR_REG_METADATA(BuildingMaskMap, (
	CR_MEMBER(maskMap)
	))


bool BuildingMaskMap::CheckBounds(unsigned int x, unsigned int z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// sets mask value for tile[x,z] in 2*SQUARE_SIZE coordinates
bool BuildingMaskMap::SetTileMask(unsigned int x, unsigned int z, boost::uint16_t value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// tests previously set mask for tile[x,z] in 2*SQUARE_SIZE coordinates against supplied value
// true - construction is allowed, false - it's not
bool BuildingMaskMap::TestTileMaskUnsafe(unsigned int x, unsigned int z, boost::uint16_t value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}