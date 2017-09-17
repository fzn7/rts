/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#ifdef SYNCDEBUG

#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include <sstream>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "Logger.h"
#include "System/Util.h"
#include "System/SafeCStrings.h"

#ifdef _MSC_VER
#include <Windows.h>
#include <imagehlp.h>
#include "System/Platform/CrashHandler.h"
#endif

#ifdef WIN32
// msvcrt doesn't have thread safe ctime_r
# define ctime_r(tm, buf) ctime(tm)
#endif


extern "C" void get_executable_name(char *output, int size);


/**
 * @brief name of the addr2line binary
 */
#define ADDR2LINE "addr2line"


/**
 * @brief name of the c++filt binary
 *
 * Only used on MinGW to work around an addr2line bug.
 */
#define CPPFILT "c++filt"


/**
 * @brief log function
 *
 * Write a printf-style formatted message to the temporary logfile buffer.
 * (which is later to be filtered through addr2line)
 *
 * The filtering is done by taking everything between { and } as being a
 * hexadecimal address into the executable. This address is literally passed
 * to addr2line, which converts it to a function, filename & line number.
 * The "{...}" string is then fully replaced by "function [filename:lineno]".
 */
void CLogger::AddLine(const char* fmt, ...)
{
    //stub method
}


/**
 * @brief close one logging session
 *
 * Writes the buffered data to file after filtering it through addr2line.
 */
void CLogger::CloseSession()
{
    //stub method
}


/**
 * @brief flushes the buffer
 *
 * This is the actual worker function. It opens the log file if it wasn't yet
 * open, composes the addr2line commandline, pipes the buffer through it and
 * writes the output of that - after some formatting - to the real logfile.
 */
void CLogger::FlushBuffer()
{
    //stub method
}


/**
 * @brief demangles sym
 *
 * On MinGW, checks if sym needs demangling by some very simple heuristic and
 * filters it through c++filt if it needs to be demangled.
 *
 * It's a workaround for MinGW GNU addr2line 2.15.91, which somehow strips
 * underscores from the symbol before trying to demangle them, resulting
 * no demangling ever happening.
 */
void CLogger::CppFilt(char* sym, int size)
{
    //stub method
}

#endif // SYNCDEBUG
