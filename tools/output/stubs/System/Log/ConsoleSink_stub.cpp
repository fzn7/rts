#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * This is a simple sink for the ILog.h logging API.
 * It routes all logging messages to the console (stdout & stderr).
 */

#include "Backend.h"
#include "FramePrefixer.h"
#include "Level.h" // for LOG_LEVEL_*
#include "System/maindefines.h"

#include <cstdio>


#ifdef __cplusplus
extern "C" {
#endif

static bool colorizedOutput = false;



/**
 * @name logging_sink_console
 * ILog.h sink implementation.
 */
///@{


void log_console_colorizedOutput(bool enable) {
	colorizedOutput = enable;
}


/// Records a log entry
static void log_sink_record_console(const char* section, int level,
		const char* record)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///@}


namespace {
	/// Auto-registers the sink defined in this file before main() is called
	struct ConsoleSinkRegistrator {
		ConsoleSinkRegistrator() {
			log_backend_registerSink(&log_sink_record_console);
		}
		~ConsoleSinkRegistrator() {
			log_backend_unregisterSink(&log_sink_record_console);
		}
	} consoleSinkRegistrator;
}

#ifdef __cplusplus
} // extern "C"
#endif

