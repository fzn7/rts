#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaUnsyncedCtrl.h"

#include "LuaInclude.h"
#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaUtils.h"
#include "LuaTextures.h"
#include "LuaOpenGLUtils.h"

#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Game/Camera/CameraController.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/InMapDraw.h"
#include "Game/InMapDrawModel.h"
#include "Game/UI/CommandColors.h"
#include "Game/UI/CursorIcons.h"
#include "Game/UI/GuiHandler.h"
#include "Game/UI/InfoConsole.h"
#include "Game/UI/KeyCodes.h"
#include "Game/UI/KeySet.h"
#include "Game/UI/KeyBindings.h"
#include "Game/UI/MiniMap.h"
#include "Game/UI/MouseHandler.h"
#include "Game/UI/Groups/Group.h"
#include "Game/UI/Groups/GroupHandler.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/BaseGroundTextures.h"
#include "Net/Protocol/NetProtocol.h"
#include "Net/GameServer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/Env/Decals/DecalsDrawerGL4.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/CommandDrawer.h"
#include "Rendering/IconHandler.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/FeatureDrawer.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/GlobalConfig.h"
#include "System/Log/DefaultFilter.h"
#include "System/Log/ILog.h"
#include "System/Net/PackPacket.h"
#include "System/Platform/Misc.h"
#include "System/Util.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/DataDirLocater.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Platform/Watchdog.h"
#include "System/Platform/WindowManagerHelper.h"
#include "System/Sync/HsiehHash.h"

#include <boost/cstdint.hpp>

#if !defined(HEADLESS) && !defined(NO_SOUND)
#include "System/Sound/OpenAL/EFX.h"
#include "System/Sound/OpenAL/EFXPresets.h"
#endif

#include <map>
#include <set>
#include <cctype>
#include <cfloat>

#include <fstream>

#include <SDL_clipboard.h>
#include <SDL_mouse.h>

using std::min;
using std::max;

// MinGW defines this for a WINAPI function
#undef SendMessage
#undef CreateDirectory

const int CMD_INDEX_OFFSET = 1; // starting index for command descriptions


/******************************************************************************/
/******************************************************************************/

