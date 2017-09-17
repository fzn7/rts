/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <set>
#include <vector>
#include <list>
#include <cctype>

#include "LuaSyncedCtrl.h"

#include "LuaInclude.h"

#include "LuaConfig.h"
#include "LuaRules.h" // for MAX_LUA_COB_ARGS
#include "LuaHandleSynced.h"
#include "LuaHashString.h"
#include "LuaMetalMap.h"
#include "LuaSyncedMoveCtrl.h"
#include "LuaUtils.h"
#include "Game/Game.h"
#include "Game/Camera.h"
#include "Game/GameHelper.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/Players/Player.h"
#include "Net/GameServer.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/Env/GrassDrawer.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/Env/ITreeDrawer.h"
#include "Rendering/Models/IModelParser.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Misc/DamageArray.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "Sim/Misc/Team.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/BuildingMaskMap.h"
#include "Sim/MoveTypes/AAirMoveType.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/PieceProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/MissileProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/StarburstProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/TorpedoProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectileFactory.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "Sim/Units/Scripts/CobInstance.h"
#include "Sim/Units/Scripts/LuaUnitScript.h"
#include "Sim/Units/UnitTypes/Builder.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/FactoryCAI.h"
#include "Sim/Units/UnitTypes/ExtractorBuilding.h"
#include "Sim/Weapons/PlasmaRepulser.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "Sim/Weapons/WeaponTarget.h"
#include "System/EventHandler.h"
#include "System/ObjectDependenceTypes.h"
#include "System/Log/ILog.h"
#include "System/Sync/HsiehHash.h"

using std::max;
using std::min;


/******************************************************************************/
/******************************************************************************/

bool LuaSyncedCtrl::inCreateUnit = false;
bool LuaSyncedCtrl::inDestroyUnit = false;
bool LuaSyncedCtrl::inTransferUnit = false;
bool LuaSyncedCtrl::inCreateFeature = false;
bool LuaSyncedCtrl::inDestroyFeature = false;
bool LuaSyncedCtrl::inGiveOrder = false;
bool LuaSyncedCtrl::inHeightMap = false;
bool LuaSyncedCtrl::inSmoothMesh = false;

static int heightMapx1 = 0;
static int heightMapx2 = 0;
static int heightMapz1 = 0;
static int heightMapz2 = 0;

static float heightMapAmountChanged = 0.0f;
static float smoothMeshAmountChanged = 0.0f;


/******************************************************************************/

inline void LuaSyncedCtrl::CheckAllowGameChanges(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

bool LuaSyncedCtrl::PushEntries(lua_State* L)
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

static inline CFeature* ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
}

static inline CProjectile* ParseProjectile(lua_State* L, const char* caller, int index)
{
    //stub method
}

static bool ParseProjectileParams(lua_State* L, ProjectileParams& params, const int tblIdx, const char* caller)
{
    //stub method
}

static CTeam* ParseTeam(lua_State* L, const char* caller, int index)
{
    //stub method
}

static int SetSolidObjectCollisionVolumeData(lua_State* L, CSolidObject* o)
{
    //stub method
}

static int SetSolidObjectBlocking(lua_State* L, CSolidObject* o)
{
    //stub method
}

static int SetSolidObjectRotation(lua_State* L, CSolidObject* o, bool isFeature)
{
    //stub method
}

static int SetSolidObjectDirection(lua_State* L, CSolidObject* o)
{
    //stub method
}

static int SetWorldObjectVelocity(lua_State* L, CWorldObject* o)
{
    //stub method
}

static int SetSolidObjectMass(lua_State* L, CSolidObject* o)
{
    //stub method
}

static int SetSolidObjectPhysicalState(lua_State* L, CSolidObject* o)
{
    //stub method
}

static int SetSolidObjectPieceCollisionVolumeData(lua_State* L, CSolidObject* obj)
{
    //stub method
}

static int SetWorldObjectAlwaysVisible(lua_State* L, CWorldObject* o, const char* caller)
{
    //stub method
}




/******************************************************************************/
/******************************************************************************/
//
// The call-outs
//

