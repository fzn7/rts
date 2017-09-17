/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaUnsyncedRead.h"

#include "LuaInclude.h"
#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaUtils.h"
#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Game/Game.h"
#include "Game/GameHelper.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Net/GameServer.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/TraceRay.h"
#include "Game/Camera/CameraController.h"
#include "Game/UI/GuiHandler.h"
#include "Game/UI/InfoConsole.h"
#include "Game/UI/KeyCodes.h"
#include "Game/UI/KeySet.h"
#include "Game/UI/KeyBindings.h"
#include "Game/UI/MiniMap.h"
#include "Game/UI/MouseHandler.h"
#include "Game/UI/PlayerRoster.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/BaseGroundTextures.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/IconHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/Env/Decals/DecalsDrawerGL4.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Sim/Features/Feature.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "Game/UI/Groups/Group.h"
#include "Game/UI/Groups/GroupHandler.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/Config/ConfigVariable.h"
#include "System/Input/KeyInput.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/LoadSave/demofile.h"
#include "System/LoadSave/DemoReader.h"
#include "System/Log/DefaultFilter.h"
#include "System/Platform/SDL1_keysym.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Misc/SpringTime.h"

#if !defined(HEADLESS) && !defined(NO_SOUND)
	#include "System/Sound/OpenAL/EFX.h"
	#include "System/Sound/OpenAL/EFXPresets.h"
#endif

#include <cctype>

#include <SDL_clipboard.h>
#include <SDL_keycode.h>
#include <SDL_mouse.h>

const int CMD_INDEX_OFFSET = 1; // starting index for command descriptions

/******************************************************************************/
/******************************************************************************/

bool LuaUnsyncedRead::PushEntries(lua_State* L)
{
    //stub method
}




/******************************************************************************/
/******************************************************************************/
//
//  Parsing helpers
//

static inline CUnit* ParseUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}

static inline CFeature* ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
}




static int GetSolidObjectLuaDraw(lua_State* L, const CSolidObject* obj)
{
    //stub method
}

static int GetSolidObjectNoDraw(lua_State* L, const CSolidObject* obj)
{
    //stub method
}




/******************************************************************************/
/******************************************************************************/
//
//  The call-outs
//

