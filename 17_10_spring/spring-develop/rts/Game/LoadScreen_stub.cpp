#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <SDL.h>
#include <boost/thread.hpp>

#include "ExternalAI/SkirmishAIHandler.h"
#include "Game.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/UI/InputReceiver.h"
#include "Game/UI/MouseHandler.h"
#include "GameVersion.h"
#include "GlobalUnsynced.h"
#include "LoadScreen.h"
#include "Lua/LuaIntro.h"
#include "Map/MapInfo.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Path/IPathManager.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"
#include "System/Platform/Watchdog.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/FPUCheck.h"
/*
#if !defined(HEADLESS) && !defined(NO_SOUND)
#include "System/Sound/OpenAL/EFX.h"
#include "System/Sound/OpenAL/EFXPresets.h"
#endif
*/
#include <vector>

CONFIG(int, LoadingMT).defaultValue(-1).safemodeValue(0);
CONFIG(bool, ShowLoadMessages).defaultValue(true);

CLoadScreen* CLoadScreen::singleton = nullptr;

/******************************************************************************/

CLoadScreen::CLoadScreen(const std::string& _mapName,
                         const std::string& _modName,
                         ILoadSaveHandler* _saveFile)
  : mapName(_mapName)
  , modName(_modName)
  , saveFile(_saveFile)
  , netHeartbeatThread(nullptr)
  , gameLoadThread(nullptr)
  , mtLoading(true)
  , showMessages(true)
  , startupTexture(0)
  , aspectRatio(1.0f)
  , last_draw(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CLoadScreen::~CLoadScreen()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
CLoadScreen::CreateInstance(const std::string& mapName,
                            const std::string& modName,
                            ILoadSaveHandler* saveFile)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLoadScreen::DeleteInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
CLoadScreen::ResizeEvent()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CLoadScreen::KeyPressed(int k, bool isRepeat)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CLoadScreen::KeyReleased(int k)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CLoadScreen::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CLoadScreen::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

void
CLoadScreen::SetLoadMessage(const std::string& text, bool replace_lastline)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

static string
SelectPicture(const std::string& dir, const std::string& prefix)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLoadScreen::RandomStartPicture(const std::string& sidePref)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLoadScreen::LoadStartPicture(const std::string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLoadScreen::UnloadStartPicture()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLoadScreen::Stop()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
