#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "MetalMap.h"
#include "ReadMap.h"
#include "System/Config/ConfigHandler.h"
#include "System/myMath.h"
#include "System/EventHandler.h"

CONFIG(bool, MetalMapPalette).defaultValue(false);

CR_BIND(CMetalMap,(NULL, 0, 0, 0.0f))

CR_REG_METADATA(CMetalMap,(
	CR_MEMBER(metalScale),
	CR_MEMBER(sizeX),
	CR_MEMBER(sizeZ),
	CR_MEMBER(metalPal),
	CR_MEMBER(distributionMap),
	CR_MEMBER(extractionMap)
))

CMetalMap::CMetalMap(const unsigned char* map, int _sizeX, int _sizeZ, float _metalScale)
	: metalScale(_metalScale)
	, sizeX(_sizeX)
	, sizeZ(_sizeZ)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



static inline void ClampInt(int& var, int min, int maxPlusOne)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CMetalMap::GetMetalAmount(int x1, int z1, int x2, int z2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CMetalMap::GetMetalAmount(int x, int z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMetalMap::SetMetalAmount(int x, int z, float m)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CMetalMap::RequestExtraction(int x, int z, float toDepth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMetalMap::RemoveExtraction(int x, int z, float depth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CMetalMap::GetMetalExtraction(int x, int z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
