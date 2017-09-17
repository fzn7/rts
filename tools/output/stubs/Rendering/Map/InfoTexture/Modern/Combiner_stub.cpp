/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Combiner.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Map/ReadMap.h"
#include "System/Exceptions.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"


CONFIG(bool, HighResInfoTexture).defaultValue(true);


CInfoTextureCombiner::CInfoTextureCombiner()
: CPboInfoTexture("info")
, disabled(true)
{
    //stub method
}


void CInfoTextureCombiner::SwitchMode(const std::string& name)
{
    //stub method
}


bool CInfoTextureCombiner::CreateShader(const std::string& filename, const bool clear, const float4 clearColor)
{
    //stub method
}


void CInfoTextureCombiner::Update()
{
    //stub method
}
