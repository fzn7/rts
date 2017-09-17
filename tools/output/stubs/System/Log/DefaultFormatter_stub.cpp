/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * This is the default formatter for the ILog.h logging API.
 * It formats the message and eventually adds a prefix.
 * The prefix will usually consist of the level, section and possibly a
 * timestamp.
 */

#include "LogUtil.h"
#include "Level.h"
#include "Section.h"
#include "System/maindefines.h"
#include "System/SafeCStrings.h"

#include <cstdio>
#include <cstdarg>
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
static inline void ResizeBuffer(char** buffer, size_t* bufferSize, const bool copy = false)
{
    //stub method
}

static inline void PrintfAppend(char** buffer, size_t* bufferSize, const char* fmt, va_list arguments)
{
    //stub method
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

static void log_formatter_createPrefix_default(
	char** buffer,
	size_t* bufferSize,
	const char* section,
	int level
) {
	(*buffer)[0] = '\0';

	if (!LOG_SECTION_IS_DEFAULT(section)) {
		const char* prepSection = log_util_prepareSection(section);
		STRCAT_T(*buffer, *bufferSize, "[");
		STRCAT_T(*buffer, *bufferSize, prepSection);
		STRCAT_T(*buffer, *bufferSize, "] ");
	}
	if (level != LOG_LEVEL_INFO && level != LOG_LEVEL_NOTICE) {
		const char* levelStr = log_util_levelToString(level);
		STRCAT_T(*buffer, *bufferSize, levelStr);
		STRCAT_T(*buffer, *bufferSize, ": ");
	}
}


static inline void log_formatter_createPrefix(
	char** buffer,
	size_t* bufferSize,
	const char* section,
	int level
) {
	//log_formatter_createPrefix_xorgStyle(buffer, bufferSize, section, level);
	//log_formatter_createPrefix_testing(buffer, bufferSize, section, level);
	log_formatter_createPrefix_default(buffer, bufferSize, section, level);

	// check if the buffer was large enough, if not resize it and try again
	if ((strlen(*buffer) + 1) >= *bufferSize) {
		ResizeBuffer(buffer, bufferSize);
		log_formatter_createPrefix(buffer, bufferSize, section, level); // recursive
	}
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
char* log_formatter_format(const char* section, int level, const char* fmt, va_list arguments)
{
    //stub method
}

///@}

#ifdef __cplusplus
} // extern "C"
#endif

