#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Platform/CrashHandler.h"

#if defined(__APPLE__)
// ### Unix(compliant) CrashHandler START

#include <AvailabilityMacros.h>

//! Same as Linux
#include "System/Platform/Linux/CrashHandler.cpp"
#include <libproc.h>
#include <limits.h>

#define ADDR2LINE "atos"

/**
 * @brief TranslateStackTrace
 * @param stacktrace These are the lines and addresses produced by
 * backtrace_symbols() Translates the module and address information from
 * backtrace symbols into a vector of StackFrame objects, each with its own set
 * of entries representing the function call and any inlined functions for
 * that call.
 */
static void
TranslateStackTrace(bool* aiCrash, StackTrace& stacktrace, const int logLevel)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
LogStacktrace(const int logLevel, StackTrace& stacktrace)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// ### Unix(compliant) CrashHandler END
#else
// ### Fallback CrashHandler (old Apple) START

namespace CrashHandler {
void
Install()
{}
void
Remove()
{}

void
Stacktrace(Threading::NativeThreadHandle thread, const std::string& threadName)
{}
void
PrepareStacktrace()
{}
void
CleanupStacktrace()
{}

void
OutputStacktrace()
{}
};

// ### Fallback CrashHandler (old Apple) END
#endif
