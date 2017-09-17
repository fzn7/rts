#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <cmath>
#include <cstdlib>
#include <cstdio>
#if defined(USE_LIBSQUISH) && !defined(HEADLESS)
	#include "lib/squish/squish.h"
	#include "lib/rg-etc1/rg_etc1.h"
#endif

#include "SMFGroundTextures.h"
#include "SMFFormat.h"
#include "SMFReadMap.h"
#include "Rendering/GL/PBO.h"
#include "Rendering/GlobalRendering.h"
#include "Map/MapInfo.h"
#include "Game/Camera.h"
#include "Game/Game.h"
#include "Game/GameSetup.h"
#include "Game/LoadScreen.h"
#include "System/Exceptions.h"
#include "System/FastMath.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/ThreadPool.h"

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



CSMFGroundTextures::CSMFGroundTextures(CSMFReadMap* rm): smfMap(rm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSMFGroundTextures::LoadTiles(CSMFMapFile& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSMFGroundTextures::LoadSquareTextures(const int mipLevel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSMFGroundTextures::ConvolveHeightMap(const int mapWidth, const int mipLevel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if defined(USE_LIBSQUISH) && !defined(HEADLESS) && defined(GLEW_ARB_ES3_compatibility)
// Not all FOSS drivers support S3TC, use ETC1 for those if possible
bool CSMFGroundTextures::RecompressTilesIfNeeded()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

inline bool CSMFGroundTextures::TexSquareInView(int btx, int bty) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSMFGroundTextures::DrawUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CSMFGroundTextures::SetSquareLuaTexture(int texSquareX, int texSquareY, int texID) {
	if (texSquareX < 0 || texSquareX >= smfMap->numBigTexX) { return false; }
	if (texSquareY < 0 || texSquareY >= smfMap->numBigTexY) { return false; }

	GroundSquare* square = &squares[texSquareY * smfMap->numBigTexX + texSquareX];

	if (texID != 0) {
		// free up some memory while the Lua texture is around
		glDeleteTextures(1, square->GetTextureIDPtr());
		square->SetRawTexture(0);
	}

	square->SetLuaTexture(texID);
	return (square->HasLuaTexture());
}

bool CSMFGroundTextures::GetSquareLuaTexture(int texSquareX, int texSquareY, int texID, int texSizeX, int texSizeY, int texMipLevel) {
	if (texSquareX < 0 || texSquareX >= smfMap->numBigTexX) { return false; }
	if (texSquareY < 0 || texSquareY >= smfMap->numBigTexY) { return false; }
	if (texMipLevel < 0 || texMipLevel > 3) { return false; }

	// no point extracting sub-rectangles from compressed data
	if (texSizeX != (smfMap->bigTexSize >> texMipLevel)) { return false; }
	if (texSizeY != (smfMap->bigTexSize >> texMipLevel)) { return false; }

	static const GLenum ttarget = GL_TEXTURE_2D;

	const int mipSqSize = smfMap->bigTexSize >> texMipLevel;
	const int numSqBytes = (mipSqSize * mipSqSize) / 2;

	pbo.Bind();
	pbo.New(numSqBytes);
	ExtractSquareTiles(texSquareX, texSquareY, texMipLevel, (GLint*) pbo.MapBuffer());
	pbo.UnmapBuffer();

	glBindTexture(ttarget, texID);
	glCompressedTexImage2D(ttarget, 0, tileTexFormat, texSizeX, texSizeY, 0, numSqBytes, pbo.GetPtr());
	glBindTexture(ttarget, 0);

	pbo.Invalidate();
	pbo.Unbind();
	return true;
}



void CSMFGroundTextures::ExtractSquareTiles(
	const int texSquareX,
	const int texSquareY,
	const int mipLevel,
	GLint* tileBuf
) const {
	static const int TILE_MIP_OFFSET[] = {0, 512, 512+128, 512+128+32};
	static const int BLOCK_SIZE = 32;

	const int mipOffset = TILE_MIP_OFFSET[mipLevel];
	const int numBlocks = SQUARE_SIZE >> mipLevel;
	const int tileOffsetX = texSquareX * BLOCK_SIZE;
	const int tileOffsetY = texSquareY * BLOCK_SIZE;

	// extract all 32x32 sub-blocks (tiles) in the 128x128 square
	// (each 32x32 tile covers a (bigSquareSize = 32 * tileScale) x
	// (bigSquareSize = 32 * tileScale) heightmap chunk)
	for (int y1 = 0; y1 < BLOCK_SIZE; y1++) {
		for (int x1 = 0; x1 < BLOCK_SIZE; x1++) {
			const int tileX = tileOffsetX + x1;
			const int tileY = tileOffsetY + y1;
			const int tileIdx = tileMap[tileY * smfMap->tileMapSizeX + tileX];
			const GLint* tile = (GLint*) &tiles[tileIdx * SMALL_TILE_SIZE + mipOffset];

			const int doff = (x1 * numBlocks) + (y1 * numBlocks * numBlocks) * BLOCK_SIZE;

			for (int b = 0; b < numBlocks; b++) {
				const GLint* sbuf = &tile[b * numBlocks * 2];
				      GLint* dbuf = &tileBuf[(doff + b * numBlocks * BLOCK_SIZE) * 2];

				// at MIP level n: ((8 >> n) * 2 * 4) = (64 >> n) bytes for each <b>
				memcpy(dbuf, sbuf, numBlocks * 2 * sizeof(GLint));
			}
		}
	}
}

void CSMFGroundTextures::LoadSquareTexture(int x, int y, int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSMFGroundTextures::BindSquareTexture(int texSquareX, int texSquareY)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
