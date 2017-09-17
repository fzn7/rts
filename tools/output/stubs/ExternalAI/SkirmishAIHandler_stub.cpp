#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SkirmishAIHandler.h"

#include "ExternalAI/EngineOutHandler.h"
#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/Interface/SSkirmishAILibrary.h"
#include "ExternalAI/LuaAIImplHandler.h"
#include "ExternalAI/SkirmishAIKey.h"
#include "Game/GameSetup.h"
#include "Game/GlobalUnsynced.h"
#include "Net/Protocol/NetProtocol.h"
#include "System/Option.h"

#include "System/creg/STL_Map.h"
#include "System/creg/STL_Set.h"

#include <assert.h>

CR_BIND(CSkirmishAIHandler, )

CR_REG_METADATA(CSkirmishAIHandler,
                (CR_MEMBER(id_ai),
                 CR_MEMBER(team_localAIsInCreation),
                 CR_MEMBER(id_dieReason),
                 CR_MEMBER(id_libKey),
                 CR_MEMBER(gameInitialized),
                 CR_MEMBER(luaAIShortNames),
                 CR_IGNORED(currentAIId)))

// not extern'ed, so static
static CSkirmishAIHandler* gSkirmishAIHandler = nullptr;

CSkirmishAIHandler*
CSkirmishAIHandler::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::FreeInstance(CSkirmishAIHandler* handler)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::ResetState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::LoadFromSetup(const CGameSetup& setup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::LoadPreGame()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAIHandler::IsActiveSkirmishAI(const size_t skirmishAIId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SkirmishAIData*
CSkirmishAIHandler::GetSkirmishAI(const size_t skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

size_t
CSkirmishAIHandler::GetSkirmishAI(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSkirmishAIHandler::ids_t
CSkirmishAIHandler::GetSkirmishAIsInTeam(const int teamId,
                                         const int hostPlayerId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSkirmishAIHandler::ids_t
CSkirmishAIHandler::GetSkirmishAIsByPlayer(const int hostPlayerId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::AddSkirmishAI(const SkirmishAIData& data,
                                  const size_t skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAIHandler::RemoveSkirmishAI(const size_t skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::CreateLocalSkirmishAI(const size_t skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::CreateLocalSkirmishAI(const SkirmishAIData& aiData)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const SkirmishAIData*
CSkirmishAIHandler::GetLocalSkirmishAIInCreation(const int teamId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::SetLocalSkirmishAIDieing(const size_t skirmishAIId,
                                             const int reason)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const SkirmishAIKey*
CSkirmishAIHandler::GetLocalSkirmishAILibraryKey(const size_t skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAIHandler::IsLocalSkirmishAI(const size_t skirmishAIId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAIHandler::IsLocalSkirmishAI(const SkirmishAIData& aiData)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::CompleteWithDefaultOptionValues(const size_t skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAIHandler::CompleteSkirmishAI(const size_t skirmishAIId)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
