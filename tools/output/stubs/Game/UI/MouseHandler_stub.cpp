#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MouseHandler.h"

#include "CommandColors.h"
#include "InputReceiver.h"
#include "GuiHandler.h"
#include "MiniMap.h"
#include "MouseCursor.h"
#include "TooltipConsole.h"
#include "Game/CameraHandler.h"
#include "Game/Camera.h"
#include "Game/Game.h"
#include "Game/GlobalUnsynced.h"
#include "Game/InMapDraw.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/TraceRay.h"
#include "Game/Camera/CameraController.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/UI/UnitTracker.h"
#include "Lua/LuaInputReceiver.h"
#include "Map/Ground.h"
#include "Map/MapDamage.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Game/UI/Groups/Group.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FastMath.h"
#include "System/myMath.h"
#include "System/Util.h"
#include "System/Input/KeyInput.h"
#include "System/Input/MouseInput.h"

#include <algorithm>
#include <boost/cstdint.hpp>

// can't be up there since those contain conflicting definitions
#include <SDL_mouse.h>
#include <SDL_events.h>
#include <SDL_keycode.h>


CONFIG(bool, HardwareCursor).defaultValue(false).description("Sets hardware mouse cursor rendering. If you have a low framerate, your mouse cursor will seem \"laggy\". Setting hardware cursor will render the mouse cursor separately from spring and the mouse will behave normally. Note, not all GPU drivers support it in fullscreen mode!");
CONFIG(bool, InvertMouse).defaultValue(false);
CONFIG(float, DoubleClickTime).defaultValue(200.0f).description("Double click time in milliseconds.");

CONFIG(float, ScrollWheelSpeed)
	.defaultValue(25.0f)
	.minimumValue(-255.f)
	.maximumValue(255.f);

CONFIG(float, CrossSize).defaultValue(12.0f);
CONFIG(float, CrossAlpha).defaultValue(0.5f);
CONFIG(float, CrossMoveScale).defaultValue(1.0f);
CONFIG(float, MouseDragScrollThreshold).defaultValue(0.3f);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMouseHandler* mouse = NULL;

static CInputReceiver*& activeReceiver = CInputReceiver::GetActiveReceiverRef();


CMouseHandler::CMouseHandler()
	: lastx(-1)
	, lasty(-1)
	, locked(false)
	, doubleClickTime(0.0f)
	, scrollWheelSpeed(0.0f)
	, activeButton(-1)
	, dir(ZeroVector)
	, wasLocked(false)
	, crossSize(0.0f)
	, crossAlpha(0.0f)
	, crossMoveScale(0.0f)
	, cursorText("")
	, currentCursor(NULL)
	, cursorScale(1.0f)
	, hide(true)
	, hwHide(true)
	, hardwareCursor(false)
	, invertMouse(false)
	, dragScrollThreshold(0.0f)
	, scrollx(0.0f)
	, scrolly(0.0f)
	, lastClicked(nullptr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMouseHandler::~CMouseHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::LoadCursors()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CMouseHandler::MouseMove(int x, int y, int dx, int dy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/**
 * GetSelectionBoxCoeff
 *  returns the topright & bottomleft corner positions of the SelectionBox in (cam->right, cam->up)-space
 */
void CMouseHandler::GetSelectionBoxCoeff(const float3& pos1, const float3& dir1, const float3& pos2, const float3& dir2, float2& topright, float2& btmleft)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::MouseWheel(float delta)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::DrawSelectionBox()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// CALLINFO:
// LuaUnsyncedRead::GetCurrentTooltip
// CTooltipConsole::Draw --> CMouseHandler::GetCurrentTooltip
std::string CMouseHandler::GetCurrentTooltip()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::WarpMouse(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::ShowMouse()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::HideMouse()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::ToggleMiddleClickScroll()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::ToggleHwCursor(const bool& enable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CMouseHandler::ChangeCursor(const std::string& cmdName, const float& scale)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::SetCursor(const std::string& cmdName, const bool& forceRebind)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::UpdateCursors()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMouseHandler::DrawScrollCursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::DrawFPSCursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::DrawCursor()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMouseHandler::AssignMouseCursor(const std::string& cmdName,
                                      const std::string& fileName,
                                      CMouseCursor::HotSpot hotSpot,
                                      bool overwrite)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CMouseHandler::ReplaceMouseCursor(const string& oldName,
                                       const string& newName,
                                       CMouseCursor::HotSpot hotSpot)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMouseHandler::SafeDeleteCursor(CMouseCursor* cursor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CMouseHandler::ConfigNotify(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
