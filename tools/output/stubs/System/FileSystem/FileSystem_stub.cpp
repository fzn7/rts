#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * Glob conversion by Chris Han (based on work by Nathaniel Smith).
 */
#include "FileSystem.h"

#include "Game/GameVersion.h"
#include "System/Log/ILog.h"
#include "System/Platform/Win/win32.h"
#include "System/Util.h"

#include <boost/regex.hpp>

#ifdef _WIN32
#include <io.h>
#endif

////////////////////////////////////////
////////// FileSystem

/**
 * @brief quote macro
 * @param c Character to test
 * @param str string currently being built
 *
 * Given an std::string str that we are assembling,
 * and an upcoming char c, will append
 * an extra '\\' to quote the character if necessary.
 * The do-while is used for legalizing the ';' in "QUOTE(c, regex);".
 */
#define QUOTE(c, str)                                                          \
    do {                                                                       \
        if (!(isalnum(c) || (c) == '_'))                                       \
            str += '\\';                                                       \
        str += c;                                                              \
    } while (0)

std::string
FileSystem::ConvertGlobToRegex(const std::string& glob)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
FileSystem::ComparePaths(std::string path1, std::string path2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
FileSystem::FileExists(std::string file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
FileSystem::GetFileSize(std::string file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
FileSystem::CreateDirectory(std::string dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
FileSystem::TouchFile(std::string filePath)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
FileSystem::GetDirectory(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
FileSystem::GetFilename(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
FileSystem::GetBasename(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
FileSystem::GetExtension(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
FileSystem::GetNormalizedPath(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string&
FileSystem::FixSlashes(std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string&
FileSystem::ForwardSlashes(std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
FileSystem::CheckFile(const std::string& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
FileSystem::Remove(std::string file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
FileSystem::GetCacheBaseDir()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
FileSystem::GetCacheDir()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
