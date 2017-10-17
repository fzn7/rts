#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/GL/myGL.h"

#include "Game/Camera.h"
#include "Game/Game.h"
#include "Game/LoadScreen.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/UI/CommandColors.h"
#include "Game/UI/GuiHandler.h"
#include "Lua/LuaUnsyncedCtrl.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/HeightMapTexture.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/CommandDrawer.h"
#include "Rendering/DebugColVolDrawer.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/Env/GrassDrawer.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/ITreeDrawer.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/FarTextureHandler.h"
#include "Rendering/FeatureDrawer.h"
#include "Rendering/IPathDrawer.h"
#include "Rendering/InMapDrawView.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/Models/IModelParser.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/SmoothHeightMeshDrawer.h"
#include "Rendering/Textures/3DOTextureHandler.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Rendering/UnitDrawer.h"
#include "System/EventHandler.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "WorldDrawer.h"

CWorldDrawer::CWorldDrawer()
  : numUpdates(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CWorldDrawer::~CWorldDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::LoadPre() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::LoadPost() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::Update(bool newSimFrame)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::GenerateIBLTextures() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::ResetMVPMatrices() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::Draw() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::DrawOpaqueObjects() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::DrawAlphaObjects() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::DrawMiscObjects() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWorldDrawer::DrawBelowWaterOverlay() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
