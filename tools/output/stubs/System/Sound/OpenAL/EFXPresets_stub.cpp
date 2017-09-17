/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "EFXPresets.h"
#include "System/Util.h"

std::map<std::string, EAXSfxProps> eaxPresets;

std::map<ALuint, unsigned> alParamType;
std::map<std::string, ALuint> nameToALParam;
std::map<ALuint, std::string> alParamToName;
std::map<std::string, ALuint> nameToALFilterParam;
std::map<ALuint, std::string> alFilterParamToName;

static void InitPresets()
{
    //stub method
}

static void InitConversionTables()
{
    //stub method
}

DO_ONCE(InitPresets)
DO_ONCE(InitConversionTables)
