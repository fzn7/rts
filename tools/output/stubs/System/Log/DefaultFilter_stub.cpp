/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DefaultFilter.h"

#include "Level.h"
#include "Section.h"
#include "ILog.h"

#include <cstdio>
#include <cstdarg>
#include <cassert>

#include <map>
#include <unordered_map>
#include <memory>
#include <set>
#include <stack>
#include <string>


#ifdef __cplusplus
extern "C" {
#endif


bool log_frontend_isEnabled(const char* section, int level);


extern void log_backend_record(const char* section, int level, const char* fmt, va_list arguments);
extern void log_backend_cleanup();


struct log_filter_section_compare {
	inline bool operator()(const char* const& section1, const char* const& section2) const
	{
		return LOG_SECTION_COMPARE(section1, section2);
	}
};
#ifdef __cplusplus
}
#endif

namespace {
	typedef std::set<const char*, log_filter_section_compare> secSet_t;
	typedef std::map<const char*, int, log_filter_section_compare> secIntMap_t;

	int minLogLevel = LOG_LEVEL_ALL;

	secIntMap_t& log_filter_getSectionMinLevels() {
		static secIntMap_t sectionMinLevels;
		return sectionMinLevels;
	}

	secSet_t& log_filter_getRegisteredSections() {
		static secSet_t sections;
		return sections;
	}

	void inline log_filter_printSectionMinLevels(const char* func) {
		printf("[%s][caller=%s]\n", __FUNCTION__, func);

		const auto& secLevels = log_filter_getSectionMinLevels();

		for (auto it = secLevels.begin(); it != secLevels.end(); ++it) {
			printf("\tsectionName=\"%s\" minLevel=%d\n", it->first, it->second);
		}
	}
}

#ifdef __cplusplus
extern "C" {
#endif


static inline int log_filter_section_getDefaultMinLevel(const char* section) {

	if (LOG_SECTION_IS_DEFAULT(section)) {
#ifdef DEBUG
		return LOG_LEVEL_DEBUG;
	} else {
		return LOG_LEVEL_INFO;
#else
		return LOG_LEVEL_INFO;
	} else {
		return LOG_LEVEL_NOTICE;
#endif
	}
}

static inline void log_filter_checkCompileTimeMinLevel(int level) {

	if (level >= _LOG_LEVEL_MIN)
		return;

	// to prevent an endless recursion
	if (_LOG_LEVEL_MIN > LOG_LEVEL_WARNING)
		return;

	LOG_L(L_WARNING,
		"Tried to set minimum log level %i, but it was set to"
		" %i at compile-time -> effective min-level is %i.",
		level, _LOG_LEVEL_MIN, _LOG_LEVEL_MIN
	);
}


int log_filter_global_getMinLevel() { return minLogLevel; }
void log_filter_global_setMinLevel(int level) { log_filter_checkCompileTimeMinLevel(level); minLogLevel = level; }


int log_filter_section_getMinLevel(const char* section)
{
    //stub method
}

// called by LogOutput for each ENABLED section
// also by LuaUnsyncedCtrl::SetLogSectionFilterLevel
void log_filter_section_setMinLevel(const char* section, int level)
{
    //stub method
}


void log_enable_and_disable(const bool enable)
{
    //stub method
}

int log_filter_section_getNumRegisteredSections() {
	return (log_filter_getRegisteredSections().size());
}

const char* log_filter_section_getRegisteredIndex(int index) {
	const secSet_t& registeredSections = log_filter_getRegisteredSections();

	if (index < 0)
		return NULL;
	if (index >= static_cast<int>(registeredSections.size()))
		return NULL;

	secSet_t::const_iterator si = registeredSections.begin();

	for (int curIndex = 0; curIndex < index; ++curIndex) {
		++si;
	}

	return (*si);
}

static void log_filter_record(const char* section, int level, const char* fmt, va_list arguments)
{
    //stub method
}


/**
 * @name logging_frontend_defaultFilter
 * ILog.h frontend implementation.
 */
///@{

bool log_frontend_isEnabled(const char* section, int level) {
	if (level < log_filter_global_getMinLevel())
		return false;
	if (level < log_filter_section_getMinLevel(section))
		return false;

	return true;
}

// see the LOG_REGISTER_SECTION_RAW macro in ILog.h
void log_frontend_register_section(const char* section) {
	if (!LOG_SECTION_IS_DEFAULT(section)) {
		secSet_t& registeredSections = log_filter_getRegisteredSections();
		secSet_t::const_iterator si = registeredSections.find(section);

		if (si == registeredSections.end()) {
			registeredSections.insert(section);
		}
	}
}

void log_frontend_register_runtime_section(const char* section_cstr_tmp, int level) {
	const char* section_cstr = log_filter_section_getSectionCString(section_cstr_tmp);

	log_frontend_register_section(section_cstr);
	log_filter_section_setMinLevel(section_cstr, level);

}

void log_frontend_record(const char* section, int level, const char* fmt, ...)
{
    //stub method
}

void log_frontend_cleanup() {
	log_backend_cleanup();
}

///@}

#ifdef __cplusplus
} // extern "C"
#endif



std::set<const char*> log_filter_section_getRegisteredSet()
{
    //stub method
}

const char* log_filter_section_getSectionCString(const char* section_cstr_tmp)
{
    //stub method
}
