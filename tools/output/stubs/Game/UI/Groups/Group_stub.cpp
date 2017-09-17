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
}

CGroup::~CGroup()
{
    //stub method
}



void CGroup::PostLoad()
{
    //stub method
}

bool CGroup::AddUnit(CUnit* unit)
{
    //stub method
}

void CGroup::RemoveUnit(CUnit* unit)
{
    //stub method
}

void CGroup::RemoveIfEmptySpecialGroup()
{
    //stub method
}

void CGroup::Update()
{
    //stub method
}

void CGroup::ClearUnits()
{
    //stub method
}

float3 CGroup::CalculateCenter() const
{
    //stub method
}
