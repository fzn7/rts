/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ArchiveNameResolver.h"

#include "Game/GlobalUnsynced.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/RapidHandler.h"
#include "System/UriParser.h"
#include "System/Util.h"

#include <boost/cstdint.hpp>
#include <iostream>

namespace ArchiveNameResolver {
//////////////////////////////////////////////////////////////////////////////
//
//  Helpers
//

static boost::uint64_t
ExtractVersionNumber(const std::string& version)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
GetGameByExactName(const std::string& lazyName, std::string* applicableName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
GetGameByShortName(const std::string& lazyName, std::string* applicableName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
GetRandomGame(const std::string& lazyName, std::string* applicableName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
GetMapByExactName(const std::string& lazyName, std::string* applicableName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
GetMapBySubString(const std::string& lazyName, std::string* applicableName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
GetRandomMap(const std::string& lazyName, std::string* applicableName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
GetGameByRapidTag(const std::string& lazyName, std::string& tag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////////////
//
//  Interface
//

std::string
GetGame(const std::string& lazyName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
GetMap(const std::string& lazyName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace ArchiveNameResolver
