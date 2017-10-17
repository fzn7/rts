#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <imagehlp.h>
#include <process.h>
#include <signal.h>
#include <windows.h>

#include "Game/GameVersion.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/Log/ILog.h"
#include "System/Log/LogSinkHandler.h"
#include "System/LogOutput.h"
#include "System/Platform/CrashHandler.h"
#include "System/Platform/errorhandler.h"
#include "System/SafeCStrings.h"
#include "System/Util.h"
#include "seh.h"
#include <new>

#define BUFFER_SIZE 2048
#define MAX_STACK_DEPTH 4096

namespace CrashHandler {

CRITICAL_SECTION stackLock;
bool imageHelpInitialised = false;
int
stackLockInit()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int dummyStackLock = stackLockInit();

static void
SigAbrtHandler(int signal)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/** Convert exception code to human readable string. */
static const char*
ExceptionName(DWORD exceptionCode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
InitImageHlpDll()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/** Callback for SymEnumerateModules */
#if _MSC_VER >= 1500
static BOOL CALLBACK
EnumModules(PCSTR moduleName, ULONG baseOfDll, PVOID userContext)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#else  // _MSC_VER >= 1500
static BOOL CALLBACK
EnumModules(LPSTR moduleName, DWORD baseOfDll, PVOID userContext)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
#endif // _MSC_VER >= 1500

static DWORD __stdcall AllocTest(void* param)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/** Print out a stacktrace. */
inline static void
StacktraceInline(const char* threadName,
                 LPEXCEPTION_POINTERS e,
                 HANDLE hThread = INVALID_HANDLE_VALUE,
                 const int logLevel = LOG_LEVEL_ERROR)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
Stacktrace(const char* threadName,
           LPEXCEPTION_POINTERS e,
           HANDLE hThread = INVALID_HANDLE_VALUE,
           const int logLevel = LOG_LEVEL_ERROR)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Stacktrace(Threading::NativeThreadHandle thread,
           const std::string& threadName,
           const int logLevel)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
PrepareStacktrace(const int logLevel)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CleanupStacktrace(const int logLevel)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
OutputStacktrace()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
NewHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/** Called by windows if an exception happens. */
LONG CALLBACK
ExceptionHandler(LPEXCEPTION_POINTERS e)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/** Install crash handler. */
void
Install()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/** Uninstall crash handler. */
void
Remove()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

}; // namespace CrashHandler
