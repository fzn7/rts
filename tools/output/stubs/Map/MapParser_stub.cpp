/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MapParser.h"

#include "Lua/LuaParser.h"
#include "Lua/LuaSyncedRead.h"
#include "System/float3.h"
#include "System/Exceptions.h"
#include "System/Util.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"

#include <string>
#include <ctype.h>


std::string MapParser::GetMapConfigName(const std::string& mapFileName)
{
    //stub method
}


MapParser::MapParser(const std::string& mapFileName) : parser(NULL)
{
    //stub method
}


MapParser::~MapParser()
{
    //stub method
}


bool MapParser::GetStartPos(int team, float3& pos) const
{
    //stub method
}


LuaTable MapParser::GetRoot()
{
    //stub method
}


bool MapParser::IsValid() const
{
    //stub method
}


std::string MapParser::GetErrorLog() const
{
    //stub method
}
