#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/EventHandler.h"

#include "Lua/LuaCallInCheck.h"
#include "Lua/LuaOpenGL.h"  // FIXME -- should be moved

#include "System/Config/ConfigHandler.h"
#include "System/Platform/Threading.h"
#include "System/GlobalConfig.h"

using std::string;
using std::vector;
using std::map;


CEventHandler eventHandler;


/******************************************************************************/
/******************************************************************************/

void CEventHandler::SetupEvent(const string& eName,
                               EventClientList* list, int props)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

CEventHandler::CEventHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CEventHandler::~CEventHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEventHandler::SetupEvents()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void CEventHandler::AddClient(CEventClient* ec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEventHandler::RemoveClient(CEventClient* ec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void CEventHandler::GetEventList(vector<string>& list) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::IsKnown(const string& eName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::IsManaged(const string& eName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::IsUnsynced(const string& eName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::IsController(const string& eName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

bool CEventHandler::InsertEvent(CEventClient* ec, const string& ciName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::RemoveEvent(CEventClient* ec, const string& ciName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CEventHandler::ListInsert(EventClientList& ecList, CEventClient* ec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::ListRemove(EventClientList& ecList, CEventClient* ec)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

#define CONTROL_ITERATE_DEF_TRUE(name, ...) \
	bool result = true;                        \
	for (int i = 0; i < list##name.size(); ) { \
		CEventClient* ec = list##name[i];  \
		result &= ec->name(__VA_ARGS__);   \
		if (i < list##name.size() && ec == list##name[i]) \
			++i; /* the call-in may remove itself from the list */ \
	} \
	return result;

#define CONTROL_ITERATE_DEF_FALSE(name, ...) \
	bool result = false;                        \
	for (int i = 0; i < list##name.size(); ) { \
		CEventClient* ec = list##name[i];  \
		result |= ec->name(__VA_ARGS__);   \
		if (i < list##name.size() && ec == list##name[i]) \
			++i; /* the call-in may remove itself from the list */ \
	} \
	return result;


bool CEventHandler::CommandFallback(const CUnit* unit, const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowCommand(const CUnit* unit, const Command& cmd, bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowUnitCreation(const UnitDef* unitDef, const CUnit* builder, const BuildInfo* buildInfo)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowUnitTransfer(const CUnit* unit, int newTeam, bool capture)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowUnitBuildStep(const CUnit* builder, const CUnit* unit, float part)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowFeatureCreation(const FeatureDef* featureDef, int allyTeamID, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowFeatureBuildStep(const CUnit* builder, const CFeature* feature, float part)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowResourceLevel(int teamID, const string& type, float level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowResourceTransfer(int oldTeam, int newTeam, const string& type, float amount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowDirectUnitControl(int playerID, const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowBuilderHoldFire(const CUnit* unit, int action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowStartPosition(int playerID, unsigned char readyState, const float3& clampedPos, const float3& rawPickPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CEventHandler::TerraformComplete(const CUnit* unit, const CUnit* build)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::MoveCtrlNotify(const CUnit* unit, int data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CEventHandler::AllowWeaponTargetCheck(unsigned int attackerID, unsigned int attackerWeaponNum, unsigned int attackerWeaponDefID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AllowWeaponTarget(
	unsigned int attackerID,
	unsigned int targetID,
	unsigned int attackerWeaponNum,
	unsigned int attackerWeaponDefID,
	float* targetPriority
) {
	CONTROL_ITERATE_DEF_TRUE(AllowWeaponTarget, attackerID, targetID, attackerWeaponNum, attackerWeaponDefID, targetPriority)
}


bool CEventHandler::AllowWeaponInterceptTarget(const CUnit* interceptorUnit, const CWeapon* interceptorWeapon, const CProjectile* interceptorTarget)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::UnitPreDamaged(
	const CUnit* unit,
	const CUnit* attacker,
	float damage,
	int weaponDefID,
	int projectileID,
	bool paralyzer,
	float* newDamage,
	float* impulseMult
) {
	CONTROL_ITERATE_DEF_FALSE(UnitPreDamaged, unit, attacker, damage, weaponDefID, projectileID, paralyzer, newDamage, impulseMult)
}


bool CEventHandler::FeaturePreDamaged(
	const CFeature* feature,
	const CUnit* attacker,
	float damage,
	int weaponDefID,
	int projectileID,
	float* newDamage,
	float* impulseMult
) {
	CONTROL_ITERATE_DEF_FALSE(FeaturePreDamaged, feature, attacker, damage, weaponDefID, projectileID, newDamage, impulseMult)
}


bool CEventHandler::ShieldPreDamaged(
	const CProjectile* projectile,
	const CWeapon* shieldEmitter,
	const CUnit* shieldCarrier,
	bool bounceProjectile,
	const CWeapon* beamEmitter,
	const CUnit* beamCarrier
) {
	CONTROL_ITERATE_DEF_FALSE(ShieldPreDamaged, projectile, shieldEmitter, shieldCarrier, bounceProjectile, beamEmitter, beamCarrier)
}


bool CEventHandler::SyncedActionFallback(const string& line, int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

#define ITERATE_EVENTCLIENTLIST(name, ...) \
	for (int i = 0; i < list##name.size(); ) { \
		CEventClient* ec = list##name[i]; \
		ec->name(__VA_ARGS__); \
		if (i < list##name.size() && ec == list##name[i]) \
			++i; /* the call-in may remove itself from the list */ \
	}


void CEventHandler::Save(zipFile archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::GamePreload()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::GameStart()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::GameOver(const std::vector<unsigned char>& winningAllyTeams)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::GamePaused(int playerID, bool paused)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::GameFrame(int gameFrame)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::GameID(const unsigned char* gameID, unsigned int numBytes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::TeamDied(int teamID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::TeamChanged(int teamID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::PlayerChanged(int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::PlayerAdded(int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::PlayerRemoved(int playerID, int reason)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void CEventHandler::UnitHarvestStorageFull(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void CEventHandler::CollectGarbage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::DbgTimingInfo(DbgTimingInfoType type, const spring_time start, const spring_time end)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::Load(IArchive* archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CEventHandler::SunChanged()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEventHandler::ViewResize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::GameProgress(int gameFrame)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


#define DRAW_CALLIN(name)                                            \
  void CEventHandler:: Draw ## name ()                               \
  {                                                                  \
    if (listDraw ## name.empty())                                    \
      return;                                                        \
    LuaOpenGL::EnableDraw ## name ();                                \
    listDraw ## name [0]->Draw ## name ();                           \
                                                                     \
    for (int i = 1; i < listDraw ## name.size(); ) {                 \
      LuaOpenGL::ResetDraw ## name ();                               \
      CEventClient* ec = listDraw ## name [i];                       \
      ec-> Draw ## name ();                                          \
      if (i < listDraw ## name.size() && ec == listDraw ## name [i]) \
	    ++i;                                                         \
    }                                                                \
                                                                     \
    LuaOpenGL::DisableDraw ## name ();                               \
  }

DRAW_CALLIN(Genesis)
DRAW_CALLIN(World)
DRAW_CALLIN(WorldPreUnit)
DRAW_CALLIN(WorldShadow)
DRAW_CALLIN(WorldReflection)
DRAW_CALLIN(WorldRefraction)
DRAW_CALLIN(GroundPreForward)
DRAW_CALLIN(GroundPreDeferred)
DRAW_CALLIN(GroundPostDeferred)
DRAW_CALLIN(UnitsPostDeferred)
DRAW_CALLIN(FeaturesPostDeferred)
DRAW_CALLIN(ScreenEffects)
DRAW_CALLIN(Screen)
DRAW_CALLIN(InMiniMap)
DRAW_CALLIN(InMiniMapBackground)


#define DRAW_ENTITY_CALLIN(name, args, args2)     \
  bool CEventHandler:: Draw ## name args        \
  {                                               \
    bool skipEngineDrawing = false;               \
    for (int i = 0; i < listDraw ## name.size(); ) { \
      CEventClient* ec = listDraw ## name [i];    \
      skipEngineDrawing |= ec-> Draw ## name args2 ; \
      if (i < listDraw ## name.size() && ec == listDraw ## name [i]) \
	    ++i;                                      \
    } \
    return skipEngineDrawing; \
  }

DRAW_ENTITY_CALLIN(Unit, (const CUnit* unit), (unit))
DRAW_ENTITY_CALLIN(Feature, (const CFeature* feature), (feature))
DRAW_ENTITY_CALLIN(Shield, (const CUnit* unit, const CWeapon* weapon), (unit, weapon))
DRAW_ENTITY_CALLIN(Projectile, (const CProjectile* projectile), (projectile))

/******************************************************************************/
/******************************************************************************/

#define CONTROL_REVERSE_ITERATE_DEF_TRUE(name, ...) \
	for (int i = list##name.size() - 1; i >= 0; --i) { \
		CEventClient* ec = list##name[i]; \
		if (ec->name(__VA_ARGS__)) \
			return true; \
	}

#define CONTROL_REVERSE_ITERATE_STRING(name, ...) \
	for (int i = list##name.size() - 1; i >= 0; --i) { \
		CEventClient* ec = list##name[i]; \
		const std::string& str = ec->name(__VA_ARGS__); \
		if (!str.empty()) \
			return str; \
	}

bool CEventHandler::CommandNotify(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::KeyPress(int key, bool isRepeat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::KeyRelease(int key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::TextInput(const std::string& utf8)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::MouseWheel(bool up, float value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CEventHandler::JoystickEvent(const std::string& event, int val1, int val2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CEventHandler::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string CEventHandler::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::AddConsoleLine(const std::string& msg, const std::string& section, int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CEventHandler::LastMessagePosition(const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::GroupChanged(int groupID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CEventHandler::GameSetup(const string& state, bool& ready,
                                  const map<int, string>& playerStates)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEventHandler::DownloadQueued(int ID, const string& archiveName, const string& archiveType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEventHandler::DownloadStarted(int ID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEventHandler::DownloadFinished(int ID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEventHandler::DownloadFailed(int ID, int errorID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CEventHandler::DownloadProgress(int ID, long downloaded, long total)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string CEventHandler::WorldTooltip(const CUnit* unit,
                                   const CFeature* feature,
                                   const float3* groundPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CEventHandler::MapDrawCmd(int playerID, int type,
                               const float3* pos0, const float3* pos1,
                                   const string* label)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void CEventHandler::MetalMapChanged(const int x, const int z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

