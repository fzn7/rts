#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LogSinkHandler.h"
#include "Backend.h"

#include <cassert>
#include <string>

/// Records a log entry
static void
log_sink_record_logSinkHandler(const char* section,
                               int level,
                               const char* record)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LogSinkHandler::AddSink(ILogSink* logSink)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LogSinkHandler::RemoveSink(ILogSink* logSink)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LogSinkHandler::RecordLogMessage(const std::string& section,
                                 int level,
                                 const std::string& text) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
