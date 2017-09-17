#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CFontTexture.h"
#include "FontLogSection.h"
#include "LanguageBlocksDefs.h"

#include <cstring> // for memset, memcpy
#include <mutex>
#include <string>

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
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/bitops.h"
#include "System/float4.h"

#ifndef HEADLESS
#undef __FTERRORS_H__
#define FT_ERRORDEF(e, v, s) { e, s },
#define FT_ERROR_START_LIST {
#define FT_ERROR_END_LIST                                                      \
    {                                                                          \
        0, 0                                                                   \
    }                                                                          \
    }                                                                          \
    ;
struct ErrorString
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif // HEADLESS

#ifdef HEADLESS
typedef unsigned char FT_Byte;
#endif

struct SP_Byte
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifndef HEADLESS
static std::shared_ptr<FontFace>
GetFontFace(const std::string& fontfile, const int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

static std::shared_ptr<FontFace>
GetFontForCharacters(std::list<char32_t>& characters,
                     const FT_Face origFace,
                     const int origSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/

CFontTexture::CFontTexture(const std::string& fontfile,
                           int size,
                           int _outlinesize,
                           float _outlineweight)
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
    std::cout << _FUNCTION_ << std::endl;
}

CFontTexture::~CFontTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFontTexture::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const GlyphInfo&
CFontTexture::GetGlyph(char32_t ch)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CFontTexture::GetKerning(const GlyphInfo& lgl, const GlyphInfo& rgl)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFontTexture::LoadBlock(char32_t start, char32_t end)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFontTexture::LoadGlyph(std::shared_ptr<FontFace>& f,
                        char32_t ch,
                        unsigned index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFontTexture::CreateTexture(const int width, const int height)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFontTexture::UpdateTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
