#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "SkyBox.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Textures/Bitmap.h"
#include "Game/Camera.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "System/Exceptions.h"
#include "System/float3.h"
#include "System/Log/ILog.h"

#define LOG_SECTION_SKY_BOX "SkyBox"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_SKY_BOX)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_SKY_BOX


CSkyBox::CSkyBox(const std::string& texture)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSkyBox::~CSkyBox()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSkyBox::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
