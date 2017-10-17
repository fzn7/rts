#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SMFGroundDrawer.h"
#include "Game/Camera.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Map/SMF/Legacy/LegacyMeshDrawer.h"
#include "Map/SMF/ROAM/RoamMeshDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/ShadowHandler.h"
#include "SMFGroundTextures.h"
#include "SMFReadMap.h"
#include "SMFRenderState.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/FastMath.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"
#include "System/myMath.h"

CONFIG(int, GroundDetail)
  .defaultValue(60)
  .headlessValue(0)
  .minimumValue(0)
  .maximumValue(200)
  .description("Controls how detailed the map geometry will be. On lowered "
               "settings, cliffs may appear to be jagged or \"melting\".");
CONFIG(bool, MapBorder)
  .defaultValue(true)
  .description("Draws a solid border at the edges of the map.");

CONFIG(int, MaxDynamicMapLights).defaultValue(1).minimumValue(0);

CONFIG(bool, AdvMapShading)
  .defaultValue(true)
  .safemodeValue(false)
  .description(
    "Enable shaders for terrain rendering and enable so more effects.");
CONFIG(bool, AllowDeferredMapRendering)
  .defaultValue(false)
  .safemodeValue(false);

CONFIG(int, ROAM)
  .defaultValue(Patch::VBO)
  .safemodeValue(Patch::DL)
  .minimumValue(0)
  .maximumValue(Patch::VA)
  .description("Use ROAM for terrain mesh rendering. 0:=disable ROAM, 1=VBO "
               "mode, 2=DL mode, 3=VA mode");

CSMFGroundDrawer::CSMFGroundDrawer(CSMFReadMap* rm)
  : smfMap(rm)
  , meshDrawer(NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CSMFGroundDrawer::~CSMFGroundDrawer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

IMeshDrawer*
CSMFGroundDrawer::SwitchMeshDrawer(int mode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::CreateWaterPlanes(bool camOufOfMap)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CSMFGroundDrawer::DrawWaterPlane(bool drawWaterReflection)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

ISMFRenderState*
CSMFGroundDrawer::SelectRenderState(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSMFGroundDrawer::HaveLuaRenderState() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::DrawDeferredPass(const DrawPass::e& drawPass, bool alphaTest)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::DrawForwardPass(const DrawPass::e& drawPass, bool alphaTest)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::Draw(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::DrawBorder(const DrawPass::e drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::DrawShadowPass()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::SetLuaShader(const LuaMapShaderData* luaMapShaderData)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::SetupBigSquare(const int bigSquareX, const int bigSquareY)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::UpdateRenderState()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::SunChanged()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CSMFGroundDrawer::UpdateGeometryBuffer(bool init)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::IncreaseDetail()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::DecreaseDetail()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSMFGroundDrawer::SetDetail(int newGroundDetail)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CSMFGroundDrawer::GetGroundDetail(const DrawPass::e& drawPass) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
