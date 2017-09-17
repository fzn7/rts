/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "VerticalSync.h"
#include "GL/myGL.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"

#if defined HEADLESS
#elif defined WIN32
	#include <GL/wglew.h>
#elif !defined(__APPLE__)
	#include <GL/glxew.h>
#endif

CONFIG(int, VSync).defaultValue(0).minimumValue(0).description("Vertical synchronization, update render frames in monitor's refresh rate.\n <=0: off\n 1: enabled \n x: render with monitor-Hz/x FPS");

CVerticalSync VSync;


/******************************************************************************/

CVerticalSync::CVerticalSync()
{
    //stub method
}


CVerticalSync::~CVerticalSync()
{
    //stub method
}


/******************************************************************************/

void CVerticalSync::Init()
{
    //stub method
}


void CVerticalSync::SetInterval(int i)
{
    //stub method
}


/******************************************************************************/

void CVerticalSync::Delay() const
{
    //stub method
}


/******************************************************************************/
