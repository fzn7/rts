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
}


ILoadSaveHandler::~ILoadSaveHandler()
{
    //stub method
}


std::string ILoadSaveHandler::FindSaveFile(const std::string& file)
{
    //stub method
}
