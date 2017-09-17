/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/cstdint.hpp>
#include <SDL_keycode.h>

#include "GroupHandler.h"
#include "Group.h"
#include "Game/SelectedUnitsHandler.h"
#include "Game/CameraHandler.h"
#include "System/creg/STL_Set.h"
#include "System/Log/ILog.h"
#include "System/Input/KeyInput.h"
#include "System/EventHandler.h"

std::vector<CGroupHandler*> grouphandlers;

CR_BIND(CGroupHandler, (0))
CR_REG_METADATA(CGroupHandler, (
	CR_MEMBER(groups),
	CR_MEMBER(team),
	CR_MEMBER(freeGroups),
	CR_MEMBER(firstUnusedGroup),
	CR_MEMBER(changedGroups)
))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGroupHandler::CGroupHandler(int teamId)
: team(teamId)
, firstUnusedGroup(FIRST_SPECIAL_GROUP)
{
    //stub method
}

CGroupHandler::~CGroupHandler()
{
    //stub method
}

void CGroupHandler::Update()
{
    //stub method
}

bool CGroupHandler::GroupCommand(int num)
{
    //stub method
}

bool CGroupHandler::GroupCommand(int num, const std::string& cmd)
{
    //stub method
}

CGroup* CGroupHandler::CreateNewGroup()
{
    //stub method
}

void CGroupHandler::RemoveGroup(CGroup* group)
{
    //stub method
}

void CGroupHandler::PushGroupChange(int id)
{
    //stub method
}
