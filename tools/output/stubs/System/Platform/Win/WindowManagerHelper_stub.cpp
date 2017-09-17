#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Platform/WindowManagerHelper.h"
#include "Rendering/GlobalRendering.h"
#include <SDL_syswm.h>
#include <windows.h>


namespace WindowManagerHelper {

void BlockCompositing(SDL_Window* window)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int GetWindowState(SDL_Window* window)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

}; // namespace WindowManagerHelper
