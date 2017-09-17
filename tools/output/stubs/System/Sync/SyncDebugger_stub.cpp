#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#ifdef SYNCDEBUG

#include "SyncDebugger.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/Players/Player.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Log/ILog.h"
#include "Net/Protocol/NetProtocol.h"

#include "HsiehHash.h"
#include "Logger.h"
#include "SyncTracer.h"

#include <string.h>
#include <map>

#ifndef WIN32
	/* for backtrace() function */
	#include <execinfo.h>
	#define HAVE_BACKTRACE
#elif defined __MINGW32__ || defined _MSC_VER
	/* from backtrace.c: */
	extern "C" int backtrace(void** array, int size);
	#define HAVE_BACKTRACE
#else
	#undef HAVE_BACKTRACE
#endif


#define LOGFILE_SERVER "syncdebug-server.log"
#define LOGFILE_CLIENT "syncdebug-client.log"


#define LOG_SECTION_SYNC_DEBUGGER "SD"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_SYNC_DEBUGGER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_SYNC_DEBUGGER



/**
 * @brief logging instance
 */
static CLogger logger;


CSyncDebugger* CSyncDebugger::GetInstance() {
	static CSyncDebugger instance;
	return &instance;
}


CSyncDebugger::CSyncDebugger()
	: history(NULL)
	, historybt(NULL)
	, historyIndex(0)
	, disable_history(false)
	, may_enable_history(false)
	, flop(0)
	, waitingForBlockResponse(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CSyncDebugger::~CSyncDebugger()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::Initialize(bool useBacktrace, unsigned numPlayers)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::Sync(const void* p, unsigned size, const char* op)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::Backtrace(int index, const char* prefix) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned CSyncDebugger::GetBacktraceChecksum(int index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncDebugger::ServerReceived(const unsigned char* inbuf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncDebugger::ClientReceived(const unsigned char* inbuf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::ServerTriggerSyncErrorHandling(int serverframenum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::ClientSendChecksumResponse()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::ServerQueueBlockRequests()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::ServerHandlePendingBlockRequests()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::ClientSendBlockResponse(int block)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::ServerReceivedBlockResponses()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::ServerDumpStack()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSyncDebugger::Reset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#endif // SYNCDEBUG
