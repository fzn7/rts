/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * This eventually prefixes log records with the current frame number.
 */

#include "System/maindefines.h"

#include <cstdarg>
#include <cstring>


#ifdef __cplusplus
extern "C" {
#endif

// GlobalSynced makes sure this can not be dangling
static int* frameNumRef = NULL;

void log_framePrefixer_setFrameNumReference(int* frameNumReference)
{
    //stub method
}

size_t log_framePrefixer_createPrefix(char* result, size_t resultSize)
{
    //stub method
}

#ifdef __cplusplus
} // extern "C"
#endif

