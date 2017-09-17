/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/TimeProfiler.h"

#include <cstring>
#include <boost/unordered_map.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

#include "System/Log/ILog.h"
#include "System/UnsyncedRNG.h"
#ifdef THREADPOOL
	#include "System/ThreadPool.h"
#endif

static boost::mutex m;
static std::map<int, std::string> hashToName;
static std::map<int, int> refs;



static unsigned hash_(const std::string& s)
{
    //stub method
}

static unsigned hash_(const char* s)
{
    //stub method
}


BasicTimer::BasicTimer(const std::string& myname)
: hash(hash_(myname))
, starttime(spring_gettime())

{
    //stub method
}


BasicTimer::BasicTimer(const char* myname)
: hash(hash_(myname))
, starttime(spring_gettime())

{
    //stub method
}


const std::string& BasicTimer::GetName() const
{
    //stub method
}


spring_time BasicTimer::GetDuration() const
{
    //stub method
}


ScopedTimer::ScopedTimer(const std::string& name, bool autoShow)
	: BasicTimer(name)
	, autoShowGraph(autoShow)

{
    //stub method
}


ScopedTimer::ScopedTimer(const char* name, bool autoShow)
	: BasicTimer(name)
	, autoShowGraph(autoShow)

{
    //stub method
}


ScopedTimer::~ScopedTimer()
{
    //stub method
}

ScopedOnceTimer::~ScopedOnceTimer()
{
    //stub method
}



ScopedMtTimer::ScopedMtTimer(const std::string& name, bool autoShow)
	: BasicTimer(name)
	, autoShowGraph(autoShow)
{
    //stub method
}


ScopedMtTimer::ScopedMtTimer(const char* name, bool autoShow)
	: BasicTimer(name)
	, autoShowGraph(autoShow)
{
    //stub method
}


ScopedMtTimer::~ScopedMtTimer()
{
    //stub method
}



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTimeProfiler::CTimeProfiler():
	lastBigUpdate(spring_gettime()),
	currentPosition(0)
{
    //stub method
}

CTimeProfiler::~CTimeProfiler()
{
    //stub method
}

CTimeProfiler& CTimeProfiler::GetInstance()
{
    //stub method
}

void CTimeProfiler::Update()
{
    //stub method
}

float CTimeProfiler::GetPercent(const char* name)
{
    //stub method
}

void CTimeProfiler::AddTime(const std::string& name, const spring_time time, const bool showGraph)
{
    //stub method
}

void CTimeProfiler::PrintProfilingInfo() const
{
    //stub method
}
