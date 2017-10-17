#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Rendering/GL/myGL.h"

#include <SDL_keyboard.h>

#include "Benchmark.h"
#include "Camera.h"
#include "CameraHandler.h"
#include "ChatMessage.h"
#include "CommandMessage.h"
#include "ConsoleHistory.h"
#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/UI/PlayerRoster.h"
#include "Game/UI/PlayerRosterDrawer.h"
#include "Game/UI/UnitTracker.h"
#include "GameHelper.h"
#include "GameJobDispatcher.h"
#include "GameSetup.h"
#include "GlobalUnsynced.h"
#include "IVideoCapturing.h"
#include "InMapDraw.h"
#include "InMapDrawModel.h"
#include "LoadScreen.h"
#include "Lua/LuaGaia.h"
#include "Lua/LuaHandle.h"
#include "Lua/LuaInputReceiver.h"
#include "Lua/LuaOpenGL.h"
#include "Lua/LuaParser.h"
#include "Lua/LuaRules.h"
#include "Lua/LuaSyncedRead.h"
#include "Lua/LuaUI.h"
#include "Lua/LuaUtils.h"
#include "Map/MapDamage.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Net/GameServer.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/CommandDrawer.h"
#include "Rendering/DebugDrawerAI.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/Fonts/CFontTexture.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/HUDDrawer.h"
#include "Rendering/IconHandler.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/TeamHighlight.h"
#include "Rendering/Textures/ColorMap.h"
#include "Rendering/Textures/NamedTextures.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/WorldDrawer.h"
#include "SelectedUnitsHandler.h"
#include "Sim/Features/FeatureDef.h"
#include "Sim/Features/FeatureDefHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/BuildingMaskMap.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/DamageArrayHandler.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/InterceptHandler.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/ResourceHandler.h"
#include "Sim/Misc/SideParser.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Projectiles/ExplosionGenerator.h"
#include "Sim/Projectiles/Projectile.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Scripts/CobEngine.h"
#include "Sim/Units/Scripts/UnitScriptEngine.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Weapons/WeaponDefHandler.h"
#include "SyncedActionExecutor.h"
#include "SyncedGameCommands.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileSystem.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/GlobalConfig.h"
#include "System/Input/KeyInput.h"
#include "System/LoadSave/DemoRecorder.h"
#include "System/LoadSave/LoadSaveHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/Watchdog.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"
#include "System/SpringApp.h"
#include "System/Sync/DumpState.h"
#include "System/Sync/FPUCheck.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "System/myMath.h"
#include "UI/CommandColors.h"
#include "UI/EndGameBox.h"
#include "UI/GameInfo.h"
#include "UI/GameSetupDrawer.h"
#include "UI/Groups/GroupHandler.h"
#include "UI/GuiHandler.h"
#include "UI/InfoConsole.h"
#include "UI/KeyBindings.h"
#include "UI/KeyCodes.h"
#include "UI/MiniMap.h"
#include "UI/MouseHandler.h"
#include "UI/ProfileDrawer.h"
#include "UI/QuitBox.h"
#include "UI/ResourceBar.h"
#include "UI/SelectionKeyHandler.h"
#include "UI/ShareBox.h"
#include "UI/TooltipConsole.h"
#include "UnsyncedActionExecutor.h"
#include "UnsyncedGameCommands.h"
#include "WaitCommandsAI.h"
#include "WordCompletion.h"

#undef CreateDirectory

CONFIG(bool, WindowedEdgeMove)
  .defaultValue(true)
  .description("Sets whether moving the mouse cursor to the screen edge will "
               "move the camera across the map.");
CONFIG(bool, FullscreenEdgeMove)
  .defaultValue(true)
  .description("see WindowedEdgeMove, just for fullscreen mode");
CONFIG(bool, ShowFPS)
  .defaultValue(false)
  .description("Displays current framerate.");
CONFIG(bool, ShowClock)
  .defaultValue(true)
  .headlessValue(false)
  .description("Displays a clock on the top-right corner of the screen showing "
               "the elapsed time of the current game.");
CONFIG(bool, ShowSpeed)
  .defaultValue(false)
  .description("Displays current game speed.");
CONFIG(int, ShowPlayerInfo).defaultValue(1).headlessValue(0);
CONFIG(float, GuiOpacity)
  .defaultValue(0.8f)
  .minimumValue(0.0f)
  .maximumValue(1.0f)
  .description("Sets the opacity of the built-in Spring UI. Generally has no "
               "effect on LuaUI widgets. Can be set in-game using shift+, to "
               "decrease and shift+. to increase.");
CONFIG(std::string, InputTextGeo).defaultValue("");

CGame* game = NULL;

CR_BIND(CGame, (std::string(""), std::string(""), NULL))

