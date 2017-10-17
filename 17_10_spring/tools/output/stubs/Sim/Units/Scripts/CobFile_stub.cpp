#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CobFile.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/byteorder.h"
#include "System/Sound/ISound.h"
#include "System/Util.h"

#include <algorithm>
#include <cctype>
#include <locale>
#include <string.h>

// The following structure is taken from
// http://visualta.tauniverse.com/Downloads/ta-cob-fmt.txt  Information on missing
// fields from Format_Cob.pas
typedef struct tagCOBHeader
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCobFile::~CCobFile()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CCobFile::GetFunctionId(const string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
