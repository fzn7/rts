/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SelectedUnitsHandler.h"
#include "SelectedUnitsAI.h"
#include "Camera.h"
#include "GlobalUnsynced.h"
#include "WaitCommandsAI.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "UI/CommandColors.h"
#include "UI/GuiHandler.h"
#include "UI/TooltipConsole.h"
#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Rendering/CommandDrawer.h"
#include "Rendering/LineDrawer.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Features/Feature.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/CommandAI/BuilderCAI.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Game/UI/Groups/GroupHandler.h"
#include "Game/UI/Groups/Group.h"
#include "System/Config/ConfigHandler.h"
#include "System/Color.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/Net/PackPacket.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Input/KeyInput.h"
#include "System/Sound/ISound.h"
#include "System/Sound/ISoundChannels.h"

#include <SDL_mouse.h>
#include <SDL_keycode.h>
#include <map>


CONFIG(bool, BuildIconsFirst).defaultValue(false);
CONFIG(bool, AutoAddBuiltUnitsToFactoryGroup).defaultValue(false).description("Controls whether or not units built by factories will inherit that factory's unit group.");
CONFIG(bool, AutoAddBuiltUnitsToSelectedGroup).defaultValue(false);

CSelectedUnitsHandler selectedUnitsHandler;


CSelectedUnitsHandler::CSelectedUnitsHandler()
	: selectionChanged(false)
	, possibleCommandsChanged(true)
	, selectedGroup(-1)
	, soundMultiselID(0)
	, autoAddBuiltUnitsToFactoryGroup(false)
	, autoAddBuiltUnitsToSelectedGroup(false)
	, buildIconsFirst(false)
{
    //stub method
}



void CSelectedUnitsHandler::Init(unsigned numPlayers)
{
    //stub method
}


bool CSelectedUnitsHandler::IsUnitSelected(const CUnit* unit) const
{
    //stub method
}

bool CSelectedUnitsHandler::IsUnitSelected(const int unitID) const
{
    //stub method
}


void CSelectedUnitsHandler::ToggleBuildIconsFirst()
{
    //stub method
}


CSelectedUnitsHandler::AvailableCommandsStruct CSelectedUnitsHandler::GetAvailableCommands()
{
    //stub method
}


void CSelectedUnitsHandler::GiveCommand(Command c, bool fromUser)
{
    //stub method
}


void CSelectedUnitsHandler::HandleUnitBoxSelection(const float4& planeRight, const float4& planeLeft, const float4& planeTop, const float4& planeBottom)
{
    //stub method
}


void CSelectedUnitsHandler::HandleSingleUnitClickSelection(CUnit* unit, bool doInViewTest, bool selectType)
{
    //stub method
}



void CSelectedUnitsHandler::AddUnit(CUnit* unit)
{
    //stub method
}


void CSelectedUnitsHandler::RemoveUnit(CUnit* unit)
{
    //stub method
}


void CSelectedUnitsHandler::ClearSelected()
{
    //stub method
}


void CSelectedUnitsHandler::SelectGroup(int num)
{
    //stub method
}


void CSelectedUnitsHandler::SelectUnits(const std::string& line)
{
    //stub method
}


void CSelectedUnitsHandler::SelectCycle(const std::string& command)
{
    //stub method
}


void CSelectedUnitsHandler::Draw()
{
    //stub method
}


void CSelectedUnitsHandler::DependentDied(CObject *o)
{
    //stub method
}


void CSelectedUnitsHandler::NetSelect(std::vector<int>& s, int playerId)
{
    //stub method
}


void CSelectedUnitsHandler::NetOrder(Command& c, int playerId)
{
    //stub method
}

void CSelectedUnitsHandler::ClearNetSelect(int playerId)
{
    //stub method
}

void CSelectedUnitsHandler::AiOrder(int unitid, const Command &c, int playerId)
{
    //stub method
}


bool CSelectedUnitsHandler::CommandsChanged()
{
    //stub method
}


/******************************************************************************/
//
//  GetDefaultCmd() and friends
//

static bool targetIsEnemy = false;
static const CUnit* targetUnit = NULL;
static const CFeature* targetFeature = NULL;


static inline bool CanDamage(const UnitDef* ud)
{
    //stub method
}


static inline bool IsBetterLeader(const UnitDef* newDef, const UnitDef* oldDef)
{
    //stub method
}


// CALLINFO:
// DrawMapStuff --> CGuiHandler::GetDefaultCommand --> GetDefaultCmd
// CMouseHandler::DrawCursor --> DrawCentroidCursor --> CGuiHandler::GetDefaultCommand --> GetDefaultCmd
// LuaUnsyncedRead::GetDefaultCommand --> CGuiHandler::GetDefaultCommand --> GetDefaultCmd
int CSelectedUnitsHandler::GetDefaultCmd(const CUnit* unit, const CFeature* feature)
{
    //stub method
}


/******************************************************************************/

void CSelectedUnitsHandler::PossibleCommandChange(CUnit* sender)
{
    //stub method
}

// CALLINFO:
// CGame::Draw --> DrawCommands
// CMiniMap::DrawForReal --> DrawCommands
void CSelectedUnitsHandler::DrawCommands()
{
    //stub method
}


// CALLINFO:
// CTooltipConsole::Draw --> CMouseHandler::GetCurrentTooltip
// LuaUnsyncedRead::GetCurrentTooltip --> CMouseHandler::GetCurrentTooltip
// CMouseHandler::GetCurrentTooltip --> CMiniMap::GetToolTip --> GetTooltip
// CMouseHandler::GetCurrentTooltip --> GetTooltip
std::string CSelectedUnitsHandler::GetTooltip()
{
    //stub method
}


void CSelectedUnitsHandler::SetCommandPage(int page)
{
    //stub method
}



void CSelectedUnitsHandler::SendCommand(const Command& c)
{
    //stub method
}


void CSelectedUnitsHandler::SendCommandsToUnits(const std::vector<int>& unitIDs, const std::vector<Command>& commands, bool pairwise)
{
    //stub method
}
