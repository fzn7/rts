#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/* heavily based on CobEngine.cpp */

#include "UnitScriptEngine.h"

#include "CobEngine.h"
#include "UnitScript.h"
#include "System/Util.h"
#include "System/FileSystem/FileHandler.h"

#ifndef _CONSOLE
	#include "System/TimeProfiler.h"
#else
	#define START_TIME_PROFILE(a) {}
	#define END_TIME_PROFILE(a) {}
	#define SCOPED_TIMER(a) {}
#endif
CUnitScriptEngine* unitScriptEngine = nullptr;


CR_BIND(CUnitScriptEngine, )

CR_REG_METADATA(CUnitScriptEngine, (
	CR_MEMBER(animating),

	//always null when saving
	CR_IGNORED(currentScript)
))


void CUnitScriptEngine::InitStatic() {
	cobEngine = new CCobEngine();
	cobFileHandler = new CCobFileHandler();
	unitScriptEngine = new CUnitScriptEngine();
}
void CUnitScriptEngine::KillStatic() {
	SafeDelete(cobEngine);
	SafeDelete(cobFileHandler);
	SafeDelete(unitScriptEngine);
}


/******************************************************************************/
/******************************************************************************/


CUnitScriptEngine::CUnitScriptEngine() : currentScript(nullptr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CUnitScriptEngine::~CUnitScriptEngine()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitScriptEngine::CheckForDuplicates(const char* name, const CUnitScript* instance)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitScriptEngine::AddInstance(CUnitScript *instance)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitScriptEngine::RemoveInstance(CUnitScript *instance)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CUnitScriptEngine::Tick(int deltaTime)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
