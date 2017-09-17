#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AirLos.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Sim/Misc/LosHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"

CAirLosTexture::CAirLosTexture()
  : CPboInfoTexture("airlos")
  , uploadTex(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAirLosTexture::~CAirLosTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAirLosTexture::UpdateCPU()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAirLosTexture::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
