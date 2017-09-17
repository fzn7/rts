#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Factory.h"
#include "Game/GameHelper.h"
#include "Game/WaitCommandsAI.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/CommandAI/FactoryCAI.h"
#include "Sim/Units/CommandAI/MobileCAI.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/UnitDefHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/UnitLoader.h"
#include "System/EventHandler.h"
#include "System/Matrix44f.h"
#include "System/Sound/ISoundChannels.h"
#include "System/Sync/SyncTracer.h"
#include "System/creg/DefTypes.h"
#include "System/myMath.h"

#include "Game/GlobalUnsynced.h"

CR_BIND_DERIVED(CFactory, CBuilding, )

CR_REG_METADATA(CFactory,
                (CR_MEMBER(buildSpeed),
                 CR_MEMBER(lastBuildUpdateFrame),
                 CR_MEMBER(curBuildDef),
                 CR_MEMBER(curBuild),
                 CR_MEMBER(finishedBuildCommand),
                 CR_MEMBER(nanoPieceCache)))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFactory::CFactory()
  : buildSpeed(100.0f)
  , curBuild(nullptr)
  , curBuildDef(nullptr)
  , lastBuildUpdateFrame(-1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::PreInit(const UnitLoadParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CFactory::CalcBuildPos(int buildPiece)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
void CFactory::SlowUpdate(void)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
*/

void
CFactory::StartBuild(const UnitDef* buildeeDef)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::UpdateBuild(CUnit* buildee)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::FinishBuild(CUnit* buildee)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
CFactory::QueueBuild(const UnitDef* buildeeDef, const Command& buildCmd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::StopBuild()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::DependentDied(CObject* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::SendToEmptySpot(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::AssignBuildeeOrders(CUnit* unit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CFactory::ChangeTeam(int newTeam, ChangeType type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CFactory::CreateNanoParticle(bool highPriority)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
