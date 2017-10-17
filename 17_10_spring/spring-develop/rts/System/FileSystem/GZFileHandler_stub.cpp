#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GZFileHandler.h"

#include <cassert>
#include <string>
#include <zlib.h>

#include "FileQueryFlags.h"
#include "FileSystem.h"

#ifndef TOOLS
#include "VFSHandler.h"
#include "DataDirsAccess.h"
#include "System/Util.h"
#include "System/Platform/Misc.h"
#endif

#define BUFFER_SIZE 8192

// We must call Open from here since in the CFileHandler ctor
// virtual functions aren't called.
CGZFileHandler::CGZFileHandler(const char* fileName, const char* modes)
  : CFileHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGZFileHandler::CGZFileHandler(const std::string& fileName,
                               const std::string& modes)
  : CFileHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGZFileHandler::ReadToBuffer(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGZFileHandler::UncompressBuffer()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGZFileHandler::TryReadFromPWD(const std::string& fileName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGZFileHandler::TryReadFromRawFS(const std::string& fileName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGZFileHandler::TryReadFromModFS(const std::string& fileName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}