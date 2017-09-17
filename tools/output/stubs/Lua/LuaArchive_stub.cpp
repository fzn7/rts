#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaArchive.h"

#include "LuaInclude.h"
#include "LuaHashString.h"
#include "LuaUtils.h"

#include "ExternalAI/LuaAIImplHandler.h"
#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/Interface/SSkirmishAILibrary.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Util.h"

#include <string>

// returns absolute filename for given archive name, empty if not found
static const std::string GetFileName(const std::string& name){
	if (name.empty())
		return name;
	const std::string& filename = archiveScanner->ArchiveFromName(name);
	if (filename == name)
		return "";
	const std::string& path = archiveScanner->GetArchivePath(filename);
	return path + filename;
}


/******************************************************************************/
/******************************************************************************/

bool LuaArchive::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/
/******************************************************************************/

int LuaArchive::GetMaps(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaArchive::GetGames(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaArchive::GetAllArchives(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int LuaArchive::HasArchive(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int LuaArchive::GetArchiveInfo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaArchive::GetArchiveDependencies(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaArchive::GetArchiveReplaces(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaArchive::GetArchiveChecksum(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int LuaArchive::GetAvailableAIs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
