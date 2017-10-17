#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "S3OTextureHandler.h"
#include "Rendering/GL/myGL.h"

#include "Rendering/Models/3DModel.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/UnitDrawer.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"
#include "System/Util.h"

#include <algorithm>
#include <cctype>
#include <set>
#include <sstream>

#define LOG_SECTION_TEXTURE "Texture"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_TEXTURE)
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_TEXTURE

#define TEX_MAT_UID(pTxID, sTxID) ((boost::uint64_t(pTxID) << 32u) | sTxID)

// The S3O texture handler uses two textures.
// The first contains diffuse color (RGB) and teamcolor (A)
// The second contains glow (R), reflectivity (G) and 1-bit Alpha (A).

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CS3OTextureHandler* texturehandlerS3O = nullptr;

CS3OTextureHandler::CS3OTextureHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CS3OTextureHandler::~CS3OTextureHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CS3OTextureHandler::PreloadTexture(S3DModel* model,
                                   bool invertAxis,
                                   bool invertAlpha)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CS3OTextureHandler::LoadTexture(S3DModel* model)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CS3OTextureHandler::LoadAndCacheTexture(const S3DModel* model,
                                        unsigned int texNum,
                                        bool invertAxis,
                                        bool invertAlpha,
                                        bool preloadCall)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CS3OTextureHandler::InsertTextureMat(const S3DModel* model)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
