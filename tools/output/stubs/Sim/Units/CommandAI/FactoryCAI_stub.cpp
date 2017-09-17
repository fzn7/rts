#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FactoryCAI.h"
#include "ExternalAI/EngineOutHandler.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/WaitCommandsAI.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/creg/STL_Map.h"

CR_BIND_DERIVED(CFactoryCAI, CCommandAI, )

CR_REG_METADATA(CFactoryCAI,
                (CR_MEMBER(newUnitCommands), CR_MEMBER(buildOptions)))

static std::string
GetUnitDefBuildOptionToolTip(const UnitDef* ud, bool disabled)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CFactoryCAI::CFactoryCAI()
  : CCommandAI()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactoryCAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactoryCAI::InsertBuildCommand(CCommandQueue::iterator& it,
                                const Command& newCmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFactoryCAI::RemoveBuildCommand(CCommandQueue::iterator& it)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactoryCAI::DecreaseQueueCount(const Command& buildCommand, int& numQueued)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// NOTE:
//   only called if Factory::QueueBuild returned FACTORY_NEXT_BUILD_ORDER
//   (meaning the order was not rejected and the callback was installed)
void
CFactoryCAI::FactoryFinishBuild(const Command& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactoryCAI::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactoryCAI::ExecuteStop(Command& c)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CFactoryCAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactoryCAI::UpdateIconName(int cmdID, const int& numQueued)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
