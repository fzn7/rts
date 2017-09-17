#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Screenshot.h"

#include <vector>
#include <iomanip>
#include <boost/thread.hpp>

#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Platform/Threading.h"

#undef CreateDirectory

CONFIG(int, ScreenshotCounter).defaultValue(0);

struct FunctionArgs
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
