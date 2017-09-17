/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

// IMPORTANT NOTE: external systems sed -i this file, so DO NOT CHANGE without
// major thought in advance, and deliberation with bibim and tvo/Tobi!

#include "GameVersion.h"

#include "System/VersionGenerated.h"

#include <cstring>
#include <boost/version.hpp>
#include <boost/config.hpp>
#include <stdio.h>

/**
 * @brief Defines the current version string.
 * Take special care when moving this file.
 * The build-bot refers to this file to append the exact SCM version.
 */
namespace SpringVersion
{
    //stub method
}

const std::string& GetMinor()
{
    //stub method
}

const std::string& GetPatchSet()
{
    //stub method
}

const std::string& GetCommits()
{
    //stub method
}

const std::string& GetHash()
{
    //stub method
}

const std::string& GetBranch()
{
    //stub method
}

std::string GetAdditional()
{
    //stub method
}

#define QUOTEME_(x) #x
#define QUOTEME(x) QUOTEME_(x)

const std::string& GetCompiler()
{
    //stub method
}

const std::string& GetBuildEnvironment()
{
    //stub method
}

bool IsRelease()
{
    //stub method
}

bool IsHeadless()
{
    //stub method
}

bool IsUnitsync()
{
    //stub method
}

const std::string& Get()
{
    //stub method
}

const std::string& GetSync()
{
    //stub method
}

const std::string& GetFull()
{
    //stub method
}

}
