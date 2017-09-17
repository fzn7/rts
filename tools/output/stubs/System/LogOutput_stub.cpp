/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/LogOutput.h"

#include "Game/GameVersion.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/DefaultFilter.h"
#include "System/Log/FileSink.h"
#include "System/Log/ILog.h"
#include "System/Log/Level.h"
#include "System/Log/LogUtil.h"
#include "System/Platform/Misc.h"
#include "System/Util.h"

#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <cassert>
#include <cstring>

#include <boost/thread/recursive_mutex.hpp>

/******************************************************************************/
/******************************************************************************/

CONFIG(bool, RotateLogFiles)
  .defaultValue(false)
  .description(
    "rotate logfiles, old logfiles will be moved into the subfolder \"log\".");

CONFIG(std::string, LogSections)
  .defaultValue("")
  .description("Comma seperated list of enabled logsections, see infolog.txt / "
               "console output for possible values");

CONFIG(int, LogFlushLevel)
  .defaultValue(LOG_LEVEL_ERROR)
  .description("Flush the logfile when level of message is above "
               "LogFlushLevel. i.e. ERROR is flushed as default, WARNING "
               "isn't.");

/******************************************************************************/
/******************************************************************************/

static std::map<std::string, int>
GetEnabledSections()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
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
static void
InitializeLogSections()
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

CLogOutput::~CLogOutput() {}

void
CLogOutput::SetFileName(std::string fname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CLogOutput::CreateFilePath(const std::string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLogOutput::RotateLogFile() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLogOutput::Initialize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLogOutput::LogSystemInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
