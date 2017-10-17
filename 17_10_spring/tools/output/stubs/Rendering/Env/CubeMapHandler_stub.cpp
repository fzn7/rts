#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/Env/CubeMapHandler.h"
#include "Game/Camera.h"
#include "Game/Game.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/UnitDrawer.h"
#include "System/Config/ConfigHandler.h"

CONFIG(int, CubeTexSizeSpecular).defaultValue(128).minimumValue(1);
CONFIG(int, CubeTexSizeReflection).defaultValue(128).minimumValue(1);

CubeMapHandler* cubeMapHandler = NULL;

CubeMapHandler::CubeMapHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CubeMapHandler::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CubeMapHandler::Free()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CubeMapHandler::UpdateReflectionTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CubeMapHandler::CreateReflectionFace(unsigned int glType,
                                     const float3& camDir,
                                     bool skyOnly)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CubeMapHandler::UpdateSpecularTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CubeMapHandler::CreateSpecularFacePart(unsigned int texType,
                                       unsigned int size,
                                       const float3& cdir,
                                       const float3& xdif,
                                       const float3& ydif,
                                       unsigned int y,
                                       unsigned char* buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CubeMapHandler::CreateSpecularFace(unsigned int texType,
                                   unsigned int size,
                                   const float3& cdir,
                                   const float3& xdif,
                                   const float3& ydif)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CubeMapHandler::UpdateSpecularFace(unsigned int texType,
                                   unsigned int size,
                                   const float3& cdir,
                                   const float3& xdif,
                                   const float3& ydif,
                                   unsigned int y,
                                   unsigned char* buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