CR_REG_METADATA(CGame,
                (CR_IGNORED(finishedLoading),
                 CR_IGNORED(numDrawFrames),
                 CR_MEMBER(lastSimFrame),
                 CR_IGNORED(lastNumQueuedSimFrames),
                 CR_IGNORED(frameStartTime),
                 CR_IGNORED(lastSimFrameTime),
                 CR_IGNORED(lastDrawFrameTime),
                 CR_IGNORED(lastFrameTime),
                 CR_IGNORED(lastReadNetTime),
                 CR_IGNORED(lastNetPacketProcessTime),
                 CR_IGNORED(lastReceivedNetPacketTime),
                 CR_IGNORED(lastSimFrameNetPacketTime),
                 CR_IGNORED(updateDeltaSeconds),
                 CR_MEMBER(totalGameTime),
                 CR_MEMBER(userInputPrefix),
                 CR_IGNORED(chatSound),
                 CR_MEMBER(hideInterface),
                 CR_MEMBER(gameOver),
                 CR_IGNORED(gameDrawMode),
                 CR_IGNORED(windowedEdgeMove),
                 CR_IGNORED(fullscreenEdgeMove),
                 CR_MEMBER(showFPS),
                 CR_MEMBER(showClock),
                 CR_MEMBER(showSpeed),
                 CR_IGNORED(chatting),
                 CR_IGNORED(curKeyChain),
                 CR_IGNORED(playerTraffic),
                 CR_MEMBER(noSpectatorChat),
                 CR_MEMBER(gameID),
                 // CR_MEMBER(infoConsole),
                 // CR_MEMBER(consoleHistory),
                 CR_IGNORED(inputTextPosX),
                 CR_IGNORED(inputTextPosY),
                 CR_IGNORED(inputTextSizeX),
                 CR_IGNORED(inputTextSizeY),
                 CR_IGNORED(skipping),
                 CR_MEMBER(playing),
                 CR_IGNORED(msgProcTimeLeft),
                 CR_IGNORED(consumeSpeedMult),

                 CR_IGNORED(skipStartFrame),
                 CR_IGNORED(skipEndFrame),
                 CR_IGNORED(skipTotalFrames),
                 CR_IGNORED(skipSeconds),
                 CR_IGNORED(skipSoundmute),
                 CR_IGNORED(skipOldSpeed),
                 CR_IGNORED(skipOldUserSpeed),
                 CR_IGNORED(skipLastDrawTime),

                 CR_MEMBER(speedControl),

                 CR_IGNORED(infoConsole),
                 CR_IGNORED(consoleHistory),
                 CR_IGNORED(jobDispatcher),
                 CR_IGNORED(worldDrawer),
                 CR_IGNORED(defsParser),
                 CR_IGNORED(saveFile),

                 // from CGameController
                 CR_IGNORED(writingPos),
                 CR_IGNORED(ignoreNextChar),
                 CR_IGNORED(userInput),
                 CR_IGNORED(userPrompt),
                 CR_IGNORED(userWriting),

                 // Post Load
                 CR_POSTLOAD(PostLoad)))

CGame::CGame(const std::string& mapName,
             const std::string& modName,
             ILoadSaveHandler* saveFile)
  : gameDrawMode(gameNotDrawing)
  , lastSimFrame(-1)
  , lastNumQueuedSimFrames(-1)
  , numDrawFrames(0)
  , frameStartTime(spring_gettime())
  , lastSimFrameTime(spring_gettime())
  , lastDrawFrameTime(spring_gettime())
  , lastFrameTime(spring_gettime())
  , lastReadNetTime(spring_gettime())
  , lastNetPacketProcessTime(spring_gettime())
  , lastReceivedNetPacketTime(spring_gettime())
  , lastSimFrameNetPacketTime(spring_gettime())
  , updateDeltaSeconds(0.0f)
  , totalGameTime(0)
  , hideInterface(false)
  , skipping(false)
  , playing(false)
  , chatting(false)
  , noSpectatorChat(false)
  , msgProcTimeLeft(0.0f)
  , consumeSpeedMult(1.0f)
  , skipStartFrame(0)
  , skipEndFrame(0)
  , skipTotalFrames(0)
  , skipSeconds(0.0f)
  , skipSoundmute(false)
  , skipOldSpeed(0.0f)
  , skipOldUserSpeed(0.0f)
  , skipLastDrawTime(spring_gettime())
  , speedControl(-1)
  , infoConsole(NULL)
  , consoleHistory(NULL)
  , worldDrawer(NULL)
  , defsParser(NULL)
  , saveFile(saveFile)
  , finishedLoading(false)
  , gameOver(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGame::~CGame()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::AddTimedJobs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::LoadGame(const std::string& mapName, bool threaded)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::LoadMap(const std::string& mapName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::LoadDefs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::PreLoadSimulation()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::PostLoadSimulation()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::PreLoadRendering()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::PostLoadRendering()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::LoadInterface()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::LoadLua()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::LoadSkirmishAIs()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::LoadFinalize()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::KillLua()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::KillMisc()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::KillRendering()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::KillInterface()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::KillSimulation()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::ResizeEvent()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CGame::KeyPressed(int key, bool isRepeat)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CGame::KeyReleased(int k)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGame::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGame::UpdateUnsynced(const spring_time currentTime)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGame::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::DrawInputReceivers()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::DrawInterfaceWidgets()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::ParseInputTextGeometry(const string& geo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::DrawInputText()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::StartPlaying()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::SimFrame()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::GameEnd(const std::vector<unsigned char>& winningAllyTeams, bool timeout)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::SendNetChat(std::string message, int destination)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::HandleChatMsg(const ChatMessage& msg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::StartSkip(int toFrame)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::EndSkip()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::DrawSkip(bool blackscreen)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::ReloadCOB(const string& msg, int player)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// FIXME remove!
void
CGame::ReColorTeams()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGame::IsLagging(float maxLatency) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::SaveGame(const std::string& filename, bool overwrite, bool usecreg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::ReloadGame()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGame::ProcessCommandText(unsigned int key, const std::string& command)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGame::ProcessKeyPressAction(unsigned int key, const Action& action)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGame::ProcessAction(const Action& action, unsigned int key, bool isRepeat)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGame::ActionReceived(const Action& action, int playerID)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGame::ActionPressed(unsigned int key, const Action& action, bool isRepeat)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
