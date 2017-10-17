#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Height.h"
#include "Map/HeightLinePalette.h"
#include "Map/HeightMapTexture.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "System/Color.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"

// currently defined in HeightLinePalette.cpp
// CONFIG(bool, ColorElev).defaultValue(true).description("If heightmap (default
// hotkey [F1]) should be colored or not.");

CHeightTexture::CHeightTexture()
  : CPboInfoTexture("height")
  , CEventClient("[CHeightTexture]", 271990, false)
  , needUpdate(true)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CHeightTexture::UpdateCPU()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CHeightTexture::~CHeightTexture()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CHeightTexture::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CHeightTexture::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CHeightTexture::IsUpdateNeeded()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
