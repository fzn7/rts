/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DemoReader.h"

#ifndef TOOLS
#include "System/Config/ConfigHandler.h"
CONFIG(bool, DisableDemoVersionCheck).defaultValue(false).description("Allow to play every replay file (may crash / cause undefined behaviour in replays)");
#endif
#include "System/Exceptions.h"
#include "System/FileSystem/GZFileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Net/RawPacket.h"
#include "Game/GameVersion.h"

#include <limits.h>
#include <stdexcept>
#include <cassert>
#include <cstring>


CDemoReader::CDemoReader(const std::string& filename, float curTime)
	: playbackDemo(NULL)
{
    //stub method
}


CDemoReader::~CDemoReader()
{
    //stub method
}


netcode::RawPacket* CDemoReader::GetData(const float readTime)
{
    //stub method
}

bool CDemoReader::ReachedEnd()
{
    //stub method
}


void CDemoReader::LoadStats()
{
    //stub method
}
