/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <windows.h>
#include <process.h>
#include <imagehlp.h>
#include <signal.h>

#include "System/Platform/CrashHandler.h"
#include "System/Platform/errorhandler.h"
#include "System/Log/ILog.h"
#include "System/Log/LogSinkHandler.h"
#include "System/LogOutput.h"
#include "Net/Protocol/NetProtocol.h"
#include "seh.h"
#include "System/Util.h"
#include "System/SafeCStrings.h"
#include "Game/GameVersion.h"
#include <new>


#define BUFFER_SIZE 2048
#define MAX_STACK_DEPTH 4096

namespace CrashHandler {

CRITICAL_SECTION stackLock;
bool imageHelpInitialised = false;
int stackLockInit() { InitializeCriticalSection(&stackLock); return 0; }
int dummyStackLock = stackLockInit();

static void SigAbrtHandler(int signal)
{
    //stub method
}

/** Convert exception code to human readable string. */
static const char* ExceptionName(DWORD exceptionCode)
{
    //stub method
}


bool InitImageHlpDll()
{
    //stub method
}


/** Callback for SymEnumerateModules */
#if _MSC_VER >= 1500
	static BOOL CALLBACK EnumModules(PCSTR moduleName, ULONG baseOfDll, PVOID userContext)
	{
		LOG_L(L_ERROR, "0x%08lx\t%s", baseOfDll, moduleName);
		return TRUE;
	}
#else // _MSC_VER >= 1500
	static BOOL CALLBACK EnumModules(LPSTR moduleName, DWORD baseOfDll, PVOID userContext)
	{
		LOG_L(L_ERROR, "0x%08lx\t%s", baseOfDll, moduleName);
		return TRUE;
	}
#endif // _MSC_VER >= 1500

static DWORD __stdcall AllocTest(void *param) {
	GlobalFree(GlobalAlloc(GMEM_FIXED, 16384));
	return 0;
}

/** Print out a stacktrace. */
inline static void StacktraceInline(const char *threadName, LPEXCEPTION_POINTERS e, HANDLE hThread = INVALID_HANDLE_VALUE, const int logLevel = LOG_LEVEL_ERROR)
{
    //stub method
}

static void Stacktrace(const char *threadName, LPEXCEPTION_POINTERS e, HANDLE hThread = INVALID_HANDLE_VALUE, const int logLevel = LOG_LEVEL_ERROR) {
	StacktraceInline(threadName, e, hThread, logLevel);
}


void Stacktrace(Threading::NativeThreadHandle thread, const std::string& threadName, const int logLevel)
{
    //stub method
}

void PrepareStacktrace(const int logLevel) {
	EnterCriticalSection( &stackLock );

	InitImageHlpDll();

	// Record list of loaded DLLs.
	LOG_I(logLevel, "DLL information:");
	SymEnumerateModules(GetCurrentProcess(), (PSYM_ENUMMODULES_CALLBACK)EnumModules, NULL);
}

void CleanupStacktrace(const int logLevel) {
	LOG_CLEANUP();
	// Unintialize IMAGEHLP.DLL
	SymCleanup(GetCurrentProcess());
	imageHelpInitialised = false;

	LeaveCriticalSection( &stackLock );
}

void OutputStacktrace() {
	LOG_L(L_ERROR, "Error handler invoked for Spring %s.", (SpringVersion::GetFull()).c_str());

	PrepareStacktrace();

	Stacktrace(NULL, NULL);

	CleanupStacktrace();
}

void NewHandler() {
	LOG_L(L_ERROR, "Failed to allocate memory"); // make sure this ends up in the log also

	OutputStacktrace();

	ErrorMessageBox("Failed to allocate memory", "Spring: Fatal Error", MBF_OK | MBF_CRASH);
}

/** Called by windows if an exception happens. */
LONG CALLBACK ExceptionHandler(LPEXCEPTION_POINTERS e)
{
    //stub method
}


/** Install crash handler. */
void Install()
{
    //stub method
}


/** Uninstall crash handler. */
void Remove()
{
    //stub method
}

}; // namespace CrashHandler
