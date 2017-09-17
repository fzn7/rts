#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FileHandler.h"

#include <algorithm>
#include <boost/regex.hpp>
#include <cctype>
#include <fstream>
#include <limits.h>
#include <set>
#include <string>
#include <vector>

#include "FileQueryFlags.h"
#include "FileSystem.h"

#ifndef TOOLS
#include "VFSHandler.h"
#include "DataDirsAccess.h"
#include "System/Util.h"
#include "System/Platform/Misc.h"
#endif

using std::string;

/******************************************************************************/
/******************************************************************************/

CFileHandler::CFileHandler(const char* fileName, const char* modes)
  : filePos(0)
  , fileSize(-1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CFileHandler::CFileHandler(const string& fileName, const string& modes)
  : filePos(0)
  , fileSize(-1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CFileHandler::~CFileHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

bool
CFileHandler::TryReadFromPWD(const string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::TryReadFromRawFS(const string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::TryReadFromModFS(const string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::TryReadFromMapFS(const string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::TryReadFromBaseFS(const string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFileHandler::Open(const string& fileName, const string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

bool
CFileHandler::FileExists(const std::string& filePath, const std::string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::FileExists() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CFileHandler::Read(void* buf, int length)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CFileHandler::ReadString(void* buf, int length)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFileHandler::Seek(int length, std::ios_base::seekdir where)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::Eof() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CFileHandler::FileSize() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CFileHandler::GetPos()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::LoadStringData(string& data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CFileHandler::GetFileExt() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

std::vector<string>
CFileHandler::FindFiles(const string& path, const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

std::vector<string>
CFileHandler::DirList(const string& path,
                      const string& pattern,
                      const string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::InsertRawFiles(std::set<string>& fileSet,
                             const string& path,
                             const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::InsertModFiles(std::set<string>& fileSet,
                             const string& path,
                             const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::InsertMapFiles(std::set<string>& fileSet,
                             const string& path,
                             const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::InsertBaseFiles(std::set<string>& fileSet,
                              const string& path,
                              const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

std::vector<string>
CFileHandler::SubDirs(const string& path,
                      const string& pattern,
                      const string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::InsertRawDirs(std::set<string>& dirSet,
                            const string& path,
                            const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::InsertModDirs(std::set<string>& dirSet,
                            const string& path,
                            const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::InsertMapDirs(std::set<string>& dirSet,
                            const string& path,
                            const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFileHandler::InsertBaseDirs(std::set<string>& dirSet,
                             const string& path,
                             const string& pattern)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

string
CFileHandler::AllowModes(const string& modes, const string& allowed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string
CFileHandler::ForbidModes(const string& modes, const string& forbidden)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
