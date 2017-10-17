#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Threading.h"
#include "Game/GameController.h"
#include "System/ThreadPool.h"
#include "System/bitops.h"
#ifndef UNIT_TEST
#include "System/Config/ConfigHandler.h"
#endif
#include "System/Log/ILog.h"
#include "System/Platform/CpuID.h"
#include "System/Platform/CrashHandler.h"

#ifndef DEDICATED
#include "System/Sync/FPUCheck.h"
#endif

#include <boost/cstdint.hpp>
#include <boost/thread.hpp>
#include <boost/version.hpp>
#include <memory>
#if defined(__APPLE__) || defined(__FreeBSD__)
#elif defined(WIN32)
#include <windows.h>
#else
#if defined(__USE_GNU)
#include <sys/prctl.h>
#endif
#include <sched.h>
#endif

#ifndef UNIT_TEST
CONFIG(int, WorkerThreadCount)
  .defaultValue(-1)
  .safemodeValue(0)
  .minimumValue(-1)
  .description("Count of worker threads (including mainthread!) used in "
               "parallel sections.");
CONFIG(int, WorkerThreadSpinTime)
  .defaultValue(5)
  .minimumValue(0)
  .description("The number of milliseconds worker threads will spin after no "
               "tasks to perform.");
#endif

namespace Threading {
static std::shared_ptr<Error> threadError;

static bool haveMainThreadID = false;
static bool haveGameLoadThreadID = false;
static bool haveWatchDogThreadID = false;

static NativeThreadId nativeMainThreadID;
static NativeThreadId nativeGameLoadThreadID;
static NativeThreadId nativeWatchDogThreadID;

boost::thread_specific_ptr<std::shared_ptr<Threading::ThreadControls>>
  threadCtls;

#if defined(__APPLE__) || defined(__FreeBSD__)
#elif defined(WIN32)
static DWORD_PTR cpusSystem = 0;
#else
static cpu_set_t cpusSystem;
#endif

void
DetectCores()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::uint32_t
GetAffinity()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::uint32_t
SetAffinity(boost::uint32_t cores_bitmask, bool hard)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SetAffinityHelper(const char* threadName, boost::uint32_t affinity)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::uint32_t
GetAvailableCoresMask()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static boost::uint32_t
GetCpuCoreForWorkerThread(int index,
                          boost::uint32_t availCores,
                          boost::uint32_t avoidCores)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
GetLogicalCpuCores()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** Function that returns the number of real cpu cores (not
    hyperthreading ones). These are the total cores in the system
    (across all existing processors, if more than one)*/
int
GetPhysicalCpuCores()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
HasHyperThreading()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
InitThreadPool()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SetThreadScheduler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

NativeThreadHandle
GetCurrentThread()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

NativeThreadId
GetCurrentThreadId()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

ThreadControls::ThreadControls()
  : handle(0)
  , running(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::shared_ptr<ThreadControls>
GetCurrentThreadControls()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

boost::thread
CreateNewThread(boost::function<void()> taskFunc,
                std::shared_ptr<Threading::ThreadControls>* ppCtlsReturn)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SetMainThread()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
IsMainThread()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
IsMainThread(NativeThreadId threadID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SetGameLoadThread()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
IsGameLoadThread()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
IsGameLoadThread(NativeThreadId threadID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SetWatchDogThread()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
IsWatchDogThread()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
IsWatchDogThread(NativeThreadId threadID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SetThreadName(const std::string& newname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SetThreadError(const Error& err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
Error*
GetThreadError()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
