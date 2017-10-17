#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <SDL_keycode.h>
#include <boost/cstdint.hpp>

#include "Game/CameraHandler.h"
#include "Game/SelectedUnitsHandler.h"
#include "Group.h"
#include "GroupHandler.h"
#include "System/EventHandler.h"
#include "System/Input/KeyInput.h"
#include "System/Log/ILog.h"
#include "System/creg/STL_Set.h"

std::vector<CGroupHandler*> grouphandlers;

CR_BIND(CGroupHandler, (0))
CR_REG_METADATA(CGroupHandler,
                (CR_MEMBER(groups),
                 CR_MEMBER(team),
                 CR_MEMBER(freeGroups),
                 CR_MEMBER(firstUnusedGroup),
                 CR_MEMBER(changedGroups)))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGroupHandler::CGroupHandler(int teamId)
  : team(teamId)
  , firstUnusedGroup(FIRST_SPECIAL_GROUP)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGroupHandler::~CGroupHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroupHandler::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroupHandler::GroupCommand(int num)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGroupHandler::GroupCommand(int num, const std::string& cmd)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CGroup*
CGroupHandler::CreateNewGroup()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroupHandler::RemoveGroup(CGroup* group)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGroupHandler::PushGroupChange(int id)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
