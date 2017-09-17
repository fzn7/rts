/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Metal.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"



CMetalTexture::CMetalTexture()
: CPboInfoTexture("metal")
, CEventClient("[CMetalTexture]", 271990, false)
, metalMapChanged(true)
{
    //stub method
}


void CMetalTexture::Update()
{
    //stub method
}


void CMetalTexture::MetalMapChanged(const int x, const int z)
{
    //stub method
}


bool CMetalTexture::IsUpdateNeeded()
{
    //stub method
}
