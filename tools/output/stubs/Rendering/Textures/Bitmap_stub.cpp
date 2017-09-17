/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <utility>
#include <ostream>
#include <fstream>
#include <memory>
#include <string.h>
#include <IL/il.h>
#include <SDL_video.h>
#include <boost/thread.hpp>

#ifndef BITMAP_NO_OPENGL
	#include "Rendering/GL/myGL.h"
	#include "System/TimeProfiler.h"
#endif // !BITMAP_NO_OPENGL

#include "Bitmap.h"
#include "Rendering/GlobalRendering.h"
#include "System/bitops.h"
#include "System/ScopedFPUSettings.h"
#include "System/Log/ILog.h"
#include "System/ThreadPool.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileHandler.h"


boost::mutex devilMutex; // devil functions, whilst expensive, aren't thread-save

static const float blurkernel[9] = {
	1.0f/16.0f, 2.0f/16.0f, 1.0f/16.0f,
	2.0f/16.0f, 4.0f/16.0f, 2.0f/16.0f,
	1.0f/16.0f, 2.0f/16.0f, 1.0f/16.0f
};
// this is a minimal list of file formats that (should) be available at all platforms
static const int formatList[] = {
	IL_PNG, IL_JPG, IL_TGA, IL_DDS, IL_BMP,
	IL_RGBA, IL_RGB, IL_BGRA, IL_BGR,
	IL_COLOUR_INDEX, IL_LUMINANCE, IL_LUMINANCE_ALPHA
};

static bool IsValidImageFormat(int format) {
	bool valid = false;

	// check if format is in the allowed list
	for (size_t i = 0; i < (sizeof(formatList) / sizeof(formatList[0])); i++) {
		if (format == formatList[i]) {
			valid = true;
			break;
		}
	}

	return valid;
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

struct InitializeOpenIL {
	InitializeOpenIL() {
		ilInit();
		//iluInit();
	}
	~InitializeOpenIL() {
		ilShutDown();
	}
} static initOpenIL;


CBitmap::CBitmap()
	: xsize(0)
	, ysize(0)
	, channels(4)
	, compressed(false)
#ifndef BITMAP_NO_OPENGL
	, textype(GL_TEXTURE_2D)
	, ddsimage(NULL)
#endif // !BITMAP_NO_OPENGL
{
    //stub method
}


CBitmap::~CBitmap()
{
    //stub method
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
}


CBitmap::CBitmap(const unsigned char* data, int _xsize, int _ysize, int _channels)
	: xsize(_xsize)
	, ysize(_ysize)
	, channels(_channels)
	, compressed(false)
#ifndef BITMAP_NO_OPENGL
	, textype(GL_TEXTURE_2D)
	, ddsimage(NULL)
#endif
{
    //stub method
}


CBitmap& CBitmap::operator=(const CBitmap& bm)
{
    //stub method
}


CBitmap& CBitmap::operator=(CBitmap&& bm)
{
    //stub method
}


void CBitmap::Alloc(int w, int h, int c)
{
    //stub method
}

void CBitmap::Alloc(int w, int h)
{
    //stub method
}

void CBitmap::AllocDummy(const SColor fill)
{
    //stub method
}

bool CBitmap::Load(std::string const& filename, unsigned char defaultAlpha)
{
    //stub method
}


bool CBitmap::LoadGrayscale(const std::string& filename)
{
    //stub method
}


bool CBitmap::Save(std::string const& filename, bool opaque) const
{
    //stub method
}


bool CBitmap::SaveFloat(std::string const& filename) const
{
    //stub method
}


#ifndef BITMAP_NO_OPENGL
unsigned int CBitmap::CreateTexture(float aniso, bool mipmaps) const
{
    //stub method
}


static void HandleDDSMipmap(GLenum target, bool mipmaps, int num_mipmaps)
{
    //stub method
}

unsigned int CBitmap::CreateDDSTexture(unsigned int texID, float aniso, bool mipmaps) const
{
    //stub method
}
#else  // !BITMAP_NO_OPENGL

unsigned int CBitmap::CreateTexture(float aniso, bool mipmaps) const {
	return 0;
}

unsigned int CBitmap::CreateDDSTexture(unsigned int texID, float aniso, bool mipmaps) const {
	return 0;
}
#endif // !BITMAP_NO_OPENGL


void CBitmap::CreateAlpha(unsigned char red, unsigned char green, unsigned char blue)
{
    //stub method
}


void CBitmap::SetTransparent(const SColor& c, const SColor trans)
{
    //stub method
}


void CBitmap::Renormalize(float3 newCol)
{
    //stub method
}


inline static void kernelBlur(CBitmap* dst, const unsigned char* src, int x, int y, int channel, float weight)
{
    //stub method
}


void CBitmap::Blur(int iterations, float weight)
{
    //stub method
}


void CBitmap::CopySubImage(const CBitmap& src, int xpos, int ypos)
{
    //stub method
}


CBitmap CBitmap::CanvasResize(const int newx, const int newy, const bool center) const
{
    //stub method
}


SDL_Surface* CBitmap::CreateSDLSurface() const
{
    //stub method
}


CBitmap CBitmap::CreateRescaled(int newx, int newy) const
{
    //stub method
}


void CBitmap::InvertColors()
{
    //stub method
}


void CBitmap::InvertAlpha()
{
    //stub method
}


void CBitmap::GrayScale()
{
    //stub method
}

static ILubyte TintByte(ILubyte value, float tint)
{
    //stub method
}


void CBitmap::Tint(const float tint[3])
{
    //stub method
}


void CBitmap::ReverseYAxis()
{
    //stub method
}
