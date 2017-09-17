/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GuiHandler.h"


#include "CommandColors.h"
#include "KeyBindings.h"
#include "KeyCodes.h"
#include "MiniMap.h"
#include "MouseHandler.h"
#include "Game/Camera.h"
#include "Game/Game.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/TraceRay.h"
#include "Lua/LuaConfig.h"
#include "Lua/LuaTextures.h"
#include "Lua/LuaGaia.h"
#include "Lua/LuaRules.h"
#include "Lua/LuaUI.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/IconHandler.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/BuilderCAI.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/GlobalConfig.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/Util.h"
#include "System/Input/KeyInput.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"

#include <map>
#include <set>
#include <list>

#include <SDL_keycode.h>
#include <SDL_mouse.h>

CONFIG(bool, MiniMapMarker).defaultValue(true).headlessValue(false);
CONFIG(bool, InvertQueueKey).defaultValue(false);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CGuiHandler* guihandler = NULL;


CGuiHandler::CGuiHandler():
	inCommand(-1),
	buildFacing(FACING_SOUTH),
	buildSpacing(0),
	needShift(false),
	showingMetal(false),
	activeMousePress(false),
	forceLayoutUpdate(false),
	maxPage(0),
	activePage(0),
	defaultCmdMemory(-1),
	explicitCommand(-1),
	curIconCommand(-1),
	actionOffset(0),
	drawSelectionInfo(true),
	gatherMode(false)
{
    //stub method
}


CGuiHandler::~CGuiHandler()
{
    //stub method
}


bool CGuiHandler::GetQueueKeystate() const
{
    //stub method
}


void CGuiHandler::LoadDefaults()
{
    //stub method
}


static bool SafeAtoF(float& var, const std::string& value)
{
    //stub method
}



bool CGuiHandler::EnableLuaUI(bool enableCommand)
{
    //stub method
}

bool CGuiHandler::DisableLuaUI()
{
    //stub method
}



bool CGuiHandler::LoadConfig(const std::string& cfg)
{
    //stub method
}


void CGuiHandler::ParseFillOrder(const std::string& text)
{
    //stub method
}


int CGuiHandler::ParseIconSlot(const std::string& text) const
{
    //stub method
}


bool CGuiHandler::ReloadConfigFromFile(const std::string& fileName)
{
    //stub method
}


bool CGuiHandler::ReloadConfigFromString(const std::string& cfg)
{
    //stub method
}


void CGuiHandler::ResizeIconArray(unsigned int size)
{
    //stub method
}


void CGuiHandler::AppendPrevAndNext(std::vector<SCommandDescription>& cmds)
{
    //stub method
}


int CGuiHandler::FindInCommandPage()
{
    //stub method
}


void CGuiHandler::RevertToCmdDesc(const SCommandDescription& cmdDesc,
                                  bool defaultCommand, bool samePage)
{
    //stub method
}


void CGuiHandler::LayoutIcons(bool useSelectionPage)
{
    //stub method
}


bool CGuiHandler::LayoutCustomIcons(bool useSelectionPage)
{
    //stub method
}


void CGuiHandler::GiveCommand(Command& cmd, bool fromUser)
{
    //stub method
}


void CGuiHandler::GiveCommandsNow() {
	std::vector< std::pair<Command, bool> > commandsToGiveTemp;
	{
		commandsToGiveTemp.swap(commandsToGive);
	}

	for(std::vector< std::pair<Command, bool> >::iterator i = commandsToGiveTemp.begin(); i != commandsToGiveTemp.end(); ++i) {
		const Command& cmd = (*i).first;
		if (eventHandler.CommandNotify(cmd)) {
			continue;
		}

		selectedUnitsHandler.GiveCommand(cmd, (*i).second);

		if (gatherMode) {
			if ((cmd.GetID() == CMD_MOVE) || (cmd.GetID() == CMD_FIGHT)) {
				Command gatherCmd(CMD_GATHERWAIT);
				GiveCommand(gatherCmd, false);
			}
		}
	}
}


void CGuiHandler::ConvertCommands(std::vector<SCommandDescription>& cmds)
{
    //stub method
}


void CGuiHandler::SetShowingMetal(bool show)
{
    //stub method
}


void CGuiHandler::Update()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void CGuiHandler::SetCursorIcon() const
{
    //stub method
}


bool CGuiHandler::TryTarget(const SCommandDescription& cmdDesc) const
{
    //stub method
}


bool CGuiHandler::MousePress(int x, int y, int button)
{
    //stub method
}


void CGuiHandler::MouseRelease(int x, int y, int button, const float3& cameraPos, const float3& mouseDir)
{
    //stub method
}


bool CGuiHandler::SetActiveCommand(int cmdIndex, bool rightMouseButton)
{
    //stub method
}


