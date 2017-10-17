#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#if defined AVI_CAPTURING
#include "AviVideoCapturing.h"

#include "Rendering/AVIGenerator.h"

#include "Rendering/GlobalRendering.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "lib/streflop/streflop_cond.h"
#include <SDL_events.h>
#include <SDL_mouse.h>

#include <string>

AviVideoCapturing::AviVideoCapturing()
  : capturing(false)
  , aviGenerator(NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
AviVideoCapturing::IsCapturing() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AviVideoCapturing::StopCapturing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AviVideoCapturing::StartCapturing()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
AviVideoCapturing::RenderFrame()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#endif // defined AVI_CAPTURING
