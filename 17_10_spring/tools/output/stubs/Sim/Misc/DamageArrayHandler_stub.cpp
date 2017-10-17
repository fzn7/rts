#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <cctype>
#include <locale>
#include <string>
#include <vector>

#include "DamageArrayHandler.h"
#include "Game/GameVersion.h"
#include "Lua/LuaParser.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/creg/STL_Map.h"

CR_BIND(CDamageArrayHandler, (NULL))

CR_REG_METADATA(CDamageArrayHandler,
                (CR_MEMBER(armorDefNameIdxMap), CR_MEMBER(armorDefKeys)))

CDamageArrayHandler* damageArrayHandler;

CDamageArrayHandler::CDamageArrayHandler(LuaParser* defsParser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CDamageArrayHandler::GetTypeFromName(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
