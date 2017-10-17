#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FarTextureHandler.h"

#include "Game/Camera.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Models/3DModel.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Objects/SolidObject.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"

#define LOG_SECTION_FAR_TEXTURE_HANDLER "FarTextureHandler"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_FAR_TEXTURE_HANDLER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_FAR_TEXTURE_HANDLER

#define NUM_ICON_ORIENTATIONS 8

CFarTextureHandler* farTextureHandler = nullptr;

CFarTextureHandler::CFarTextureHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CFarTextureHandler::~CFarTextureHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Returns the (row, column) pair of a FarTexture in the TextureAtlas.
 */
int2
CFarTextureHandler::GetTextureCoordsInt(const int farTextureNum,
                                        const int orientation) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Returns the TexCoords of a FarTexture in the TextureAtlas.
 */
float2
CFarTextureHandler::GetTextureCoords(const int farTextureNum,
                                     const int orientation) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFarTextureHandler::HaveFarIcon(const CSolidObject* obj) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Really create the far texture for the given model.
 */
void
CFarTextureHandler::CreateFarTexture(const CSolidObject* obj)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFarTextureHandler::DrawFarTexture(const CSolidObject* obj, CVertexArray* va)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFarTextureHandler::Queue(const CSolidObject* obj)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFarTextureHandler::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFarTextureHandler::CheckResizeAtlas()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
