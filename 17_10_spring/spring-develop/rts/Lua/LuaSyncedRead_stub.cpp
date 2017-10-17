#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaSyncedRead.h"

#include "LuaInclude.h"

#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/Camera.h"
#include "Game/Game.h"
#include "Game/GameHelper.h"
#include "Game/GameSetup.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "LuaConfig.h"
#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaMetalMap.h"
#include "LuaPathFinder.h"
#include "LuaRules.h"
#include "LuaRulesParams.h"
#include "LuaUtils.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Models/IModelParser.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/SideParser.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
#include "Sim/MoveTypes/GroundMoveType.h"
#include "Sim/MoveTypes/HoverAirMoveType.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/MoveTypes/ScriptMoveType.h"
#include "Sim/MoveTypes/StaticMoveType.h"
#include "Sim/MoveTypes/StrafeAirMoveType.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Projectiles/PieceProjectile.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "Sim/Units/CommandAI/FactoryCAI.h"
#include "Sim/Units/CommandAI/MobileCAI.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "Sim/Units/UnitTypes/Builder.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Util.h"
#include "System/bitops.h"
#include "System/myMath.h"

#include <cctype>
#include <map>
#include <set>

using std::map;
using std::max;
using std::min;
using std::set;

static const LuaHashString hs_n("n");

// 0 and positive numbers are teams (not allyTeams)
enum UnitAllegiance
{
    AllUnits   = -1,
	MyUnits    = -2,
	AllyUnits  = -3,
	EnemyUnits = -4
};

/******************************************************************************/
/******************************************************************************/
//
//  Access helpers
//

