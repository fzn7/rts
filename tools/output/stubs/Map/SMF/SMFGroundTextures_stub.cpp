#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#if defined(USE_LIBSQUISH) && !defined(HEADLESS)
#include "lib/squish/squish.h"
#include "lib/rg-etc1/rg_etc1.h"
#endif

#include "Game/Camera.h"
#include "Game/Game.h"
#include "Game/GameSetup.h"
#include "Game/LoadScreen.h"
#include "Map/MapInfo.h"
#include "Rendering/GL/PBO.h"
#include "Rendering/GlobalRendering.h"
#include "SMFFormat.h"
#include "SMFGroundTextures.h"
#include "SMFReadMap.h"
#include "System/Exceptions.h"
#include "System/FastMath.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/ThreadPool.h"
#include "System/TimeProfiler.h"

using std::sprintf;

#define LOG_SECTION_SMF_GROUND_TEXTURES "CSMFGroundTextures"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_SMF_GROUND_TEXTURES)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_SMF_GROUND_TEXTURES

CSMFGroundTextures::GroundSquare::~GroundSquare()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSMFGroundTextures::CSMFGroundTextures(CSMFReadMap* rm)
  : smfMap(rm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSMFGroundTextures::LoadTiles(CSMFMapFile& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSMFGroundTextures::LoadSquareTextures(const int mipLevel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSMFGroundTextures::ConvolveHeightMap(const int mapWidth, const int mipLevel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if defined(USE_LIBSQUISH) && !defined(HEADLESS) &&                            \
  defined(GLEW_ARB_ES3_compatibility)
// Not all FOSS drivers support S3TC, use ETC1 for those if possible
bool
CSMFGroundTextures::RecompressTilesIfNeeded()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

inline bool
CSMFGroundTextures::TexSquareInView(int btx, int bty) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSMFGroundTextures::DrawUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSMFGroundTextures::SetSquareLuaTexture(int texSquareX,
                                        int texSquareY,
                                        int texID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSMFGroundTextures::GetSquareLuaTexture(int texSquareX,
                                        int texSquareY,
                                        int texID,
                                        int texSizeX,
                                        int texSizeY,
                                        int texMipLevel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSMFGroundTextures::ExtractSquareTiles(const int texSquareX,
                                       const int texSquareY,
                                       const int mipLevel,
                                       GLint* tileBuf) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSMFGroundTextures::LoadSquareTexture(int x, int y, int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSMFGroundTextures::BindSquareTexture(int texSquareX, int texSquareY)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
