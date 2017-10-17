#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaAIImplHandler.h"

#include "ExternalAI/Interface/SSkirmishAILibrary.h"
#include "Lua/LuaParser.h"
//#include "ExternalAI/SkirmishAIKey.h"
#include "System/Exceptions.h"
#include "System/FileSystem/VFSHandler.h"

#include <assert.h>

// CR_BIND(CLuaAIImplHandler,);
//
// CR_REG_METADATA(CLuaAIImplHandler, (
//	CR_RESERVED(64)
//));

CLuaAIImplHandler&
CLuaAIImplHandler::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CLuaAIImplHandler::CLuaAIImplHandler() {}

CLuaAIImplHandler::~CLuaAIImplHandler() {}

std::vector<std::vector<InfoItem>>
CLuaAIImplHandler::LoadInfos()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
