#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaHandleSynced.h"

#include "LuaInclude.h"

#include "LuaUtils.h"
#include "LuaArchive.h"
#include "LuaCallInCheck.h"
#include "LuaConfig.h"
#include "LuaConstGL.h"
#include "LuaConstCMD.h"
#include "LuaConstCMDTYPE.h"
#include "LuaConstCOB.h"
#include "LuaConstGame.h"
#include "LuaInterCall.h"
#include "LuaSyncedCtrl.h"
#include "LuaSyncedRead.h"
#include "LuaSyncedTable.h"
#include "LuaUICommand.h"
#include "LuaUnsyncedCtrl.h"
#include "LuaUnsyncedRead.h"
#include "LuaFeatureDefs.h"
#include "LuaUnitDefs.h"
#include "LuaWeaponDefs.h"
#include "LuaScream.h"
#include "LuaOpenGL.h"
#include "LuaVFS.h"
#include "LuaZip.h"

#include "Game/Game.h"
#include "Game/WordCompletion.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/Scripts/CobInstance.h"
#include "Sim/Units/Scripts/LuaUnitScript.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileHandler.h"



LuaRulesParams::Params  CLuaHandleSynced::gameParams;



/******************************************************************************/
/******************************************************************************/
// ##     ## ##    ##  ######  ##    ## ##    ##  ######  ######## ########
// ##     ## ###   ## ##    ##  ##  ##  ###   ## ##    ## ##       ##     ##
// ##     ## ####  ## ##         ####   ####  ## ##       ##       ##     ##
// ##     ## ## ## ##  ######     ##    ## ## ## ##       ######   ##     ##
// ##     ## ##  ####       ##    ##    ##  #### ##       ##       ##     ##
// ##     ## ##   ### ##    ##    ##    ##   ### ##    ## ##       ##     ##
//  #######  ##    ##  ######     ##    ##    ##  ######  ######## ########

