#include <iostream>
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
    std::cout << _FUNCTION_ << std::endl;
}




/******************************************************************************/
/******************************************************************************/
//
//  Parsing helpers
//

static inline CUnit* ParseUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline CFeature* ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




static int GetSolidObjectLuaDraw(lua_State* L, const CSolidObject* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int GetSolidObjectNoDraw(lua_State* L, const CSolidObject* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




/******************************************************************************/
/******************************************************************************/
//
//  The call-outs
//

int LuaUnsyncedRead::IsReplay(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetReplayLength(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetModUICtrl(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetViewGeometry(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetWindowGeometry(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetScreenGeometry(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetMiniMapGeometry(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetMiniMapDualScreen(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::IsAboveMiniMap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetDrawFrame(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetFrameTimeOffset(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetLastUpdateSeconds(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetHasLag(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::IsAABBInView(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::IsSphereInView(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::IsUnitAllied(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::IsUnitInView(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::IsUnitVisible(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::IsUnitIcon(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::IsUnitSelected(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetUnitLuaDraw(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetUnitNoDraw(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetUnitNoMinimap(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetUnitNoSelect(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetFeatureLuaDraw(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetFeatureNoDraw(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



int LuaUnsyncedRead::GetUnitTransformMatrix(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetUnitViewPosition(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
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
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetVisibleFeatures(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetVisibleProjectiles(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetLocalPlayerID(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetLocalTeamID(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetLocalAllyTeamID(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetSpectatingState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetSelectedUnits(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetSelectedUnitsSorted(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetSelectedUnitsCounts(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetSelectedUnitsCount(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::IsGUIHidden(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::HaveShadows(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::HaveAdvShading(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetWaterMode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetMapDrawMode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetMapSquareTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetLosViewColors(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetCameraNames(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetCameraState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetCameraPosition(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetCameraDirection(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetCameraFOV(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetCameraVectors(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::WorldToScreenCoords(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::TraceScreenRay(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetPixelDir(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/

static void AddPlayerToRoster(lua_State* L, int playerID, bool includePathingFlag)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetTeamColor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetTeamOrigColor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

static void PushTimer(lua_State* L, const spring_time& time)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetTimer(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetFrameTimer(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::DiffTimers(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetSoundStreamTime(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetSoundEffectParams(lua_State* L)
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

int LuaUnsyncedRead::GetFPS(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetGameSpeed(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetActiveCommand(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetDefaultCommand(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetActiveCmdDescs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetActiveCmdDesc(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetCmdDescIndex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetBuildFacing(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetBuildSpacing(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetGatherMode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetActivePage(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetMouseState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetMouseCursor(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetMouseStartPosition(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedRead::GetClipboard(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedRead::GetLastMessagePositions(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedRead::GetConsoleBuffer(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetCurrentTooltip(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetKeyState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetModKeyState(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetPressedKeys(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetInvertQueueKey(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetKeyCode(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetKeySymbol(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetKeyBindings(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetActionHotKeys(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaUnsyncedRead::GetGroupList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetSelectedGroup(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetUnitGroup(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaUnsyncedRead::GetGroupUnits(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetGroupUnitsSorted(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetGroupUnitsCounts(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetGroupUnitsCount(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetPlayerRoster(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetPlayerTraffic(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaUnsyncedRead::GetPlayerStatistics(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetDrawSelectionInfo(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaUnsyncedRead::GetConfigParams(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
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
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetDecalPos(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetDecalSize(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetDecalRotation(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetDecalTexture(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetDecalAlpha(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetDecalOwner(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaUnsyncedRead::GetDecalType(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

