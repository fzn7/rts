#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DataDirsAccess.h"
#include "DataDirLocater.h"
#include "FileHandler.h"
#include "FileQueryFlags.h"
#include "FileSystem.h"

#include <cassert>
#include <string>
#include <vector>

DataDirsAccess dataDirsAccess;

std::vector<std::string>
DataDirsAccess::FindFiles(std::string dir,
                          const std::string& pattern,
                          int flags) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
DataDirsAccess::FindFilesInternal(const std::string& dir,
                                  const std::string& pattern,
                                  int flags) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
DataDirsAccess::LocateFileInternal(const std::string& file) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DataDirsAccess::FindFilesSingleDir(std::vector<std::string>& matches,
                                   const std::string& datadir,
                                   const std::string& dir,
                                   const std::string& pattern,
                                   int flags) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
DataDirsAccess::LocateFile(std::string file, int flags) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
DataDirsAccess::LocateDir(std::string dir, int flags) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
std::vector<std::string>
DataDirsAccess::LocateDirs(std::string dir) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
DataDirsAccess::FindDirsInDirectSubDirs(const std::string& relPath) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
DataDirsAccess::InReadDir(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
DataDirsAccess::InWriteDir(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
