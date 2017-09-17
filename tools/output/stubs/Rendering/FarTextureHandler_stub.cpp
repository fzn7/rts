/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "FarTextureHandler.h"

#include "Game/Camera.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Models/3DModel.h"
#include "Sim/Objects/SolidObject.h"
#include "System/myMath.h"
#include "System/Log/ILog.h"

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
}


CFarTextureHandler::~CFarTextureHandler()
{
    //stub method
}


/**
 * @brief Returns the (row, column) pair of a FarTexture in the TextureAtlas.
 */
int2 CFarTextureHandler::GetTextureCoordsInt(const int farTextureNum, const int orientation) const
{
    //stub method
}

/**
 * @brief Returns the TexCoords of a FarTexture in the TextureAtlas.
 */
float2 CFarTextureHandler::GetTextureCoords(const int farTextureNum, const int orientation) const
{
    //stub method
}


bool CFarTextureHandler::HaveFarIcon(const CSolidObject* obj) const
{
    //stub method
}


/**
 * @brief Really create the far texture for the given model.
 */
void CFarTextureHandler::CreateFarTexture(const CSolidObject* obj)
{
    //stub method
}


void CFarTextureHandler::DrawFarTexture(const CSolidObject* obj, CVertexArray* va)
{
    //stub method
}


void CFarTextureHandler::Queue(const CSolidObject* obj)
{
    //stub method
}


void CFarTextureHandler::Draw()
{
    //stub method
}



bool CFarTextureHandler::CheckResizeAtlas()
{
    //stub method
}

