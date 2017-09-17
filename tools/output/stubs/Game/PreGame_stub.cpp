#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cfloat>
#include <map>

#include <SDL_keycode.h>

#include "PreGame.h"

#include "ClientSetup.h"
#include "Game.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "GameData.h"
#include "GameSetup.h"
#include "GameVersion.h"
#include "GlobalUnsynced.h"
#include "LoadScreen.h"
#include "Map/Generation/SimpleMapGenerator.h"
#include "Net/GameServer.h"
#include "System/Sync/FPUCheck.h"
#include "System/TimeProfiler.h"
#include "UI/InfoConsole.h"

#include "ExternalAI/SkirmishAIHandler.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/Fonts/glFont.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/Input/KeyInput.h"
#include "System/TdfParser.h"
#include "aGui/Gui.h"
//// #include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/LoadSave/DemoReader.h"
#include "System/LoadSave/DemoRecorder.h"
#include "System/LoadSave/LoadSaveHandler.h"
#include "System/Log/ILog.h"
#include "System/Net/RawPacket.h"
#include "System/Net/UnpackPacket.h"
#include "System/Platform/errorhandler.h"
#include "System/Sync/SyncedPrimitiveBase.h"
#include "lib/luasocket/src/restrictions.h"
#ifdef SYNCDEBUG
#include "System/Sync/SyncDebugger.h"
#endif

using netcode::RawPacket;
using std::string;

CONFIG(bool, DemoFromDemo).defaultValue(false);

CPreGame* pregame = NULL;

CPreGame::CPreGame(boost::shared_ptr<ClientSetup> setup)
  : clientSetup(setup)
  , savefile(NULL)
  , timer(spring_gettime())
  , wantDemo(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CPreGame::~CPreGame()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::LoadSetupscript(const std::string& script)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::LoadDemo(const std::string& demo)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::LoadSavefile(const std::string& save, bool usecreg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CPreGame::KeyPressed(int k, bool isRepeat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CPreGame::Draw()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CPreGame::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::AddGameSetupArchivesToVFS(const CGameSetup* setup, bool mapOnly)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::StartServer(const std::string& setupscript)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::UpdateClientNet()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::StartServerForDemo(const std::string& demoName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::ReadDataFromDemo(const std::string& demoName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPreGame::GameDataReceived(boost::shared_ptr<const netcode::RawPacket> packet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
