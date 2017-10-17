#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ISky.h"
#include "AdvSky.h"
#include "BasicSky.h"
#include "Game/TraceRay.h"
#include "Map/MapInfo.h"
#include "Rendering/GlobalRendering.h"
#include "SkyBox.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"

CONFIG(bool, DynamicSun)
  .defaultValue(false)
  .description("Sets whether the sun will move around the sky throughout the "
               "game.\nThe sun will always stay above DynamicSunMinElevation");
CONFIG(bool, AdvSky)
  .defaultValue(true)
  .headlessValue(false)
  .defaultValue(false)
  .description("Enables High Resolution Clouds.");

ISky* sky = NULL;

ISky::ISky()
  : wireframe(false)
  , dynamicSky(false)
  , skyColor(mapInfo->atmosphere.skyColor)
  , sunColor(mapInfo->atmosphere.sunColor)
  , cloudColor(mapInfo->atmosphere.cloudColor)
  , fogColor(mapInfo->atmosphere.fogColor)
  , fogStart(mapInfo->atmosphere.fogStart)
  , fogEnd(mapInfo->atmosphere.fogEnd)
  , cloudDensity(mapInfo->atmosphere.cloudDensity)
  , skyLight(NULL)
// 	, cloudDensity(0.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ISky::~ISky()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ISky::SetupFog()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ISky*
ISky::GetSky()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ISky::SetLight(bool dynamic)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
ISky::SunVisible(const float3 pos) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
