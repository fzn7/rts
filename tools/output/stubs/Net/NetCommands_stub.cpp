/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Game/Game.h"
#include "GameServer.h"

#ifdef _WIN32
#  include "winerror.h" // TODO someone on windows (MinGW? VS?) please check if this is required
#endif
#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/CommandMessage.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/ChatMessage.h"
#include "Game/WordCompletion.h"
#include "Game/IVideoCapturing.h"
#include "Game/InMapDraw.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/UI/GameSetupDrawer.h"
#include "Game/UI/MouseHandler.h"
#include "Lua/LuaHandle.h"
#include "Rendering/GlobalRendering.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Path/IPathManager.h"
#include "Sim/Units/UnitHandler.h"
#include "System/EventHandler.h"
#include "System/GlobalConfig.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/TimeProfiler.h"
#include "System/LoadSave/DemoRecorder.h"
#include "System/Net/UnpackPacket.h"
#include "System/Sound/ISound.h"

#include <boost/cstdint.hpp>

#define LOG_SECTION_NET "Net"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_NET)


static std::map<int, unsigned int> mySyncChecksums;


void CGame::AddTraffic(int playerID, int packetCode, int length)
{
    //stub method
}

void CGame::SendClientProcUsage()
{
    //stub method
}


unsigned int CGame::GetNumQueuedSimFrameMessages(unsigned int maxFrames) const
{
    //stub method
}

void CGame::UpdateNumQueuedSimFrames()
{
    //stub method
}

void CGame::UpdateNetMessageProcessingTimeLeft()
{
    //stub method
}

float CGame::GetNetMessageProcessingTimeLimit() const
{
    //stub method
}

void CGame::ClientReadNet()
{
    //stub method
}
