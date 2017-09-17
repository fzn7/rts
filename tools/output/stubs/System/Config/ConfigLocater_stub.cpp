/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef WIN32
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#else
	#include <io.h>
	#include <direct.h>
	#include <windows.h>
#endif
#include <stdlib.h>

#include "ConfigLocater.h"
#include "Game/GameVersion.h"
#include "System/Exceptions.h"
#include "System/FileSystem/DataDirLocater.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Platform/Misc.h"
#include "System/Platform/Win/win32.h"
#include <boost/foreach.hpp>


using std::string;
using std::vector;


static void AddCfgFile(vector<string>& locations, const  std::string& filepath)
{
    //stub method
}


static void LoadCfgs(vector<string>& locations, const std::string& defCfg, const std::string& verCfg)
{
    //stub method
}


static void LoadCfgsInFolder(vector<string>& locations, const std::string& path, const bool hidden = false)
{
    //stub method
}



/**
 * @brief Get the names of the default configuration files
 */
void ConfigLocater::GetDefaultLocations(vector<string>& locations)
{
    //stub method
}