bool CGuiHandler::SetActiveCommand(int cmdIndex, int button,
                                   bool leftMouseButton, bool rightMouseButton,
                                   bool alt, bool ctrl, bool meta, bool shift)
{
    //stub method
}


int CGuiHandler::IconAtPos(int x, int y) // GetToolTip --> IconAtPos
{
    //stub method
}


/******************************************************************************/

enum ModState {
	DontCare, Required, Forbidden
};

struct ModGroup {
	ModGroup()
	: alt(DontCare),
	  ctrl(DontCare),
	  meta(DontCare),
	  shift(DontCare),
	  right(DontCare) {}
	ModState alt, ctrl, meta, shift, right;
};


static bool ParseCustomCmdMods(std::string& cmd, ModGroup& in, ModGroup& out)
{
    //stub method
}


static bool CheckCustomCmdMods(bool rightMouseButton, ModGroup& inMods)
{
    //stub method
}


void CGuiHandler::RunCustomCommands(const std::vector<std::string>& cmds, bool rightMouseButton)
{
    //stub method
}


bool CGuiHandler::AboveGui(int x, int y)
{
    //stub method
}


unsigned char CGuiHandler::CreateOptions(bool rightMouseButton)
{
    //stub method
}
unsigned char CGuiHandler::CreateOptions(int button)
{
    //stub method
}


float CGuiHandler::GetNumberInput(const SCommandDescription& cd) const
{
    //stub method
}

// CALLINFO:
// DrawMapStuff --> GetDefaultCommand
// CMouseHandler::DrawCursor --> DrawCentroidCursor --> GetDefaultCommand
// LuaUnsyncedRead::GetDefaultCommand --> GetDefaultCommand
int CGuiHandler::GetDefaultCommand(int x, int y, const float3& cameraPos, const float3& mouseDir) const
{
    //stub method
}


bool CGuiHandler::ProcessLocalActions(const Action& action)
{
    //stub method
}


bool CGuiHandler::ProcessBuildActions(const Action& action)
{
    //stub method
}


int CGuiHandler::GetIconPosCommand(int slot) const // only called by SetActiveCommand
{
    //stub method
}


bool CGuiHandler::KeyPressed(int key, bool isRepeat)
{
    //stub method
}


bool CGuiHandler::SetActiveCommand(const Action& action,
                                   const CKeySet& ks, int actionIndex)
{
    //stub method
}


bool CGuiHandler::KeyReleased(int key)
{
    //stub method
}

void CGuiHandler::FinishCommand(int button)
{
    //stub method
}


bool CGuiHandler::IsAbove(int x, int y)
{
    //stub method
}


std::string CGuiHandler::GetTooltip(int x, int y)
{
    //stub method
}

// CALLINFO:
// luaunsyncedread::getcurrenttooltip --> mousehandler::getcurrenttooltip
// tooltipconsole::draw --> mousehandler::getcurrenttooltip
// mousehandler::getcurrenttooltip --> GetBuildTooltip
// mousehandler::getcurrenttooltip --> CMiniMap::gettooltip --> GetBuildTooltip
std::string CGuiHandler::GetBuildTooltip() const
{
    //stub method
}


Command CGuiHandler::GetOrderPreview()
{
    //stub method
}


inline Command CheckCommand(Command c) {
	if (selectedUnitsHandler.selectedUnits.empty() || (c.options & SHIFT_KEY))
		return c; // always allow queued commands, since conditions may change so the command becomes valid
	for (CUnitSet::iterator ui = selectedUnitsHandler.selectedUnits.begin(); ui != selectedUnitsHandler.selectedUnits.end(); ++ui) {
		if((*ui)->commandAI->AllowedCommand(c, false))
			return c;
	}
	Command failedRet(CMD_FAILED);
	return failedRet;
}

bool ZeroRadiusAllowed(const Command &c) {
	switch(c.GetID()) {
	case CMD_CAPTURE:
	case CMD_GUARD:
	case CMD_LOAD_UNITS:
	case CMD_RECLAIM:
	case CMD_REPAIR:
	case CMD_RESTORE:
	case CMD_RESURRECT:
		return false;
	}
	return true;
}

Command CGuiHandler::GetCommand(int mouseX, int mouseY, int buttonHint, bool preview, const float3& cameraPos, const float3& mouseDir)
{
    //stub method
}



static bool WouldCancelAnyQueued(const BuildInfo& b)
{
    //stub method
}

static void FillRowOfBuildPos(const BuildInfo& startInfo, float x, float z, float xstep, float zstep, int n, int facing, bool nocancel, std::vector<BuildInfo>& ret)
{
    //stub method
}

// Assuming both builds have the same unitdef
std::vector<BuildInfo> CGuiHandler::GetBuildPos(const BuildInfo& startInfo, const BuildInfo& endInfo, const float3& cameraPos, const float3& mouseDir)
{
    //stub method
}


