#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaHandle.h"

#include "LuaGaia.h"
#include "LuaRules.h"
#include "LuaUI.h"

#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/UI/KeyBindings.h"
#include "Game/UI/KeyCodes.h"
#include "Game/UI/KeySet.h"
#include "Game/UI/MiniMap.h"
#include "LuaBitOps.h"
#include "LuaCallInCheck.h"
#include "LuaConfig.h"
#include "LuaHashString.h"
#include "LuaMathExtra.h"
#include "LuaOpenGL.h"
#include "LuaUtils.h"
#include "LuaZip.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/GlobalConfig.h"
#include "System/Input/KeyInput.h"
#include "System/Log/ILog.h"
#include "System/Platform/SDL1_keysym.h"
#include "System/Rectangle.h"
#include "System/ScopedFPUSettings.h"

#include "LuaInclude.h"

#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_mouse.h>

#include <string>

bool CLuaHandle::devMode = false;
bool CLuaHandle::modUICtrl = true;

/******************************************************************************/
/******************************************************************************/

void
CLuaHandle::PushTracebackFuncToRegistry(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
handlepanic(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CLuaHandle::CLuaHandle(const string& _name,
                       int _order,
                       bool _userMode,
                       bool _synced)
  : CEventClient(_name, _order, _synced)
  , userMode(_userMode)
  , killMe(false)
  , callinErrors(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CLuaHandle::~CLuaHandle()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// can be called from a handler constructor or FreeHandler
// we care about calling Shutdown only in the latter case!
void
CLuaHandle::KillLua(bool inFreeHandler)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
CLuaHandle::KillActiveHandle(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

bool
CLuaHandle::AddEntriesToTable(lua_State* L,
                              const char* name,
                              bool (*entriesFunc)(lua_State*))
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CLuaHandle::CheckStack()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::XCall(lua_State* srcState, const string& funcName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
CLuaHandle::RunCallInTraceback(lua_State* L,
                               const LuaHashString* hs,
                               int inArgs,
                               int outArgs,
                               int errFuncIndex,
                               std::string& tracebackMsg,
                               bool popErrorFunc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::RunCallInTraceback(lua_State* L,
                               const LuaHashString& hs,
                               int inArgs,
                               int outArgs,
                               int errFuncIndex,
                               bool popErrFunc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
CLuaHandle::LoadCode(lua_State* L, const string& code, const string& debug)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CLuaHandle::Shutdown()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::GotChatMsg(const string& msg, int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::Load(IArchive* archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::HasCallIn(lua_State* L, const string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::UpdateCallIn(lua_State* L, const string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::GamePreload()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::GameStart()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::GameOver(const std::vector<unsigned char>& winningAllyTeams)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::GamePaused(int playerID, bool paused)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::GameFrame(int frameNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::GameID(const unsigned char* gameID, unsigned int numBytes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::TeamDied(int teamID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::TeamChanged(int teamID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::PlayerChanged(int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::PlayerAdded(int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::PlayerRemoved(int playerID, int reason)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

inline void
CLuaHandle::UnitCallIn(const LuaHashString& hs, const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitCreated(const CUnit* unit, const CUnit* builder)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitFinished(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitFromFactory(const CUnit* unit,
                            const CUnit* factory,
                            bool userOrders)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitReverseBuilt(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitDestroyed(const CUnit* unit, const CUnit* attacker)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitTaken(const CUnit* unit, int oldTeam, int newTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitGiven(const CUnit* unit, int oldTeam, int newTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitIdle(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitCommand(const CUnit* unit, const Command& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitCmdDone(const CUnit* unit, const Command& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitDamaged(const CUnit* unit,
                        const CUnit* attacker,
                        float damage,
                        int weaponDefID,
                        int projectileID,
                        bool paralyzer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitStunned(const CUnit* unit, bool stunned)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitExperience(const CUnit* unit, float oldExperience)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitHarvestStorageFull(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::UnitSeismicPing(const CUnit* unit,
                            int allyTeam,
                            const float3& pos,
                            float strength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::LosCallIn(const LuaHashString& hs, const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitEnteredRadar(const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitEnteredLos(const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitLeftRadar(const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitLeftLos(const CUnit* unit, int allyTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::UnitLoaded(const CUnit* unit, const CUnit* transport)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitUnloaded(const CUnit* unit, const CUnit* transport)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::UnitEnteredWater(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitEnteredAir(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitLeftWater(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitLeftAir(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::UnitCloaked(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitDecloaked(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitUnitCollision(const CUnit* collider, const CUnit* collidee)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitFeatureCollision(const CUnit* collider,
                                 const CFeature* collidee)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnitMoveFailed(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::RenderUnitDestroyed(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::FeatureCreated(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::FeatureDestroyed(const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::FeatureDamaged(const CFeature* feature,
                           const CUnit* attacker,
                           float damage,
                           int weaponDefID,
                           int projectileID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::ProjectileCreated(const CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::ProjectileDestroyed(const CProjectile* p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

bool
CLuaHandle::Explosion(int weaponDefID,
                      int projectileID,
                      const float3& pos,
                      const CUnit* owner)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::StockpileChanged(const CUnit* unit,
                             const CWeapon* weapon,
                             int oldCount)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::RecvLuaMsg(const string& msg, int playerID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::HandleLuaMsg(int playerID,
                         int script,
                         int mode,
                         const std::vector<boost::uint8_t>& data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CLuaHandle::Save(zipFile archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::ViewResize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::DefaultCommand(const CUnit* unit, const CFeature* feature, int& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::RunDrawCallIn(const LuaHashString& hs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#define DRAW_CALLIN(name)                                                      \
    void CLuaHandle::name()                                                    \
    {                                                                          \
        static const LuaHashString cmdStr(#name);                              \
        RunDrawCallIn(cmdStr);                                                 \
    }

DRAW_CALLIN(DrawGenesis)
DRAW_CALLIN(DrawWorld)
DRAW_CALLIN(DrawWorldPreUnit)
DRAW_CALLIN(DrawWorldShadow)
DRAW_CALLIN(DrawWorldReflection)
DRAW_CALLIN(DrawWorldRefraction)
DRAW_CALLIN(DrawGroundPreForward)
DRAW_CALLIN(DrawGroundPreDeferred)
DRAW_CALLIN(DrawGroundPostDeferred)
DRAW_CALLIN(DrawUnitsPostDeferred)
DRAW_CALLIN(DrawFeaturesPostDeferred)

void
CLuaHandle::DrawScreen()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::DrawScreenEffects()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::DrawInMiniMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::DrawInMiniMapBackground()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::GameProgress(int frameNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
CLuaHandle::KeyPress(int key, bool isRepeat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::KeyRelease(int key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::TextInput(const std::string& utf8)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::MouseWheel(bool up, float value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::JoystickEvent(const std::string& event, int val1, int val2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string
CLuaHandle::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::CommandNotify(const Command& cmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::AddConsoleLine(const string& msg, const string& section, int level)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::GroupChanged(int groupID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

string
CLuaHandle::WorldTooltip(const CUnit* unit,
                         const CFeature* feature,
                         const float3* groundPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::MapDrawCmd(int playerID,
                       int type,
                       const float3* pos0,
                       const float3* pos1,
                       const string* label)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CLuaHandle::GameSetup(const string& state,
                      bool& ready,
                      const map<int, string>& playerStates)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
CLuaHandle::RecvSkirmishAIMessage(int aiTeam, const char* inData, int inSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::DownloadQueued(int ID,
                           const string& archiveName,
                           const string& archiveType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::DownloadStarted(int ID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::DownloadFinished(int ID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::DownloadFailed(int ID, int errorID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CLuaHandle::DownloadProgress(int ID, long downloaded, long total)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

CONFIG(float, MaxLuaGarbageCollectionTime)
  .defaultValue(5.f)
  .minimumValue(1.0f)
  .description("in MilliSecs");

void
CLuaHandle::CollectGarbage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
CLuaHandle::AddBasicCalls(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetName(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetSynced(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetFullCtrl(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetFullRead(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetCtrlTeam(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetReadTeam(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetReadAllyTeam(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetSelectTeam(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetGlobal(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetRegistry(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutIsEngineMinVersion(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutGetCallInList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CLuaHandle::CallOutUpdateCallIn(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
