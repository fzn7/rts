#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CommandColors.h"

#include "Rendering/GL/myGL.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Util.h"

#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

/******************************************************************************/

CCommandColors cmdColors;

CCommandColors::CCommandColors()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCommandColors::~CCommandColors() {}

static bool
ParseBlendMode(const string& word, unsigned int& mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
IsValidSrcMode(unsigned int mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
IsValidDstMode(unsigned int mode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
SafeAtoF(float& var, const string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
SafeAtoI(unsigned int& var, const string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCommandColors::LoadConfigFromFile(const string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCommandColors::LoadConfigFromString(const string& cfg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCommandColors::SetCustomCmdData(int cmdID,
                                 int cmdIconID,
                                 const float color[4],
                                 bool showArea)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCommandColors::ClearCustomCmdData(int cmdID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CCommandColors::DrawData*
CCommandColors::GetCustomCmdData(int cmdID) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
