/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaSyncedRead.h"

#include "LuaInclude.h"

#include "LuaConfig.h"
#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaMetalMap.h"
#include "LuaPathFinder.h"
#include "LuaRules.h"
#include "LuaRulesParams.h"
#include "LuaUtils.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/Game.h"
#include "Game/GameSetup.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Models/IModelParser.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/SideParser.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
#include "Sim/MoveTypes/StrafeAirMoveType.h"
#include "Sim/MoveTypes/GroundMoveType.h"
#include "Sim/MoveTypes/HoverAirMoveType.h"
#include "Sim/MoveTypes/ScriptMoveType.h"
#include "Sim/MoveTypes/StaticMoveType.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/PieceProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "Sim/Units/UnitTypes/Builder.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/FactoryCAI.h"
#include "Sim/Units/CommandAI/MobileCAI.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/bitops.h"
#include "System/myMath.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"

#include <set>
#include <map>
#include <cctype>


using std::min;
using std::max;
using std::map;
using std::set;

static const LuaHashString hs_n("n");

// 0 and positive numbers are teams (not allyTeams)
enum UnitAllegiance {
	AllUnits   = -1,
	MyUnits    = -2,
	AllyUnits  = -3,
	EnemyUnits = -4
};


/******************************************************************************/
/******************************************************************************/

bool LuaSyncedRead::PushEntries(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
//
//  Access helpers
//

static inline bool IsAlliedTeam(lua_State* L, int team)
{
    //stub method
}

static inline bool IsAlliedAllyTeam(lua_State* L, int allyTeam)
{
    //stub method
}


static inline bool IsAllyUnit(lua_State* L, const CUnit* unit)
{
    //stub method
}

static inline bool IsEnemyUnit(lua_State* L, const CUnit* unit)
{
    //stub method
}


static inline bool IsUnitVisible(lua_State* L, const CUnit* unit)
{
    //stub method
}

static inline bool IsUnitInLos(lua_State* L, const CUnit* unit)
{
    //stub method
}


static inline bool IsUnitTyped(lua_State* L, const CUnit* unit)
{
    //stub method
}


static inline const UnitDef* EffectiveUnitDef(lua_State* L, const CUnit* unit)
{
    //stub method
}


static inline bool IsFeatureVisible(lua_State* L, const CFeature* feature)
{
    //stub method
}

static inline bool IsProjectileVisible(lua_State* L, const CProjectile* pro)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static int GetSolidObjectLastHitPiece(lua_State* L, const CSolidObject* o)
{
    //stub method
}

static int PushCollisionVolumeData(lua_State* L, const CollisionVolume* vol) {
	lua_pushnumber(L, vol->GetScales().x);
	lua_pushnumber(L, vol->GetScales().y);
	lua_pushnumber(L, vol->GetScales().z);
	lua_pushnumber(L, vol->GetOffsets().x);
	lua_pushnumber(L, vol->GetOffsets().y);
	lua_pushnumber(L, vol->GetOffsets().z);
	lua_pushnumber(L, vol->GetVolumeType());
	lua_pushnumber(L, int(vol->UseContHitTest()));
	lua_pushnumber(L, vol->GetPrimaryAxis());
	lua_pushboolean(L, vol->IgnoreHits());
	return 10;
}

static int PushPieceCollisionVolumeData(lua_State* L, const CSolidObject* o)
{
    //stub method
}


static int PushTerrainTypeData(lua_State* L, const CMapInfo::TerrainType* tt, bool groundInfo) {
	lua_pushsstring(L, tt->name);

	if (groundInfo) {
		assert(lua_isnumber(L, 1));
		assert(lua_isnumber(L, 2));
		// WTF is this still doing here?
		LuaMetalMap::GetMetalAmount(L);
	}

	lua_pushnumber(L, tt->hardness);
	lua_pushnumber(L, tt->tankSpeed);
	lua_pushnumber(L, tt->kbotSpeed);
	lua_pushnumber(L, tt->hoverSpeed);
	lua_pushnumber(L, tt->shipSpeed);
	lua_pushboolean(L, tt->receiveTracks);
	return (7 + int(groundInfo));
}

static int GetWorldObjectVelocity(lua_State* L, const CWorldObject* o)
{
    //stub method
}

static int GetSolidObjectMass(lua_State* L, const CSolidObject* o)
{
    //stub method
}

static int GetSolidObjectPosition(lua_State* L, const CSolidObject* o, bool isFeature)
{
    //stub method
}

static int GetSolidObjectRotation(lua_State* L, const CSolidObject* o)
{
    //stub method
}

static int GetSolidObjectBlocking(lua_State* L, const CSolidObject* o)
{
    //stub method
}




/******************************************************************************/
/******************************************************************************/
//
//  Parsing helpers
//

static inline CUnit* ParseRawUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}

