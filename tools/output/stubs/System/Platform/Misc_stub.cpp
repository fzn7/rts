#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Misc.h"

#ifdef __linux__
#include <unistd.h>
#include <dlfcn.h> // for dladdr(), dlopen()

#elif WIN32
#include <io.h>
#include <direct.h>
#include <process.h>
#include <shlobj.h>
#include <shlwapi.h>
#ifndef SHGFP_TYPE_CURRENT
	#define SHGFP_TYPE_CURRENT 0
#endif
#include "System/Platform/Win/WinVersion.h"

#elif __APPLE__
#include <unistd.h>
#include <mach-o/dyld.h>
#include <stdlib.h>
#include <dlfcn.h> // for dladdr(), dlopen()
#include <climits> // for PATH_MAX

#elif defined __FreeBSD__
#include <unistd.h>
#include <dlfcn.h> // for dladdr(), dlopen()
#include <sys/types.h>
#include <sys/sysctl.h>

#else

#endif

#if !defined(WIN32)
#include <sys/utsname.h> // for uname()
#include <sys/types.h> // for getpw
#include <pwd.h> // for getpw

#include <fstream>
#endif

#include <cstring>
#include <cerrno>

#include "System/Util.h"
#include "System/SafeCStrings.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileSystem.h"

#if       defined WIN32
/**
 * Returns a handle to the currently loaded module.
 * Note: requires at least Windows 2000
 * @return handle to the currently loaded module, or NULL if an error occures
 */
static HMODULE GetCurrentModule()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif // defined WIN32

/**
 * The user might want to define the user dir manually,
 * to locate spring related data in a non-default location.
 * @link http://en.wikipedia.org/wiki/Environment_variable#Synopsis
 */
static std::string GetUserDirFromEnvVar()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::string GetUserDirFromSystemApi()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


namespace Platform
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void SetOrigCWD()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string GetUserDir()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifndef WIN32
static std::string GetRealPath(const std::string& path) {

	std::string pathReal = path;

	// using NULL here is not supported in very old systems,
	// but should be no problem for spring
	// see for older systems:
	// http://stackoverflow.com/questions/4109638/what-is-the-safe-alternative-to-realpath
	char* pathRealC = realpath(path.c_str(), NULL);
	if (pathRealC != NULL) {
		pathReal = pathRealC;
		free(pathRealC);
		pathRealC = NULL;
	}

	if (FileSystem::GetDirectory(pathReal).empty()) {
		pathReal = GetProcessExecutablePath() + pathReal;
	}

	return pathReal;
}
#endif

// Mac OS X:        _NSGetExecutablePath() (man 3 dyld)
// Linux:           readlink /proc/self/exe
// Solaris:         getexecname()
// FreeBSD:         sysctl CTL_KERN KERN_PROC KERN_PROC_PATHNAME -1
// BSD with procfs: readlink /proc/curproc/file
// Windows:         GetModuleFileName() with hModule = NULL
std::string GetProcessExecutableFile()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string GetProcessExecutablePath()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string GetModuleFile(std::string moduleName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
std::string GetModulePath(const std::string& moduleName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string GetOS()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool Is64Bit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef WIN32
typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

/** @brief checks if the current process is running in 32bit emulation mode
    @return FALSE, TRUE, -1 on error (usually no permissions) */
bool Is32BitEmulation()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#else
// simply assume other OS don't need 32bit emulation
bool Is32BitEmulation()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

bool IsRunningInGDB() {
	#ifndef _WIN32
	char buf[1024];

	std::string fname = "/proc/" + IntToString(getppid(), "%d") + "/cmdline";
	std::ifstream f(fname.c_str());

	if (!f.good())
		return false;

	f.read(buf, sizeof(buf));
	f.close();

	return (strstr(buf, "gdb") != NULL);
	#else
	return IsDebuggerPresent();
	#endif
}

std::string GetShortFileName(const std::string& file) {
#ifdef WIN32
	std::vector<TCHAR> shortPathC(file.size() + 1, 0);

	// FIXME: stackoverflow.com/questions/843843/getshortpathname-unpredictable-results
	const int length = GetShortPathName(file.c_str(), &shortPathC[0], file.size() + 1);

	if (length > 0 && length <= (file.size() + 1)) {
		return (std::string(reinterpret_cast<const char*>(&shortPathC[0])));
	}
#endif

	return file;
}

std::string ExecuteProcess(const std::string& file, std::vector<std::string> args, bool asSubprocess)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

} // namespace Platform
