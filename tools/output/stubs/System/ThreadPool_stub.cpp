#ifdef THREADPOOL

#include "ThreadPool.h"
#include "Exceptions.h"
#include "Platform/Threading.h"
#include "TimeProfiler.h"
#include "Util.h"
#if !defined(UNITSYNC) && !defined(UNIT_TEST)
	#include "OffscreenGLContext.h"
#endif

#include <deque>
#include <vector>
#include <utility>
#include <boost/optional.hpp>
#include <boost/thread.hpp>
#include <boost/thread/shared_mutex.hpp>

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

int GetThreadNum()
{
    //stub method
}

static void SetThreadNum(const int idx)
{
    //stub method
}


int GetMaxThreads()
{
    //stub method
}

int GetNumThreads()
{
    //stub method
}

bool HasThreads()
{
    //stub method
}


/// returns false, when no further tasks were found
static bool DoTask(boost::shared_lock<boost::shared_mutex>& lk_)
{
    //stub method
}


static bool DoTask(std::shared_ptr<ITaskGroup> tg)
{
    //stub method
}


__FORCE_ALIGN_STACK__
static void WorkerLoop(int id)
{
    //stub method
}


void WaitForFinished(std::shared_ptr<ITaskGroup> taskgroup)
{
    //stub method
}


void PushTaskGroup(std::shared_ptr<ITaskGroup> taskgroup)
{
    //stub method
}


void NotifyWorkerThreads()
{
    //stub method
}


void SetThreadCount(int num)
{
    //stub method
}

void SetThreadSpinTime(int milliSeconds)
{
    //stub method
}

}

#endif

