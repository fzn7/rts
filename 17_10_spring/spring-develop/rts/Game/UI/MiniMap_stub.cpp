#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <SDL_keycode.h>
#include <SDL_mouse.h>

#include "CommandColors.h"
#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/UI/UnitTracker.h"
#include "GuiHandler.h"
#include "Lua/LuaUnsyncedCtrl.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "MiniMap.h"
#include "MouseHandler.h"
#include "Rendering/CommandDrawer.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/IconHandler.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/UnitDrawer.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Input/KeyInput.h"
#include "System/Sound/ISoundChannels.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "TooltipConsole.h"

#include <boost/cstdint.hpp>

CONFIG(std::string, MiniMapGeometry).defaultValue("2 2 200 200");
CONFIG(bool, MiniMapFullProxy).defaultValue(true);
CONFIG(int, MiniMapButtonSize).defaultValue(16);

CONFIG(float, MiniMapUnitSize).defaultValue(2.5f).minimumValue(0.0f);

CONFIG(float, MiniMapUnitExp).defaultValue(0.25f);
CONFIG(float, MiniMapCursorScale).defaultValue(-0.5f);
CONFIG(bool, MiniMapIcons).defaultValue(true).headlessValue(false);

CONFIG(int, MiniMapDrawCommands)
  .defaultValue(1)
  .headlessValue(0)
  .minimumValue(0);

CONFIG(bool, MiniMapDrawProjectiles).defaultValue(true).headlessValue(false);
CONFIG(bool, SimpleMiniMapColors).defaultValue(false);

CONFIG(bool, MiniMapRenderToTexture)
  .defaultValue(true)
  .safemodeValue(false)
  .description(
    "Asynchronous render MiniMap to a texture independent of screen FPS.");
CONFIG(int, MiniMapRefreshRate)
  .defaultValue(0)
  .minimumValue(0)
  .description("The refresh rate of the async MiniMap texture. Needs "
               "MiniMapRenderToTexture to be true. Value of \"0\" autoselects "
               "between 10-60FPS.");

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMiniMap* minimap = NULL;

CMiniMap::CMiniMap()
  : CInputReceiver(BACK)
  , fullProxy(false)
  , proxyMode(false)
  , selecting(false)
  , maxspect(false)
  , maximized(false)
  , minimized(false)
  , mouseLook(false)
  , mouseMove(false)
  , mouseResize(false)
  , slaveDrawMode(false)
  , showButtons(false)
  , useIcons(true)
  , myColor(0.2f, 0.9f, 0.2f, 1.0f)
  , allyColor(0.3f, 0.3f, 0.9f, 1.0f)
  , enemyColor(0.9f, 0.2f, 0.2f, 1.0f)
  , renderToTexture(true)
  , multisampledFBO(false)
  , minimapTex(0)
  , lastClicked(nullptr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CMiniMap::~CMiniMap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::ParseGeometry(const string& geostr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::ToggleMaximized(bool _maxspect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::SetMaximizedGeometry()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
CMiniMap::SetSlaveMode(bool newMode)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::ConfigCommand(const std::string& line)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
CMiniMap::SetGeometry(int px, int py, int sx, int sy)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::UpdateGeometry()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
CMiniMap::MoveView(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::SelectUnits(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

bool
CMiniMap::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

CUnit*
CMiniMap::GetSelectUnit(const float3& pos) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CMiniMap::GetMapPosition(int x, int y) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::ProxyMousePress(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::ProxyMouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

bool
CMiniMap::IsAbove(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CMiniMap::GetTooltip(int x, int y)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::AddNotification(float3 pos, float3 color, float alpha)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
CMiniMap::DrawCircle(const float3& pos, float radius) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawSquare(const float3& pos, float xsize, float zsize) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawSurfaceCircle(const float3& pos, float radius, unsigned int)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawSurfaceSquare(const float3& pos, float xsize, float ysize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::ApplyConstraintsMatrix() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
CMiniMap::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::ResizeTextureCache()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::UpdateTextureCache()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
CMiniMap::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawForReal(bool use_geo, bool updateTex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CMiniMap::DrawCameraFrustumAndMouseSelection()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawFrame()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawMinimizedButton()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::IntBox::DrawBox() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::IntBox::DrawTextureBox() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawButtons()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawNotes()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CMiniMap::RenderCachedTexture(bool use_geo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawBackground() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawUnitIcons() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawUnitRanges() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::DrawWorldStuff() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CMiniMap::SetClipPlanes(const bool lua) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
