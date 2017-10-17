#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Watchdog.h"

#ifdef USE_VALGRIND
#include <valgrind/valgrind.h>
#endif

#include <algorithm>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/thread/recursive_mutex.hpp>

#include "Game/GameVersion.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/Misc/SpringTime.h"
#include "System/Platform/CrashHandler.h"
#include "System/Platform/Misc.h"
#include "System/Platform/Threading.h"
#include "System/maindefines.h"

CONFIG(int, HangTimeout)
  .defaultValue(10)
  .minimumValue(-1)
  .maximumValue(600)
  .description("Number of seconds that, if spent in the same code segment, "
               "indicate a hang; -1 to disable.");

namespace Watchdog {
const char* threadNames[] = { "main", "sim", "load", "audio", "self" };

static boost::mutex wdmutex;

static unsigned int curorder = 0;

struct WatchDogThreadInfo
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

__FORCE_ALIGN_STACK__
static void
HangDetectorLoop()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
RegisterThread(WatchdogThreadnum num, bool primary)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DeregisterThread(WatchdogThreadnum num)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ClearTimer(bool disable, Threading::NativeThreadId* _threadId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ClearTimer(WatchdogThreadnum num, bool disable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ClearTimer(const std::string& name, bool disable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ClearPrimaryTimers(bool disable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Install()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Uninstall()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
