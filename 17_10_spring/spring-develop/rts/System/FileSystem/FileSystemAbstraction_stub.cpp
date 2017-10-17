#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#if defined(_MSC_VER) && !defined(S_ISDIR)
#define S_ISDIR(m) (((m)&0170000) == 0040000)
#endif

#include "FileSystemAbstraction.h"

#include "FileQueryFlags.h"

#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <boost/filesystem.hpp>
#include <boost/regex.hpp>
#include <cassert>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef _WIN32
#include <dirent.h>
#include <sstream>
#include <unistd.h>
#include <time.h>
#else
#include <windows.h>
#include <io.h>
#include <direct.h>
#include <fstream>
// Win-API redifines these, which breaks things
#if defined(CreateDirectory)
#undef CreateDirectory
#endif
#if defined(DeleteFile)
#undef DeleteFile
#endif
#endif

std::string
FileSystemAbstraction::RemoveLocalPathPrefix(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::IsFSRoot(const std::string& p)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::IsPathSeparator(char aChar)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::IsNativePathSeparator(char aChar)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::HasPathSepAtEnd(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileSystemAbstraction::EnsurePathSepAtEnd(std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
std::string
FileSystemAbstraction::EnsurePathSepAtEnd(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileSystemAbstraction::EnsureNoPathSepAtEnd(std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
std::string
FileSystemAbstraction::EnsureNoPathSepAtEnd(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
FileSystemAbstraction::StripTrailingSlashes(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
FileSystemAbstraction::GetParent(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

size_t
FileSystemAbstraction::GetFileSize(const std::string& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::IsReadableFile(const std::string& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
FileSystemAbstraction::GetFileModificationDate(const std::string& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

char
FileSystemAbstraction::GetNativePathSeparator()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::IsAbsolutePath(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief creates a rwxr-xr-x dir in the writedir
 *
 * Returns true if the postcondition of this function is that dir exists in
 * the write directory.
 *
 * Note that this function does not check access to the dir, ie. if you've
 * created it manually with 0000 permissions then this function may return
 * true, subsequent operation on files inside the directory may still fail.
 *
 * As a rule of thumb, set identical permissions on identical items in the
 * data directory, ie. all subdirectories the same perms, all files the same
 * perms.
 */
bool
FileSystemAbstraction::MkDir(const std::string& dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::DeleteFile(const std::string& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::FileExists(const std::string& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::DirExists(const std::string& dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::DirIsWritable(const std::string& dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FileSystemAbstraction::ComparePaths(const std::string& path1,
                                    const std::string& path2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
FileSystemAbstraction::GetCwd()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileSystemAbstraction::ChDir(const std::string& dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
FindFiles(std::vector<std::string>& matches,
          const std::string& datadir,
          const std::string& dir,
          const boost::regex& regexPattern,
          int flags)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileSystemAbstraction::FindFiles(std::vector<std::string>& matches,
                                 const std::string& dataDir,
                                 const std::string& dir,
                                 const std::string& regex,
                                 int flags)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
