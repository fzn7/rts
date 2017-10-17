#include <iostream>
#ifdef THREADPOOL

#include "ThreadPool.h"
#include "Exceptions.h"
#include "Platform/Threading.h"
#include "TimeProfiler.h"
#include "Util.h"
#if !defined(UNITSYNC) && !defined(UNIT_TEST)
#include "OffscreenGLContext.h"
#endif

#include <boost/optional.hpp>
#include <boost/thread.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <deque>
#include <utility>
#include <vector>

static std::deque<std::shared_ptr<ITaskGroup>> taskGroups;
static std::deque<void*> thread_group;

static boost::shared_mutex taskMutex;
static boost::condition_variable newTasks;
static std::atomic<bool> waitForLock(false);

#if !defined(UNITSYNC) && !defined(UNIT_TEST)
static bool hasOGLthreads = false; // disable for now (not used atm)
#else
static bool hasOGLthreads = false;
#endif
#if defined(_MSC_VER)
static __declspec(thread) int threadnum(0);
static __declspec(thread) bool exitThread(false);
#else
static __thread int threadnum(0);
static __thread bool exitThread(false);
#endif

static int spinlockMs = 5;

namespace ThreadPool {

int
GetThreadNum()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
SetThreadNum(const int idx)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
GetMaxThreads()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
GetNumThreads()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
HasThreads()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/// returns false, when no further tasks were found
static bool
DoTask(boost::shared_lock<boost::shared_mutex>& lk_)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static bool
DoTask(std::shared_ptr<ITaskGroup> tg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

__FORCE_ALIGN_STACK__
static void
WorkerLoop(int id)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
WaitForFinished(std::shared_ptr<ITaskGroup> taskgroup)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
PushTaskGroup(std::shared_ptr<ITaskGroup> taskgroup)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
NotifyWorkerThreads()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SetThreadCount(int num)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
SetThreadSpinTime(int milliSeconds)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
}

#endif
