#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <IL/il.h>
#include <SDL_video.h>
#include <boost/thread.hpp>
#include <fstream>
#include <memory>
#include <ostream>
#include <string.h>
#include <utility>

#ifndef BITMAP_NO_OPENGL
#include "Rendering/GL/myGL.h"
#include "System/TimeProfiler.h"
#endif // !BITMAP_NO_OPENGL

#include "Bitmap.h"
#include "Rendering/GlobalRendering.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/Log/ILog.h"
#include "System/ScopedFPUSettings.h"
#include "System/ThreadPool.h"
#include "System/bitops.h"

boost::mutex
  devilMutex; // devil functions, whilst expensive, aren't thread-save

static const float blurkernel[9] = { 1.0f / 16.0f, 2.0f / 16.0f, 1.0f / 16.0f,
                                     2.0f / 16.0f, 4.0f / 16.0f, 2.0f / 16.0f,
                                     1.0f / 16.0f, 2.0f / 16.0f, 1.0f / 16.0f };
// this is a minimal list of file formats that (should) be available at all
// platforms
static const int formatList[] = {
    IL_PNG, IL_JPG,  IL_TGA, IL_DDS,          IL_BMP,       IL_RGBA,
    IL_RGB, IL_BGRA, IL_BGR, IL_COLOUR_INDEX, IL_LUMINANCE, IL_LUMINANCE_ALPHA
};

static bool
IsValidImageFormat(int format)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

struct InitializeOpenIL
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBitmap::CBitmap(const CBitmap& old)
  : mem(old.mem)
  , xsize(old.xsize)
  , ysize(old.ysize)
  , channels(old.channels)
  , compressed(false)
#ifndef BITMAP_NO_OPENGL
  , textype(old.textype)
  , ddsimage(NULL)
#endif // !BITMAP_NO_OPENGL
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBitmap::CBitmap(CBitmap&& bm)
  : mem(std::move(bm.mem))
  , xsize(std::move(bm.xsize))
  , ysize(std::move(bm.ysize))
  , channels(std::move(bm.channels))
  , compressed(std::move(bm.compressed))
#ifndef BITMAP_NO_OPENGL
  , textype(std::move(bm.textype))
  , ddsimage(std::move(bm.ddsimage))
#endif
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBitmap&
CBitmap::operator=(const CBitmap& bm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBitmap&
CBitmap::operator=(CBitmap&& bm)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::Alloc(int w, int h, int c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::Alloc(int w, int h)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::AllocDummy(const SColor fill)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBitmap::Load(std::string const& filename, unsigned char defaultAlpha)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBitmap::LoadGrayscale(const std::string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBitmap::Save(std::string const& filename, bool opaque) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CBitmap::SaveFloat(std::string const& filename) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifndef BITMAP_NO_OPENGL
unsigned int
CBitmap::CreateTexture(float aniso, bool mipmaps) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
HandleDDSMipmap(GLenum target, bool mipmaps, int num_mipmaps)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CBitmap::CreateDDSTexture(unsigned int texID, float aniso, bool mipmaps) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#else  // !BITMAP_NO_OPENGL

unsigned int
CBitmap::CreateTexture(float aniso, bool mipmaps) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CBitmap::CreateDDSTexture(unsigned int texID, float aniso, bool mipmaps) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif // !BITMAP_NO_OPENGL

void
CBitmap::CreateAlpha(unsigned char red, unsigned char green, unsigned char blue)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::SetTransparent(const SColor& c, const SColor trans)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::Renormalize(float3 newCol)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline static void
kernelBlur(CBitmap* dst,
           const unsigned char* src,
           int x,
           int y,
           int channel,
           float weight)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::Blur(int iterations, float weight)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::CopySubImage(const CBitmap& src, int xpos, int ypos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBitmap
CBitmap::CanvasResize(const int newx, const int newy, const bool center) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SDL_Surface*
CBitmap::CreateSDLSurface() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CBitmap
CBitmap::CreateRescaled(int newx, int newy) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::InvertColors()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::InvertAlpha()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::GrayScale()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static ILubyte
TintByte(ILubyte value, float tint)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::Tint(const float tint[3])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CBitmap::ReverseYAxis()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
