#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DemoReader.h"

#ifndef TOOLS
#include "System/Config/ConfigHandler.h"
CONFIG(bool, DisableDemoVersionCheck)
  .defaultValue(false)
  .description("Allow to play every replay file (may crash / cause undefined "
               "behaviour in replays)");
#endif
#include "Game/GameVersion.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/GZFileHandler.h"
#include "System/Log/ILog.h"
#include "System/Net/RawPacket.h"

#include <cassert>
#include <cstring>
#include <limits.h>
#include <stdexcept>

CDemoReader::CDemoReader(const std::string& filename, float curTime)
  : playbackDemo(NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CDemoReader::~CDemoReader()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

netcode::RawPacket*
CDemoReader::GetData(const float readTime)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CDemoReader::ReachedEnd()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CDemoReader::LoadStats()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
