#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#if defined BUILDING_AI
#include "System/Util.h"
#else // defined BUILDING_AI
#include "System/Log/ILog.h"
#endif // defined BUILDING_AI

// OS dependent stuff
#ifdef _WIN32
#include "Win/DllLib.h"
#define SL_IMPL_CLS DllLib
#define SL_IMPL_EXT "dll"
#else // _WIN32
#include "Linux/SoLib.h"
#define SL_IMPL_CLS SoLib
#if defined __APPLE__
#define SL_IMPL_EXT "dylib"
#else // defined __APPLE__
#define SL_IMPL_EXT "so"
#endif // defined __APPLE__
#endif // _WIN32

/**
 * Used to create a platform-specific shared library handler.
 */
SharedLib*
SharedLib::Instantiate(const char* fileName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * Used to create a platform-specific shared library handler.
 */
SharedLib*
SharedLib::Instantiate(const std::string& fileName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const char*
SharedLib::GetLibExtension()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SharedLib::reportError(const char* errorMsg,
                       const char* fileName,
                       int lineNumber,
                       const char* function)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SharedLib::~SharedLib()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#undef SL_IMPL_CLS
#undef SL_IMPL_EXT