void CGuiHandler::ProcessFrontPositions(float3& pos0, const float3& pos1)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void CGuiHandler::Draw()
{
    //stub method
}


static std::string FindCornerText(const std::string& corner, const vector<std::string>& params)
{
    //stub method
}


void CGuiHandler::DrawCustomButton(const IconInfo& icon, bool highlight)
{
    //stub method
}


bool CGuiHandler::DrawUnitBuildIcon(const IconInfo& icon, int unitDefID)
{
    //stub method
}


static inline bool ParseTextures(const std::string& texString,
		std::string& tex1, std::string& tex2, float& xscale, float& yscale)
{
    //stub method
}


static inline bool BindUnitTexByString(const std::string& str)
{
    //stub method
}


static inline bool BindIconTexByString(const std::string& str)
{
    //stub method
}


static inline bool BindLuaTexByString(const std::string& str)
{
    //stub method
}


static bool BindTextureString(const std::string& str)
{
    //stub method
}


bool CGuiHandler::DrawTexture(const IconInfo& icon, const std::string& texName)
{
    //stub method
}


void CGuiHandler::DrawIconFrame(const IconInfo& icon)
{
    //stub method
}


void CGuiHandler::DrawName(const IconInfo& icon, const std::string& text,
		bool offsetForLEDs)
{
    //stub method
}


void CGuiHandler::DrawNWtext(const IconInfo& icon, const std::string& text)
{
    //stub method
}


void CGuiHandler::DrawSWtext(const IconInfo& icon, const std::string& text)
{
    //stub method
}


void CGuiHandler::DrawNEtext(const IconInfo& icon, const std::string& text)
{
    //stub method
}


void CGuiHandler::DrawSEtext(const IconInfo& icon, const std::string& text)
{
    //stub method
}


void CGuiHandler::DrawHilightQuad(const IconInfo& icon)
{
    //stub method
}


void CGuiHandler::DrawButtons() // Only called by Draw
{
    //stub method
}


void CGuiHandler::DrawMenuName() // Only called by drawbuttons
{
    //stub method
}


void CGuiHandler::DrawSelectionInfo()
{
    //stub method
}


void CGuiHandler::DrawNumberInput() // Only called by drawbuttons
{
    //stub method
}


void CGuiHandler::DrawPrevArrow(const IconInfo& icon)
{
    //stub method
}


void CGuiHandler::DrawNextArrow(const IconInfo& icon)
{
    //stub method
}


void CGuiHandler::DrawOptionLEDs(const IconInfo& icon)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static inline void DrawSensorRange(int radius, const float* color, const float3& pos)
{
    //stub method
}


static void DrawUnitDefRanges(const CUnit* unit, const UnitDef* unitdef, const float3 pos)
{
    //stub method
}



static inline GLuint GetConeList()
{
    //stub method
}


static void DrawWeaponCone(const float3& pos,
                           float len, float hrads, float heading, float pitch)
{
    //stub method
}


static inline void DrawWeaponArc(const CUnit* unit)
{
    //stub method
}


void CGuiHandler::DrawMapStuff(bool onMinimap)
{
    //stub method
}


void CGuiHandler::DrawMiniMapMarker(const float3& cameraPos)
{
    //stub method
}


void CGuiHandler::DrawCentroidCursor()
{
    //stub method
}


void CGuiHandler::DrawArea(float3 pos, float radius, const float* color)
{
    //stub method
}


void CGuiHandler::DrawFront(int button, float maxSize, float sizeDiv, bool onMinimap, const float3& cameraPos, const float3& mouseDir)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

struct BoxData {
	float3 mins;
	float3 maxs;
};


static void DrawBoxShape(const void* data)
{
    //stub method
}


static void DrawCornerPosts(const float3& pos0, const float3& pos1)
{
    //stub method
}


static void StencilDrawSelectBox(const float3& pos0, const float3& pos1,
		bool invColorSelect)
{
    //stub method
}


static void FullScreenDraw()
{
    //stub method
}


static void DrawMinMaxBox(const float3& mins, const float3& maxs)
{
    //stub method
}


void CGuiHandler::DrawSelectBox(const float3& pos0, const float3& pos1, const float3& cameraPos)
{
    //stub method
}


/******************************************************************************/

struct CylinderData {
	int divs;
	float xc, zc, yp, yn;
	float radius;
};


static void DrawCylinderShape(const void* data)
{
    //stub method
}


void CGuiHandler::DrawSelectCircle(const float3& pos, float radius,
                                   const float* color)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void CGuiHandler::SetBuildFacing(unsigned int facing)
{
    //stub method
}

void CGuiHandler::SetBuildSpacing(int spacing)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/
