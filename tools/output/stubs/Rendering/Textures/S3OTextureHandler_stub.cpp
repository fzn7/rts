#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Rendering/GL/myGL.h"
#include "S3OTextureHandler.h"

#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Models/3DModel.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Util.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"

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


void CS3OTextureHandler::PreloadTexture(S3DModel* model, bool invertAxis, bool invertAlpha)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CS3OTextureHandler::LoadTexture(S3DModel* model)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int CS3OTextureHandler::LoadAndCacheTexture(
	const S3DModel* model,
	unsigned int texNum,
	bool invertAxis,
	bool invertAlpha,
	bool preloadCall
) {
	CBitmap* bitmap = nullptr;

	const auto& textureName = model->texs[texNum];
	const auto textureIt = textureCache.find(textureName);

	if (textureIt != textureCache.end())
		return textureIt->second.texID;

	const auto bitmapIt = bitmapCache.find(textureName);

	if (bitmapIt != bitmapCache.end()) {
		// bitmap was previously preloaded but not yet loaded
		// if !preloading, we will now turn the bitmap into a
		// texture and cache it
		bitmap = &(bitmapIt->second);
	} else {
		// bitmap was not yet preloaded, meaning we are the
		// first to (all non-3DO model textures are always
		// preloaded)
		assert(preloadCall);

		auto pair = bitmapCache.emplace(textureName, CBitmap());
		auto iter = pair.first;

		bitmap = &(iter->second);

		if (!bitmap->Load(textureName)) {
			if (!bitmap->Load("unittextures/" + textureName)) {
				LOG_L(L_WARNING, "[%s] could not load texture \"%s\" from model \"%s\"",
					__FUNCTION__, textureName.c_str(), model->name.c_str());

				// file not found (or headless build), set a single pixel so unit is visible
				bitmap->AllocDummy(SColor(255 * (texNum == 0), 0, 0, 255));
			}
		}

		if (invertAxis)
			bitmap->ReverseYAxis();
		if (invertAlpha)
			bitmap->InvertAlpha();
	}

	// don't generate a texture yet, just save the bitmap for later
	if (preloadCall)
		return 0;

	const unsigned int texID = bitmap->CreateMipMapTexture();

	textureCache[textureName] = {
		texID,
		static_cast<unsigned int>(bitmap->xsize),
		static_cast<unsigned int>(bitmap->ysize)
	};

	bitmapCache.erase(textureName);
	return texID;
}


unsigned int CS3OTextureHandler::InsertTextureMat(const S3DModel* model)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