int LuaUnsyncedRead::IsReplay(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetReplayLength(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetModUICtrl(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetViewGeometry(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetWindowGeometry(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetScreenGeometry(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetMiniMapGeometry(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetMiniMapDualScreen(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::IsAboveMiniMap(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetDrawFrame(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetFrameTimeOffset(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetLastUpdateSeconds(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetHasLag(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::IsAABBInView(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::IsSphereInView(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::IsUnitAllied(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::IsUnitInView(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::IsUnitVisible(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::IsUnitIcon(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::IsUnitSelected(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetUnitLuaDraw(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetUnitNoDraw(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetUnitNoMinimap(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetUnitNoSelect(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetFeatureLuaDraw(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetFeatureNoDraw(lua_State* L)
{
    //stub method
}



int LuaUnsyncedRead::GetUnitTransformMatrix(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetUnitViewPosition(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

// FIXME -- copied from LuaSyncedRead.cpp, commonize
enum UnitAllegiance {
	AllUnits   = -1,
	MyUnits    = -2,
	AllyUnits  = -3,
	EnemyUnits = -4
};


// never instantiated directly
template<class T> class CWorldObjectQuadDrawer: public CReadMap::IQuadDrawer {
public:
	typedef std::vector<T*> ObjectList;
	typedef std::vector< const ObjectList* > ObjectVector;

	void ResetState() {
		objectLists.clear();
		objectLists.reserve(64);

		objectCount = 0;
	}

	unsigned int GetQuadCount() const { return (objectLists.size()); }
	unsigned int GetObjectCount() const { return objectCount; }

	const ObjectVector& GetObjectLists() { return objectLists; }

	void AddObjectList(const ObjectList* objects) {
		if (objects->empty())
			return;

		objectLists.push_back(objects);
		objectCount += objects->size();
	}

protected:
	// note: stores pointers to lists, not copies
	// its size equals the number of visible quads
	ObjectVector objectLists;

	unsigned int objectCount;
};


class CVisUnitQuadDrawer: public CWorldObjectQuadDrawer<CUnit> {
public:
	void DrawQuad(int x, int y) {
		const CQuadField::Quad& q = quadField->GetQuadAt(x, y);
		const ObjectList* o = &q.units;

		AddObjectList(o);
	}
};

class CVisFeatureQuadDrawer: public CWorldObjectQuadDrawer<CFeature> {
public:
	void DrawQuad(int x, int y) {
		const CQuadField::Quad& q = quadField->GetQuadAt(x, y);
		const ObjectList* o = &q.features;

		AddObjectList(o);
	}
};

class CVisProjectileQuadDrawer: public CWorldObjectQuadDrawer<CProjectile> {
public:
	void DrawQuad(int x, int y) {
		const CQuadField::Quad& q = quadField->GetQuadAt(x, y);
		const ObjectList* o = &q.projectiles;

		AddObjectList(o);
	}
};




int LuaUnsyncedRead::GetVisibleUnits(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetVisibleFeatures(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetVisibleProjectiles(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetLocalPlayerID(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetLocalTeamID(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetLocalAllyTeamID(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetSpectatingState(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetSelectedUnits(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetSelectedUnitsSorted(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetSelectedUnitsCounts(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetSelectedUnitsCount(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::IsGUIHidden(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::HaveShadows(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::HaveAdvShading(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetWaterMode(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetMapDrawMode(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetMapSquareTexture(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetLosViewColors(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetCameraNames(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetCameraState(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetCameraPosition(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetCameraDirection(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetCameraFOV(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetCameraVectors(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::WorldToScreenCoords(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::TraceScreenRay(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetPixelDir(lua_State* L)
{
    //stub method
}



/******************************************************************************/

static void AddPlayerToRoster(lua_State* L, int playerID, bool includePathingFlag)
{
    //stub method
}


int LuaUnsyncedRead::GetTeamColor(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetTeamOrigColor(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static void PushTimer(lua_State* L, const spring_time& time)
{
    //stub method
}

int LuaUnsyncedRead::GetTimer(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetFrameTimer(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::DiffTimers(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetSoundStreamTime(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetSoundEffectParams(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
//
// moved from LuaUI
//
/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetFPS(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetGameSpeed(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetActiveCommand(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetDefaultCommand(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetActiveCmdDescs(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetActiveCmdDesc(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetCmdDescIndex(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetBuildFacing(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetBuildSpacing(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetGatherMode(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetActivePage(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetMouseState(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetMouseCursor(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetMouseStartPosition(lua_State* L)
{
    //stub method
}

/******************************************************************************/

int LuaUnsyncedRead::GetClipboard(lua_State* L)
{
    //stub method
}

/******************************************************************************/

int LuaUnsyncedRead::GetLastMessagePositions(lua_State* L)
{
    //stub method
}

/******************************************************************************/

int LuaUnsyncedRead::GetConsoleBuffer(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetCurrentTooltip(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetKeyState(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetModKeyState(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetPressedKeys(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetInvertQueueKey(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetKeyCode(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetKeySymbol(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetKeyBindings(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetActionHotKeys(lua_State* L)
{
    //stub method
}

/******************************************************************************/

int LuaUnsyncedRead::GetGroupList(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetSelectedGroup(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetUnitGroup(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaUnsyncedRead::GetGroupUnits(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetGroupUnitsSorted(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetGroupUnitsCounts(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetGroupUnitsCount(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetPlayerRoster(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetPlayerTraffic(lua_State* L)
{
    //stub method
}

int LuaUnsyncedRead::GetPlayerStatistics(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetDrawSelectionInfo(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetConfigParams(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetLogSections(lua_State* L) {
	const int numLogSections = log_filter_section_getNumRegisteredSections();

	lua_createtable(L, 0, numLogSections);
	for (int i = 0; i < numLogSections; ++i) {
		const char* sectionName = log_filter_section_getRegisteredIndex(i);
		const int logLevel = log_filter_section_getMinLevel(sectionName);

		lua_pushstring(L, sectionName);
		lua_pushnumber(L, logLevel);
		lua_rawset(L, -3);
	}

	return 1;
}

/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetAllDecals(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetDecalPos(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetDecalSize(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetDecalRotation(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetDecalTexture(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetDecalAlpha(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetDecalOwner(lua_State* L)
{
    //stub method
}


int LuaUnsyncedRead::GetDecalType(lua_State* L)
{
    //stub method
}

