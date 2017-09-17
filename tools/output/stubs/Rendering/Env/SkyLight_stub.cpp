#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */
#include <cfloat>

#include "Map/BaseGroundDrawer.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Misc/GlobalSynced.h"
#include "SkyLight.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/myMath.h"

CONFIG(float, DynamicSunMinElevation)
  .defaultValue(0.1f)
  .description("Sets the minimum elevation of the dynamic sun. If less than "
               "0.0, the sun can disappear under the map completely as it "
               "moves.");

StaticSkyLight::StaticSkyLight()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

DynamicSkyLight::DynamicSkyLight()
  : luaControl(false)
  , updateNeeded(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DynamicSkyLight::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
DynamicSkyLight::SetLightDir(const float4& newLightDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float4
DynamicSkyLight::CalculateSunPos(const float startAngle) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
DynamicSkyLight::SetLightParams(float4 newLightDir,
                                float startAngle,
                                float orbitTime)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
