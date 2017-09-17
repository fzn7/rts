#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DefaultFilter.h"

#include "ILog.h"
#include "Level.h"
#include "Section.h"

#include <cassert>
#include <cstdarg>
#include <cstdio>

#include <map>
#include <memory>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>

#ifdef __cplusplus
extern "C" {
#endif

bool
log_frontend_isEnabled(const char* section, int level);

extern void
log_backend_record(const char* section,
                   int level,
                   const char* fmt,
                   va_list arguments);
extern void
log_backend_cleanup();

struct log_filter_section_compare
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

namespace {
typedef std::set<const char*, log_filter_section_compare> secSet_t;
typedef std::map<const char*, int, log_filter_section_compare> secIntMap_t;

int minLogLevel = LOG_LEVEL_ALL;

secIntMap_t&
log_filter_getSectionMinLevels()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

secSet_t&
log_filter_getRegisteredSections()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void inline log_filter_printSectionMinLevels(const char* func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}

#ifdef __cplusplus
extern "C" {
#endif

static inline int
log_filter_section_getDefaultMinLevel(const char* section)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
log_filter_checkCompileTimeMinLevel(int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
log_filter_global_getMinLevel()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
log_filter_global_setMinLevel(int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
log_filter_section_getMinLevel(const char* section)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// called by LogOutput for each ENABLED section
// also by LuaUnsyncedCtrl::SetLogSectionFilterLevel
void
log_filter_section_setMinLevel(const char* section, int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
log_enable_and_disable(const bool enable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
log_filter_section_getNumRegisteredSections()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
log_filter_section_getRegisteredIndex(int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
log_filter_record(const char* section,
                  int level,
                  const char* fmt,
                  va_list arguments)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @name logging_frontend_defaultFilter
 * ILog.h frontend implementation.
 */
///@{

bool
log_frontend_isEnabled(const char* section, int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// see the LOG_REGISTER_SECTION_RAW macro in ILog.h
void
log_frontend_register_section(const char* section)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
log_frontend_register_runtime_section(const char* section_cstr_tmp, int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
log_frontend_record(const char* section, int level, const char* fmt, ...)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
log_frontend_cleanup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    ///@}

#ifdef __cplusplus
} // extern "C"
#endif

std::set<const char*>
log_filter_section_getRegisteredSet()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
log_filter_section_getSectionCString(const char* section_cstr_tmp)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
