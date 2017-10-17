#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IInfoTextureHandler.h"
#include "Legacy/LegacyInfoTextureHandler.h"
#include "Modern/InfoTextureHandler.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GlobalRendering.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"

IInfoTextureHandler* infoTextureHandler = nullptr;

void
IInfoTextureHandler::Create()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
