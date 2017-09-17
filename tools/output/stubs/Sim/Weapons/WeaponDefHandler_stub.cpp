/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>
#include "WeaponDefHandler.h"

#include "Lua/LuaParser.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "System/Exceptions.h"
#include "System/Util.h"
#include "System/Log/ILog.h"


CWeaponDefHandler* weaponDefHandler = NULL;


CWeaponDefHandler::CWeaponDefHandler(LuaParser* defsParser)
{
    //stub method
}


CWeaponDefHandler::~CWeaponDefHandler()
{
    //stub method
}



const WeaponDef* CWeaponDefHandler::GetWeaponDef(std::string weaponname) const
{
    //stub method
}


const WeaponDef* CWeaponDefHandler::GetWeaponDefByID(int weaponDefId) const
{
    //stub method
}
