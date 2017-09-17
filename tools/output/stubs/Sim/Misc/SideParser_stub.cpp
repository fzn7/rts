#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <string>
#include <set>


#include "SideParser.h"
#include "Lua/LuaParser.h"
#include "Lua/LuaSyncedRead.h"
#include "System/Log/ILog.h"
#include "System/Util.h"



SideParser sideParser;

const std::string SideParser::emptyStr = "";


/******************************************************************************/

bool SideParser::Load()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

 
/******************************************************************************/

const SideParser::Data* SideParser::FindSide(const std::string& sideName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::string& SideParser::GetSideName(unsigned int index,
		const std::string& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::string& SideParser::GetCaseName(unsigned int index,
		const std::string& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::string& SideParser::GetCaseName(const std::string& name,
		const std::string& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::string& SideParser::GetStartUnit(unsigned int index,
		const std::string& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::string& SideParser::GetStartUnit(const std::string& name,
		const std::string& def) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
