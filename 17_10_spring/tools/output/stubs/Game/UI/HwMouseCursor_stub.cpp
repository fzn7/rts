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

#include "CommandColors.h"
#include "MouseCursor.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"
#include "System/bitops.h"
#include "System/myMath.h"
#include <cstring> // for memset

#include <SDL_config.h>
#include <SDL_events.h>
#include <SDL_mouse.h>
#include <SDL_syswm.h>
#endif

// int savedcount=0;

//////////////////////////////////////////////////////////////////////
// Platform dependent classes
//////////////////////////////////////////////////////////////////////

#if defined(__APPLE__) || defined(HEADLESS)
// no hardware cursor support for mac's and headless build
class CHwDummyCursor : public IHwCursor
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

void
CHwWinCursor::PushImage(int xsize, int ysize, void* mem)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwWinCursor::SetDelay(float delay)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwWinCursor::PushFrame(int index, float delay)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwWinCursor::resizeImage(ImageData* image, int new_x, int new_y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwWinCursor::buildIco(unsigned char* dst, ImageData& image)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline int
GetBestCursorSize(const int minSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwWinCursor::Finish()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwWinCursor::Bind()
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

void
CHwX11Cursor::resizeImage(XcursorImage*& image,
                          const int new_x,
                          const int new_y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwX11Cursor::PushImage(int xsize, int ysize, void* mem)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwX11Cursor::SetDelay(float delay)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwX11Cursor::PushFrame(int index, float delay)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwX11Cursor::Finish()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CHwX11Cursor::Bind()
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
