#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "UnsyncedGameCommands.h"

#include "Action.h"
#include "CameraHandler.h"
#include "CommandMessage.h"
#include "ConsoleHistory.h"
#include "Game.h"
#include "GameSetup.h"
#include "GlobalUnsynced.h"
#include "IVideoCapturing.h"
#include "InMapDraw.h"
#include "InMapDrawModel.h"
#include "SelectedUnitsHandler.h"
#include "SyncedActionExecutor.h"
#include "SyncedGameCommands.h"
#include "System/TimeProfiler.h"
#include "UnsyncedActionExecutor.h"
#include "WordCompletion.h"
#ifdef _WIN32
#include "winerror.h" // TODO someone on windows (MinGW? VS?) please check if this is required
#endif
#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/UI/Groups/GroupHandler.h"
#include "Game/UI/PlayerRoster.h"
#include "Lua/LuaOpenGL.h"
#include "Lua/LuaUI.h"
#include "Map/Ground.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"
#include "Map/SMF/ROAM/Patch.h"
#include "Map/SMF/ROAM/RoamMeshDrawer.h"
#include "Map/SMF/SMFGroundDrawer.h"
#include "Net/GameServer.h"
#include "Net/Protocol/NetProtocol.h"
#include "Rendering/DebugColVolDrawer.h"
#include "Rendering/DebugDrawerAI.h"
#include "Rendering/Env/IGroundDecalDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/ITreeDrawer.h"
#include "Rendering/Env/IWater.h"
#include "Rendering/FeatureDrawer.h"
#include "Rendering/Fonts/glFont.h"
#include "Rendering/HUDDrawer.h"
#include "Rendering/IPathDrawer.h"
#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/Map/InfoTexture/IInfoTextureHandler.h"
#include "Rendering/Map/InfoTexture/Modern/Path.h"
#include "Rendering/Screenshot.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/ShadowHandler.h"
#include "Rendering/TeamHighlight.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/VerticalSync.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/GlobalConfig.h"
#include "System/Log/ILog.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/DumpState.h"
#include "System/Util.h"
#include "UI/CommandColors.h"
#include "UI/EndGameBox.h"
#include "UI/GameInfo.h"
#include "UI/GuiHandler.h"
#include "UI/InfoConsole.h"
#include "UI/InputReceiver.h"
#include "UI/KeyBindings.h"
#include "UI/KeyCodes.h"
#include "UI/MiniMap.h"
#include "UI/ProfileDrawer.h"
#include "UI/QuitBox.h"
#include "UI/ResourceBar.h"
#include "UI/SelectionKeyHandler.h"
#include "UI/ShareBox.h"
#include "UI/TooltipConsole.h"
#include "UI/UnitTracker.h"

#include <SDL_events.h>
#include <SDL_video.h>

static std::vector<std::string>
_local_strSpaceTokenize(const std::string& text)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

namespace { // prevents linking problems in case of duplicate symbols

/**
 * Special case executor which is used for creating aliases to other commands.
 * The inner executor will be delet'ed in this executors dtor.
 */
class AliasActionExecutor : public IUnsyncedActionExecutor
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UnsyncedGameCommands::AddDefaultActionExecutors()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

UnsyncedGameCommands* UnsyncedGameCommands::singleton = NULL;

void
UnsyncedGameCommands::CreateInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
UnsyncedGameCommands::DestroyInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
