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
#include <sstream>
#include <cassert>
#include <string.h>

#include "FileSystem.h"
#include "CacheDir.h"
#include "System/Exceptions.h"
#include "System/maindefines.h" // for sPS, cPS, cPD
#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/Misc.h"

CONFIG(std::string, SpringData).defaultValue("")
		.description("List of addidional data-directories, separated by ';' on windows, ':' on other OSs")
		.readOnly(true);


static inline std::string GetSpringBinaryName()
{
    //stub method
}

static inline std::string GetUnitsyncLibName()
{
    //stub method
}


static std::string GetBinaryLocation()
{
    //stub method
}


DataDir::DataDir(const std::string& path)
	: path(path)
	, writable(false)
{
    //stub method
}

DataDirLocater::DataDirLocater()
	: isolationMode(false)
	, writeDir(NULL)
{
    //stub method
}


void DataDirLocater::UpdateIsolationModeByEnvVar()
{
    //stub method
}

const std::vector<DataDir>& DataDirLocater::GetDataDirs() const
{
    //stub method
}

std::string DataDirLocater::SubstEnvVars(const std::string& in) const
{
    //stub method
}

void DataDirLocater::AddDirs(const std::string& dirs)
{
    //stub method
}

void DataDirLocater::AddDir(const std::string& dir)
{
    //stub method
}

bool DataDirLocater::DeterminePermissions(DataDir* dataDir)
{
    //stub method
}

void DataDirLocater::FilterUsableDataDirs()
{
    //stub method
}


bool DataDirLocater::IsWriteableDir(DataDir* dataDir)
{
    //stub method
}

void DataDirLocater::FindWriteableDataDir()
{
    //stub method
}


void DataDirLocater::AddCurWorkDir()
{
    //stub method
}


void DataDirLocater::AddPortableDir()
{
    //stub method
}


void DataDirLocater::AddHomeDirs()
{
    //stub method
}


void DataDirLocater::AddEtcDirs()
{
    //stub method
}


void DataDirLocater::AddShareDirs()
{
    //stub method
}


void DataDirLocater::LocateDataDirs()
{
    //stub method
}


void DataDirLocater::Check()
{
    //stub method
}


void DataDirLocater::ChangeCwdToWriteDir()
{
    //stub method
}


bool DataDirLocater::IsInstallDirDataDir()
{
    //stub method
}


bool DataDirLocater::IsPortableMode()
{
    //stub method
}


bool DataDirLocater::LooksLikeMultiVersionDataDir(const std::string& dirPath)
{
    //stub method
}


std::string DataDirLocater::GetWriteDirPath() const
{
    //stub method
}


std::vector<std::string> DataDirLocater::GetDataDirPaths() const
{
    //stub method
}

static DataDirLocater* instance = nullptr;
DataDirLocater& DataDirLocater::GetInstance()
{
    //stub method
}

void DataDirLocater::FreeInstance()
{
    //stub method
}

