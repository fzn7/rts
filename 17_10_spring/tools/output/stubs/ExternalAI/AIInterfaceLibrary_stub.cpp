#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AIInterfaceLibrary.h"

#include "AIInterfaceLibraryInfo.h"
#include "Interface/aidefines.h"
#include "SAIInterfaceCallbackImpl.h"
#include "SkirmishAILibrary.h"
#include "SkirmishAILibraryInfo.h"

#include "IAILibraryManager.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

CAIInterfaceLibrary::CAIInterfaceLibrary(const CAIInterfaceLibraryInfo& _info)
  : interfaceId(-1)
  , initialized(false)
  , sAIInterfaceLibrary(
      { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL })
  , info(_info)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAIInterfaceLibrary::~CAIInterfaceLibrary()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAIInterfaceLibrary::InitStatic()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAIInterfaceLibrary::ReleaseStatic()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

AIInterfaceKey
CAIInterfaceLibrary::GetKey() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

LevelOfSupport
CAIInterfaceLibrary::GetLevelOfSupportFor(
  const std::string& engineVersionString,
  int engineVersionNumber) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAIInterfaceLibrary::GetSkirmishAICount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::map<std::string, std::string>
CAIInterfaceLibrary::GetSkirmishAIInfos(int aiIndex) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CAIInterfaceLibrary::GetSkirmishAIOptions(int aiIndex) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAIInterfaceLibrary::GetLoadCount() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// used as fallback, when an AI could not be found
static int CALLING_CONV
handleEvent_empty(int teamId, int receiver, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SSkirmishAILibrary
CAIInterfaceLibrary::EmptyInterfaceLib()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Skirmish AI methods
const CSkirmishAILibrary*
CAIInterfaceLibrary::FetchSkirmishAILibrary(
  const CSkirmishAILibraryInfo& aiInfo)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAIInterfaceLibrary::ReleaseSkirmishAILibrary(const SkirmishAIKey& key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAIInterfaceLibrary::GetSkirmishAILibraryLoadCount(
  const SkirmishAIKey& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAIInterfaceLibrary::ReleaseAllSkirmishAILibraries()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAIInterfaceLibrary::reportInterfaceFunctionError(
  const std::string& libFileName,
  const std::string& functionName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CAIInterfaceLibrary::InitializeFromLib(const std::string& libFilePath)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
CAIInterfaceLibrary::FindLibFile()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
