/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CFontTexture.h"
#include "FontLogSection.h"
#include "LanguageBlocksDefs.h"

#include <mutex>
#include <string>
#include <cstring> // for memset, memcpy

#include <boost/thread/recursive_mutex.hpp>

#ifndef HEADLESS
	#include <ft2build.h>
	#include FT_FREETYPE_H
	#ifdef USE_FONTCONFIG
		#include <fontconfig/fontconfig.h>
		#include <fontconfig/fcfreetype.h>
	#endif
#endif // HEADLESS

#include "Game/Camera.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Exceptions.h"
#include "System/Util.h"
#include "System/float4.h"
#include "System/bitops.h"


#ifndef HEADLESS
	#undef __FTERRORS_H__
	#define FT_ERRORDEF( e, v, s )  { e, s },
	#define FT_ERROR_START_LIST     {
	#define FT_ERROR_END_LIST       { 0, 0 } };
	struct ErrorString {
		int          err_code;
		const char*  err_msg;
	} static errorTable[] =
	#include FT_ERRORS_H


	static const char* GetFTError(FT_Error e) {
		for (int a = 0; errorTable[a].err_msg; ++a) {
			if (errorTable[a].err_code == e)
				return errorTable[a].err_msg;
		}
		return "Unknown error";
	}
#endif // HEADLESS




#ifdef HEADLESS
typedef unsigned char FT_Byte;
#endif

struct SP_Byte { //wrapper to allow usage as shared_ptr
	SP_Byte(size_t size) {
		vec.resize(size);
	}
	FT_Byte* data() {
		return vec.data();
	}
private:
	std::vector<FT_Byte> vec;
};

struct FontFace {
	FontFace(FT_Face f, std::shared_ptr<SP_Byte>& mem) : face(f), memory(mem) { }
	~FontFace() {
	#ifndef HEADLESS
		FT_Done_Face(face);
	#endif
	}
	operator FT_Face() { return this->face; }

	FT_Face face;
	std::shared_ptr<SP_Byte> memory;
};

static std::unordered_set<CFontTexture*> allFonts;
static std::unordered_map<std::string, std::weak_ptr<FontFace>> fontCache;
static std::unordered_map<std::string, std::weak_ptr<SP_Byte>> fontMemCache;
static boost::recursive_mutex m;



#ifndef HEADLESS
class FtLibraryHandler
{
    //stub method
}


#ifndef HEADLESS
static std::shared_ptr<FontFace> GetFontFace(const std::string& fontfile, const int size)
{
    //stub method
}
#endif



static std::shared_ptr<FontFace> GetFontForCharacters(std::list<char32_t>& characters, const FT_Face origFace, const int origSize)
{
    //stub method
}


/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/


CFontTexture::CFontTexture(const std::string& fontfile, int size, int _outlinesize, float  _outlineweight)
	: outlineSize(_outlinesize)
	, outlineWeight(_outlineweight)
	, lineHeight(0)
	, fontDescender(0)
	, fontSize(size)
	, texWidth(0)
	, texHeight(0)
	, wantedTexWidth(0)
	, wantedTexHeight(0)
	, texture(0)
	, textureSpaceMatrix(0)
	, atlasUpdate(NULL)
	, atlasUpdateShadow(NULL)
	, lastTextureUpdate(0)
	, curTextureUpdate(0)
	, face(NULL)
{
    //stub method
}

CFontTexture::~CFontTexture()
{
    //stub method
}


void CFontTexture::Update() {
	std::lock_guard<boost::recursive_mutex> lk(m);
	for (auto& font: allFonts) {
		font->UpdateTexture();
	}
}


const GlyphInfo& CFontTexture::GetGlyph(char32_t ch)
{
    //stub method
}


float CFontTexture::GetKerning(const GlyphInfo& lgl, const GlyphInfo& rgl)
{
    //stub method
}


void CFontTexture::LoadBlock(char32_t start, char32_t end)
{
    //stub method
}



void CFontTexture::LoadGlyph(std::shared_ptr<FontFace>& f, char32_t ch, unsigned index)
{
    //stub method
}


void CFontTexture::CreateTexture(const int width, const int height)
{
    //stub method
}


void CFontTexture::UpdateTexture()
{
    //stub method
}
