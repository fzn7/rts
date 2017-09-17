#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MetalExtraction.h"
#include "InfoTextureHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Sim/Misc/LosHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"



CMetalExtractionTexture::CMetalExtractionTexture()
: CPboInfoTexture("metalextraction")
, updateN(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMetalExtractionTexture::IsUpdateNeeded()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMetalExtractionTexture::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
