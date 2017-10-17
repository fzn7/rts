#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FileSystemInitializer.h"
#include "ArchiveScanner.h"
#include "DataDirLocater.h"
#include "System/Config/ConfigHandler.h"
#include "System/LogOutput.h"
#include "System/Platform/Misc.h"
#include "System/Util.h"
#include "VFSHandler.h"

bool FileSystemInitializer::initialized = false;

void
FileSystemInitializer::PreInitializeConfigHandler(
  const std::string& configSource,
  const bool safemode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileSystemInitializer::InitializeLogOutput(const std::string& filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileSystemInitializer::Initialize()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileSystemInitializer::Cleanup(bool deallocConfigHandler)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
