#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Los.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Sim/Misc/LosHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"

CLosTexture::CLosTexture()
  : CPboInfoTexture("los")
  , uploadTex(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CLosTexture::~CLosTexture()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLosTexture::UpdateCPU()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLosTexture::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
