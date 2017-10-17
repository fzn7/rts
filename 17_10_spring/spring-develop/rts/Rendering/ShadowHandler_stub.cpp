#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */
#include <cfloat>

#include "Game/Camera.h"
#include "Game/GameVersion.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/GrassDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/ITreeDrawer.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/FeatureDrawer.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/UnitDrawer.h"
#include "ShadowHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"

#define SHADOWMATRIX_NONLINEAR 0

CONFIG(int, Shadows)
  .defaultValue(2)
  .headlessValue(-1)
  .minimumValue(-1)
  .safemodeValue(-1)
  .description("Sets whether shadows are rendered.\n-1:=forceoff, 0:=off, "
               "1:=full, 2:=fast (skip terrain)"); // FIXME document bitmask
CONFIG(int, ShadowMapSize)
  .defaultValue(CShadowHandler::DEF_SHADOWMAP_SIZE)
  .minimumValue(32)
  .description("Sets the resolution of shadows. Higher numbers increase "
               "quality at the cost of performance.");
CONFIG(int, ShadowProjectionMode)
  .defaultValue(CShadowHandler::SHADOWPROMODE_CAM_CENTER);

CShadowHandler* shadowHandler = NULL;

bool CShadowHandler::shadowsSupported = false;
bool CShadowHandler::firstInit = true;

void
CShadowHandler::Reload(const char* argv)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::Init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::Kill()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::FreeTextures()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::LoadShadowGenShaderProgs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CShadowHandler::InitDepthTarget()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CShadowHandler::WorkaroundUnsupportedFboRenderTargets()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::DrawShadowPasses()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::SetShadowMapSizeFactors()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static CMatrix44f
ComposeLightMatrix(const ISkyLight* light)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static CMatrix44f
ComposeScaleMatrix(const float4 scales)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::SetShadowMatrix(CCamera* playerCam, CCamera* shadowCam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::SetShadowCamera(CCamera* shadowCam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::SetupShadowTexSampler(unsigned int texUnit, bool enable) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::SetupShadowTexSamplerRaw() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::ResetShadowTexSampler(unsigned int texUnit, bool disable) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::ResetShadowTexSamplerRaw() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CShadowHandler::CreateShadows()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float4
CShadowHandler::GetShadowProjectionScales(CCamera* cam, const float3& projDir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CShadowHandler::GetOrthoProjectedMapRadius(const float3& sunDir,
                                           float3& projPos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float
CShadowHandler::GetOrthoProjectedFrustumRadius(CCamera* cam, float3& projPos)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#if 0
void CShadowHandler::CalcMinMaxView()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif
