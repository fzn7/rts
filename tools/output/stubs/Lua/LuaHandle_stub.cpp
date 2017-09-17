/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaHandle.h"

#include "LuaGaia.h"
#include "LuaRules.h"
#include "LuaUI.h"

#include "LuaCallInCheck.h"
#include "LuaConfig.h"
#include "LuaHashString.h"
#include "LuaOpenGL.h"
#include "LuaBitOps.h"
#include "LuaMathExtra.h"
#include "LuaUtils.h"
#include "LuaZip.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Net/Protocol/BaseNetProtocol.h"
#include "Game/UI/KeyCodes.h"
#include "Game/UI/KeySet.h"
#include "Game/UI/KeyBindings.h"
#include "Game/UI/MiniMap.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/WeaponProjectiles/WeaponProjectile.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/GlobalConfig.h"
#include "System/Rectangle.h"
#include "System/ScopedFPUSettings.h"
#include "System/Log/ILog.h"
#include "System/Input/KeyInput.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Platform/SDL1_keysym.h"

#include "LuaInclude.h"

#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_mouse.h>


#include <string>

bool CLuaHandle::devMode = false;
bool CLuaHandle::modUICtrl = true;


/******************************************************************************/
/******************************************************************************/

void CLuaHandle::PushTracebackFuncToRegistry(lua_State* L)
{
    //stub method
}



static int handlepanic(lua_State* L)
{
    //stub method
}



CLuaHandle::CLuaHandle(const string& _name, int _order, bool _userMode, bool _synced)
	: CEventClient(_name, _order, _synced)
	, userMode(_userMode)
	, killMe(false)
	, callinErrors(0)
{
    //stub method
}


CLuaHandle::~CLuaHandle()
{
    //stub method
}


// can be called from a handler constructor or FreeHandler
// we care about calling Shutdown only in the latter case!
void CLuaHandle::KillLua(bool inFreeHandler)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int CLuaHandle::KillActiveHandle(lua_State* L)
{
    //stub method
}


/******************************************************************************/

bool CLuaHandle::AddEntriesToTable(lua_State* L, const char* name,
                                   bool (*entriesFunc)(lua_State*))
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void CLuaHandle::CheckStack()
{
    //stub method
}


int CLuaHandle::XCall(lua_State* srcState, const string& funcName)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int CLuaHandle::RunCallInTraceback(
	lua_State* L,
	const LuaHashString* hs,
	int inArgs,
	int outArgs,
	int errFuncIndex,
	std::string& tracebackMsg,
	bool popErrorFunc
) {
	// do not signal floating point exceptions in user Lua code
	ScopedDisableFpuExceptions fe;

	struct ScopedLuaCall {
	public:
		ScopedLuaCall(
			CLuaHandle* handle,
			lua_State* state,
			const LuaHashString* func,
			int _nInArgs,
			int _nOutArgs,
			int _errFuncIdx,
			bool _popErrFunc
		)
			: luaState(state)
			, luaHandle(handle)

			, nInArgs(_nInArgs)
			, nOutArgs(_nOutArgs)
			, errFuncIdx(_errFuncIdx)
			, popErrFunc(_popErrFunc)
		{
			handle->SetHandleRunning(state, true); // inc
			const bool canDraw = LuaOpenGL::IsDrawingEnabled(state);
			SMatrixStateData prevMatState;
			GLMatrixStateTracker& matTracker = GetLuaContextData(state)->glMatrixTracker;
			if (canDraw) {
				prevMatState = matTracker.PushMatrixState();
				LuaOpenGL::InitMatrixState(state, func);
			}

			top = lua_gettop(state);
			// note1: disable GC outside of this scope to prevent sync errors and similar
			// note2: we collect garbage now in its own callin "CollectGarbage"
			// lua_gc(L, LUA_GCRESTART, 0);
			error = lua_pcall(state, nInArgs, nOutArgs, errFuncIdx);
			// only run GC inside of "SetHandleRunning(L, true) ... SetHandleRunning(L, false)"!
			lua_gc(state, LUA_GCSTOP, 0);
			if (canDraw) {
				LuaOpenGL::CheckMatrixState(state, func, error);
				matTracker.PopMatrixState(prevMatState);
			}

			handle->SetHandleRunning(state, false); // dec
		}

		~ScopedLuaCall() {
			assert(!popErrFunc); // deprecated!
			if (popErrFunc) {
				lua_remove(luaState, errFuncIdx);
			}
		}

		void CheckFixStack(std::string& trace) {
			// note: assumes error-handler has not been popped yet (!)
			const int outArgs = (lua_gettop(luaState) - (GetTop() - 1)) + nInArgs;

			if (GetError() == 0) {
				if (nOutArgs != LUA_MULTRET) {
					if (outArgs != nOutArgs) {
						LOG_L(L_ERROR, "Internal Lua error: %d return values, %d expected", outArgs, nOutArgs);
						if (outArgs > nOutArgs)
							lua_pop(luaState, outArgs - nOutArgs);
					}
				} else {
					if (outArgs < 0) {
						LOG_L(L_ERROR, "Internal Lua error: stack corrupted");
					}
				}
			} else {
				const int dbgOutArgs = 1; // the traceback string

				if (outArgs > dbgOutArgs) {
					LOG_L(L_ERROR, "Internal Lua error: %i too many elements on the stack", outArgs - dbgOutArgs);
					lua_pop(luaState, outArgs - dbgOutArgs); // only leave traceback str on the stack
				} else if (outArgs < dbgOutArgs) {
					LOG_L(L_ERROR, "Internal Lua error: stack corrupted");
					lua_pushnil(luaState); // to make the code below valid
				}

				trace += "[Internal Lua error: Call failure] ";
				trace += luaL_optstring(luaState, -1, "[No traceback returned]");
				lua_pop(luaState, 1); // pop traceback string

				// log only errors that lead to a crash
				luaHandle->callinErrors += (GetError() == LUA_ERRRUN);
			}
		}

		int GetTop() const { return top; }
		int GetError() const { return error; }

	private:
		lua_State* luaState;
		CLuaHandle* luaHandle;

		int nInArgs;
		int nOutArgs;
		int errFuncIdx;
		bool popErrFunc;

		int top;
		int error;
	};

	// TODO: use closure so we do not need to copy args
	ScopedLuaCall call(this, L, hs, inArgs, outArgs, errFuncIndex, popErrorFunc);
	call.CheckFixStack(tracebackMsg);

	return (call.GetError());
}


bool CLuaHandle::RunCallInTraceback(lua_State* L, const LuaHashString& hs, int inArgs, int outArgs, int errFuncIndex, bool popErrFunc)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

bool CLuaHandle::LoadCode(lua_State* L, const string& code, const string& debug)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

void CLuaHandle::Shutdown()
{
    //stub method
}


bool CLuaHandle::GotChatMsg(const string& msg, int playerID)
{
    //stub method
}


void CLuaHandle::Load(IArchive* archive)
{
    //stub method
}


bool CLuaHandle::HasCallIn(lua_State* L, const string& name)
{
    //stub method
}


bool CLuaHandle::UpdateCallIn(lua_State* L, const string& name)
{
    //stub method
}


void CLuaHandle::GamePreload()
{
    //stub method
}

void CLuaHandle::GameStart()
{
    //stub method
}

void CLuaHandle::GameOver(const std::vector<unsigned char>& winningAllyTeams)
{
    //stub method
}


void CLuaHandle::GamePaused(int playerID, bool paused)
{
    //stub method
}


void CLuaHandle::GameFrame(int frameNum)
{
    //stub method
}


void CLuaHandle::GameID(const unsigned char* gameID, unsigned int numBytes)
{
    //stub method
}


void CLuaHandle::TeamDied(int teamID)
{
    //stub method
}


void CLuaHandle::TeamChanged(int teamID)
{
    //stub method
}


void CLuaHandle::PlayerChanged(int playerID)
{
    //stub method
}


void CLuaHandle::PlayerAdded(int playerID)
{
    //stub method
}


void CLuaHandle::PlayerRemoved(int playerID, int reason)
{
    //stub method
}


/******************************************************************************/

inline void CLuaHandle::UnitCallIn(const LuaHashString& hs, const CUnit* unit)
{
    //stub method
}


void CLuaHandle::UnitCreated(const CUnit* unit, const CUnit* builder)
{
    //stub method
}


void CLuaHandle::UnitFinished(const CUnit* unit)
{
    //stub method
}


