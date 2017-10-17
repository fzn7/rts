#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "StreamSink.h"
#include "Backend.h"

#include <cstring>
#include <ostream>
#include <string>

static std::ostream* logStreamInt = NULL;

void
log_sink_stream_setLogStream(std::ostream* logStream)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name logging_sink_stream
 * ILog.h sink implementation.
 */
///@{

/// Records a log entry
void
log_sink_record_stream(const char* section, int level, const char* record)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

///@}

namespace {
/// Auto-registers the sink defined in this file before main() is called
struct StreamSinkRegistrator
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

#ifdef __cplusplus
} // extern "C"
#endif
