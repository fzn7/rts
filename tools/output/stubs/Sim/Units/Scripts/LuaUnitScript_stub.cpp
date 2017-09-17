#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#define LUA_SYNCED_ONLY

#include <sstream>
#include "LuaUnitScript.h"

#include "CobInstance.h"
#include "LuaInclude.h"
#include "NullUnitScript.h"
#include "LuaScriptNames.h"
#include "Lua/LuaConfig.h"
#include "Lua/LuaCallInCheck.h"
#include "Lua/LuaHandleSynced.h"
#include "Lua/LuaUtils.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/PlasmaRepulser.h"


using std::map;
using std::pair;
using std::string;
using std::vector;

static inline LocalModelPiece* ParseLocalModelPiece(lua_State* L, CUnitScript* script, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline int ToLua(lua_State* L, const float3& v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*

some notes:
- all piece numbers are 1 based, to be consistent with other parts of interface
- all axes are 1 based, so 1 = x, 2 = y, 3 = z
- destination, speed for Move are in world coords, and NOT in COB coords
- therefore, compared to COB, the X axis for the Move callout is mirrored
- destination, speed, accel, decel for Turn, Spin, StopSpin are in radians
- GetUnitCOBValue(PLAY_SOUND, ...) does NOT work for Lua unit scripts,
  use Spring.PlaySound instead (synced code can call unsynced funcs!).
- Because in current design CBCobThreadFinish can impossibly be called, certain
  state changes which normally happen immediately when script returns should
  be triggered through a call to a callOut when using Lua scripts.
  This applies to:
  * Spring.SetUnitShieldState(unitID, false|true) replaces return value 0|1 of
    COB's AimWeaponX function for plasma repulsers.
  * Spring.SetUnitWeaponState(unitID, weaponNum, "aimReady", 0|1) replaces
    return value 0|1 of COB's AimWeaponX function for all other weapons.
  * Spring.UnitScript.SetDeathScriptFinished(wreckLevel) replaces
    return value of wreckLevel from Killed function.
    This MUST be called, otherwise zombie units will eat your Spring!


callIn notes:
- Killed takes recentDamage,maxHealth instead of severity, to calculate
  severity use: 'local severity = recentDamage / maxHealth'
- SetMaxReloadTime doesn't exist, max reload time can be calculated in Lua
  (without the WTFs that are present in max reload time calculation for COB)
- RockUnit takes x,z instead of 500z,500x
- HitByWeapon takes x,z instead of 500z,500x
- HitByWeaponId takes x,z,weaponDefID,damage instead of 500z,500x,tdfID,damage
- HitByWeaponId returns the new damage, instead of a percentage of old damage
- QueryLandingPadCount doesn't exist
- QueryLandingPad should return an array (table) of all pieces
- BeginTransport and QueryTransport take unitID instead of unit->height*65536,
  use 'local height = Spring.GetUnitHeight(unitID)' to get the height.
- TransportDrop takes x,y,z instead of PACKXZ(x,z)
- AimWeapon for a shield (plasma repulser) takes no arguments instead of 0,0
- Shot takes no arguments instead of 0
- new callins MoveFinished and TurnFinished, see below


docs for callins defined in this file:

  TODO: document other callins properly

TurnFinished(number piece, number axis)
	Called after a turn finished for this unit/piece/axis (not a turn-now!)
	Should resume coroutine of the particular thread which called the Lua
	WaitForTurn function (see below).

MoveFinished(number piece, number axis)
	Called after a move finished for this unit/piece/axis (not a move-now!)
	Should resume coroutine of the particular thread which called the Lua
	WaitForMove function (see below).


docs for callouts defined in this file:

Spring.UnitScript.SetUnitValue(...)
	see wiki for Spring.SetUnitCOBValue (unchanged)

Spring.UnitScript.GetUnitValue(...)
	see wiki for Spring.GetUnitCOBValue (unchanged)

Spring.UnitScript.SetPieceVisibility(number piece, boolean visible) -> nil
	Set's piece visibility.  Same as COB's hide/show.

Spring.UnitSript.EmitSfx(number piece, number type) -> nil
	Same as COB's emit-sfx.

Spring.UnitScript.AttachUnit(number piece, number transporteeID) -> nil
	Same as COB's attach-unit.

Spring.UnitScript.DropUnit(number transporteeID) -> nil
	Same as COB's drop-unit.

Spring.UnitScript.Explode(number piece, number flags) -> nil
	Same as COB's explode.

Spring.UnitScript.ShowFlare(number piece) -> nil
	Same as COB's show _inside_ FireWeaponX.

Spring.UnitScript.Spin(number piece, number axis, number speed[, number accel]) -> nil
	Same as COB's spin.  If accel isn't given spinning starts at the desired speed.

Spring.UnitScript.StopSpin(number piece, number axis[, number decel]) -> nil
	Same as COB's stop-spin.  If decel isn't given spinning stops immediately.

Spring.UnitScript.Turn(number piece, number axis, number destination[, number speed]) -> nil
	Same as COB's turn iff speed is given and not zero, and turn-now otherwise.

Spring.UnitScript.Move(number piece, number axis, number destination[, number speed]) -> nil
	Same as COB's move iff speed is given and not zero, and move-now otherwise.

Spring.UnitScript.IsInTurn(number piece, number axis) -> boolean
Spring.UnitScript.IsInMove(number piece, number axis) -> boolean
Spring.UnitScript.IsInSpin(number piece, number axis) -> boolean
	Returns true iff such an animation exists, false otherwise.

Spring.UnitScript.WaitForTurn(number piece, number axis) -> boolean
	Returns true iff such an animation exists, false otherwise.  Iff it returns
	true, the TurnFinished callIn will be called once the turn completes.

Spring.UnitScript.WaitForMove(number piece, number axis) -> boolean
	Returns true iff such an animation exists, false otherwise.  Iff it returns
	true, the MoveFinished callIn will be called once the move completes.

Spring.UnitScript.SetDeathScriptFinished(number wreckLevel])
	Tells Spring the Killed script finished, and which wreckLevel to use.
	If wreckLevel is not given no wreck is created.

Spring.UnitScript.CreateScript(number unitID, table callIns) -> nil
	Replaces the current unit script (independent of type, also replaces COB)
	with the unit script given by a table of callins for the unit.
	Callins are similar to COB functions, e.g. a number of predefined names are
	called by the engine if they exist in the table.

Spring.UnitScript.UpdateCallIn(number unitID, string fname[, function callIn]) -> number|boolean
	Iff callIn is a function, a single callIn is replaced or added, and the
	new functionID is returned.  If callIn isn't given or is nil, the callIn is
	nilled, returns true if it was removed, or false if the callin didn't exist.
	See also Spring.UnitScript.CreateScript.
*/


#define LUA_TRACE(m) \
	do { \
		if (unit) { \
			LOG_L(L_DEBUG, "%s: %d: %s", __FUNCTION__, unit->id, m); \
		} else { \
			LOG_L(L_DEBUG, "%s: %s", __FUNCTION__, m); \
		} \
	} while (false)


CUnit* CLuaUnitScript::activeUnit;
CUnitScript* CLuaUnitScript::activeScript;


/******************************************************************************/
/******************************************************************************/


CLuaUnitScript::CLuaUnitScript(lua_State* L, CUnit* unit)
	: CNullUnitScript(unit)
	, handle(CLuaHandle::GetHandle(L)), L(L)
	, scriptIndex(LUAFN_Last, LUA_NOREF)
	, inKilled(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CLuaUnitScript::~CLuaUnitScript()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::HandleFreed(CLuaHandle* handle)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::UpdateCallIn()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::UpdateCallIn(const string& fname, int ref)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::RemoveCallIn(const string& fname)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::ShowScriptError(const string& msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUnitScript::HasBlockShot(int weaponNum) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUnitScript::HasTargetWeight(int weaponNum) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/


inline float CLuaUnitScript::PopNumber(int fn, float def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


inline bool CLuaUnitScript::PopBoolean(int fn, bool def)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


inline void CLuaUnitScript::RawPushFunction(int functionId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


inline void CLuaUnitScript::PushFunction(int id)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


inline void CLuaUnitScript::PushUnit(const CUnit* targetUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


inline bool CLuaUnitScript::RunCallIn(int id, int inArgs, int outArgs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::RunQueryCallIn(int fn)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::RunQueryCallIn(int fn, float arg1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::Call(int fn, float arg1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::Call(int fn, float arg1, float arg2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::Call(int fn, float arg1, float arg2, float arg3)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/


void CLuaUnitScript::Create()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::Killed()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::WindChanged(float heading, float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::ExtractionRateChanged(float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::RockUnit(const float3& rockDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::HitByWeapon(const float3& hitDir, int weaponDefId, float& inoutDamage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::SetSFXOccupy(int curTerrainType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::QueryLandingPads(std::vector<int>& out_pieces)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::BeginTransport(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::QueryTransport(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::TransportPickup(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::TransportDrop(const CUnit* unit, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::StartBuilding(float heading, float pitch)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::QueryNanoPiece()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::QueryBuildInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::QueryWeapon(int weaponNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::AimWeapon(int weaponNum, float heading, float pitch)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void  CLuaUnitScript::AimShieldWeapon(CPlasmaRepulser* weapon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::AimFromWeapon(int weaponNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::Shot(int weaponNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUnitScript::BlockShot(int weaponNum, const CUnit* targetUnit, bool userTarget)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float CLuaUnitScript::TargetWeight(int weaponNum, const CUnit* targetUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::AnimFinished(AnimType type, int piece, int axis)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::RawCall(int functionId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


string CLuaUnitScript::GetScriptName(int functionId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUnitScript::RawRunCallIn(int functionId, int inArgs, int outArgs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaUnitScript::Destroy() { Call(LUAFN_Destroy); }
void CLuaUnitScript::StartMoving(bool reversing) { Call(LUAFN_StartMoving, reversing * 1.0f); }
void CLuaUnitScript::StopMoving() { Call(LUAFN_StopMoving); }
void CLuaUnitScript::StartUnload() { Call(LUAFN_StartUnload); }
void CLuaUnitScript::EndTransport() { Call(LUAFN_EndTransport); }
void CLuaUnitScript::StartBuilding() { Call(LUAFN_StartBuilding); }
void CLuaUnitScript::StopBuilding() { Call(LUAFN_StopBuilding); }
void CLuaUnitScript::Falling() { Call(LUAFN_Falling); }
void CLuaUnitScript::Landed() { Call(LUAFN_Landed); }
void CLuaUnitScript::Activate() { Call(LUAFN_Activate); }
void CLuaUnitScript::Deactivate() { Call(LUAFN_Deactivate); }
void CLuaUnitScript::MoveRate(int curRate) { Call(LUAFN_MoveRate, curRate); }
void CLuaUnitScript::FireWeapon(int weaponNum) { Call(LUAFN_FireWeapon, weaponNum + LUA_WEAPON_BASE_INDEX); }
void CLuaUnitScript::EndBurst(int weaponNum) { Call(LUAFN_EndBurst, weaponNum + LUA_WEAPON_BASE_INDEX); }


/******************************************************************************/
/******************************************************************************/


static void PushEntry(lua_State* L, const char* name, lua_CFunction fun)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CLuaUnitScript::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
//  Parsing helpers
//

// FIXME: this badly needs a clean up, it's duplicated

static inline CUnit* ParseRawUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static inline CUnit* ParseUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static inline int ParseAxis(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/


int CLuaUnitScript::CreateScript(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::UpdateCallIn(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::CallAsUnit(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// moved from LuaSyncedCtrl

int CLuaUnitScript::GetUnitValue(lua_State* L, CUnitScript* script, int arg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::GetUnitCOBValue(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::GetUnitValue(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// moved from LuaSyncedCtrl

int CLuaUnitScript::SetUnitValue(lua_State* L, CUnitScript* script, int arg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::SetUnitCOBValue(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::SetUnitValue(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::SetPieceVisibility(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::EmitSfx(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::AttachUnit(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::DropUnit(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::Explode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::ShowFlare(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::Spin(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::StopSpin(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::Turn(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::Move(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::IsInAnimation(lua_State* L, const char* caller, AnimType type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::IsInTurn(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::IsInMove(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::IsInSpin(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::WaitForAnimation(lua_State* L, const char* caller, AnimType type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::WaitForTurn(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::WaitForMove(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::SetDeathScriptFinished(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int CLuaUnitScript::GetPieceTranslation(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::GetPieceRotation(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaUnitScript::GetPiecePosDir(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int CLuaUnitScript::GetActiveUnitID(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