void CLuaHandle::UnitFromFactory(const CUnit* unit,
                                 const CUnit* factory, bool userOrders)
{
    //stub method
}


void CLuaHandle::UnitReverseBuilt(const CUnit* unit)
{
    //stub method
}


void CLuaHandle::UnitDestroyed(const CUnit* unit, const CUnit* attacker)
{
    //stub method
}


void CLuaHandle::UnitTaken(const CUnit* unit, int oldTeam, int newTeam)
{
    //stub method
}


void CLuaHandle::UnitGiven(const CUnit* unit, int oldTeam, int newTeam)
{
    //stub method
}


void CLuaHandle::UnitIdle(const CUnit* unit)
{
    //stub method
}


void CLuaHandle::UnitCommand(const CUnit* unit, const Command& command)
{
    //stub method
}


void CLuaHandle::UnitCmdDone(const CUnit* unit, const Command& command)
{
    //stub method
}


void CLuaHandle::UnitDamaged(
	const CUnit* unit,
	const CUnit* attacker,
	float damage,
	int weaponDefID,
	int projectileID,
	bool paralyzer)
{
    //stub method
}

void CLuaHandle::UnitStunned(
	const CUnit* unit,
	bool stunned)
{
    //stub method
}

void CLuaHandle::UnitExperience(const CUnit* unit, float oldExperience)
{
    //stub method
}


void CLuaHandle::UnitHarvestStorageFull(const CUnit* unit)
{
    //stub method
}


/******************************************************************************/

void CLuaHandle::UnitSeismicPing(const CUnit* unit, int allyTeam,
                                 const float3& pos, float strength)
{
    //stub method
}


/******************************************************************************/

void CLuaHandle::LosCallIn(const LuaHashString& hs,
                           const CUnit* unit, int allyTeam)
{
    //stub method
}


void CLuaHandle::UnitEnteredRadar(const CUnit* unit, int allyTeam)
{
    //stub method
}


void CLuaHandle::UnitEnteredLos(const CUnit* unit, int allyTeam)
{
    //stub method
}


void CLuaHandle::UnitLeftRadar(const CUnit* unit, int allyTeam)
{
    //stub method
}


void CLuaHandle::UnitLeftLos(const CUnit* unit, int allyTeam)
{
    //stub method
}


/******************************************************************************/

void CLuaHandle::UnitLoaded(const CUnit* unit, const CUnit* transport)
{
    //stub method
}


void CLuaHandle::UnitUnloaded(const CUnit* unit, const CUnit* transport)
{
    //stub method
}


/******************************************************************************/

void CLuaHandle::UnitEnteredWater(const CUnit* unit)
{
    //stub method
}


void CLuaHandle::UnitEnteredAir(const CUnit* unit)
{
    //stub method
}


void CLuaHandle::UnitLeftWater(const CUnit* unit)
{
    //stub method
}


void CLuaHandle::UnitLeftAir(const CUnit* unit)
{
    //stub method
}


/******************************************************************************/

void CLuaHandle::UnitCloaked(const CUnit* unit)
{
    //stub method
}


void CLuaHandle::UnitDecloaked(const CUnit* unit)
{
    //stub method
}



void CLuaHandle::UnitUnitCollision(const CUnit* collider, const CUnit* collidee)
{
    //stub method
}

void CLuaHandle::UnitFeatureCollision(const CUnit* collider, const CFeature* collidee)
{
    //stub method
}

void CLuaHandle::UnitMoveFailed(const CUnit* unit)
{
    //stub method
}


void CLuaHandle::RenderUnitDestroyed(const CUnit* unit)
{
    //stub method
}


/******************************************************************************/

void CLuaHandle::FeatureCreated(const CFeature* feature)
{
    //stub method
}

void CLuaHandle::FeatureDestroyed(const CFeature* feature)
{
    //stub method
}

void CLuaHandle::FeatureDamaged(
	const CFeature* feature,
	const CUnit* attacker,
	float damage,
	int weaponDefID,
	int projectileID)
{
    //stub method
}


/******************************************************************************/

void CLuaHandle::ProjectileCreated(const CProjectile* p)
{
    //stub method
}


void CLuaHandle::ProjectileDestroyed(const CProjectile* p)
{
    //stub method
}

/******************************************************************************/

bool CLuaHandle::Explosion(int weaponDefID, int projectileID, const float3& pos, const CUnit* owner)
{
    //stub method
}


