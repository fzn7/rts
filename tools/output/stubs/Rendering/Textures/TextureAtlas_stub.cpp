/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "TextureAtlas.h"

#include "Bitmap.h"
#include "LegacyAtlasAlloc.h"
#include "QuadtreeAtlasAlloc.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/PBO.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/Exceptions.h"

#include <list>
#include <cstring>

CR_BIND(AtlasedTexture, )
CR_REG_METADATA(AtlasedTexture,
		(CR_MEMBER(x), CR_MEMBER(y), CR_MEMBER(z), CR_MEMBER(w)))

// texture spacing in the atlas (in pixels)
#define TEXMARGIN 2

bool CTextureAtlas::debug;

CTextureAtlas::CTextureAtlas(unsigned int allocType)
	: atlasAllocator(NULL)
	, atlasTexID(0)
	, initialized(false)
	, freeTexture(true)
{
    //stub method
}

CTextureAtlas::~CTextureAtlas()
{
    //stub method
}

void* CTextureAtlas::AddTex(std::string name, int xsize, int ysize, TextureType texType)
{
    //stub method
}

int CTextureAtlas::AddTexFromMem(std::string name, int xsize, int ysize, TextureType texType, void* data)
{
    //stub method
}

int CTextureAtlas::AddTexFromFile(std::string name, std::string file)
{
    //stub method
}

bool CTextureAtlas::Finalize()
{
    //stub method
}

void CTextureAtlas::CreateTexture()
{
    //stub method
}

int CTextureAtlas::GetBPP(TextureType texType)
{
    //stub method
}

void CTextureAtlas::BindTexture()
{
    //stub method
}

bool CTextureAtlas::TextureExists(const std::string& name)
{
    //stub method
}


AtlasedTexture& CTextureAtlas::GetTexture(const std::string& name)
{
    //stub method
}


AtlasedTexture& CTextureAtlas::GetTextureWithBackup(const std::string& name, const std::string& backupName)
{
    //stub method
}

int2 CTextureAtlas::GetSize() const {
	return (atlasAllocator->GetAtlasSize());
}

