#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Game/ClientSetup.h"
#include "Game/GameData.h"
#include "Game/GameSetup.h"
#include "Game/GameVersion.h"
#include "Net/GameServer.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/DataDirLocater.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystemInitializer.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/GlobalConfig.h"
#include "System/LoadSave/DemoRecorder.h"
#include "System/Log/ConsoleSink.h"
#include "System/Log/DefaultFilter.h"
#include "System/Log/ILog.h"
#include "System/LogOutput.h"
#include "System/Misc/SpringTime.h"
#include "System/Platform/CmdLineParams.h"
#include "System/Platform/CrashHandler.h"
#include "System/Platform/Threading.h"
#include "System/Platform/errorhandler.h"
#include "System/UnsyncedRNG.h"

#define LOG_SECTION_DEDICATED_SERVER "DedicatedServer"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_DEDICATED_SERVER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_DEDICATED_SERVER

#ifdef __cplusplus
extern "C" {
#endif

void
ParseCmdLine(CmdLineParams& cmdLine, std::string& scriptName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
main(int argc, char* argv[])
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if defined(WIN32) && !defined(_MSC_VER)
int WINAPI
WinMain(HINSTANCE hInstanceIn,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

#ifdef __cplusplus
} // extern "C"
#endif