bool LuaUnsyncedCtrl::PushEntries(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
//  Parsing helpers
//

static inline CProjectile* ParseRawProjectile(lua_State* L, const char* caller, int index, bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static inline CUnit* ParseRawUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline CFeature* ParseRawFeature(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static inline CUnit* ParseAllyUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static inline CUnit* ParseCtrlUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline CFeature* ParseCtrlFeature(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static inline CUnit* ParseSelectUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/
/******************************************************************************/
//
//  The call-outs
//

int LuaUnsyncedCtrl::Echo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::Log(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static string ParseMessage(lua_State* L, const string& msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void PrintMessage(lua_State* L, const string& msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SendMessage(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SendMessageToSpectators(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SendMessageToPlayer(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SendMessageToTeam(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SendMessageToAllyTeam(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::LoadSoundDef(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::PlaySoundFile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::PlaySoundStream(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::StopSoundStream(lua_State*)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
int LuaUnsyncedCtrl::PauseSoundStream(lua_State*)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
int LuaUnsyncedCtrl::SetSoundStreamVolume(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetSoundEffectParams(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::AddWorldIcon(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::AddWorldText(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::AddWorldUnit(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::DrawUnitCommands(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

static CCameraController::StateMap ParseCamStateMap(lua_State* L, int tableIdx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetCameraTarget(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetCameraState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::SelectUnitArray(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SelectUnitMap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::SetTeamColor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::AssignMouseCursor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::ReplaceMouseCursor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedCtrl::SetCustomCommandDrawData(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::SetDrawSky(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetDrawWater(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetDrawGround(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetDrawGroundDeferred(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetDrawModelsDeferred(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::SetWaterParams(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



static bool ParseLight(lua_State* L, GL::Light& light, const int tblIdx, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::AddMapLight(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::AddModelLight(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::UpdateMapLight(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::UpdateModelLight(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static bool AddLightTrackingTarget(lua_State* L, GL::Light* light, bool trackEnable, bool trackUnit, const char* caller)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// set a map-illuminating light to start/stop tracking
// the position of a moving object (unit or projectile)
int LuaUnsyncedCtrl::SetMapLightTrackingState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// set a model-illuminating light to start/stop tracking
// the position of a moving object (unit or projectile)
int LuaUnsyncedCtrl::SetModelLightTrackingState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::SetMapShader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetMapSquareTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static MapTextureData ParseLuaTextureData(lua_State* L, bool mapTex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetMapShadingTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetSkyBoxTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedCtrl::SetUnitNoDraw(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetUnitNoMinimap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetUnitNoSelect(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetUnitLeaveTracks(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetFeatureNoDraw(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetFeatureFade(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/

int LuaUnsyncedCtrl::AddUnitIcon(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::FreeUnitIcon(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

// TODO: move this to LuaVFS?
int LuaUnsyncedCtrl::ExtractModArchiveFile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
// moved from LuaUI
//
/******************************************************************************/
/******************************************************************************/


int LuaUnsyncedCtrl::SendCommands(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int SetActiveCommandByIndex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static int SetActiveCommandByAction(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetActiveCommand(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::LoadCmdColorsConfig(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::LoadCtrlPanelConfig(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::ForceLayoutUpdate(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::WarpMouse(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetMouseCursor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedCtrl::SetClipboard(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedCtrl::SetCameraOffset(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::SetLosViewColors(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

#define SET_IN_OVERLAY_WARNING \
	if (lua_isboolean(L, 3)) { \
		static bool shown = false; \
		if (!shown) { \
			LOG_L(L_WARNING, "%s: third parameter \"setInOverlay\" is deprecated", __FUNCTION__); \
			shown = true; \
		} \
	}

int LuaUnsyncedCtrl::GetConfigInt(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetConfigInt(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::GetConfigString(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetConfigString(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::CreateDir(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int ReloadOrRestart(const std::string& springArgs, const std::string& scriptText, bool isStart=false) {
	if (springArgs.empty() && !isStart) {
		// signal SpringApp
		gameSetup->setupText = scriptText;
		gu->globalReload = true;

		LOG("[%s] Spring \"%s\" should be reloading", __FUNCTION__, (Platform::GetProcessExecutableFile()).c_str());
	} else {
		const std::string springFullName = Platform::GetProcessExecutableFile();
		const std::string scriptFullName = dataDirLocater.GetWriteDirPath() + "script.txt";

		std::vector<std::string> processArgs;

		// arguments to Spring binary given by Lua code, if any
		if (!springArgs.empty()) {
			processArgs.push_back(springArgs);
		}

		if (!scriptText.empty()) {
			// create file 'script.txt' with contents given by Lua code
			std::ofstream scriptFile(scriptFullName.c_str());

			scriptFile.write(scriptText.c_str(), scriptText.size());
			scriptFile.close();

			processArgs.push_back(scriptFullName);
		}
		if (!isStart) {
			#ifdef _WIN32
				// else OpenAL crashes when using execvp
				ISound::Shutdown();
			#endif
			// close local socket to avoid "bind: Address already in use"
			SafeDelete(gameServer);
		}

		LOG("[%s] Spring \"%s\" should be restarting", __FUNCTION__, springFullName.c_str());
		Platform::ExecuteProcess(springFullName, processArgs, isStart);

		// only reached on failure
		return 1;
	}

	return 0;
}


int LuaUnsyncedCtrl::Reload(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::Restart(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::Start(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetWMIcon(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetWMCaption(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedCtrl::SetUnitDefIcon(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetUnitDefImage(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::SetUnitGroup(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static void ParseUnitMap(lua_State* L, const char* caller,
                         int table, vector<int>& unitIDs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void ParseUnitArray(lua_State* L, const char* caller,
                           int table, vector<int>& unitIDs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static bool CanGiveOrders(const lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::GiveOrder(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::GiveOrderToUnit(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::GiveOrderToUnitMap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::GiveOrderToUnitArray(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::GiveOrderArrayToUnitMap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::GiveOrderArrayToUnitArray(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static string GetRawMsg(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SendLuaUIMsg(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SendLuaGaiaMsg(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SendLuaRulesMsg(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedCtrl::SetShareLevel(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::ShareResources(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/


int LuaUnsyncedCtrl::SetLastMessagePosition(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::MarkerAddPoint(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::MarkerAddLine(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::MarkerErasePosition(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::SetDrawSelectionInfo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::SetBuildSpacing(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetBuildFacing(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::SetAtmosphere(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetSunLighting(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetSunParameters(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetSunManualControl(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedCtrl::SetSunDirection(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::SendSkirmishAIMessage(lua_State* L) {
	if (CLuaHandle::GetHandleSynced(L)) {
		return 0;
	}

	const int aiTeam = luaL_checkint(L, 1);
	const char* inData = luaL_checkstring(L, 2);

	std::vector<const char*> outData;

	luaL_checkstack(L, 2, __FUNCTION__);
	lua_pushboolean(L, eoh->SendLuaMessages(aiTeam, inData, outData));

	// push the AI response(s)
	lua_createtable(L, outData.size(), 0);
	for (unsigned int n = 0; n < outData.size(); n++) {
		lua_pushstring(L, outData[n]);
		lua_rawseti(L, -2, n + 1);
	}

	return 2;
}

/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::SetLogSectionFilterLevel(lua_State* L) {
	int logLevel = LOG_LEVEL_INFO;

	if (lua_israwnumber(L, 2)) {
		logLevel = lua_tonumber(L, 2);
	}
	if (lua_isstring(L, 2)) {
		const std::string& loglvlstr = StringToLower(lua_tostring(L, 2));

		if (loglvlstr == "debug") {
			logLevel = LOG_LEVEL_DEBUG;
		}
		else if (loglvlstr == "info") {
			logLevel = LOG_LEVEL_INFO;
		}
		else if (loglvlstr == "warning") {
			logLevel = LOG_LEVEL_WARNING;
		}
		else if (loglvlstr == "error") {
			logLevel = LOG_LEVEL_ERROR;
		}
		else if (loglvlstr == "fatal") {
			logLevel = LOG_LEVEL_FATAL;
		}
		else {
			return luaL_error(L, "Incorrect arguments to Spring.SetLogSectionFilterLevel(logsection, loglevel)");
		}
	}

	log_frontend_register_runtime_section(luaL_checkstring(L, 1), logLevel);
	return 0;
}

/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::ClearWatchDogTimer(lua_State* L) {
	if (lua_gettop(L) == 0) {
		Watchdog::ClearTimer();
		return 0;
	}

	if (lua_isstring(L, 1)) {
		Watchdog::ClearTimer(lua_tostring(L, 1));
	} else {
		Watchdog::ClearTimer("main");
	}

	return 0;
}

/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::PreloadUnitDefModel(lua_State* L) {
	const UnitDef* ud = unitDefHandler->GetUnitDefByID(luaL_checkint(L, 1));

	if (ud == nullptr)
		return 0;

	ud->PreloadModel();
	return 0;
}

int LuaUnsyncedCtrl::PreloadFeatureDefModel(lua_State* L) {
	const FeatureDef* fd = featureDefHandler->GetFeatureDefByID(luaL_checkint(L, 1));

	if (fd == nullptr)
		return 0;

	fd->PreloadModel();
	return 0;
}

/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedCtrl::CreateDecal(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::DestroyDecal(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetDecalPos(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetDecalSize(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetDecalRotation(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetDecalTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedCtrl::SetDecalAlpha(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


