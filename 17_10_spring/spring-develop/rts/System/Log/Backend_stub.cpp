#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Backend.h"

#include <cstdarg>
#include <cstdio>
#include <set>

namespace {
std::set<log_sink_ptr>&
log_formatter_getSinks()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::set<log_cleanup_ptr>&
log_formatter_getCleanupFuncs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}

#ifdef __cplusplus
extern "C" {
#endif

extern char*
log_formatter_format(const char* section,
                     int level,
                     const char* fmt,
                     va_list arguments);

void
log_backend_registerSink(log_sink_ptr sink)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
log_backend_unregisterSink(log_sink_ptr sink)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
log_backend_registerCleanup(log_cleanup_ptr cleanupFunc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
log_backend_unregisterCleanup(log_cleanup_ptr cleanupFunc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @name logging_backend
 * ILog.h backend implementation.
 */
///@{

/// Eventually formats and routes the record to all sinks
void
log_backend_record(const char* section,
                   int level,
                   const char* fmt,
                   va_list arguments)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/// Passes on a cleanup request to all sinks
void
log_backend_cleanup()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

    ///@}

#ifdef __cplusplus
} // extern "C"
#endif
