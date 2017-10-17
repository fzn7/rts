#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaScriptNames.h"
#include "Sim/Misc/GlobalConstants.h"

using std::map;
using std::pair;
using std::string;
using std::vector;

// script function-indices never change, so this is fine wrt. reloading
static vector<string> scriptNames;
static map<string, int> scriptMap;

const vector<string>&
CLuaUnitScriptNames::GetScriptNames()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::map<std::string, int>&
CLuaUnitScriptNames::GetScriptMap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CLuaUnitScriptNames::GetScriptNumber(const std::string& fname)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const string&
CLuaUnitScriptNames::GetScriptName(int num)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
