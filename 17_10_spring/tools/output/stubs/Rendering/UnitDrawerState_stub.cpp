#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UnitDrawerState.hpp"
#include "Game/Camera.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/Env/SkyLight.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/GeometryBuffer.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/myMath.h"
#include "UnitDrawer.h"

void
IUnitDrawerState::PushTransform(const CCamera* cam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IUnitDrawerState::PopTransform()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float4
IUnitDrawerState::GetTeamColor(int team, float alpha)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IUnitDrawerState*
IUnitDrawerState::GetInstance(bool haveARB, bool haveGLSL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IUnitDrawerState::EnableCommon(const CUnitDrawer* ud, bool deferredPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IUnitDrawerState::DisableCommon(const CUnitDrawer* ud, bool deferredPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IUnitDrawerState::EnableTexturesCommon() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
IUnitDrawerState::DisableTexturesCommon() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// note: never actually called, SSP-state is tested
bool
UnitDrawerStateFFP::CanEnable(const CUnitDrawer* ud) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateFFP::Enable(const CUnitDrawer* ud,
                           bool deferredPass,
                           bool alphaPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateFFP::Disable(const CUnitDrawer* ud, bool)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateFFP::EnableTextures() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateFFP::DisableTextures() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateFFP::SetTeamColor(int team, const float2 alpha) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateFFP::SetNanoColor(const float4& color) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
UnitDrawerStateARB::Init(const CUnitDrawer* ud)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateARB::Kill()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
UnitDrawerStateARB::CanEnable(const CUnitDrawer* ud) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateARB::Enable(const CUnitDrawer* ud,
                           bool deferredPass,
                           bool alphaPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateARB::Disable(const CUnitDrawer* ud, bool)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateARB::EnableTextures() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
UnitDrawerStateARB::DisableTextures() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateARB::EnableShaders(const CUnitDrawer*)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
UnitDrawerStateARB::DisableShaders(const CUnitDrawer*)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateARB::SetTeamColor(int team, const float2 alpha) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateARB::SetNanoColor(const float4& color) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
UnitDrawerStateGLSL::Init(const CUnitDrawer* ud)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateGLSL::Kill()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
UnitDrawerStateGLSL::CanEnable(const CUnitDrawer* ud) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateGLSL::Enable(const CUnitDrawer* ud,
                            bool deferredPass,
                            bool alphaPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateGLSL::Disable(const CUnitDrawer* ud, bool deferredPass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateGLSL::EnableTextures() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
UnitDrawerStateGLSL::DisableTextures() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateGLSL::EnableShaders(const CUnitDrawer*)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
UnitDrawerStateGLSL::DisableShaders(const CUnitDrawer*)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateGLSL::UpdateCurrentShaderSky(const CUnitDrawer* ud,
                                            const ISkyLight* skyLight) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateGLSL::SetTeamColor(int team, const float2 alpha) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
UnitDrawerStateGLSL::SetNanoColor(const float4& color) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
