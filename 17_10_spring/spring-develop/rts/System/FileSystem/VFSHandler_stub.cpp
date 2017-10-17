#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "VFSHandler.h"

#include <algorithm>
#include <cstring>
#include <set>

#include "ArchiveLoader.h"
#include "ArchiveScanner.h"
#include "FileSystem.h"
#include "System/Exceptions.h"
#include "System/FileSystem/Archives/IArchive.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#define LOG_SECTION_VFS "VFS"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_VFS)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_VFS

CVFSHandler* vfsHandler = NULL;

CVFSHandler::CVFSHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CVFSHandler::AddArchive(const std::string& archiveName,
                        bool override,
                        const std::string& type)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CVFSHandler::AddArchiveWithDeps(const std::string& archiveName,
                                bool override,
                                const std::string& type)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CVFSHandler::RemoveArchive(const std::string& archiveName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CVFSHandler::~CVFSHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CVFSHandler::GetNormalizedPath(const std::string& rawPath)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const CVFSHandler::FileData*
CVFSHandler::GetFileData(const std::string& normalizedFilePath)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CVFSHandler::LoadFile(const std::string& filePath,
                      std::vector<boost::uint8_t>& buffer)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CVFSHandler::FileExists(const std::string& filePath)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
CVFSHandler::GetFilesInDir(const std::string& rawDir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<std::string>
CVFSHandler::GetDirsInDir(const std::string& rawDir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
