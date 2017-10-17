#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/thread/tss.hpp>
#include <fstream>
#include <pthread.h>
#include <signal.h>
#include <sys/syscall.h>
#include <unistd.h>

#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"

#define LOG_SECTION_CRASHHANDLER "CrashHandler"

// already registerd in CrashHandler.cpp
// LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_CRASHHANDLER);

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_CRASHHANDLER

namespace Threading {

enum LinuxThreadState
{
    LTS_RUNNING,
    LTS_SLEEP,
    LTS_DISK_SLEEP,
    LTS_STOPPED,
    LTS_PAGING,
    LTS_ZOMBIE,
    LTS_UNKNOWN
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

/**
 * This method requires at least a 2.6 kernel in order to access the file
 * /proc/<pid>/task/<tid>/status.
 *
 * @brief GetLinuxThreadState
 * @param handle
 * @return
 */
static LinuxThreadState
GetLinuxThreadState(int tid)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
ThreadSIGUSR1Handler(int signum, siginfo_t* info, void* pCtx)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static bool
SetThreadSignalHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SetCurrentThreadControls(bool isLoadThread)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief ThreadStart Entry point for wrapped pthread. Allows us to register
 * signal handlers specific to that thread, enabling suspend/resume
 * functionality.
 * @param ptr Points to a platform-specific ThreadControls object.
 */
void
ThreadStart(boost::function<void()> taskFunc,
            std::shared_ptr<ThreadControls>* ppCtlsReturn,
            ThreadControls* tempCtls)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SuspendResult
ThreadControls::Suspend()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SuspendResult
ThreadControls::Resume()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}
