#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ModInfo.h"

#include "Lua/LuaParser.h"
#include "Lua/LuaSyncedRead.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"

CModInfo modInfo;

void
CModInfo::ResetState()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModInfo::Init(const char* modArchive)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
