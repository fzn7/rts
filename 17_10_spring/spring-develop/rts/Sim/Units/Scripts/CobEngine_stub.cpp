#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CobEngine.h"
#include "CobFile.h"
#include "CobInstance.h"
#include "CobThread.h"
#include "System/FileSystem/FileHandler.h"
#include "System/TimeProfiler.h"

CCobEngine* cobEngine = nullptr;
CCobFileHandler* cobFileHandler = nullptr;

/******************************************************************************/
/******************************************************************************/

CR_BIND(CCobEngine, )

CR_REG_METADATA(CCobEngine,
                (CR_MEMBER(currentTime),
                 CR_MEMBER(running),
                 CR_MEMBER(sleeping),

                 // always null/empty when saving
                 CR_IGNORED(wantToRun),
                 CR_IGNORED(curThread)))

CCobEngine::CCobEngine()
  : curThread(nullptr)
  , currentTime(0)

{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CCobFileHandler::~CCobFileHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// A thread wants to continue running at a later time, and adds itself to the
// scheduler
void
CCobEngine::AddThread(CCobThread* thread)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCobEngine::TickThread(CCobThread* thread)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCobEngine::Tick(int deltaTime)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CCobEngine::ShowScriptError(const string& msg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

CCobFile*
CCobFileHandler::GetCobFile(const string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CCobFile*
CCobFileHandler::ReloadCobFile(const string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const CCobFile*
CCobFileHandler::GetScriptAddr(const string& name) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
