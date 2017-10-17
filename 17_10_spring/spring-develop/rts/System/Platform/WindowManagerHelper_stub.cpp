#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "WindowManagerHelper.h"

#include <SDL_video.h>
#include <string>

#include "Game/GameVersion.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Log/ILog.h"

namespace WindowManagerHelper {

static SDL_Surface* currentIcon = nullptr;

void
SetIcon(const CBitmap* icon)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FreeIcon()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SetCaption(const std::string& title)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

}; // namespace WindowManagerHelper
