#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <sstream>
#include <string>

#include "LuaLoadSaveHandler.h"

#include "minizip/zip.h"

#include "ExternalAI/EngineOutHandler.h"
#include "Game/GameSetup.h"
#include "Lua/LuaZip.h"
#include "Map/MapDamage.h"
#include "Map/ReadMap.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveLoader.h"
#include "System/FileSystem/Archives/IArchive.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Platform/byteorder.h"

// Prefix for all files in the save file.
// May be used to prevent clashes with other code. (AI, Lua)
#define PREFIX "Spring/"

// Names of files in save file for various components of engine.
// They all have a version number as suffix. When breaking compatibility
// in the respective file format, please increment its version number.
static const char* FILE_STARTSCRIPT = PREFIX "startscript.0";
static const char* FILE_AIDATA = PREFIX "aidata.0";
static const char* FILE_HEIGHTMAP = PREFIX "heightmap.0";

#undef PREFIX

CLuaLoadSaveHandler::CLuaLoadSaveHandler()
  : savefile(NULL)
  , loadfile(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::SaveGame(const std::string& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::SaveEventClients()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::SaveGameStartInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::SaveAIData()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::SaveHeightmap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::SaveEntireFile(const char* file,
                                    const char* what,
                                    const void* data,
                                    int size,
                                    bool throwOnError)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::LoadGameStartInfo(const std::string& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::LoadGame()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::LoadEventClients()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::LoadAIData()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaLoadSaveHandler::LoadHeightmap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CLuaLoadSaveHandler::LoadEntireFile(const std::string& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