CUnsyncedLuaHandle::CUnsyncedLuaHandle(CLuaHandleSynced* _base, const string& _name, int _order)
	: CLuaHandle(_name, _order, false, false)
	, base(*_base)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CUnsyncedLuaHandle::~CUnsyncedLuaHandle()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnsyncedLuaHandle::Init(const string& code, const string& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


//
// Call-Ins
//

void CUnsyncedLuaHandle::RecvFromSynced(lua_State* srcState, int args)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnsyncedLuaHandle::DrawUnit(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnsyncedLuaHandle::DrawFeature(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnsyncedLuaHandle::DrawShield(const CUnit* unit, const CWeapon* weapon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CUnsyncedLuaHandle::DrawProjectile(const CProjectile* projectile)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


//
// Call-Outs
//


/******************************************************************************/
/******************************************************************************/
//  ######  ##    ## ##    ##  ######  ######## ########
// ##    ##  ##  ##  ###   ## ##    ## ##       ##     ##
// ##         ####   ####  ## ##       ##       ##     ##
//  ######     ##    ## ## ## ##       ######   ##     ##
//       ##    ##    ##  #### ##       ##       ##     ##
// ##    ##    ##    ##   ### ##    ## ##       ##     ##
//  ######     ##    ##    ##  ######  ######## ########

CSyncedLuaHandle::CSyncedLuaHandle(CLuaHandleSynced* _base, const string& _name, int _order)
	: CLuaHandle(_name, _order, false, true)
	, base(*_base)
	, origNextRef(-1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CSyncedLuaHandle::~CSyncedLuaHandle()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::Init(const string& code, const string& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


//
// Call-Ins
//

bool CSyncedLuaHandle::SyncedActionFallback(const string& msg, int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::CommandFallback(const CUnit* unit, const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowCommand(const CUnit* unit, const Command& cmd, bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowUnitCreation(const UnitDef* unitDef,
                                  const CUnit* builder, const BuildInfo* buildInfo)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CSyncedLuaHandle::AllowUnitTransfer(const CUnit* unit, int newTeam, bool capture)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowUnitBuildStep(const CUnit* builder,
                                   const CUnit* unit, float part)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowFeatureCreation(const FeatureDef* featureDef,
                                     int teamID, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowFeatureBuildStep(const CUnit* builder,
                                      const CFeature* feature, float part)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowResourceLevel(int teamID, const string& type, float level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowResourceTransfer(int oldTeam, int newTeam,
                                      const string& type, float amount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowDirectUnitControl(int playerID, const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowBuilderHoldFire(const CUnit* unit, int action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowStartPosition(int playerID, unsigned char readyState, const float3& clampedPos, const float3& rawPickPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::MoveCtrlNotify(const CUnit* unit, int data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::TerraformComplete(const CUnit* unit, const CUnit* build)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/**
 * called after every damage modification (even HitByWeaponId)
 * but before the damage is applied
 *
 * expects two numbers returned by lua code:
 * 1st is stored under *newDamage if newDamage != NULL
 * 2nd is stored under *impulseMult if impulseMult != NULL
 */
bool CSyncedLuaHandle::UnitPreDamaged(
	const CUnit* unit,
	const CUnit* attacker,
	float damage,
	int weaponDefID,
	int projectileID,
	bool paralyzer,
	float* newDamage,
	float* impulseMult)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CSyncedLuaHandle::FeaturePreDamaged(
	const CFeature* feature,
	const CUnit* attacker,
	float damage,
	int weaponDefID,
	int projectileID,
	float* newDamage,
	float* impulseMult)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CSyncedLuaHandle::ShieldPreDamaged(
	const CProjectile* projectile,
	const CWeapon* shieldEmitter,
	const CUnit* shieldCarrier,
	bool bounceProjectile,
	const CWeapon* beamEmitter,
	const CUnit* beamCarrier)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CSyncedLuaHandle::AllowWeaponTargetCheck(unsigned int attackerID, unsigned int attackerWeaponNum, unsigned int attackerWeaponDefID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowWeaponTarget(
	unsigned int attackerID,
	unsigned int targetID,
	unsigned int attackerWeaponNum,
	unsigned int attackerWeaponDefID,
	float* targetPriority)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSyncedLuaHandle::AllowWeaponInterceptTarget(
	const CUnit* interceptorUnit,
	const CWeapon* interceptorWeapon,
	const CProjectile* interceptorTarget
) {
	bool ret = true;

	if (!watchWeaponDefs[interceptorWeapon->weaponDef->id])
		return ret;

	LUA_CALL_IN_CHECK(L, true);
	luaL_checkstack(L, 2 + 3 + 1, __func__);
	const LuaUtils::ScopedDebugTraceBack traceBack(L);

	static const LuaHashString cmdStr(__func__);
	if (!cmdStr.GetGlobalFunc(L))
		return ret;

	lua_pushnumber(L, interceptorUnit->id);
	lua_pushnumber(L, interceptorWeapon->weaponNum + LUA_WEAPON_BASE_INDEX);
	lua_pushnumber(L, interceptorTarget->id);

	if (!RunCallInTraceback(L, cmdStr, 3, 1, traceBack.GetErrFuncIdx(), false))
		return ret;

	ret = luaL_optboolean(L, -1, false);
	lua_pop(L, 1);
	return ret;
}


//
// Call-Outs
//

int CSyncedLuaHandle::SyncedRandom(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CSyncedLuaHandle::SyncedRandomSeed(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CSyncedLuaHandle::SyncedNext(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CSyncedLuaHandle::SyncedPairs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CSyncedLuaHandle::SendToUnsynced(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CSyncedLuaHandle::AddSyncedActionFallback(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CSyncedLuaHandle::RemoveSyncedActionFallback(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


#define GetWatchDef(DefType)                                          \
	int CSyncedLuaHandle::GetWatch ## DefType ## Def(lua_State* L) {  \
		CSyncedLuaHandle* lhs = GetSyncedHandle(L);                   \
		const unsigned int defID = luaL_checkint(L, 1);               \
		if (defID >= lhs->watch ## DefType ## Defs.size()) {          \
			return 0;                                                 \
		}                                                             \
		lua_pushboolean(L, lhs->watch ## DefType ## Defs[defID]);     \
		return 1;                                                     \
	}

#define SetWatchDef(DefType)                                          \
	int CSyncedLuaHandle::SetWatch ## DefType ## Def(lua_State* L) {  \
		CSyncedLuaHandle* lhs = GetSyncedHandle(L);                   \
		const unsigned int defID = luaL_checkint(L, 1);               \
		if (defID >= lhs->watch ## DefType ## Defs.size()) {          \
			return 0;                                                 \
		}                                                             \
		lhs->watch ## DefType ## Defs[defID] = luaL_checkboolean(L, 2);   \
		return 0;                                                     \
	}

GetWatchDef(Unit)
GetWatchDef(Feature)
GetWatchDef(Weapon)

SetWatchDef(Unit)
SetWatchDef(Feature)
SetWatchDef(Weapon)

#undef GetWatchDef
#undef SetWatchDef


/******************************************************************************/
/******************************************************************************/
//  ######  ##     ##    ###    ########  ######## ########
// ##    ## ##     ##   ## ##   ##     ## ##       ##     ##
// ##       ##     ##  ##   ##  ##     ## ##       ##     ##
//  ######  ######### ##     ## ########  ######   ##     ##
//       ## ##     ## ######### ##   ##   ##       ##     ##
// ##    ## ##     ## ##     ## ##    ##  ##       ##     ##
//  ######  ##     ## ##     ## ##     ## ######## ########

CLuaHandleSynced::CLuaHandleSynced(const string& _name, int _order)
	: syncedLuaHandle(this, _name, _order)
	, unsyncedLuaHandle(this, _name, _order + 1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CLuaHandleSynced::~CLuaHandleSynced()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CLuaHandleSynced::Init(const string& syncedFile, const string& unsyncedFile, const string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


string CLuaHandleSynced::LoadFile(const string& filename, const string& modes) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//
// Call-Outs
//

int CLuaHandleSynced::LoadStringData(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CLuaHandleSynced::CallAsTeam(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/
/******************************************************************************/
