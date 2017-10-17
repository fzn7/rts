#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/OffscreenGLContext.h"
#include "lib/streflop/streflop_cond.h" //! must happen before OffscreenGLContext.h, which includes agl.h

#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"
#include "System/Platform/errorhandler.h"
#include "System/maindefines.h"
#include <boost/thread.hpp>

static PFNGLACTIVETEXTUREPROC mainGlActiveTexture = NULL;

#ifdef HEADLESS
/////////////////////////////////////////////////////////////////////////////////////////////////
//! Headless

COffscreenGLContext::COffscreenGLContext() {}
COffscreenGLContext::~COffscreenGLContext() {}
void
COffscreenGLContext::WorkerThreadPost()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

COffscreenGLContext::~COffscreenGLContext()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COffscreenGLContext::WorkerThreadPost()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COffscreenGLContext::WorkerThreadFree()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#elif __APPLE__
/////////////////////////////////////////////////////////////////////////////////////////////////
//! APPLE

#include <OpenGL/CGLCurrent.h>
#include <OpenGL/OpenGL.h>

COffscreenGLContext::COffscreenGLContext()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

COffscreenGLContext::~COffscreenGLContext()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COffscreenGLContext::WorkerThreadPost()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COffscreenGLContext::WorkerThreadFree()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#else
/////////////////////////////////////////////////////////////////////////////////////////////////
//! UNIX

#include <SDL.h>
#include <SDL_syswm.h>

COffscreenGLContext::COffscreenGLContext()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

COffscreenGLContext::~COffscreenGLContext()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COffscreenGLContext::WorkerThreadPost()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COffscreenGLContext::WorkerThreadFree()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#endif

/******************************************************************************/
/******************************************************************************/

COffscreenGLThread::COffscreenGLThread(boost::function<void()> f)
  : thread(NULL)
  , glOffscreenCtx() //! may trigger an opengl_error exception!
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

COffscreenGLThread::~COffscreenGLThread()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
COffscreenGLThread::IsFinished(boost::posix_time::time_duration wait)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
COffscreenGLThread::Join()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

__FORCE_ALIGN_STACK__
void
COffscreenGLThread::WrapFunc(boost::function<void()> f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
