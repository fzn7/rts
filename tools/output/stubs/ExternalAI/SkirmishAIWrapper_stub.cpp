/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SkirmishAIWrapper.h"

#include "AICallback.h"
#include "AICheats.h"
#include "EngineOutHandler.h"
#include "IAILibraryManager.h"

#include "SSkirmishAICallbackImpl.h"
#include "SkirmishAIData.h"
#include "SkirmishAIHandler.h"
#include "SkirmishAILibrary.h"
#include "SkirmishAILibraryInfo.h"

#include "Interface/AISCommands.h"
#include "Interface/AISEvents.h"
#include "Interface/SSkirmishAILibrary.h"

#include "Sim/Misc/TeamHandler.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"

#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"

#include <fstream>
#include <iostream>
#include <sstream>

#undef DeleteFile

CR_BIND_DERIVED(CSkirmishAIWrapper, CObject, )
CR_REG_METADATA(CSkirmishAIWrapper,
                (CR_MEMBER(key),

                 CR_IGNORED(library),
                 CR_IGNORED(sCallback),

                 CR_IGNORED(callback),
                 CR_IGNORED(cheats),

                 CR_MEMBER(timerName),

                 CR_MEMBER(skirmishAIId),
                 CR_MEMBER(teamId),

                 // handled in PostLoad
                 CR_IGNORED(initialized),
                 CR_IGNORED(released),
                 CR_MEMBER(cheatEvents),

                 CR_MEMBER(initOk),
                 CR_MEMBER(dieing),

                 CR_SERIALIZER(Serialize),
                 CR_POSTLOAD(PostLoad)))

/// used only by creg
CSkirmishAIWrapper::CSkirmishAIWrapper()
  : library(nullptr)
  , sCallback(nullptr)
  ,

  skirmishAIId(-1)
  , teamId(-1)
  ,

  initialized(false)
  , released(false)
  , cheatEvents(false)
  ,

  initOk(false)
  , dieing(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::CreateCallback()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSkirmishAIWrapper::~CSkirmishAIWrapper()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::PreDestroy()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::Serialize(creg::ISerializer* s)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAIWrapper::LoadSkirmishAI(bool postLoad)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::Release(int reason)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
streamCopy(/*const*/ std::istream* in, std::ostream* out)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::string
createTempFileName(const char* action, int teamId, int skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::Load(std::istream* loadStream)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::Save(std::ostream* saveStream)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::UnitIdle(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::UnitCreated(int unitId, int builderId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::UnitFinished(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::UnitDestroyed(int unitId, int attackerUnitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::UnitDamaged(int unitId,
                                int attackerUnitId,
                                float damage,
                                const float3& dir,
                                int weaponDefId,
                                bool paralyzer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::UnitMoveFailed(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::UnitGiven(int unitId, int oldTeam, int newTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::UnitCaptured(int unitId, int oldTeam, int newTeam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::EnemyCreated(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::EnemyFinished(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::EnemyEnterLOS(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::EnemyLeaveLOS(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::EnemyEnterRadar(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::EnemyLeaveRadar(int unitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::EnemyDestroyed(int enemyUnitId, int attackerUnitId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::EnemyDamaged(int enemyUnitId,
                                 int attackerUnitId,
                                 float damage,
                                 const float3& dir,
                                 int weaponDefId,
                                 bool paralyzer)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::Update(int frame)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::SendChatMessage(const char* msg, int fromPlayerId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::SendLuaMessage(const char* inData, const char** outData)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::WeaponFired(int unitId, int weaponDefId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::PlayerCommandGiven(
  const std::vector<int>& playerSelectedUnits,
  const Command& c,
  int playerId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::CommandFinished(int unitId,
                                    int commandId,
                                    int commandTopicId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIWrapper::SeismicPing(int allyTeam,
                                int unitId,
                                const float3& pos,
                                float strength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CSkirmishAIWrapper::HandleEvent(int topic, const void* data) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
