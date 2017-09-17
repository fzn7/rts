/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/LogOutput.h"

#include "System/Util.h"
#include "Game/GameVersion.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/DefaultFilter.h"
#include "System/Log/FileSink.h"
#include "System/Log/ILog.h"
#include "System/Log/Level.h"
#include "System/Log/LogUtil.h"
#include "System/Platform/Misc.h"

#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include <cassert>
#include <cstring>

#include <boost/thread/recursive_mutex.hpp>


/******************************************************************************/
/******************************************************************************/

CONFIG(bool, RotateLogFiles).defaultValue(false)
		.description("rotate logfiles, old logfiles will be moved into the subfolder \"log\".");

CONFIG(std::string, LogSections).defaultValue("")
		.description("Comma seperated list of enabled logsections, see infolog.txt / console output for possible values");

CONFIG(int, LogFlushLevel).defaultValue(LOG_LEVEL_ERROR)
		.description("Flush the logfile when level of message is above LogFlushLevel. i.e. ERROR is flushed as default, WARNING isn't.");

/******************************************************************************/
/******************************************************************************/

static std::map<std::string, int> GetEnabledSections() {
	std::map<std::string, int> sectionLevelMap;

	std::string enabledSections = ",";
	std::string envSections = ",";

#if defined(UNITSYNC)
	#if defined(DEBUG)
	// unitsync logging in debug mode always on
	// configHandler cannot be accessed here in unitsync, as it may not exist.
	enabledSections += "unitsync,ArchiveScanner,";
	#endif
#else
	#if defined(DEDICATED)
	enabledSections += "DedicatedServer,";
	#endif
	#if !defined(DEBUG)
	// Always show at least INFO level of these sections
	enabledSections += "Sound,";
	#endif
	enabledSections += StringToLower(configHandler->GetString("LogSections"));
#endif

	if (getenv("SPRING_LOG_SECTIONS") != NULL) {
		// allow disabling all sections from the env var by setting it to "none"
		envSections += getenv("SPRING_LOG_SECTIONS");
		envSections = StringToLower(envSections);

		if (envSections == "none") {
			enabledSections = "";
		} else {
			enabledSections += envSections;
		}
	}

	enabledSections = StringToLower(enabledSections);
	enabledSections = StringStrip(enabledSections, " \t\n\r");

	// make the last "section:level" substring findable
	if (!enabledSections.empty() && enabledSections.back() != ',')
		enabledSections += ",";

	// n=1 because <enabledSections> always starts with a ',' (if non-empty)
	for (size_t n = 1; n < enabledSections.size(); ) {
		const size_t k = enabledSections.find(",", n);

		if (k != std::string::npos) {
			const std::string& sub = enabledSections.substr(n, k - n);

			if (!sub.empty()) {
				const size_t sepChr = sub.find(":");

				const std::string& logSec = (sepChr != std::string::npos)? sub.substr(         0,            sepChr): sub;
				const std::string& logLvl = (sepChr != std::string::npos)? sub.substr(sepChr + 1, std::string::npos):  "";

				if (!logLvl.empty()) {
					sectionLevelMap[logSec] = StringToInt(logLvl);
				} else {
					#if defined(DEBUG)
					sectionLevelMap[logSec] = LOG_LEVEL_DEBUG;
					#else
					sectionLevelMap[logSec] = DEFAULT_LOG_LEVEL;
					#endif

				}
			}

			n = k + 1;
		} else {
			n = k;
		}
	}

	return sectionLevelMap;
}

/**
 * @brief initialize the log sections
 *
 * This writes a list of all available and all enabled sections to the log.
 *
 * Log sections can be enabled using the configuration key "LogSections",
 * or the environment variable "SPRING_LOG_SECTIONS".
 *
 * Both specify a comma-separated list of sections that should be enabled.
 * The lists from both sources are combined, there is no overriding.
 *
 * A section that is enabled by default, can not be disabled.
 */
static void InitializeLogSections()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




CLogOutput logOutput;

CLogOutput::CLogOutput()
	: fileName("")
	, filePath("")
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CLogOutput::~CLogOutput()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CLogOutput::SetFileName(std::string fname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CLogOutput::CreateFilePath(const std::string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLogOutput::RotateLogFile() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CLogOutput::Initialize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CLogOutput::LogSystemInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

