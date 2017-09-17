/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string>
#include <sstream>

#include "LuaLoadSaveHandler.h"

#include "minizip/zip.h"

#include "ExternalAI/EngineOutHandler.h"
#include "Game/GameSetup.h"
#include "Lua/LuaZip.h"
#include "Map/MapDamage.h"
#include "Map/ReadMap.h"
#include "System/FileSystem/Archives/IArchive.h"
#include "System/FileSystem/ArchiveLoader.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/Platform/byteorder.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"



// Prefix for all files in the save file.
// May be used to prevent clashes with other code. (AI, Lua)
#define PREFIX "Spring/"

// Names of files in save file for various components of engine.
// They all have a version number as suffix. When breaking compatibility
// in the respective file format, please increment its version number.
static const char* FILE_STARTSCRIPT  = PREFIX"startscript.0";
static const char* FILE_AIDATA       = PREFIX"aidata.0";
static const char* FILE_HEIGHTMAP    = PREFIX"heightmap.0";

#undef PREFIX


CLuaLoadSaveHandler::CLuaLoadSaveHandler()
	: savefile(NULL)
	, loadfile(NULL)
{
    //stub method
}


CLuaLoadSaveHandler::~CLuaLoadSaveHandler()
{
    //stub method
}


void CLuaLoadSaveHandler::SaveGame(const std::string& file)
{
    //stub method
}


void CLuaLoadSaveHandler::SaveEventClients()
{
    //stub method
}


void CLuaLoadSaveHandler::SaveGameStartInfo()
{
    //stub method
}


void CLuaLoadSaveHandler::SaveAIData()
{
    //stub method
}


void CLuaLoadSaveHandler::SaveHeightmap()
{
    //stub method
}


void CLuaLoadSaveHandler::SaveEntireFile(const char* file, const char* what, const void* data, int size, bool throwOnError)
{
    //stub method
}


void CLuaLoadSaveHandler::LoadGameStartInfo(const std::string& file)
{
    //stub method
}


void CLuaLoadSaveHandler::LoadGame()
{
    //stub method
}


void CLuaLoadSaveHandler::LoadEventClients()
{
    //stub method
}


void CLuaLoadSaveHandler::LoadAIData()
{
    //stub method
}


void CLuaLoadSaveHandler::LoadHeightmap()
{
    //stub method
}


std::string CLuaLoadSaveHandler::LoadEntireFile(const std::string& file)
{
    //stub method
}
