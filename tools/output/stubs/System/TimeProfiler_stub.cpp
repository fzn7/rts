#include <iostream>
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
    std::cout << _FUNCTION_ << std::endl;
}

static unsigned hash_(const char* s)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


BasicTimer::BasicTimer(const std::string& myname)
: hash(hash_(myname))
, starttime(spring_gettime())

{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


BasicTimer::BasicTimer(const char* myname)
: hash(hash_(myname))
, starttime(spring_gettime())

{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::string& BasicTimer::GetName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


spring_time BasicTimer::GetDuration() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


ScopedTimer::ScopedTimer(const std::string& name, bool autoShow)
	: BasicTimer(name)
	, autoShowGraph(autoShow)

{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


ScopedTimer::ScopedTimer(const char* name, bool autoShow)
	: BasicTimer(name)
	, autoShowGraph(autoShow)

{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


ScopedTimer::~ScopedTimer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

ScopedOnceTimer::~ScopedOnceTimer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



ScopedMtTimer::ScopedMtTimer(const std::string& name, bool autoShow)
	: BasicTimer(name)
	, autoShowGraph(autoShow)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


ScopedMtTimer::ScopedMtTimer(const char* name, bool autoShow)
	: BasicTimer(name)
	, autoShowGraph(autoShow)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


ScopedMtTimer::~ScopedMtTimer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTimeProfiler::CTimeProfiler():
	lastBigUpdate(spring_gettime()),
	currentPosition(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CTimeProfiler::~CTimeProfiler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CTimeProfiler& CTimeProfiler::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CTimeProfiler::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float CTimeProfiler::GetPercent(const char* name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CTimeProfiler::AddTime(const std::string& name, const spring_time time, const bool showGraph)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CTimeProfiler::PrintProfilingInfo() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