void CLuaHandle::StockpileChanged(const CUnit* unit,
                                  const CWeapon* weapon, int oldCount)
{
    //stub method
}



bool CLuaHandle::RecvLuaMsg(const string& msg, int playerID)
{
    //stub method
}


/******************************************************************************/

void CLuaHandle::HandleLuaMsg(int playerID, int script, int mode, const std::vector<boost::uint8_t>& data)
{
    //stub method
}


/******************************************************************************/


void CLuaHandle::Save(zipFile archive)
{
    //stub method
}


void CLuaHandle::UnsyncedHeightMapUpdate(const SRectangle& rect)
{
    //stub method
}


void CLuaHandle::Update()
{
    //stub method
}


void CLuaHandle::ViewResize()
{
    //stub method
}


bool CLuaHandle::DefaultCommand(const CUnit* unit,
                                const CFeature* feature, int& cmd)
{
    //stub method
}


void CLuaHandle::RunDrawCallIn(const LuaHashString& hs)
{
    //stub method
}

#define DRAW_CALLIN(name)                     \
void CLuaHandle::name()                       \
{
    //stub method
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


void CLuaHandle::DrawScreen()
{
    //stub method
}


void CLuaHandle::DrawScreenEffects()
{
    //stub method
}


void CLuaHandle::DrawInMiniMap()
{
    //stub method
}


void CLuaHandle::DrawInMiniMapBackground()
{
    //stub method
}


void CLuaHandle::GameProgress(int frameNum )
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

bool CLuaHandle::KeyPress(int key, bool isRepeat)
{
    //stub method
}


bool CLuaHandle::KeyRelease(int key)
{
    //stub method
}


bool CLuaHandle::TextInput(const std::string& utf8)
{
    //stub method
}


bool CLuaHandle::MousePress(int x, int y, int button)
{
    //stub method
}


void CLuaHandle::MouseRelease(int x, int y, int button)
{
    //stub method
}


bool CLuaHandle::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
}


bool CLuaHandle::MouseWheel(bool up, float value)
{
    //stub method
}

bool CLuaHandle::JoystickEvent(const std::string& event, int val1, int val2)
{
    //stub method
}

bool CLuaHandle::IsAbove(int x, int y)
{
    //stub method
}


string CLuaHandle::GetTooltip(int x, int y)
{
    //stub method
}


bool CLuaHandle::CommandNotify(const Command& cmd)
{
    //stub method
}


bool CLuaHandle::AddConsoleLine(const string& msg, const string& section, int level)
{
    //stub method
}



bool CLuaHandle::GroupChanged(int groupID)
{
    //stub method
}



string CLuaHandle::WorldTooltip(const CUnit* unit,
                                const CFeature* feature,
                                const float3* groundPos)
{
    //stub method
}


bool CLuaHandle::MapDrawCmd(int playerID, int type,
                            const float3* pos0,
                            const float3* pos1,
                            const string* label)
{
    //stub method
}


bool CLuaHandle::GameSetup(const string& state, bool& ready,
                           const map<int, string>& playerStates)
{
    //stub method
}



const char* CLuaHandle::RecvSkirmishAIMessage(int aiTeam, const char* inData, int inSize)
{
    //stub method
}

void CLuaHandle::DownloadQueued(int ID, const string& archiveName, const string& archiveType)
{
    //stub method
}

void CLuaHandle::DownloadStarted(int ID)
{
    //stub method
}

void CLuaHandle::DownloadFinished(int ID)
{
    //stub method
}

void CLuaHandle::DownloadFailed(int ID, int errorID)
{
    //stub method
}

void CLuaHandle::DownloadProgress(int ID, long downloaded, long total)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

CONFIG(float, MaxLuaGarbageCollectionTime ).defaultValue(5.f).minimumValue(1.0f).description("in MilliSecs");


void CLuaHandle::CollectGarbage()
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

bool CLuaHandle::AddBasicCalls(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetName(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetSynced(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetFullCtrl(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetFullRead(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetCtrlTeam(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetReadTeam(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetReadAllyTeam(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetSelectTeam(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetGlobal(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetRegistry(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutIsEngineMinVersion(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutGetCallInList(lua_State* L)
{
    //stub method
}


int CLuaHandle::CallOutUpdateCallIn(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

