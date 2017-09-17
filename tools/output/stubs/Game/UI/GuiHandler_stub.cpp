#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GuiHandler.h"

#include "CommandColors.h"
#include "Game/Camera.h"
#include "Game/Game.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/TraceRay.h"
#include "KeyBindings.h"
#include "KeyCodes.h"
#include "Lua/LuaConfig.h"
#include "Lua/LuaGaia.h"
#include "Lua/LuaRules.h"
#include "Lua/LuaTextures.h"
#include "Lua/LuaUI.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"
#include "MiniMap.h"
#include "MouseHandler.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/IconHandler.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Units/CommandAI/BuilderCAI.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/GlobalConfig.h"
#include "System/Input/KeyInput.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Util.h"
#include "System/myMath.h"

#include <list>
#include <map>
#include <set>

#include <SDL_keycode.h>
#include <SDL_mouse.h>

CONFIG(bool, MiniMapMarker).defaultValue(true).headlessValue(false);
CONFIG(bool, InvertQueueKey).defaultValue(false);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGuiHandler* guihandler = NULL;

CGuiHandler::CGuiHandler()
  : inCommand(-1)
  , buildFacing(FACING_SOUTH)
  , buildSpacing(0)
  , needShift(false)
  , showingMetal(false)
  , activeMousePress(false)
  , forceLayoutUpdate(false)
  , maxPage(0)
  , activePage(0)
  , defaultCmdMemory(-1)
  , explicitCommand(-1)
  , curIconCommand(-1)
  , actionOffset(0)
  , drawSelectionInfo(true)
  , gatherMode(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGuiHandler::~CGuiHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::GetQueueKeystate() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::LoadDefaults()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
SafeAtoF(float& var, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::EnableLuaUI(bool enableCommand)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::DisableLuaUI()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::LoadConfig(const std::string& cfg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::ParseFillOrder(const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CGuiHandler::ParseIconSlot(const std::string& text) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::ReloadConfigFromFile(const std::string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::ReloadConfigFromString(const std::string& cfg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::ResizeIconArray(unsigned int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::AppendPrevAndNext(std::vector<SCommandDescription>& cmds)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CGuiHandler::FindInCommandPage()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::RevertToCmdDesc(const SCommandDescription& cmdDesc,
                             bool defaultCommand,
                             bool samePage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::LayoutIcons(bool useSelectionPage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::LayoutCustomIcons(bool useSelectionPage)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::GiveCommand(Command& cmd, bool fromUser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::GiveCommandsNow()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::ConvertCommands(std::vector<SCommandDescription>& cmds)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::SetShowingMetal(bool show)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CGuiHandler::SetCursorIcon() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::TryTarget(const SCommandDescription& cmdDesc) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::MouseRelease(int x,
                          int y,
                          int button,
                          const float3& cameraPos,
                          const float3& mouseDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::SetActiveCommand(int cmdIndex, bool rightMouseButton)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::SetActiveCommand(int cmdIndex,
                              int button,
                              bool leftMouseButton,
                              bool rightMouseButton,
                              bool alt,
                              bool ctrl,
                              bool meta,
                              bool shift)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CGuiHandler::IconAtPos(int x, int y) // GetToolTip --> IconAtPos
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

enum ModState
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
CheckCustomCmdMods(bool rightMouseButton, ModGroup& inMods)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::RunCustomCommands(const std::vector<std::string>& cmds,
                               bool rightMouseButton)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::AboveGui(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned char
CGuiHandler::CreateOptions(bool rightMouseButton)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
unsigned char
CGuiHandler::CreateOptions(int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CGuiHandler::GetNumberInput(const SCommandDescription& cd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// CALLINFO:
// DrawMapStuff --> GetDefaultCommand
// CMouseHandler::DrawCursor --> DrawCentroidCursor --> GetDefaultCommand
// LuaUnsyncedRead::GetDefaultCommand --> GetDefaultCommand
int
CGuiHandler::GetDefaultCommand(int x,
                               int y,
                               const float3& cameraPos,
                               const float3& mouseDir) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::ProcessLocalActions(const Action& action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::ProcessBuildActions(const Action& action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CGuiHandler::GetIconPosCommand(
  int slot) const // only called by SetActiveCommand
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::KeyPressed(int key, bool isRepeat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::SetActiveCommand(const Action& action,
                              const CKeySet& ks,
                              int actionIndex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::KeyReleased(int key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::FinishCommand(int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CGuiHandler::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// CALLINFO:
// luaunsyncedread::getcurrenttooltip --> mousehandler::getcurrenttooltip
// tooltipconsole::draw --> mousehandler::getcurrenttooltip
// mousehandler::getcurrenttooltip --> GetBuildTooltip
// mousehandler::getcurrenttooltip --> CMiniMap::gettooltip --> GetBuildTooltip
std::string
CGuiHandler::GetBuildTooltip() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Command
CGuiHandler::GetOrderPreview()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline Command
CheckCommand(Command c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
ZeroRadiusAllowed(const Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

Command
CGuiHandler::GetCommand(int mouseX,
                        int mouseY,
                        int buttonHint,
                        bool preview,
                        const float3& cameraPos,
                        const float3& mouseDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
WouldCancelAnyQueued(const BuildInfo& b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
FillRowOfBuildPos(const BuildInfo& startInfo,
                  float x,
                  float z,
                  float xstep,
                  float zstep,
                  int n,
                  int facing,
                  bool nocancel,
                  std::vector<BuildInfo>& ret)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Assuming both builds have the same unitdef
std::vector<BuildInfo>
CGuiHandler::GetBuildPos(const BuildInfo& startInfo,
                         const BuildInfo& endInfo,
                         const float3& cameraPos,
                         const float3& mouseDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::ProcessFrontPositions(float3& pos0, const float3& pos1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CGuiHandler::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::string
FindCornerText(const std::string& corner, const vector<std::string>& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawCustomButton(const IconInfo& icon, bool highlight)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::DrawUnitBuildIcon(const IconInfo& icon, int unitDefID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
ParseTextures(const std::string& texString,
              std::string& tex1,
              std::string& tex2,
              float& xscale,
              float& yscale)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
BindUnitTexByString(const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
BindIconTexByString(const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
BindLuaTexByString(const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
BindTextureString(const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CGuiHandler::DrawTexture(const IconInfo& icon, const std::string& texName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawIconFrame(const IconInfo& icon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawName(const IconInfo& icon,
                      const std::string& text,
                      bool offsetForLEDs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawNWtext(const IconInfo& icon, const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawSWtext(const IconInfo& icon, const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawNEtext(const IconInfo& icon, const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawSEtext(const IconInfo& icon, const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawHilightQuad(const IconInfo& icon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawButtons() // Only called by Draw
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawMenuName() // Only called by drawbuttons
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawSelectionInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawNumberInput() // Only called by drawbuttons
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawPrevArrow(const IconInfo& icon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawNextArrow(const IconInfo& icon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawOptionLEDs(const IconInfo& icon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static inline void
DrawSensorRange(int radius, const float* color, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawUnitDefRanges(const CUnit* unit, const UnitDef* unitdef, const float3 pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline GLuint
GetConeList()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawWeaponCone(const float3& pos,
               float len,
               float hrads,
               float heading,
               float pitch)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void
DrawWeaponArc(const CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawMapStuff(bool onMinimap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawMiniMapMarker(const float3& cameraPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawCentroidCursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawArea(float3 pos, float radius, const float* color)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawFront(int button,
                       float maxSize,
                       float sizeDiv,
                       bool onMinimap,
                       const float3& cameraPos,
                       const float3& mouseDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

struct BoxData
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawCornerPosts(const float3& pos0, const float3& pos1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
StencilDrawSelectBox(const float3& pos0,
                     const float3& pos1,
                     bool invColorSelect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
FullScreenDraw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
DrawMinMaxBox(const float3& mins, const float3& maxs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawSelectBox(const float3& pos0,
                           const float3& pos1,
                           const float3& cameraPos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

struct CylinderData
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::DrawSelectCircle(const float3& pos,
                              float radius,
                              const float* color)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CGuiHandler::SetBuildFacing(unsigned int facing)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CGuiHandler::SetBuildSpacing(int spacing)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
