#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ConfigSource.h"
#include "ConfigVariable.h"
#include "System/Log/ILog.h"
#include "System/Platform/ScopedFileLock.h"

#ifdef WIN32
#include <io.h>
#endif
#include <boost/bind.hpp>
#include <stdexcept>
#include <string.h>

/******************************************************************************/

using std::map;
using std::string;

typedef map<string, string> StringMap;

/******************************************************************************/

bool
ReadOnlyConfigSource::IsSet(const string& key) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

string
ReadOnlyConfigSource::GetString(const string& key) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
ReadWriteConfigSource::SetString(const string& key, const string& value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ReadWriteConfigSource::Delete(const string& key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

FileConfigSource::FileConfigSource(const string& filename)
  : filename(filename)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileConfigSource::SetStringInternal(const std::string& key,
                                    const std::string& value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileConfigSource::SetString(const string& key, const string& value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileConfigSource::DeleteInternal(const string& key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileConfigSource::Delete(const string& key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FileConfigSource::ReadModifyWrite(boost::function<void()> modify)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief strip whitespace
 *
 * Strips whitespace off the string [begin, end] by setting the last
 * whitespace character from the end to 0 and returning a pointer
 * to the first non-whitespace character from the beginning.
 *
 * Precondition: end must point to the last character of the string,
 * i.e. the one before the terminating '\0'.
 */
char*
FileConfigSource::Strip(char* begin, char* end)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Rewind file and re-read it.
 */
void
FileConfigSource::Read(FILE* file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Truncate file and write data to it.
 */
void
FileConfigSource::Write(FILE* file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

/**
 * @brief Fill with default values of declared configuration variables.
 */
DefaultConfigSource::DefaultConfigSource()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Fill with safemode values of declared configuration variables.
 */
SafemodeConfigSource::SafemodeConfigSource()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Fill with dedicated values of declared configuration variables.
 */
DedicatedConfigSource::DedicatedConfigSource()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Fill with headless values of declared configuration variables.
 */
HeadlessConfigSource::HeadlessConfigSource()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
