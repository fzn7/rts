/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CommandColors.h"


#include "Rendering/GL/myGL.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Util.h"

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

/******************************************************************************/


CCommandColors cmdColors;


CCommandColors::CCommandColors()
{
    //stub method
}


CCommandColors::~CCommandColors()
{
    //stub method
}


static bool ParseBlendMode(const string& word, unsigned int& mode)
{
    //stub method
}


static bool IsValidSrcMode(unsigned int mode)
{
    //stub method
}



static bool IsValidDstMode(unsigned int mode)
{
    //stub method
}


static bool SafeAtoF(float& var, const string& value)
{
    //stub method
}


static bool SafeAtoI(unsigned int& var, const string& value)
{
    //stub method
}


bool CCommandColors::LoadConfigFromFile(const string& filename)
{
    //stub method
}


bool CCommandColors::LoadConfigFromString(const string& cfg)
{
    //stub method
}


void CCommandColors::SetCustomCmdData(int cmdID, int cmdIconID,
                                      const float color[4], bool showArea)
{
    //stub method
}


void CCommandColors::ClearCustomCmdData(int cmdID)
{
    //stub method
}


const CCommandColors::DrawData*
	CCommandColors::GetCustomCmdData(int cmdID) const
{
    //stub method
}


/******************************************************************************/
