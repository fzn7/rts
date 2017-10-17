#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SpringTime.h"
#include "System/maindefines.h"
#include "System/myMath.h"

#include <boost/thread/mutex.hpp>

#ifndef UNIT_TEST
#ifdef USING_CREG
#include "System/creg/Serializer.h"

// FIXME always use class even in non-debug! for creg!
CR_BIND(spring_time, )
CR_REG_METADATA(spring_time, (CR_IGNORED(x), CR_SERIALIZER(Serialize)))
#endif
#endif

// mingw doesn't support std::this_thread (yet?)
#if defined(__MINGW32__) || defined(SPRINGTIME_USING_BOOST)
#undef gt
#include <boost/thread/thread.hpp>
namespace this_thread {
using namespace boost::this_thread;
};
#else
#define SPRINGTIME_USING_STD_SLEEP
#ifdef _GLIBCXX_USE_SCHED_YIELD
#undef _GLIBCXX_USE_SCHED_YIELD
#endif
#define _GLIBCXX_USE_SCHED_YIELD // workaround a gcc <4.8 bug
#include <thread>
#include <mutex>
namespace this_thread {
using namespace std::this_thread;
}
#endif

#define USE_NATIVE_WINDOWS_CLOCK                                               \
    (defined(WIN32) && !defined(FORCE_CHRONO_TIMERS))
#if USE_NATIVE_WINDOWS_CLOCK
#include <windows.h>
#endif

namespace spring_clock {
static bool highResMode = false;
static bool timerInited = false;

void
PushTickRate(bool b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
PopTickRate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if USE_NATIVE_WINDOWS_CLOCK
// QPC wants the LARGE_INTEGER's to be qword-aligned
__FORCE_ALIGN_STACK__
boost::int64_t
GetTicksNative()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

boost::int64_t
GetTicks()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
GetName()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}

boost::int64_t spring_time::xs = 0;

static float avgThreadYieldTimeMilliSecs = 0.0f;
static float avgThreadSleepTimeMilliSecs = 0.0f;

static boost::mutex yieldTimeMutex;
static boost::mutex sleepTimeMutex;

static void
thread_yield()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
spring_time::sleep()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
spring_time::sleep_until()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#if defined USING_CREG && !defined UNIT_TEST
void
spring_time::Serialize(creg::ISerializer* s)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif
