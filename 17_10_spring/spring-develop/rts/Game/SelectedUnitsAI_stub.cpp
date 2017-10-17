#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SelectedUnitsAI.h"

#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Net/Protocol/NetProtocol.h"
#include "SelectedUnitsHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "WaitCommandsAI.h"

const int CMDPARAM_MOVE_X = 0;
const int CMDPARAM_MOVE_Y = 1;
const int CMDPARAM_MOVE_Z = 2;

// Global object
CSelectedUnitsHandlerAI selectedUnitsAI;

CSelectedUnitsHandlerAI::CSelectedUnitsHandlerAI()
  : centerPos(ZeroVector)
  , rightPos(ZeroVector)
  , sumLength(0)
  , avgLength(0.0f)
  , frontLength(0.0f)
  , addSpace(0.0f)
  , minCoor(ZeroVector)
  , maxCoor(ZeroVector)
  , centerCoor(ZeroVector)
  , minMaxSpeed(0.0f)

  , frontDir(ZeroVector)
  , sideDir(ZeroVector)
  , columnDist(64.0f)
  , numColumns(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

inline void
CSelectedUnitsHandlerAI::AddGroupSetMaxSpeedCommand(CUnit* unit,
                                                    unsigned char options)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static inline bool
MayRequireSetMaxSpeedCommand(const Command& c)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSelectedUnitsHandlerAI::GiveCommandNet(Command& c, int player)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//
// Calculate the outer limits and the center of the group coordinates.
//
void
CSelectedUnitsHandlerAI::CalculateGroupData(int player, bool queueing)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSelectedUnitsHandlerAI::MakeFrontMove(Command* c, int player)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSelectedUnitsHandlerAI::CreateUnitOrder(std::multimap<float, int>& out,
                                         int player)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CSelectedUnitsHandlerAI::MoveToPos(
  int unit,
  float3 nextCornerPos,
  float3 dir,
  Command* command,
  std::vector<std::pair<int, Command>>* frontcmds,
  bool* newline)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

struct DistInfo
{
    //stub method
    //std::cout << __FUNCTION__ << std::endl;
};

void
CSelectedUnitsHandlerAI::SelectCircleUnits(const float3& pos,
                                           float radius,
                                           int player,
                                           std::vector<int>& units)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CSelectedUnitsHandlerAI::SelectRectangleUnits(const float3& pos0,
                                              const float3& pos1,
                                              int player,
                                              std::vector<int>& units)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
CSelectedUnitsHandlerAI::LastQueuePosition(const CUnit* unit)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
