#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/myGL.h"
#include "RefractWater.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "System/bitops.h"

CRefractWater::CRefractWater()
	: CAdvWater(false)
	, subSurfaceTex(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CRefractWater::LoadGfx()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CRefractWater::~CRefractWater()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CRefractWater::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CRefractWater::SetupWaterDepthTex()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

