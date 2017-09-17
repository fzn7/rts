#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#ifdef TRACE_SYNC

#include "SyncTracer.h"
#include "System/Log/ILog.h"

#include <cstdio>

CSyncTracer tracefile;

void CSyncTracer::Initialize(int playerIndex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif // TRACE_SYNC