static inline CUnit* ParseUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}

static inline CUnit* ParseAllyUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}

static inline CUnit* ParseInLosUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}


static inline CUnit* ParseTypedUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}


static CFeature* ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
}


static CProjectile* ParseProjectile(lua_State* L, const char* caller, int index)
{
    //stub method
}


static inline CTeam* ParseTeam(lua_State* L, const char* caller, int index)
{
    //stub method
}


/******************************************************************************/

static int PushRulesParams(lua_State* L, const char* caller,
                          const LuaRulesParams::Params& params,
                          const int losStatus)
{
    //stub method
}


static int GetRulesParam(lua_State* L, const char* caller, int index,
                          const LuaRulesParams::Params& params,
                          const int& losStatus)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
//
// The call-outs
//

int LuaSyncedRead::IsCheatingEnabled(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsGodModeEnabled(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsDevLuaEnabled(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsEditDefsEnabled(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::AreHelperAIsEnabled(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::FixedAllies(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsGameOver(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetGaiaTeamID(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetGameFrame(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetGameSeconds(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetWind(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetGameRulesParams(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetGameRulesParam(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetMapOptions(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetModOptions(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetHeadingFromVector(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetVectorFromHeading(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetSideData(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetAllyTeamStartBox(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamStartPosition(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetAllyTeamList(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamList(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetPlayerList(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetTeamInfo(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamResources(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamUnitStats(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamResourceStats(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamRulesParams(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamRulesParam(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamStatsHistory(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamLuaAI(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetPlayerInfo(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetPlayerControlledUnit(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetAIInfo(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetAllyTeamInfo(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::AreTeamsAllied(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::ArePlayersAllied(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
//
//  Grouped Unit Queries
//

int LuaSyncedRead::GetAllUnits(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamUnits(lua_State* L)
{
    //stub method
}


static inline void PushUnitsVector(lua_State* L, const std::vector<CUnit*>& vec, int unitDefID, bool& createdTable, unsigned& count, unsigned& defCount, std::vector<int>& unknownIDs)
{
    //stub method
}

int LuaSyncedRead::GetTeamUnitsSorted(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamUnitsCounts(lua_State* L)
{
    //stub method
}


static inline void InsertSearchUnitDefs(const UnitDef* ud, bool allied,
                                        set<int>& defs)
{
    //stub method
}


int LuaSyncedRead::GetTeamUnitsByDefs(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamUnitDefCount(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTeamUnitCount(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
//
//  Spatial Unit Queries
//

// Macro Requirements:
//   L, units

#define LOOP_UNIT_CONTAINER(ALLEGIANCE_TEST, CUSTOM_TEST, NEWTABLE) \
	{                                                               \
		unsigned int count = 0;                                     \
                                                                    \
		if (NEWTABLE) {                                             \
			lua_createtable(L, units.size(), 0);                    \
		}                                                           \
                                                                    \
		for (auto it = units.cbegin(); it != units.cend(); ++it) {  \
			const CUnit* unit = *it;                                \
                                                                    \
			ALLEGIANCE_TEST;                                        \
			CUSTOM_TEST;                                            \
                                                                    \
			lua_pushnumber(L, unit->id);                            \
			lua_rawseti(L, -2, ++count);                            \
		}                                                           \
	}

// Macro Requirements:
//   unit
//   readTeam   for MY_UNIT_TEST
//   allegiance for SIMPLE_TEAM_TEST and VISIBLE_TEAM_TEST

#define NULL_TEST  ;  // always passes

#define VISIBLE_TEST \
	if (!IsUnitVisible(L, unit)) { continue; }

#define SIMPLE_TEAM_TEST \
	if (unit->team != allegiance) { continue; }

#define VISIBLE_TEAM_TEST \
	if (unit->team != allegiance) { continue; } \
	if (!IsUnitVisible(L, unit)) { continue; }

#define MY_UNIT_TEST \
	if (unit->team != readTeam) { continue; }

#define ALLY_UNIT_TEST \
	if (unit->allyteam != CLuaHandle::GetHandleReadAllyTeam(L)) { continue; }

#define ENEMY_UNIT_TEST \
	if (unit->allyteam == CLuaHandle::GetHandleReadAllyTeam(L)) { continue; } \
	if (!IsUnitVisible(L, unit)) { continue; }


static int ParseAllegiance(lua_State* L, const char* caller, int index)
{
    //stub method
}


int LuaSyncedRead::GetUnitsInRectangle(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitsInBox(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitsInCylinder(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitsInSphere(lua_State* L)
{
    //stub method
}


struct Plane {
	float x, y, z, d;  // ax + by + cz + d = 0
};


static inline bool UnitInPlanes(const CUnit* unit, const vector<Plane>& planes)
{
    //stub method
}


int LuaSyncedRead::GetUnitsInPlanes(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetUnitNearestAlly(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitNearestEnemy(lua_State* L)
{
    //stub method
}


/******************************************************************************/

inline void ProcessFeatures(lua_State* L, const vector<CFeature*>& features) {
	const unsigned int featureCount = features.size();
	unsigned int arrayIndex = 1;

	lua_createtable(L, featureCount, 0);

	if (CLuaHandle::GetHandleReadAllyTeam(L) < 0) {
		if (CLuaHandle::GetHandleFullRead(L)) {
			for (unsigned int i = 0; i < featureCount; i++) {
				const CFeature* feature = features[i];

				lua_pushnumber(L, feature->id);
				lua_rawseti(L, -2, arrayIndex++);
			}
		}
	} else {
		for (unsigned int i = 0; i < featureCount; i++) {
			const CFeature* feature = features[i];

			if (!IsFeatureVisible(L, feature)) {
				continue;
			}

			lua_pushnumber(L, feature->id);
			lua_rawseti(L, -2, arrayIndex++);
		}
	}
}

int LuaSyncedRead::GetFeaturesInRectangle(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeaturesInSphere(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeaturesInCylinder(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectilesInRectangle(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaSyncedRead::ValidUnitID(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitStates(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitArmored(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitIsActive(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitIsCloaked(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitSelfDTime(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitStockpile(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitSensorRadius(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitPosErrorParams(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitTooltip(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitDefID(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitTeam(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitAllyTeam(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitNeutral(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitHealth(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitIsDead(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitIsStunned(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitResources(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitMetalExtraction(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitExperience(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitHeight(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitRadius(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitMass(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitPosition(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitBasePosition(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitVectors(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitRotation(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitDirection(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitHeading(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitVelocity(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitBuildFacing(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitIsBuilding(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitCurrentBuildPower(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitHarvestStorage(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitNanoPieces(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitTransporter(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitIsTransporting(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitShieldState(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitFlanking(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitMaxRange(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitWeaponState(lua_State* L)
{
    //stub method
}


static inline int PushDamagesKey(lua_State* L, const DynDamageArray& damages, int index)
{
    //stub method
}


int LuaSyncedRead::GetUnitWeaponDamages(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitWeaponVectors(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitWeaponTryTarget(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitWeaponTestTarget(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitWeaponTestRange(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitWeaponHaveFreeLineOfFire(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitWeaponCanFire(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitWeaponTarget(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitTravel(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitFuel(lua_State* L) { lua_pushnumber(L, 0.0f); return 1; } // DEPRECATED


int LuaSyncedRead::GetUnitEstimatedPath(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitLastAttacker(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitLastAttackedPiece(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitCollisionVolumeData(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitPieceCollisionVolumeData(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitSeparation(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitFeatureSeparation(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitDefDimensions(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitBlocking(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitMoveTypeData(lua_State* L)
{
    //stub method
}



/******************************************************************************/

static void PackCommand(lua_State* L, const Command& cmd)
{
    //stub method
}


static void PackCommandQueue(lua_State* L, const CCommandQueue& commands, size_t count)
{
    //stub method
}


int LuaSyncedRead::GetUnitCommands(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFactoryCommands(lua_State* L)
{
    //stub method
}


static void PackFactoryCounts(lua_State* L,
                              const CCommandQueue& q, int count, bool noCmds)
{
    //stub method
}


int LuaSyncedRead::GetFactoryCounts(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetCommandQueue(lua_State* L)
{
    //stub method
}


static int PackBuildQueue(lua_State* L, bool canBuild, const char* caller)
{
    //stub method
}


int LuaSyncedRead::GetFullBuildQueue(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetRealBuildQueue(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetUnitRulesParams(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitRulesParam(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetUnitCmdDescs(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::FindUnitCmdDesc(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaSyncedRead::ValidFeatureID(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetAllFeatures(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureDefID(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureTeam(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureAllyTeam(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureHealth(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureHeight(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureRadius(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeatureMass(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeaturePosition(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeatureSeparation(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeatureRotation(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeatureDirection(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeatureVelocity(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureHeading(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureResources(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureBlocking(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureNoSelect(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureResurrect(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureLastAttackedPiece(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeatureCollisionVolumeData(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetFeaturePieceCollisionVolumeData(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureRulesParams(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetFeatureRulesParam(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaSyncedRead::GetProjectilePosition(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileDirection(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileVelocity(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetProjectileGravity(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileSpinAngle(lua_State* L) { lua_pushnumber(L, 0.0f); return 1; } // DEPRECATED
int LuaSyncedRead::GetProjectileSpinSpeed(lua_State* L) { lua_pushnumber(L, 0.0f); return 1; } // DEPRECATED
int LuaSyncedRead::GetProjectileSpinVec(lua_State* L) {
	lua_pushnumber(L, 0.0f);
	lua_pushnumber(L, 0.0f);
	lua_pushnumber(L, 0.0f);
	return 3;
} // DEPRECATED

int LuaSyncedRead::GetPieceProjectileParams(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileTarget(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileIsIntercepted(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileTimeToLive(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileOwnerID(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileTeamID(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileType(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileDefID(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileDamages(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetProjectileName(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaSyncedRead::GetGroundHeight(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetGroundOrigHeight(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetGroundNormal(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetGroundInfo(lua_State* L)
{
    //stub method
}


// similar to ParseMapParams in LuaSyncedCtrl
static void ParseMapCoords(lua_State* L, const char* caller,
                           int& tx1, int& tz1, int& tx2, int& tz2)
{
    //stub method
}


int LuaSyncedRead::GetGroundBlocked(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetGroundExtremes(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetTerrainTypeData(lua_State* L)
{
    //stub method
}

/******************************************************************************/

int LuaSyncedRead::GetSmoothMeshHeight(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/


int LuaSyncedRead::TestMoveOrder(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::TestBuildOrder(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::Pos2BuildPos(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static int GetEffectiveLosAllyTeam(lua_State* L, int arg)
{
    //stub method
}


int LuaSyncedRead::GetPositionLosState(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsPosInLos(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsPosInRadar(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsPosInAirLos(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetUnitLosState(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsUnitInLos(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsUnitInAirLos(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsUnitInRadar(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::IsUnitInJammer(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedRead::GetClosestValidPosition(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static int GetSolidObjectPieceMap(lua_State* L, const CSolidObject* o)
{
    //stub method
}

static int GetSolidObjectPieceList(lua_State* L, const CSolidObject* o)
{
    //stub method
}



static int GetSolidObjectPieceInfoHelper(lua_State* L, const S3DModelPiece& op)
{
    //stub method
}

static int GetSolidObjectPieceInfo(lua_State* L, const CSolidObject* o)
{
    //stub method
}

static int GetSolidObjectPiecePosition(lua_State* L, const CSolidObject* o)
{
    //stub method
}

static int GetSolidObjectPieceDirection(lua_State* L, const CSolidObject* o)
{
    //stub method
}

static int GetSolidObjectPiecePosDir(lua_State* L, const CSolidObject* o)
{
    //stub method
}

static int GetSolidObjectPieceMatrix(lua_State* L, const CSolidObject* o)
{
    //stub method
}



int LuaSyncedRead::GetUnitPieceMap(lua_State* L) {
	return (GetSolidObjectPieceMap(L, ParseTypedUnit(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetUnitPieceList(lua_State* L) {
	return (GetSolidObjectPieceList(L, ParseTypedUnit(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetUnitPieceInfo(lua_State* L) {
	return (GetSolidObjectPieceInfo(L, ParseTypedUnit(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetUnitPiecePosDir(lua_State* L) {
	return (GetSolidObjectPiecePosDir(L, ParseTypedUnit(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetUnitPiecePosition(lua_State* L) {
	return (GetSolidObjectPiecePosition(L, ParseTypedUnit(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetUnitPieceDirection(lua_State* L) {
	return (GetSolidObjectPieceDirection(L, ParseTypedUnit(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetUnitPieceMatrix(lua_State* L) {
	return (GetSolidObjectPieceMatrix(L, ParseTypedUnit(L, __FUNCTION__, 1)));
}


int LuaSyncedRead::GetFeaturePieceMap(lua_State* L) {
	return (GetSolidObjectPieceMap(L, ParseFeature(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetFeaturePieceList(lua_State* L) {
	return (GetSolidObjectPieceList(L, ParseFeature(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetFeaturePieceInfo(lua_State* L) {
	return (GetSolidObjectPieceInfo(L, ParseFeature(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetFeaturePiecePosDir(lua_State* L) {
	return (GetSolidObjectPiecePosDir(L, ParseFeature(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetFeaturePiecePosition(lua_State* L) {
	return (GetSolidObjectPiecePosition(L, ParseFeature(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetFeaturePieceDirection(lua_State* L) {
	return (GetSolidObjectPieceDirection(L, ParseFeature(L, __FUNCTION__, 1)));
}
int LuaSyncedRead::GetFeaturePieceMatrix(lua_State* L) {
	return (GetSolidObjectPieceMatrix(L, ParseFeature(L, __FUNCTION__, 1)));
}



int LuaSyncedRead::GetUnitScriptPiece(lua_State* L)
{
    //stub method
}

int LuaSyncedRead::GetUnitScriptNames(lua_State* L)
{
    //stub method
}


int LuaSyncedRead::GetRadarErrorParams(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
