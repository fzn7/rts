/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Watchdog.h"

#ifdef USE_VALGRIND
	#include <valgrind/valgrind.h>
#endif

#include <algorithm>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/thread/recursive_mutex.hpp>

#include "Game/GameVersion.h"
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/maindefines.h"
#include "System/Misc/SpringTime.h"
#include "System/Platform/CrashHandler.h"
#include "System/Platform/Misc.h"
#include "System/Platform/Threading.h"

CONFIG(int, HangTimeout).defaultValue(10).minimumValue(-1).maximumValue(600)
		.description("Number of seconds that, if spent in the same code segment, indicate a hang; -1 to disable.");

namespace Watchdog
{
    //stub method
}
