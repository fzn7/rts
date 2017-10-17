#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DataDirLocater.h"

#include <cstdlib>
#ifdef WIN32
#include <io.h>
#include <direct.h>
#include <windows.h>
#include <shlobj.h>
#include <shlwapi.h>
#ifndef SHGFP_TYPE_CURRENT
#define SHGFP_TYPE_CURRENT 0
#endif
#else
#include <wordexp.h>
#endif

#include "System/Platform/Win/win32.h"
#include <cassert>
#include <sstream>
#include <string.h>

#include "CacheDir.h"
#include "FileSystem.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Platform/Misc.h"
#include "System/maindefines.h" // for sPS, cPS, cPD

CONFIG(std::string, SpringData)
  .defaultValue("")
  .description("List of addidional data-directories, separated by ';' on "
               "windows, ':' on other OSs")
  .readOnly(true);

static inline std::string
GetSpringBinaryName()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline std::string
GetUnitsyncLibName()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static std::string
GetBinaryLocation()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

DataDir::DataDir(const std::string& path)
  : path(path)
  , writable(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

DataDirLocater::DataDirLocater()
  : isolationMode(false)
  , writeDir(NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::UpdateIsolationModeByEnvVar()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::vector<DataDir>&
DataDirLocater::GetDataDirs() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
DataDirLocater::SubstEnvVars(const std::string& in) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::AddDirs(const std::string& dirs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::AddDir(const std::string& dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
DataDirLocater::DeterminePermissions(DataDir* dataDir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::FilterUsableDataDirs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
DataDirLocater::IsWriteableDir(DataDir* dataDir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::FindWriteableDataDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::AddCurWorkDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::AddPortableDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::AddHomeDirs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::AddEtcDirs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::AddShareDirs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::LocateDataDirs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::Check()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::ChangeCwdToWriteDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
DataDirLocater::IsInstallDirDataDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
DataDirLocater::IsPortableMode()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
DataDirLocater::LooksLikeMultiVersionDataDir(const std::string& dirPath)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
DataDirLocater::GetWriteDirPath() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
DataDirLocater::GetDataDirPaths() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static DataDirLocater* instance = nullptr;
DataDirLocater&
DataDirLocater::GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirLocater::FreeInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
