#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CommandDrawer.h"
#include "LineDrawer.h"
#include "Game/GameHelper.h"
#include "Game/UI/CommandColors.h"
#include "Game/WaitCommandsAI.h"
#include "Map/Ground.h"
#include "Rendering/GL/glExtra.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Units/CommandAI/Command.h"
#include "Sim/Units/CommandAI/CommandQueue.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/AirCAI.h"
#include "Sim/Units/CommandAI/BuilderCAI.h"
#include "Sim/Units/CommandAI/FactoryCAI.h"
#include "Sim/Units/CommandAI/MobileCAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitDefHandler.h"
#include "System/myMath.h"
#include "System/Log/ILog.h"

static const CUnit* GetTrackableUnit(const CUnit* caiOwner, const CUnit* cmdUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CommandDrawer* CommandDrawer::GetInstance() {
	// luaQueuedUnitSet gets cleared each frame, so this is fine wrt. reloading
	static CommandDrawer drawer;
	return &drawer;
}



void CommandDrawer::Draw(const CCommandAI* cai) const {
	// note: {Air,Builder}CAI inherit from MobileCAI, so test that last
	if ((dynamic_cast<const     CAirCAI*>(cai)) != nullptr) {     DrawAirCAICommands(static_cast<const     CAirCAI*>(cai)); return; }
	if ((dynamic_cast<const CBuilderCAI*>(cai)) != nullptr) { DrawBuilderCAICommands(static_cast<const CBuilderCAI*>(cai)); return; }
	if ((dynamic_cast<const CFactoryCAI*>(cai)) != nullptr) { DrawFactoryCAICommands(static_cast<const CFactoryCAI*>(cai)); return; }
	if ((dynamic_cast<const  CMobileCAI*>(cai)) != nullptr) {  DrawMobileCAICommands(static_cast<const  CMobileCAI*>(cai)); return; }

	DrawCommands(cai);
}



void CommandDrawer::AddLuaQueuedUnit(const CUnit* unit) {
	// needs to insert by id, pointers can become dangling
	luaQueuedUnitSet.insert(unit->id);
}

void CommandDrawer::DrawLuaQueuedUnitSetCommands() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CommandDrawer::DrawCommands(const CCommandAI* cai) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CommandDrawer::DrawAirCAICommands(const CAirCAI* cai) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CommandDrawer::DrawBuilderCAICommands(const CBuilderCAI* cai) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CommandDrawer::DrawFactoryCAICommands(const CFactoryCAI* cai) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CommandDrawer::DrawMobileCAICommands(const CMobileCAI* cai) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CommandDrawer::DrawWaitIcon(const Command& cmd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CommandDrawer::DrawDefaultCommand(const Command& c, const CUnit* owner) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CommandDrawer::DrawQuedBuildingSquares(const CBuilderCAI* cai) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

