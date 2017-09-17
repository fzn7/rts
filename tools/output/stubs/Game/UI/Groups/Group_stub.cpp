#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Group.h"
#include "GroupHandler.h"
#include "Game/GlobalUnsynced.h"
#include "System/EventHandler.h"
#include "System/creg/STL_Set.h"
#include "System/float3.h"

CR_BIND(CGroup, (0, NULL))
CR_REG_METADATA(CGroup, (
	CR_MEMBER(id),
	CR_MEMBER(units),
	CR_MEMBER(handler),
	CR_POSTLOAD(PostLoad)
))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGroup::CGroup(int id, CGroupHandler* groupHandler)
		: id(id)
		, handler(groupHandler)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CGroup::~CGroup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CGroup::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CGroup::AddUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGroup::RemoveUnit(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGroup::RemoveIfEmptySpecialGroup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGroup::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CGroup::ClearUnits()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 CGroup::CalculateCenter() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
