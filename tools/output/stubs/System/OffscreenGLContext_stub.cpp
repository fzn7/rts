/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "lib/streflop/streflop_cond.h" //! must happen before OffscreenGLContext.h, which includes agl.h
#include "System/OffscreenGLContext.h"

#include "System/Exceptions.h"
#include "System/maindefines.h"
#include "System/Log/ILog.h"
#include "System/Platform/errorhandler.h"
#include "System/Platform/Threading.h"
#include <boost/thread.hpp>


static PFNGLACTIVETEXTUREPROC mainGlActiveTexture = NULL;


#ifdef HEADLESS
/////////////////////////////////////////////////////////////////////////////////////////////////
//! Headless

COffscreenGLContext::COffscreenGLContext() {}
COffscreenGLContext::~COffscreenGLContext() {}
void COffscreenGLContext::WorkerThreadPost() {}
void COffscreenGLContext::WorkerThreadFree() {}


#elif WIN32
/////////////////////////////////////////////////////////////////////////////////////////////////
//! WINDOWS

#include <GL/wglew.h>

COffscreenGLContext::COffscreenGLContext()
{
    //stub method
}


COffscreenGLContext::~COffscreenGLContext() {
	wglDeleteContext(offscreenRC);
}

void COffscreenGLContext::WorkerThreadPost()
{
    //stub method
}


void COffscreenGLContext::WorkerThreadFree()
{
    //stub method
}


#elif __APPLE__
/////////////////////////////////////////////////////////////////////////////////////////////////
//! APPLE

#include <OpenGL/CGLCurrent.h>
#include <OpenGL/OpenGL.h>

COffscreenGLContext::COffscreenGLContext()
{
    //stub method
}


COffscreenGLContext::~COffscreenGLContext() {
	CGLDestroyContext(cglWorkerCtx);
}


void COffscreenGLContext::WorkerThreadPost()
{
    //stub method
}


void COffscreenGLContext::WorkerThreadFree()
{
    //stub method
}

#else
/////////////////////////////////////////////////////////////////////////////////////////////////
//! UNIX

#include <SDL.h>
#include <SDL_syswm.h>

COffscreenGLContext::COffscreenGLContext()
{
    //stub method
}


COffscreenGLContext::~COffscreenGLContext() {
	glXDestroyContext(display, workerCtx);
	glXDestroyPbuffer(display, pbuf);
}


void COffscreenGLContext::WorkerThreadPost()
{
    //stub method
}


void COffscreenGLContext::WorkerThreadFree()
{
    //stub method
}

#endif


/******************************************************************************/
/******************************************************************************/

COffscreenGLThread::COffscreenGLThread(boost::function<void()> f) :
	thread(NULL),
	glOffscreenCtx() //! may trigger an opengl_error exception!
{
    //stub method
}


COffscreenGLThread::~COffscreenGLThread()
{
    //stub method
}


bool COffscreenGLThread::IsFinished(boost::posix_time::time_duration wait)
{
    //stub method
}


void COffscreenGLThread::Join()
{
    //stub method
}


__FORCE_ALIGN_STACK__
void COffscreenGLThread::WrapFunc(boost::function<void()> f)
{
    //stub method
}


/******************************************************************************/
