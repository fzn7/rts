/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "FactoryCAI.h"
#include "ExternalAI/EngineOutHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Game/GameHelper.h"
#include "Game/GlobalUnsynced.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/WaitCommandsAI.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/BuildInfo.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitTypes/Factory.h"
#include "System/Log/ILog.h"
#include "System/creg/STL_Map.h"
#include "System/Util.h"
#include "System/EventHandler.h"
#include "System/Exceptions.h"

CR_BIND_DERIVED(CFactoryCAI ,CCommandAI , )

CR_REG_METADATA(CFactoryCAI , (
	CR_MEMBER(newUnitCommands),
	CR_MEMBER(buildOptions)
))

static std::string GetUnitDefBuildOptionToolTip(const UnitDef* ud, bool disabled) {
	std::string tooltip;

	if (disabled) {
		tooltip = "\xff\xff\x22\x22" "DISABLED: " "\xff\xff\xff\xff";
	} else {
		tooltip = "Build: ";
	}

	tooltip += (ud->humanName + " - " + ud->tooltip);
	tooltip += ("\nHealth "      + FloatToString(ud->health,    "%.0f"));
	tooltip += ("\nMetal cost "  + FloatToString(ud->metal,     "%.0f"));
	tooltip += ("\nEnergy cost " + FloatToString(ud->energy,    "%.0f"));
	tooltip += ("\nBuild time "  + FloatToString(ud->buildTime, "%.0f"));

	return tooltip;
}



CFactoryCAI::CFactoryCAI(): CCommandAI()
{
    //stub method
}



void CFactoryCAI::GiveCommandReal(const Command& c, bool fromSynced)
{
    //stub method
}


void CFactoryCAI::InsertBuildCommand(CCommandQueue::iterator& it,
                                     const Command& newCmd)
{
    //stub method
}


bool CFactoryCAI::RemoveBuildCommand(CCommandQueue::iterator& it)
{
    //stub method
}


void CFactoryCAI::DecreaseQueueCount(const Command& buildCommand, int& numQueued)
{
    //stub method
}



// NOTE:
//   only called if Factory::QueueBuild returned FACTORY_NEXT_BUILD_ORDER
//   (meaning the order was not rejected and the callback was installed)
void CFactoryCAI::FactoryFinishBuild(const Command& command) {
	DecreaseQueueCount(command, buildOptions[command.GetID()]);
}

void CFactoryCAI::SlowUpdate()
{
    //stub method
}


void CFactoryCAI::ExecuteStop(Command& c)
{
    //stub method
}


int CFactoryCAI::GetDefaultCmd(const CUnit* pointed, const CFeature* feature)
{
    //stub method
}


void CFactoryCAI::UpdateIconName(int cmdID, const int& numQueued)
{
    //stub method
}
