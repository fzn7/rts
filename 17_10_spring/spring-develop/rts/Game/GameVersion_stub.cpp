#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

// IMPORTANT NOTE: external systems sed -i this file, so DO NOT CHANGE without
// major thought in advance, and deliberation with bibim and tvo/Tobi!

#include "GameVersion.h"

#include "System/VersionGenerated.h"

#include <boost/config.hpp>
#include <boost/version.hpp>
#include <cstring>
#include <stdio.h>

/**
 * @brief Defines the current version string.
 * Take special care when moving this file.
 * The build-bot refers to this file to append the exact SCM version.
 */
namespace SpringVersion {

const std::string&
GetMajor()
{
    static const std::string major = SPRING_VERSION_ENGINE_MAJOR;

    //stub method
    std::cout << __FUNCTION__ << std::endl;
    return major;
}

const std::string&
GetMinor()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
GetPatchSet()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
GetCommits()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
GetHash()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
GetBranch()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
GetAdditional()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#define QUOTEME_(x) #x
#define QUOTEME(x) QUOTEME_(x)

const std::string&
GetCompiler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
GetBuildEnvironment()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
IsRelease()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
IsHeadless()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
IsUnitsync()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
Get()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
GetSync()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
GetFull()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
