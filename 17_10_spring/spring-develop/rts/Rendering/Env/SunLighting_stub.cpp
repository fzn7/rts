#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cassert>

#include "SunLighting.h"

#include "Map/MapInfo.h"
#include "System/EventHandler.h"
#include "System/Sync/HsiehHash.h"

/**
 * @brief sunLightingInst
 *
 * Global instance of CSunLighting
 */
CSunLighting sunLightingInst;

CSunLighting::CSunLighting()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// need an explicit copy-ctor because of colors[]
CSunLighting::CSunLighting(const CSunLighting& sl)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSunLighting&
CSunLighting::operator=(const CSunLighting& sl)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSunLighting::Init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSunLighting::Copy(const CSunLighting& sl)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSunLighting::SetValue(unsigned int keyHash, const float4 value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSunLighting::operator==(const CSunLighting& sl) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSunLighting::IsGlobalInstance() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
