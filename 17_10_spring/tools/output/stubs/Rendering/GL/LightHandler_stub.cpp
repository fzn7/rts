#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LightHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/Shaders/Shader.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/LosHandler.h"
#include "myGL.h"

static const float4 ZeroVector4 = float4(0.0f, 0.0f, 0.0f, 0.0f);

void
GL::LightHandler::Init(unsigned int cfgBaseLight, unsigned int cfgMaxLights)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
GL::LightHandler::AddLight(const GL::Light& light)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
GL::LightHandler::SetLight(unsigned int lgtIndex, const GL::Light& light)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GL::Light*
GL::LightHandler::GetLight(unsigned int lgtHandle)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
GL::LightHandler::Update(Shader::IProgramObject* shader)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
