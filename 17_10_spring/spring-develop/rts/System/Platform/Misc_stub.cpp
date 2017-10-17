#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Misc.h"

#ifdef __linux__
#include <dlfcn.h> // for dladdr(), dlopen()
#include <unistd.h>

#elif WIN32
#include <direct.h>
#include <io.h>
#include <process.h>
#include <shlobj.h>
#include <shlwapi.h>
#ifndef SHGFP_TYPE_CURRENT
#define SHGFP_TYPE_CURRENT 0
#endif
#include "System/Platform/Win/WinVersion.h"

#elif __APPLE__
#include <climits> // for PATH_MAX
#include <dlfcn.h> // for dladdr(), dlopen()
#include <mach-o/dyld.h>
#include <stdlib.h>
#include <unistd.h>

#elif defined __FreeBSD__
#include <dlfcn.h> // for dladdr(), dlopen()
#include <sys/sysctl.h>
#include <sys/types.h>
#include <unistd.h>

#else

#endif

#if !defined(WIN32)
#include <pwd.h>         // for getpw
#include <sys/types.h>   // for getpw
#include <sys/utsname.h> // for uname()

#include <fstream>
#endif

#include <cerrno>
#include <cstring>

#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/SafeCStrings.h"
#include "System/Util.h"

#if defined WIN32
/**
 * Returns a handle to the currently loaded module.
 * Note: requires at least Windows 2000
 * @return handle to the currently loaded module, or NULL if an error occures
 */
static HMODULE
GetCurrentModule()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif // defined WIN32

/**
 * The user might want to define the user dir manually,
 * to locate spring related data in a non-default location.
 * @link http://en.wikipedia.org/wiki/Environment_variable#Synopsis
 */
static std::string
GetUserDirFromEnvVar()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static std::string
GetUserDirFromSystemApi()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

namespace Platform {

static std::string origCWD;

std::string
GetOrigCWD()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SetOrigCWD()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
GetUserDir()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#ifndef WIN32
static std::string
GetRealPath(const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif

// Mac OS X:        _NSGetExecutablePath() (man 3 dyld)
// Linux:           readlink /proc/self/exe
// Solaris:         getexecname()
// FreeBSD:         sysctl CTL_KERN KERN_PROC KERN_PROC_PATHNAME -1
// BSD with procfs: readlink /proc/curproc/file
// Windows:         GetModuleFileName() with hModule = NULL
std::string
GetProcessExecutableFile()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
GetProcessExecutablePath()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
GetModuleFile(std::string moduleName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
std::string
GetModulePath(const std::string& moduleName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
GetOS()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
Is64Bit()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#ifdef WIN32
typedef BOOL(WINAPI* LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

/** @brief checks if the current process is running in 32bit emulation mode
    @return FALSE, TRUE, -1 on error (usually no permissions) */
bool
Is32BitEmulation()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#else
// simply assume other OS don't need 32bit emulation
bool
Is32BitEmulation()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif

bool
IsRunningInGDB()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
GetShortFileName(const std::string& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
ExecuteProcess(const std::string& file,
               std::vector<std::string> args,
               bool asSubprocess)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

} // namespace Platform
