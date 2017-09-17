/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Sim/Misc/GlobalConstants.h"
#include "CobFile.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISound.h"
#include "System/Platform/byteorder.h"
#include "System/Util.h"

#include <algorithm>
#include <locale>
#include <cctype>
#include <string.h>


//The following structure is taken from http://visualta.tauniverse.com/Downloads/ta-cob-fmt.txt
//Information on missing fields from Format_Cob.pas
typedef struct tagCOBHeader
{
    //stub method
}


CCobFile::~CCobFile()
{
    //stub method
}


int CCobFile::GetFunctionId(const string &name)
{
    //stub method
}