int LuaSyncedCtrl::SetAlly(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::KillTeam(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::AssignPlayerToTeam(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::GameOver(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetGlobalLos(lua_State* L)
{
    //stub method
}




int LuaSyncedCtrl::AddTeamResource(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::UseTeamResource(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetTeamResource(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetTeamShareLevel(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::ShareTeamResource(lua_State* L)
{
    //stub method
}



/******************************************************************************/

void SetRulesParam(lua_State* L, const char* caller, int offset,
				LuaRulesParams::Params& params)
{
    //stub method
}


int LuaSyncedCtrl::SetGameRulesParam(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetTeamRulesParam(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitRulesParam(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeatureRulesParam(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

static inline void ParseCobArgs(lua_State* L,
                                int first, int last, vector<int>& args)
{
    //stub method
}


int LuaSyncedCtrl::CallCOBScript(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::GetCOBScriptID(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaSyncedCtrl::CreateUnit(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::DestroyUnit(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::TransferUnit(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedCtrl::SetUnitCosts(lua_State* L)
{
    //stub method
}


static bool SetUnitResourceParam(CUnit* unit, const string& name, float value)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitResourcing(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitTooltip(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitHealth(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitMaxHealth(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitStockpile(lua_State* L)
{
    //stub method
}


static int SetSingleUnitWeaponState(lua_State* L, CWeapon* weapon, int index)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitWeaponState(lua_State* L)
{
    //stub method
}


static int SetSingleDamagesKey(lua_State* L, DynDamageArray* damages, int index)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitWeaponDamages(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitMaxRange(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitExperience(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitArmored(lua_State* L)
{
    //stub method
}


static unsigned char ParseLosBits(lua_State* L, int index, unsigned char bits)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitLosMask(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitLosState(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitCloak(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitStealth(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitSonarStealth(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitAlwaysVisible(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitMetalExtraction(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitHarvestStorage(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetUnitBuildSpeed(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitNanoPieces(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitBlocking(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitCrashing(lua_State* L) {
	CUnit* unit = ParseUnit(L, __FUNCTION__, 1);

	if (unit == NULL) {
		return 0;
	}

	AAirMoveType* amt = dynamic_cast<AAirMoveType*>(unit->moveType);
	bool ret = false;

	if (amt != NULL) {
		const bool wantCrash = luaL_optboolean(L, 2, false);
		const AAirMoveType::AircraftState aircraftState = amt->aircraftState;

		// for simplicity, this can only set a non-landed aircraft to
		// start crashing, or a crashing aircraft to start flying
		if ( wantCrash && (aircraftState != AAirMoveType::AIRCRAFT_LANDED))
			amt->SetState(AAirMoveType::AIRCRAFT_CRASHING);

		if (!wantCrash && (aircraftState == AAirMoveType::AIRCRAFT_CRASHING))
			amt->SetState(AAirMoveType::AIRCRAFT_FLYING);

		ret = (amt->aircraftState != aircraftState);
	}

	lua_pushboolean(L, ret);
	return 1;
}


int LuaSyncedCtrl::SetUnitShieldState(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitFlanking(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitTravel(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitFuel(lua_State* L) { return 0; } // DEPRECATED


int LuaSyncedCtrl::SetUnitNeutral(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitTarget(lua_State* L)
{
    //stub method
}



int LuaSyncedCtrl::SetUnitMidAndAimPos(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetUnitRadiusAndHeight(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetUnitPieceParent(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitCollisionVolumeData(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetUnitPieceCollisionVolumeData(lua_State* L)
{
    //stub method
}



int LuaSyncedCtrl::SetUnitSensorRadius(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitPosErrorParams(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitMoveGoal(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitLandGoal(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::ClearUnitGoal(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitPhysics(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetUnitMass(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetUnitPosition(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitRotation(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetUnitDirection(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetUnitVelocity(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::AddUnitDamage(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::AddUnitImpulse(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::AddUnitSeismicPing(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedCtrl::AddUnitResource(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::UseUnitResource(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedCtrl::RemoveBuildingDecal(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::AddGrass(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::RemoveGrass(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedCtrl::CreateFeature(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::DestroyFeature(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::TransferFeature(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeatureAlwaysVisible(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeatureHealth(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeatureReclaim(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeatureMoveCtrl(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeaturePhysics(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetFeatureMass(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetFeaturePosition(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetFeatureRotation(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetFeatureDirection(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetFeatureVelocity(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeatureResurrect(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeatureBlocking(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetFeatureNoSelect(lua_State* L)
{
    //stub method
}



int LuaSyncedCtrl::SetFeatureMidAndAimPos(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetFeatureRadiusAndHeight(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetFeatureCollisionVolumeData(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetFeaturePieceCollisionVolumeData(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaSyncedCtrl::SetProjectileAlwaysVisible(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetProjectileMoveControl(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetProjectilePosition(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetProjectileVelocity(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetProjectileCollision(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetProjectileTarget(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetProjectileIsIntercepted(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetProjectileDamages(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetProjectileIgnoreTrackingError(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetProjectileGravity(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetProjectileSpinAngle(lua_State* L) { return 0; } // DEPRECATED
int LuaSyncedCtrl::SetProjectileSpinSpeed(lua_State* L) { return 0; } // DEPRECATED
int LuaSyncedCtrl::SetProjectileSpinVec(lua_State* L) { return 0; } // DEPRECATED

int LuaSyncedCtrl::SetPieceProjectileParams(lua_State* L)
{
    //stub method
}

//
// TODO: move this and SpawnCEG to LuaUnsyncedCtrl
//
int LuaSyncedCtrl::SetProjectileCEG(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static void ParseUnitMap(lua_State* L, const char* caller,
                         int table, vector<CUnit*>& unitIDs)
{
    //stub method
}


static void ParseUnitArray(lua_State* L, const char* caller,
                           int table, vector<CUnit*>& unitIDs)
{
    //stub method
}


/******************************************************************************/

int LuaSyncedCtrl::GiveOrderToUnit(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::GiveOrderToUnitMap(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::GiveOrderToUnitArray(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::GiveOrderArrayToUnitMap(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::GiveOrderArrayToUnitArray(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static void ParseParams(lua_State* L, const char* caller, float& factor,
		int& x1, int& z1, int& x2, int& z2, int resolution, int maxX, int maxZ)
{
    //stub method
}

static inline void ParseMapParams(lua_State* L, const char* caller,
		float& factor, int& x1, int& z1, int& x2, int& z2)
{
    //stub method
}


int LuaSyncedCtrl::LevelHeightMap(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::AdjustHeightMap(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::RevertHeightMap(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaSyncedCtrl::AddHeightMap(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetHeightMap(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetHeightMapFunc(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/* smooth mesh manipulation                                                   */
/******************************************************************************/

static inline void ParseSmoothMeshParams(lua_State* L, const char* caller,
		float& factor, int& x1, int& z1, int& x2, int& z2)
{
    //stub method
}


int LuaSyncedCtrl::LevelSmoothMesh(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::AdjustSmoothMesh(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::RevertSmoothMesh(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::AddSmoothMesh(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetSmoothMesh(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetSmoothMeshFunc(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaSyncedCtrl::SetMapSquareTerrainType(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::SetTerrainTypeData(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaSyncedCtrl::SetSquareBuildingMask(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaSyncedCtrl::UnitWeaponFire(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::UnitWeaponHoldFire(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::UnitAttach(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::UnitDetach(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::UnitDetachFromAir(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitLoadingTransport(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SpawnProjectile(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::DeleteProjectile(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SpawnCEG(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaSyncedCtrl::SetNoPause(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetUnitToFeature(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetExperienceGrade(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::SetRadarErrorParams(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static bool ParseNamedInt(lua_State* L, const string& key,
                          const string& name, int& value)
{
    //stub method
}


static bool ParseNamedBool(lua_State* L, const string& key,
                           const string& name, bool& value)
{
    //stub method
}


static bool ParseNamedString(lua_State* L, const string& key,
                             const string& name, string& value)
{
    //stub method
}


static int ParseStringVector(lua_State* L, int index, vector<string>& strvec)
{
    //stub method
}


/******************************************************************************/

static bool ParseCommandDescription(lua_State* L, int table,
                                    SCommandDescription& cd)
{
    //stub method
}


int LuaSyncedCtrl::EditUnitCmdDesc(lua_State* L)
{
    //stub method
}


int LuaSyncedCtrl::InsertUnitCmdDesc(lua_State* L)
{
    //stub method
}

int LuaSyncedCtrl::RemoveUnitCmdDesc(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
