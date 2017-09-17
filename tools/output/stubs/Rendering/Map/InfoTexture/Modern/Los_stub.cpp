#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Los.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Sim/Misc/LosHandler.h"
#include "System/Exceptions.h"
#include "System/TimeProfiler.h"
#include "System/Log/ILog.h"



CLosTexture::CLosTexture()
: CPboInfoTexture("los")
, uploadTex(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CLosTexture::~CLosTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLosTexture::UpdateCPU()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLosTexture::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
