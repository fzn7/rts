/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cassert>

#include "UnitHandler.h"
#include "Unit.h"
#include "UnitDefHandler.h"
#include "CommandAI/BuilderCAI.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Weapons/Weapon.h"
#include "System/EventHandler.h"
#include "System/Log/ILog.h"
#include "System/myMath.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "System/Sync/SyncTracer.h"
#include "System/creg/STL_Deque.h"
#include "System/creg/STL_List.h"
#include "System/creg/STL_Set.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUnitHandler* unitHandler = NULL;

CR_BIND(CUnitHandler, )
CR_REG_METADATA(CUnitHandler, (
	CR_MEMBER(units),
	CR_MEMBER(unitsByDefs),
	CR_MEMBER(activeUnits),
	CR_MEMBER(builderCAIs),
	CR_MEMBER(idPool),
	CR_MEMBER(unitsToBeRemoved),
	CR_MEMBER(activeSlowUpdateUnit),
	CR_MEMBER(activeUpdateUnit),
	CR_MEMBER(maxUnits),
	CR_MEMBER(maxUnitRadius)
))


CUnitHandler::CUnitHandler()
:
	maxUnits(0),
	maxUnitRadius(0.0f)
{
    //stub method
}


CUnitHandler::~CUnitHandler()
{
    //stub method
}


void CUnitHandler::DeleteScripts()
{
    //stub method
}


void CUnitHandler::InsertActiveUnit(CUnit* unit)
{
    //stub method
}


bool CUnitHandler::AddUnit(CUnit* unit)
{
    //stub method
}


void CUnitHandler::DeleteUnit(CUnit* unit)
{
    //stub method
}

void CUnitHandler::DeleteUnitsNow()
{
    //stub method
}

void CUnitHandler::DeleteUnitNow(CUnit* delUnit)
{
    //stub method
}


void CUnitHandler::Update()
{
    //stub method
}



void CUnitHandler::AddBuilderCAI(CBuilderCAI* b)
{
    //stub method
}

void CUnitHandler::RemoveBuilderCAI(CBuilderCAI* b)
{
    //stub method
}



bool CUnitHandler::CanBuildUnit(const UnitDef* unitdef, int team) const
{
    //stub method
}
