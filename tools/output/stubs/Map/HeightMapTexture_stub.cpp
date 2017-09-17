/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "HeightMapTexture.h"

#include "ReadMap.h"
#include "System/EventHandler.h"
#include "System/Rectangle.h"
#include "System/Config/ConfigHandler.h"


CONFIG(bool, HeightMapTexture).defaultValue(true);

HeightMapTexture* heightMapTexture = NULL;
HeightMapTexture::HeightMapTexture()
	: CEventClient("[HeightMapTexture]", 2718965, false)
{
    //stub method
}


HeightMapTexture::~HeightMapTexture()
{
    //stub method
}


void HeightMapTexture::Init()
{
    //stub method
}


void HeightMapTexture::Kill()
{
    //stub method
}


void HeightMapTexture::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
}
