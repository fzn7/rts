#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SkirmishAILibrary.h"

#include "ExternalAI/AIInterfaceKey.h"
#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Log/ILog.h"

#include <string>

CSkirmishAILibrary::CSkirmishAILibrary(const SSkirmishAILibrary& ai,
                                       const SkirmishAIKey& key)
  : sSAI(ai)
  , key(key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LevelOfSupport
CSkirmishAILibrary::GetLevelOfSupportFor(
  const std::string& engineVersionString,
  const int engineVersionNumber,
  const AIInterfaceKey& interfaceKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAILibrary::Init(int skirmishAIId,
                         const SSkirmishAICallback* c_callback) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAILibrary::Release(int skirmishAIId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CSkirmishAILibrary::HandleEvent(int skirmishAIId,
                                int topic,
                                const void* data) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
