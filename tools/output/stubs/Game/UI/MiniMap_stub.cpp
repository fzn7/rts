#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <SDL_keycode.h>
#include <SDL_mouse.h>

#include "CommandColors.h"
#include "GuiHandler.h"
#include "MiniMap.h"
#include "MouseHandler.h"
#include "TooltipConsole.h"
#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/Players/Player.h"
#include "Game/UI/UnitTracker.h"
#include "Sim/Misc/TeamHandler.h"
#include "Lua/LuaUnsyncedCtrl.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Rendering/CommandDrawer.h"
#include "Rendering/IconHandler.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "Sim/Weapons/Weapon.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Util.h"
#include "System/TimeProfiler.h"
#include "System/Input/KeyInput.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Sound/ISoundChannels.h"

#include <boost/cstdint.hpp>

CONFIG(std::string, MiniMapGeometry).defaultValue("2 2 200 200");
CONFIG(bool, MiniMapFullProxy).defaultValue(true);
CONFIG(int, MiniMapButtonSize).defaultValue(16);

CONFIG(float, MiniMapUnitSize)
	.defaultValue(2.5f)
	.minimumValue(0.0f);

CONFIG(float, MiniMapUnitExp).defaultValue(0.25f);
CONFIG(float, MiniMapCursorScale).defaultValue(-0.5f);
CONFIG(bool, MiniMapIcons).defaultValue(true).headlessValue(false);

CONFIG(int, MiniMapDrawCommands).defaultValue(1).headlessValue(0).minimumValue(0);

CONFIG(bool, MiniMapDrawProjectiles).defaultValue(true).headlessValue(false);
CONFIG(bool, SimpleMiniMapColors).defaultValue(false);

CONFIG(bool, MiniMapRenderToTexture).defaultValue(true).safemodeValue(false).description("Asynchronous render MiniMap to a texture independent of screen FPS.");
CONFIG(int, MiniMapRefreshRate).defaultValue(0).minimumValue(0).description("The refresh rate of the async MiniMap texture. Needs MiniMapRenderToTexture to be true. Value of \"0\" autoselects between 10-60FPS.");



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
	lastWindowSizeX = globalRendering->viewSizeX;
	lastWindowSizeY = globalRendering->viewSizeY;

	if (globalRendering->dualScreenMode) {
		width = globalRendering->viewSizeX;
		height = globalRendering->viewSizeY;
		xpos = (globalRendering->viewSizeX - globalRendering->viewPosX);
		ypos = 0;
	}
	else {
		const std::string geo = configHandler->GetString("MiniMapGeometry");
		ParseGeometry(geo);
	}

	fullProxy = configHandler->GetBool("MiniMapFullProxy");
	buttonSize = configHandler->GetInt("MiniMapButtonSize");

	unitBaseSize = configHandler->GetFloat("MiniMapUnitSize");
	unitExponent = configHandler->GetFloat("MiniMapUnitExp");

	cursorScale = configHandler->GetFloat("MiniMapCursorScale");
	useIcons = configHandler->GetBool("MiniMapIcons");
	drawCommands = configHandler->GetInt("MiniMapDrawCommands");
	drawProjectiles = configHandler->GetBool("MiniMapDrawProjectiles");
	simpleColors = configHandler->GetBool("SimpleMiniMapColors");
	minimapRefreshRate = configHandler->GetInt("MiniMapRefreshRate");
	renderToTexture = configHandler->GetBool("MiniMapRenderToTexture") && FBO::IsSupported();

	UpdateGeometry();

	circleLists = glGenLists(circleListsCount);
	for (int cl = 0; cl < circleListsCount; cl++) {
		glNewList(circleLists + cl, GL_COMPILE);
		glBegin(GL_LINE_LOOP);
		const int divs = (1 << (cl + 3));
		for (int d = 0; d < divs; d++) {
			const float rads = float(2.0 * PI) * float(d) / float(divs);
			glVertex3f(std::sin(rads), 0.0f, std::cos(rads));
		}
		glEnd();
		glEndList();
	}

	// setup the buttons' texture and texture coordinates
	buttonsTexture = 0;
	CBitmap bitmap;
	bool unfiltered = false;
	if (bitmap.Load("bitmaps/minimapbuttons.png")) {
		if ((bitmap.ysize == buttonSize) && (bitmap.xsize == (buttonSize * 4))) {
			unfiltered = true;
		}
		glGenTextures(1, &buttonsTexture);
		glBindTexture(GL_TEXTURE_2D, buttonsTexture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8,
								 bitmap.xsize, bitmap.ysize, 0,
								 GL_RGBA, GL_UNSIGNED_BYTE, &bitmap.mem[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		if (unfiltered) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		} else {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		}
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	const float xshift = unfiltered ? 0.0f : (0.5f / bitmap.xsize);
	const float yshift = unfiltered ? 0.0f : (0.5f / bitmap.ysize);
	    moveBox.xminTx = 0.50f + xshift;
	    moveBox.xmaxTx = 0.75f - xshift;
	  resizeBox.xminTx = 0.75f + xshift;
	  resizeBox.xmaxTx = 1.00f - xshift;
	minimizeBox.xminTx = 0.00f + xshift;
	minimizeBox.xmaxTx = 0.25f - xshift;
	maximizeBox.xminTx = 0.25f + xshift;
	maximizeBox.xmaxTx = 0.50f - xshift;
	    moveBox.yminTx = 1.00f - yshift;
	  resizeBox.yminTx = 1.00f - yshift;
	minimizeBox.yminTx = 1.00f - yshift;
	maximizeBox.yminTx = 1.00f - yshift;
	    moveBox.ymaxTx = 0.00f + yshift;
	  resizeBox.ymaxTx = 0.00f + yshift;
	minimizeBox.ymaxTx = 0.00f + yshift;
	maximizeBox.ymaxTx = 0.00f + yshift;
}


CMiniMap::~CMiniMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::ParseGeometry(const string& geostr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::ToggleMaximized(bool _maxspect)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::SetMaximizedGeometry()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CMiniMap::SetSlaveMode(bool newMode)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::ConfigCommand(const std::string& line)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void CMiniMap::SetGeometry(int px, int py, int sx, int sy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::UpdateGeometry()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CMiniMap::MoveView(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::SelectUnits(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

bool CMiniMap::MousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::MouseMove(int x, int y, int dx, int dy, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::MouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

CUnit* CMiniMap::GetSelectUnit(const float3& pos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 CMiniMap::GetMapPosition(int x, int y) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::ProxyMousePress(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::ProxyMouseRelease(int x, int y, int button)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

bool CMiniMap::IsAbove(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CMiniMap::GetTooltip(int x, int y)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::AddNotification(float3 pos, float3 color, float alpha)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CMiniMap::DrawCircle(const float3& pos, float radius) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMiniMap::DrawSquare(const float3& pos, float xsize, float zsize) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawSurfaceCircle(const float3& pos, float radius, unsigned int)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawSurfaceSquare(const float3& pos, float xsize, float ysize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::ApplyConstraintsMatrix() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CMiniMap::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::ResizeTextureCache()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::UpdateTextureCache()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void CMiniMap::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawForReal(bool use_geo, bool updateTex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

void CMiniMap::DrawCameraFrustumAndMouseSelection()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawFrame()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawMinimizedButton()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::IntBox::DrawBox() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::IntBox::DrawTextureBox() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawButtons()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawNotes()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CMiniMap::RenderCachedTexture(bool use_geo)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawBackground() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawUnitIcons() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawUnitRanges() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::DrawWorldStuff() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMiniMap::SetClipPlanes(const bool lua) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/
