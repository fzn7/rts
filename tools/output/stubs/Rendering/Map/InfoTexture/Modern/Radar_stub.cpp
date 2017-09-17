#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Radar.h"
#include "InfoTextureHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "System/Exceptions.h"
#include "System/TimeProfiler.h"
#include "System/Log/ILog.h"



CRadarTexture::CRadarTexture()
: CPboInfoTexture("radar")
, uploadTexRadar(0)
, uploadTexJammer(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CRadarTexture::~CRadarTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CRadarTexture::UpdateCPU()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CRadarTexture::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
