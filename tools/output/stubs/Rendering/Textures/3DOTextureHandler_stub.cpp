#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <cctype>
#include <set>
#include <sstream>

#include "3DOTextureHandler.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/IAtlasAllocator.h"
#include "Rendering/Textures/TextureAtlas.h"
#include "TAPalette.h"
#include "System/Exceptions.h"
#include "System/Util.h"
#include "System/type2.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

C3DOTextureHandler* texturehandler3DO = NULL;

struct TexFile {
	CBitmap tex;  ///< same format as s3o's
	CBitmap tex2; ///< same format as s3o's
	std::string name;
};


C3DOTextureHandler::C3DOTextureHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

C3DOTextureHandler::~C3DOTextureHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::vector<TexFile*> C3DOTextureHandler::LoadTexFiles()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


C3DOTextureHandler::UnitTexture* C3DOTextureHandler::Get3DOTexture(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void C3DOTextureHandler::Set3doAtlases() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

TexFile* C3DOTextureHandler::CreateTex(const std::string& name, const std::string& name2, bool teamcolor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

