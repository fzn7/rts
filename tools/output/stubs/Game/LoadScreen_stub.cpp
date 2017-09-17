/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <SDL.h>
#include <boost/thread.hpp>

#include "Rendering/GL/myGL.h"
#include "LoadScreen.h"
#include "Game.h"
#include "GameVersion.h"
#include "GlobalUnsynced.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/UI/MouseHandler.h"
#include "Game/UI/InputReceiver.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Lua/LuaIntro.h"
#include "Map/MapInfo.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Path/IPathManager.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Sync/FPUCheck.h"
#include "System/Log/ILog.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Platform/Watchdog.h"
#include "System/Platform/Threading.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"

#if !defined(HEADLESS) && !defined(NO_SOUND)
#include "System/Sound/OpenAL/EFX.h"
#include "System/Sound/OpenAL/EFXPresets.h"
#endif

#include <vector>

CONFIG(int, LoadingMT).defaultValue(-1).safemodeValue(0);
CONFIG(bool, ShowLoadMessages).defaultValue(true);

CLoadScreen* CLoadScreen::singleton = nullptr;

/******************************************************************************/

CLoadScreen::CLoadScreen(const std::string& _mapName, const std::string& _modName, ILoadSaveHandler* _saveFile) :
	mapName(_mapName),
	modName(_modName),
	saveFile(_saveFile),
	netHeartbeatThread(nullptr),
	gameLoadThread(nullptr),
	mtLoading(true),
	showMessages(true),
	startupTexture(0),
	aspectRatio(1.0f),
	last_draw(0)
{
    //stub method
}

void CLoadScreen::Init()
{
    //stub method
}


CLoadScreen::~CLoadScreen()
{
    //stub method
}


/******************************************************************************/

void CLoadScreen::CreateInstance(const std::string& mapName, const std::string& modName, ILoadSaveHandler* saveFile)
{
    //stub method
}


void CLoadScreen::DeleteInstance()
{
    //stub method
}


/******************************************************************************/

void CLoadScreen::ResizeEvent()
{
    //stub method
}


int CLoadScreen::KeyPressed(int k, bool isRepeat)
{
    //stub method
}


int CLoadScreen::KeyReleased(int k)
{
    //stub method
}


bool CLoadScreen::Update()
{
    //stub method
}


bool CLoadScreen::Draw()
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

void CLoadScreen::SetLoadMessage(const std::string& text, bool replace_lastline)
{
    //stub method
}


/******************************************************************************/

static string SelectPicture(const std::string& dir, const std::string& prefix)
{
    //stub method
}


void CLoadScreen::RandomStartPicture(const std::string& sidePref)
{
    //stub method
}


void CLoadScreen::LoadStartPicture(const std::string& name)
{
    //stub method
}


void CLoadScreen::UnloadStartPicture()
{
    //stub method
}


void CLoadScreen::Stop()
{
    //stub method
}


/******************************************************************************/
