#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AIScriptHandler.h"

#include "ExternalAI/Interface/aidefines.h"
#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/SkirmishAIKey.h"

#include <stdexcept>

CAIScriptHandler& CAIScriptHandler::Instance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CAIScriptHandler::IsSkirmishAITestScript(const std::string& scriptName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const SkirmishAIData& CAIScriptHandler::GetSkirmishAIData(const std::string& scriptName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CAIScriptHandler::Add(CScript* script)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CAIScriptHandler::CAIScriptHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CAIScriptHandler::~CAIScriptHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
