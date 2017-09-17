#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "HeightMapTexture.h"

#include "ReadMap.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Rectangle.h"

CONFIG(bool, HeightMapTexture).defaultValue(true);

HeightMapTexture* heightMapTexture = NULL;
HeightMapTexture::HeightMapTexture()
  : CEventClient("[HeightMapTexture]", 2718965, false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

HeightMapTexture::~HeightMapTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
HeightMapTexture::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
HeightMapTexture::Kill()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
HeightMapTexture::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
