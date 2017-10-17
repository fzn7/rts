#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * This is the default formatter for the ILog.h logging API.
 * It formats the message and eventually adds a prefix.
 * The prefix will usually consist of the level, section and possibly a
 * timestamp.
 */

#include "Level.h"
#include "LogUtil.h"
#include "Section.h"
#include "System/SafeCStrings.h"
#include "System/maindefines.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
#define va_copy(dst, src) ((dst) = (src))
#endif

static const int SECTION_SIZE_MIN = 10;
static const int SECTION_SIZE_MAX = 20;

// *******************************************************************************************
// Helpers
static inline void
ResizeBuffer(char** buffer, size_t* bufferSize, const bool copy = false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
PrintfAppend(char** buffer,
             size_t* bufferSize,
             const char* fmt,
             va_list arguments)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// *******************************************************************************************

/*
static void log_formatter_createPrefix_xorgStyle(
        char** buffer,
        size_t* bufferSize,
        const char* section,
        int level
) {
        const char* prepSection = log_util_prepareSection(section);
        const char levelChar = log_util_levelToChar(level);

        SNPRINTF(*buffer, *bufferSize, "(%c%c) %*.*s - ", levelChar, levelChar,
                        SECTION_SIZE_MIN, SECTION_SIZE_MAX, prepSection);
}
*/

/*
static void log_formatter_createPrefix_testing(
        char** buffer,
        size_t* bufferSize,
        const char* section,
        int level
) {
        const char* prepSection = log_util_prepareSection(section);
        const char* levelStr = log_util_levelToString(level);

        SNPRINTF(*buffer, *bufferSize, "%s %s: ", levelStr, prepSection);
}
*/

static void
log_formatter_createPrefix_default(char** buffer,
                                   size_t* bufferSize,
                                   const char* section,
                                   int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
log_formatter_createPrefix(char** buffer,
                           size_t* bufferSize,
                           const char* section,
                           int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// *******************************************************************************************

/**
 * @name logging_formatter
 * ILog.h formatter implementation.
 */
///@{

/**
 * Formats a log entry into its final string form.
 * @return a string buffer, allocated with new[] -> you have to delete[] it
 */
char*
log_formatter_format(const char* section,
                     int level,
                     const char* fmt,
                     va_list arguments)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    ///@}

#ifdef __cplusplus
} // extern "C"
#endif
