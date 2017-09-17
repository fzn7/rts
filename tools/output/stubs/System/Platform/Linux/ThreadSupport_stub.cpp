#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <fstream>
#include <sys/syscall.h>
#include <boost/thread/tss.hpp>

#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"


#define LOG_SECTION_CRASHHANDLER "CrashHandler"


// already registerd in CrashHandler.cpp
//LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_CRASHHANDLER);

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
        #undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_CRASHHANDLER


namespace Threading {


enum LinuxThreadState {
	LTS_RUNNING,
	LTS_SLEEP,
	LTS_DISK_SLEEP,
	LTS_STOPPED,
	LTS_PAGING,
	LTS_ZOMBIE,
	LTS_UNKNOWN
};

/**
 * There is no glibc wrapper for this system call, so you have to write one:
 */
static int gettid () {
	long tid = syscall(SYS_gettid);
	return tid;
}

/**
 * This method requires at least a 2.6 kernel in order to access the file /proc/<pid>/task/<tid>/status.
 *
 * @brief GetLinuxThreadState
 * @param handle
 * @return
 */
static LinuxThreadState GetLinuxThreadState(int tid)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void ThreadSIGUSR1Handler(int signum, siginfo_t* info, void* pCtx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool SetThreadSignalHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void SetCurrentThreadControls(bool isLoadThread)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * @brief ThreadStart Entry point for wrapped pthread. Allows us to register signal handlers specific to that thread, enabling suspend/resume functionality.
 * @param ptr Points to a platform-specific ThreadControls object.
 */
void ThreadStart(
	boost::function<void()> taskFunc,
	std::shared_ptr<ThreadControls>* ppCtlsReturn,
	ThreadControls* tempCtls
) {
	// Install the SIGUSR1 handler
	SetCurrentThreadControls(false);

	auto ppThreadCtls = threadCtls.get(); // std::shared_ptr<Threading::ThreadControls>*
	auto pThreadCtls = ppThreadCtls->get(); // Threading::ThreadControls*

	assert(ppThreadCtls != nullptr);
	assert(pThreadCtls != nullptr);

	if (ppCtlsReturn != nullptr)
		*ppCtlsReturn = *ppThreadCtls;

	{
		// Lock the thread object so that users can't suspend/resume yet.
		tempCtls->mutSuspend.lock();

		LOG_L(L_DEBUG, "ThreadStart(): New thread's handle is %.4lx", pThreadCtls->handle);

		// We are fully initialized, so notify the condition variable. The
		// thread's parent will unblock in whatever function created this
		// thread.
		tempCtls->condInitialized.notify_all();

		// Ok, the thread should be ready to run its task now, so unlock the suspend mutex!
		tempCtls->mutSuspend.unlock();
	}

	// Run the task function...
	taskFunc();

	// Finish up: change the thread's running state to false.
	pThreadCtls->mutSuspend.lock();
	pThreadCtls->running = false;
	pThreadCtls->mutSuspend.unlock();
}



SuspendResult ThreadControls::Suspend()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SuspendResult ThreadControls::Resume()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

}
