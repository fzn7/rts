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
}


CLosTexture::~CLosTexture()
{
    //stub method
}


void CLosTexture::UpdateCPU()
{
    //stub method
}


void CLosTexture::Update()
{
    //stub method
}
