/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaSyncedMoveCtrl.h"

#include "LuaInclude.h"

#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaUtils.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/ScriptMoveType.h"
#include "Sim/MoveTypes/GroundMoveType.h"
#include "Sim/MoveTypes/AAirMoveType.h"
#include "Sim/MoveTypes/StrafeAirMoveType.h"
#include "Sim/MoveTypes/HoverAirMoveType.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "System/myMath.h"
#include "System/Log/ILog.h"
#include "System/Sync/HsiehHash.h"

#include <cctype>


/******************************************************************************/
/******************************************************************************/


bool LuaSyncedMoveCtrl::PushMoveCtrl(lua_State* L)
{
    //stub method
}




static inline CUnit* ParseUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}


static inline CScriptMoveType* ParseScriptMoveType(lua_State* L, const char* caller, int index)
{
    //stub method
}

template<typename DerivedMoveType>
static inline DerivedMoveType* ParseDerivedMoveType(lua_State* L, const char* caller, int index)
{
    //stub method
}



/******************************************************************************/
/******************************************************************************/

int LuaSyncedMoveCtrl::IsEnabled(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::Enable(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::Disable(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedMoveCtrl::SetTag(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::GetTag(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaSyncedMoveCtrl::SetProgressState(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedMoveCtrl::SetExtrapolate(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedMoveCtrl::SetPhysics(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetPosition(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetVelocity(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetRelativeVelocity(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetRotation(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetRotationOffset(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetRotationVelocity(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetHeading(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedMoveCtrl::SetTrackSlope(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetTrackGround(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetGroundOffset(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetGravity(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetDrag(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetWindFactor(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetLimits(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedMoveCtrl::SetNoBlocking(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetShotStop(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetSlopeStop(lua_State* L)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetCollideStop(lua_State* L)
{
    //stub method
}



/******************************************************************************/
/* MoveType member-value handling */

template<typename value_type>
static bool SetMoveTypeValue(AMoveType* mt, const string& key, value_type value)
{
    //stub method
}

static inline bool SetMoveTypeValue(lua_State* L, AMoveType* moveType, int keyIdx, int valIdx)
{
    //stub method
}


static int SetMoveTypeData(lua_State* L, AMoveType* moveType, const char* caller)
{
    //stub method
}


int LuaSyncedMoveCtrl::SetGunshipMoveTypeData(lua_State* L)
{
    //stub method
}

int LuaSyncedMoveCtrl::SetAirMoveTypeData(lua_State* L)
{
    //stub method
}

int LuaSyncedMoveCtrl::SetGroundMoveTypeData(lua_State* L)
{
    //stub method
}



/******************************************************************************/
/******************************************************************************/

int LuaSyncedMoveCtrl::SetMoveDef(lua_State* L)
{
    //stub method
}

