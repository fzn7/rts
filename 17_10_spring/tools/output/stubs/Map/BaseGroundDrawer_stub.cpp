#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "BaseGroundDrawer.h"

#include "Game/Camera.h"
#include "ReadMap.h"
#include "Rendering/Env/ITreeDrawer.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "System/Config/ConfigHandler.h"

CONFIG(float, GroundLODScaleReflection).defaultValue(1.0f).headlessValue(0.0f);
CONFIG(float, GroundLODScaleRefraction).defaultValue(1.0f).headlessValue(0.0f);
CONFIG(float, GroundLODScaleTerrainReflection).defaultValue(1.0f);

CBaseGroundDrawer::CBaseGroundDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBaseGroundDrawer::~CBaseGroundDrawer() {}

void
CBaseGroundDrawer::DrawTrees(bool drawReflection) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
