#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SMFRenderState.h"
#include "Game/Camera.h"
#include "Map/MapInfo.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SkyLight.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "SMFGroundDrawer.h"
#include "SMFReadMap.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Config/ConfigHandler.h"
#include "System/Util.h"

#define SMF_TEXSQUARE_SIZE 1024.0f

ISMFRenderState*
ISMFRenderState::GetInstance(bool haveARB, bool haveGLSL, bool luaShaders)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SMFRenderStateARB::Init(const CSMFGroundDrawer* smfGroundDrawer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateARB::Kill()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SMFRenderStateARB::HasValidShader(const DrawPass::e& drawPass) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SMFRenderStateGLSL::Init(const CSMFGroundDrawer* smfGroundDrawer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateGLSL::Kill()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateGLSL::Update(const CSMFGroundDrawer* smfGroundDrawer,
                           const LuaMapShaderData* luaMapShaderData)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SMFRenderStateGLSL::HasValidShader(const DrawPass::e& drawPass) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SMFRenderStateFFP::CanEnable(const CSMFGroundDrawer* smfGroundDrawer) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SMFRenderStateARB::CanEnable(const CSMFGroundDrawer* smfGroundDrawer) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
SMFRenderStateGLSL::CanEnable(const CSMFGroundDrawer* smfGroundDrawer) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateFFP::Enable(const CSMFGroundDrawer* smfGroundDrawer,
                          const DrawPass::e&)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateFFP::Disable(const CSMFGroundDrawer*, const DrawPass::e&)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateARB::Enable(const CSMFGroundDrawer* smfGroundDrawer,
                          const DrawPass::e& drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateARB::Disable(const CSMFGroundDrawer*, const DrawPass::e& drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateGLSL::Enable(const CSMFGroundDrawer* smfGroundDrawer,
                           const DrawPass::e&)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateGLSL::Disable(const CSMFGroundDrawer*, const DrawPass::e&)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateFFP::SetSquareTexGen(const int sqx, const int sqy) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateARB::SetSquareTexGen(const int sqx, const int sqy) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateGLSL::SetSquareTexGen(const int sqx, const int sqy) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateARB::SetCurrentShader(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateGLSL::SetCurrentShader(const DrawPass::e& drawPass)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateARB::UpdateCurrentShaderSky(const ISkyLight* skyLight) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SMFRenderStateGLSL::UpdateCurrentShaderSky(const ISkyLight* skyLight) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
