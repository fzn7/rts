/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <algorithm>
#include <locale>
#include <string>
#include <vector>
#include <cctype>

#include "DamageArrayHandler.h"
#include "Game/GameVersion.h"
#include "Lua/LuaParser.h"
#include "System/creg/STL_Map.h"
#include "System/Log/ILog.h"
#include "System/Exceptions.h"
#include "System/Util.h"


CR_BIND(CDamageArrayHandler, (NULL))

CR_REG_METADATA(CDamageArrayHandler, (
	CR_MEMBER(armorDefNameIdxMap),
	CR_MEMBER(armorDefKeys)
))


CDamageArrayHandler* damageArrayHandler;


CDamageArrayHandler::CDamageArrayHandler(LuaParser* defsParser)
{
    //stub method
}



int CDamageArrayHandler::GetTypeFromName(const std::string& name) const
{
    //stub method
}

