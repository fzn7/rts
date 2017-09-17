/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FileSystemInitializer.h"
#include "DataDirLocater.h"
#include "ArchiveScanner.h"
#include "VFSHandler.h"
#include "System/LogOutput.h"
#include "System/Util.h"
#include "System/Config/ConfigHandler.h"
#include "System/Platform/Misc.h"



bool FileSystemInitializer::initialized = false;

void FileSystemInitializer::PreInitializeConfigHandler(const std::string& configSource, const bool safemode)
{
    //stub method
}


void FileSystemInitializer::InitializeLogOutput(const std::string& filename)
{
    //stub method
}


void FileSystemInitializer::Initialize()
{
    //stub method
}

void FileSystemInitializer::Cleanup(bool deallocConfigHandler)
{
    //stub method
}
