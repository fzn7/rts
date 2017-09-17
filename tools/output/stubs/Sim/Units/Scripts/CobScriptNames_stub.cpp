/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CobScriptNames.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Util.h"

using std::map;
using std::pair;
using std::string;
using std::vector;

// script function-indices never change, so this is fine wrt. reloading
static vector<string> scriptNames;
static map<string, int> scriptMap;


const vector<string>& CCobUnitScriptNames::GetScriptNames()
{
    //stub method
}


const std::map<std::string, int>& CCobUnitScriptNames::GetScriptMap()
{
    //stub method
}


int CCobUnitScriptNames::GetScriptNumber(const std::string& fname)
{
    //stub method
}

const string& CCobUnitScriptNames::GetScriptName(int num)
{
    //stub method
}
