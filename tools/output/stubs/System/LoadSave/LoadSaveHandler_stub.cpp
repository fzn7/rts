#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string>

#include "LoadSaveHandler.h"
#include "CregLoadSaveHandler.h"
#include "LuaLoadSaveHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileSystem.h"


ILoadSaveHandler* ILoadSaveHandler::Create(bool usecreg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


ILoadSaveHandler::~ILoadSaveHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string ILoadSaveHandler::FindSaveFile(const std::string& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
