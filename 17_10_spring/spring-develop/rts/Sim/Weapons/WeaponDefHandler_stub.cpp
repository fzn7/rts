/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "WeaponDefHandler.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>

#include "Lua/LuaParser.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

CWeaponDefHandler* weaponDefHandler = NULL;

CWeaponDefHandler::CWeaponDefHandler(LuaParser* defsParser)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CWeaponDefHandler::~CWeaponDefHandler() {}

const WeaponDef*
CWeaponDefHandler::GetWeaponDef(std::string weaponname) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const WeaponDef*
CWeaponDefHandler::GetWeaponDefByID(int weaponDefId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
