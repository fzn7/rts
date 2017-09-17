/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "CobEngine.h"
#include "CobThread.h"
#include "CobInstance.h"
#include "CobFile.h"
#include "System/FileSystem/FileHandler.h"
#include "System/TimeProfiler.h"


CCobEngine* cobEngine = nullptr;
CCobFileHandler* cobFileHandler = nullptr;


/******************************************************************************/
/******************************************************************************/

CR_BIND(CCobEngine, )

CR_REG_METADATA(CCobEngine, (
	CR_MEMBER(currentTime),
	CR_MEMBER(running),
	CR_MEMBER(sleeping),

	//always null/empty when saving
	CR_IGNORED(wantToRun),
	CR_IGNORED(curThread)
))


CCobEngine::CCobEngine()
	: curThread(nullptr)
	, currentTime(0)

{
    //stub method
}


CCobFileHandler::~CCobFileHandler()
{
    //stub method
}


//A thread wants to continue running at a later time, and adds itself to the scheduler
void CCobEngine::AddThread(CCobThread *thread)
{
    //stub method
}


void CCobEngine::TickThread(CCobThread* thread)
{
    //stub method
}


void CCobEngine::Tick(int deltaTime)
{
    //stub method
}


void CCobEngine::ShowScriptError(const string& msg)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

CCobFile* CCobFileHandler::GetCobFile(const string& name)
{
    //stub method
}


CCobFile* CCobFileHandler::ReloadCobFile(const string& name)
{
    //stub method
}


const CCobFile* CCobFileHandler::GetScriptAddr(const string& name) const
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
