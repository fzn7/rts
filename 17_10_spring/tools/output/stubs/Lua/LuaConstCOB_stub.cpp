#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/* exports the #defines from CobDefines.h to Lua */

#include "LuaConstCOB.h"
#include "LuaInclude.h"
#include "LuaUtils.h"
#include "Sim/Projectiles/PieceProjectile.h"
#include "Sim/Units/Scripts/CobDefines.h"

/******************************************************************************/
/******************************************************************************/

bool
LuaConstCOB::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
LuaConstSFX::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
