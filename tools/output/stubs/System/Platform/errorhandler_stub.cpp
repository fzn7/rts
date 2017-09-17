/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * @brief error messages
 * Error handling based on platform.
 */


#include "errorhandler.h"

#include <string>
#include <sstream>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include "Game/GlobalUnsynced.h"
#include "System/Log/ILog.h"
#include "System/Log/LogSinkHandler.h"
#include "System/Util.h"

#if !defined(DEDICATED) || defined(_MSC_VER)
	#include "System/SpringApp.h"
	#include "System/Platform/Threading.h"
	#include "System/Platform/Watchdog.h"
#endif
#if !defined(DEDICATED) && !defined(HEADLESS)
	#include "System/Platform/MessageBox.h"
#endif
#ifdef DEDICATED
	#include "Net/GameServer.h"
#endif

static void ExitMessage(const std::string& msg, const std::string& caption, unsigned int flags, bool forced)
{
    //stub method
}


volatile bool shutdownSucceeded = false;

__FORCE_ALIGN_STACK__
void ForcedExit(const std::string& msg, const std::string& caption, unsigned int flags) {

	for (unsigned int n = 0; !shutdownSucceeded && (n < 10); ++n) {
		boost::this_thread::sleep(boost::posix_time::seconds(1));
	}

	if (!shutdownSucceeded) {
		ExitMessage(msg, caption, flags, true);
	}
}

void ErrorMessageBox(const std::string& msg, const std::string& caption, unsigned int flags, bool fromMain)
{
    //stub method
}

static int exitcode = 0;
void SetExitCode(int code) { exitcode = code; }
int GetExitCode() { return exitcode; }

