#include <iostream>
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
    std::cout << _FUNCTION_ << std::endl;
}


MapParser::MapParser(const std::string& mapFileName) : parser(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


MapParser::~MapParser()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool MapParser::GetStartPos(int team, float3& pos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


LuaTable MapParser::GetRoot()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool MapParser::IsValid() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string MapParser::GetErrorLog() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