static inline bool
IsAlliedTeam(lua_State* L, int team)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsAlliedAllyTeam(lua_State* L, int allyTeam)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsAllyUnit(lua_State* L, const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsEnemyUnit(lua_State* L, const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsUnitVisible(lua_State* L, const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsUnitInLos(lua_State* L, const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsUnitTyped(lua_State* L, const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline const UnitDef*
EffectiveUnitDef(lua_State* L, const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsFeatureVisible(lua_State* L, const CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
IsProjectileVisible(lua_State* L, const CProjectile* pro)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static int
GetSolidObjectLastHitPiece(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
PushCollisionVolumeData(lua_State* L, const CollisionVolume* vol)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
PushPieceCollisionVolumeData(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
PushTerrainTypeData(lua_State* L,
                    const CMapInfo::TerrainType* tt,
                    bool groundInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetWorldObjectVelocity(lua_State* L, const CWorldObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectMass(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectPosition(lua_State* L, const CSolidObject* o, bool isFeature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectRotation(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectBlocking(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Parsing helpers
//

static inline CUnit*
ParseRawUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline CUnit*
ParseUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline CUnit*
ParseAllyUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline CUnit*
ParseInLosUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline CUnit*
ParseTypedUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static CFeature*
ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static CProjectile*
ParseProjectile(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline CTeam*
ParseTeam(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

static int
PushRulesParams(lua_State* L,
                const char* caller,
                const LuaRulesParams::Params& params,
                const int losStatus)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetRulesParam(lua_State* L,
              const char* caller,
              int index,
              const LuaRulesParams::Params& params,
              const int& losStatus)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
// The call-outs
//

int
LuaSyncedRead::IsCheatingEnabled(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsGodModeEnabled(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsDevLuaEnabled(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsEditDefsEnabled(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::AreHelperAIsEnabled(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::FixedAllies(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsGameOver(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGaiaTeamID(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGameFrame(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGameSeconds(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetWind(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetGameRulesParams(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGameRulesParam(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetMapOptions(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetModOptions(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetHeadingFromVector(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetVectorFromHeading(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetSideData(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetAllyTeamStartBox(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamStartPosition(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetAllyTeamList(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamList(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetPlayerList(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetTeamInfo(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamResources(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamUnitStats(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamResourceStats(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamRulesParams(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamRulesParam(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamStatsHistory(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamLuaAI(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetPlayerInfo(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetPlayerControlledUnit(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetAIInfo(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetAllyTeamInfo(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::AreTeamsAllied(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::ArePlayersAllied(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Grouped Unit Queries
//

int
LuaSyncedRead::GetAllUnits(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamUnits(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline void
PushUnitsVector(lua_State* L,
                const std::vector<CUnit*>& vec,
                int unitDefID,
                bool& createdTable,
                unsigned& count,
                unsigned& defCount,
                std::vector<int>& unknownIDs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamUnitsSorted(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamUnitsCounts(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline void
InsertSearchUnitDefs(const UnitDef* ud, bool allied, set<int>& defs)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamUnitsByDefs(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamUnitDefCount(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTeamUnitCount(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

    /******************************************************************************/
    /******************************************************************************/
    //
    //  Spatial Unit Queries
    //

    // Macro Requirements:
    //   L, units

#define LOOP_UNIT_CONTAINER(ALLEGIANCE_TEST, CUSTOM_TEST, NEWTABLE)            \
    {                                                                          \
        unsigned int count = 0;                                                \
                                                                               \
        if (NEWTABLE) {                                                        \
            lua_createtable(L, units.size(), 0);                               \
        }                                                                      \
                                                                               \
        for (auto it = units.cbegin(); it != units.cend(); ++it) {             \
            const CUnit* unit = *it;                                           \
                                                                               \
            ALLEGIANCE_TEST;                                                   \
            CUSTOM_TEST;                                                       \
                                                                               \
            lua_pushnumber(L, unit->id);                                       \
            lua_rawseti(L, -2, ++count);                                       \
        }                                                                      \
    }

    // Macro Requirements:
    //   unit
    //   readTeam   for MY_UNIT_TEST
    //   allegiance for SIMPLE_TEAM_TEST and VISIBLE_TEAM_TEST

#define NULL_TEST ; // always passes

#define VISIBLE_TEST                                                           \
    if (!IsUnitVisible(L, unit)) {                                             \
        continue;                                                              \
    }

#define SIMPLE_TEAM_TEST                                                       \
    if (unit->team != allegiance) {                                            \
        continue;                                                              \
    }

#define VISIBLE_TEAM_TEST                                                      \
    if (unit->team != allegiance) {                                            \
        continue;                                                              \
    }                                                                          \
    if (!IsUnitVisible(L, unit)) {                                             \
        continue;                                                              \
    }

#define MY_UNIT_TEST                                                           \
    if (unit->team != readTeam) {                                              \
        continue;                                                              \
    }

#define ALLY_UNIT_TEST                                                         \
    if (unit->allyteam != CLuaHandle::GetHandleReadAllyTeam(L)) {              \
        continue;                                                              \
    }

#define ENEMY_UNIT_TEST                                                        \
    if (unit->allyteam == CLuaHandle::GetHandleReadAllyTeam(L)) {              \
        continue;                                                              \
    }                                                                          \
    if (!IsUnitVisible(L, unit)) {                                             \
        continue;                                                              \
    }

static int
ParseAllegiance(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitsInRectangle(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitsInBox(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitsInCylinder(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitsInSphere(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

struct Plane
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

int
LuaSyncedRead::GetUnitsInPlanes(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetUnitNearestAlly(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitNearestEnemy(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

inline void
ProcessFeatures(lua_State* L, const vector<CFeature*>& features)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeaturesInRectangle(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeaturesInSphere(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeaturesInCylinder(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectilesInRectangle(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaSyncedRead::ValidUnitID(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitStates(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitArmored(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitIsActive(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitIsCloaked(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitSelfDTime(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitStockpile(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitSensorRadius(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitPosErrorParams(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitTooltip(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitDefID(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitTeam(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitAllyTeam(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitNeutral(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitHealth(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitIsDead(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitIsStunned(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitResources(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitMetalExtraction(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitExperience(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitHeight(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitRadius(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitMass(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitPosition(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitBasePosition(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitVectors(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitRotation(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitDirection(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitHeading(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitVelocity(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitBuildFacing(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitIsBuilding(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitCurrentBuildPower(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitHarvestStorage(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitNanoPieces(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitTransporter(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitIsTransporting(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitShieldState(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitFlanking(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitMaxRange(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponState(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline int
PushDamagesKey(lua_State* L, const DynDamageArray& damages, int index)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponDamages(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponVectors(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponTryTarget(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponTestTarget(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponTestRange(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponHaveFreeLineOfFire(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponCanFire(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitWeaponTarget(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitTravel(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitFuel(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitLastAttacker(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitLastAttackedPiece(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitCollisionVolumeData(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitPieceCollisionVolumeData(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitSeparation(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitFeatureSeparation(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitDefDimensions(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitBlocking(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitMoveTypeData(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

static void
PackCommand(lua_State* L, const Command& cmd)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
PackCommandQueue(lua_State* L, const CCommandQueue& commands, size_t count)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitCommands(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFactoryCommands(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
PackFactoryCounts(lua_State* L, const CCommandQueue& q, int count, bool noCmds)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFactoryCounts(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetCommandQueue(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
PackBuildQueue(lua_State* L, bool canBuild, const char* caller)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFullBuildQueue(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetRealBuildQueue(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetUnitRulesParams(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitRulesParam(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetUnitCmdDescs(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::FindUnitCmdDesc(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaSyncedRead::ValidFeatureID(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetAllFeatures(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureDefID(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureTeam(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureAllyTeam(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureHealth(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureHeight(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureRadius(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureMass(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeaturePosition(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureSeparation(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureRotation(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureDirection(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureVelocity(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureHeading(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureResources(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureBlocking(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureNoSelect(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureResurrect(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureLastAttackedPiece(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureCollisionVolumeData(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeaturePieceCollisionVolumeData(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureRulesParams(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeatureRulesParam(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaSyncedRead::GetProjectilePosition(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileDirection(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileVelocity(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileGravity(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileSpinAngle(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileTarget(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileIsIntercepted(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileTimeToLive(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileOwnerID(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileTeamID(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileType(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileDefID(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileDamages(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetProjectileName(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaSyncedRead::GetGroundHeight(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGroundOrigHeight(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGroundNormal(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGroundInfo(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// similar to ParseMapParams in LuaSyncedCtrl
static void
ParseMapCoords(lua_State* L,
               const char* caller,
               int& tx1,
               int& tz1,
               int& tx2,
               int& tz2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGroundBlocked(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetGroundExtremes(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetTerrainTypeData(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetSmoothMeshHeight(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaSyncedRead::TestMoveOrder(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::TestBuildOrder(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::Pos2BuildPos(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static int
GetEffectiveLosAllyTeam(lua_State* L, int arg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetPositionLosState(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsPosInLos(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsPosInRadar(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsPosInAirLos(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitLosState(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsUnitInLos(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsUnitInAirLos(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsUnitInRadar(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::IsUnitInJammer(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

int
LuaSyncedRead::GetClosestValidPosition(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static int
GetSolidObjectPieceMap(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectPieceList(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectPieceInfoHelper(lua_State* L, const S3DModelPiece& op)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectPieceInfo(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectPiecePosition(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectPieceDirection(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectPiecePosDir(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static int
GetSolidObjectPieceMatrix(lua_State* L, const CSolidObject* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitPieceMap(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetUnitPieceList(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetUnitPieceInfo(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetUnitPiecePosDir(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetUnitPiecePosition(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetUnitPieceDirection(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetUnitPieceMatrix(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetFeaturePieceMap(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetFeaturePieceList(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetFeaturePieceInfo(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetFeaturePiecePosDir(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetFeaturePiecePosition(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetFeaturePieceDirection(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
int
LuaSyncedRead::GetFeaturePieceMatrix(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitScriptPiece(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetUnitScriptNames(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
LuaSyncedRead::GetRadarErrorParams(lua_State* L)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
