#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string>

#include "CregLoadSaveHandler.h"
#include "LoadSaveHandler.h"
#include "LuaLoadSaveHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileSystem.h"

ILoadSaveHandler*
ILoadSaveHandler::Create(bool usecreg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

ILoadSaveHandler::~ILoadSaveHandler() {}

std::string
ILoadSaveHandler::FindSaveFile(const std::string& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
