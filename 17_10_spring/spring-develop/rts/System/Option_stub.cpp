#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef _OPTION_CPP
#define _OPTION_CPP

#include "System/Option.h"

#include "Lua/LuaParser.h"
#include "Map/MapParser.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <assert.h>

static const char* Option_badKeyChars = " =;\r\n\t";

std::string
option_getDefString(const Option& option)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
option_parseOption(const LuaTable& root,
                   int index,
                   Option& opt,
                   std::set<string>& optionsSet)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
option_parseOptionsInternal(std::vector<Option>& options,
                            LuaParser& luaParser,
                            const std::string& luaSourceDesc,
                            std::set<std::string>* optionsSet)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
option_parseOptions(std::vector<Option>& options,
                    const std::string& fileName,
                    const std::string& fileModes,
                    const std::string& accessModes,
                    std::set<std::string>* optionsSet)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
option_parseOptionsLuaString(std::vector<Option>& options,
                             const std::string& optionsLuaString,
                             const std::string& accessModes,
                             std::set<std::string>* optionsSet)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
option_parseMapOptions(std::vector<Option>& options,
                       const std::string& fileName,
                       const std::string& mapName,
                       const std::string& fileModes,
                       const std::string& accessModes,
                       std::set<std::string>* optionsSet)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#endif // _OPTION_CPP
