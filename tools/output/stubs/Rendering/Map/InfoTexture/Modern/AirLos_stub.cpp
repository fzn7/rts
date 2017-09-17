/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AirLos.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Sim/Misc/LosHandler.h"
#include "System/Exceptions.h"
#include "System/TimeProfiler.h"
#include "System/Log/ILog.h"



CAirLosTexture::CAirLosTexture()
: CPboInfoTexture("airlos")
, uploadTex(0)
{
    //stub method
}


CAirLosTexture::~CAirLosTexture()
{
    //stub method
}


void CAirLosTexture::UpdateCPU()
{
    //stub method
}


void CAirLosTexture::Update()
{
    //stub method
}
