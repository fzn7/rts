#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <assert.h>

#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/Camera.h"
#include "Game/CameraHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/UI/MouseHandler.h"
#include "Game/UI/UnitTracker.h"
#include "Lua/LuaUI.h"
#include "Map/ReadMap.h"
#include "Player.h"
#include "PlayerHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/creg/STL_Set.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CPlayer, PlayerBase, )
CR_REG_METADATA(CPlayer,
                (CR_MEMBER(active),
                 CR_MEMBER(playerNum),
                 CR_IGNORED(ping),
                 CR_MEMBER(currentStats),
                 CR_IGNORED(fpsController),
                 CR_MEMBER(controlledTeams)))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPlayer::CPlayer()
  : PlayerBase()
  , active(false)
  , playerNum(-1)
  , ping(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayer::SetControlledTeams()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayer::UpdateControlledTeams()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayer::StartSpectating()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayer::JoinTeam(int newTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayer::GameFrame(int frameNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayer::StartControllingUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CPlayer::StopControllingUnit()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
