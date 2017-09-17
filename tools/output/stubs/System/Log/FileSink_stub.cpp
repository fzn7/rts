#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FileSink.h"

#include "Backend.h"
#include "FramePrefixer.h"
#include "Level.h" // for LOG_LEVEL_*
#include "System/Log/ILog.h"
#include "System/Log/Level.h"
#include "System/maindefines.h"

#include <cassert>
#include <cstdio>
#include <list>
#include <map>
#include <string>

namespace {

struct LogFileDetails
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * This class allows us to stop logging cleanly, when the application exits,
 * and while the container is still valid (not deleted yet).
 */
struct LogRecord
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline bool
log_file_isActivelyLogging()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
log_file_writeToFile(FILE* outStream, const char* record, bool flush)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Writes to the individual log files, if they do want to log the section.
 */
void
log_file_writeToFiles(const char* section, int level, const char* record)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Flushes the buffers of the individual log files.
 */
void
log_file_flushFiles()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Writes the content of the buffer to all the currently registered log
 * files.
 */
void
log_file_writeBufferToFiles()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
log_file_writeToBuffer(const std::string& section,
                       int level,
                       const std::string& record)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}

#ifdef __cplusplus
extern "C" {
#endif

void
log_file_addLogFile(const char* filePath,
                    const char* sections,
                    int minLevel,
                    int flushLevel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
log_file_removeLogFile(const char* filePath)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
log_file_removeAllLogFiles()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @name logging_sink_file
 * ILog.h sink implementation.
 */
///@{

/// Records a log entry
static void
log_sink_record_file(const char* section, int level, const char* record)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// Cleans up all log streams, by flushing them.
static void
log_sink_cleanup_file()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///@}

namespace {
/// Auto-registers the sink defined in this file before main() is called
struct FileSinkRegistrator
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef __cplusplus
} // extern "C"
#endif
