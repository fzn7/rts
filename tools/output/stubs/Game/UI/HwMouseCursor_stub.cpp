#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Platform/Win/win32.h"
#if !defined(HEADLESS)
	#include "Rendering/Textures/Bitmap.h"
#endif
#include "Rendering/GlobalRendering.h"

#if defined(__APPLE__) || defined(HEADLESS)
	// no hardware cursor support for mac's and headless build
	// FIXME: duno how to create cursors at runtime on macs
#elif defined(WIN32)
	#include <windows.h>
	#include "System/Input/MouseInput.h"
	typedef unsigned char byte;
#else
	#include <X11/Xcursor/Xcursor.h>
#endif

#include "HwMouseCursor.h"

#if !defined(__APPLE__) && !defined(HEADLESS)

#include "System/bitops.h"
#include "MouseCursor.h"
#include "CommandColors.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include <cstring> // for memset

#include <SDL_config.h>
#include <SDL_syswm.h>
#include <SDL_mouse.h>
#include <SDL_events.h>
#endif



//int savedcount=0;

//////////////////////////////////////////////////////////////////////
// Platform dependent classes
//////////////////////////////////////////////////////////////////////

#if defined(__APPLE__) || defined(HEADLESS)
// no hardware cursor support for mac's and headless build
class CHwDummyCursor : public IHwCursor {
	public:
		void PushImage(int xsize, int ysize, void* mem){};
		void SetDelay(float delay){};
		void PushFrame(int index, float delay){};
		void Finish(){};

		bool NeedsYFlip() {return false;};

		bool IsValid(){return false;};
		void Bind(){};
};
#elif defined(WIN32)
class CHwWinCursor : public IHwCursor {
	public:
		CHwWinCursor();
		~CHwWinCursor();

		void PushImage(int xsize, int ysize, void* mem);
		void SetDelay(float delay);
		void PushFrame(int index, float delay);
		void Finish();

		bool NeedsYFlip() {return true;};

		void Bind();

		bool IsValid() {return (cursor!=NULL);};
	protected:
		HCURSOR cursor;
#ifndef _MSC_VER
	#pragma push(pack,1)
#endif
		struct CursorDirectoryHeader {
			byte  xsize,ysize,ncolors,reserved1;
			short hotx,hoty;
			DWORD size,offset;
		};

		struct CursorInfoHeader {
			DWORD size,width,height;
			WORD  planes, bpp;
			DWORD res1,res2,res3,res4,res5,res6;
		};

		struct AnihStructure {
			DWORD size,images,frames,width,height,bpp,planes,rate,flags;
		};
#ifndef _MSC_VER
	#pragma pop(pack)
#endif

	protected:
		struct ImageData {
			unsigned char* data;
			int width,height;
		};

		void buildIco(unsigned char* dst, ImageData &image);
		void resizeImage(ImageData *image, int new_x, int new_y);

		int xmaxsize, ymaxsize;
		short hotx, hoty;

		byte image_count;

		std::vector<ImageData> icons;
		std::vector<byte>  frames;
		std::vector<int>   framerates;
};
#else
class CHwX11Cursor : public IHwCursor {
	public:
		CHwX11Cursor();
		~CHwX11Cursor();

		void PushImage(int xsize, int ysize, void* mem);
		void SetDelay(float delay);
		void PushFrame(int index, float delay);
		void Finish();

		bool NeedsYFlip() {return false;};

		bool IsValid() {return (cursor!=0);};
		void Bind();
	protected:
		int xmaxsize, ymaxsize;

		void resizeImage(XcursorImage*& image, const int new_x, const int new_y);

		Cursor cursor;
		std::vector<XcursorImage*> cimages;
};
#endif

//////////////////////////////////////////////////////////////////////
// GetHwCursor()
//////////////////////////////////////////////////////////////////////

IHwCursor* GetNewHwCursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


//////////////////////////////////////////////////////////////////////
// Implementation
//////////////////////////////////////////////////////////////////////


#if defined(__APPLE__) || defined(HEADLESS)
	// no hardware cursor support for mac's and headless build
#elif defined(WIN32)

void CHwWinCursor::PushImage(int xsize, int ysize, void* mem)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwWinCursor::SetDelay(float delay)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwWinCursor::PushFrame(int index, float delay)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwWinCursor::resizeImage(ImageData *image, int new_x, int new_y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwWinCursor::buildIco(unsigned char* dst, ImageData &image)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static inline int GetBestCursorSize(const int minSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CHwWinCursor::Finish()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwWinCursor::Bind()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CHwWinCursor::CHwWinCursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CHwWinCursor::~CHwWinCursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#else

void CHwX11Cursor::resizeImage(XcursorImage*& image, const int new_x, const int new_y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwX11Cursor::PushImage(int xsize, int ysize, void* mem)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwX11Cursor::SetDelay(float delay)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwX11Cursor::PushFrame(int index, float delay)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwX11Cursor::Finish()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHwX11Cursor::Bind()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CHwX11Cursor::CHwX11Cursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CHwX11Cursor::~CHwX11Cursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif
