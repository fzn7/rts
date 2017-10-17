#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AILibraryManager.h"

#include "AIInterfaceLibrary.h"
#include "AIInterfaceLibraryInfo.h"
#include "Interface/SAIInterfaceLibrary.h"
#include "Interface/aidefines.h"
#include "SkirmishAIData.h"
#include "SkirmishAILibraryInfo.h"

#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/Team.h"
#include "Sim/Misc/TeamHandler.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Platform/SharedLib.h"
#include "System/Platform/errorhandler.h"
#include "System/Util.h"

#include <limits.h>
#include <set>
#include <sstream>
#include <string>

CAILibraryManager::CAILibraryManager()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::GatherInterfaceLibrariesInfos()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::GatherSkirmishAIsLibrariesInfos()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::StoreSkirmishAILibraryInfos(
  T_dupSkirm duplicateSkirmishAIInfoCheck,
  CSkirmishAILibraryInfo& skirmishAIInfo,
  const std::string& sourceDesc)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::GatherSkirmishAIsLibrariesInfosFromLuaFiles(
  T_dupSkirm duplicateSkirmishAIInfoCheck)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::GatherSkirmishAIsLibrariesInfosFromInterfaceLibrary(
  T_dupSkirm duplicateSkirmishAIInfoCheck)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::FilterDuplicateSkirmishAILibrariesInfos(
  T_dupSkirm duplicateSkirmishAIInfoCheck)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::ClearAllInfos()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CAILibraryManager::~CAILibraryManager()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<SkirmishAIKey>
CAILibraryManager::FittingSkirmishAIKeys(
  const SkirmishAIKey& skirmishAIKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const CSkirmishAILibrary*
CAILibraryManager::FetchSkirmishAILibrary(const SkirmishAIKey& skirmishAIKey)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::ReleaseSkirmishAILibrary(const SkirmishAIKey& skirmishAIKey)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::ReleaseEverything()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CAIInterfaceLibrary*
CAILibraryManager::FetchInterface(const AIInterfaceKey& interfaceKey)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CAILibraryManager::ReleaseInterface(const AIInterfaceKey& interfaceKey)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

AIInterfaceKey
CAILibraryManager::FindFittingInterfaceSpecifier(
  const std::string& shortName,
  const std::string& minVersion,
  const IAILibraryManager::T_interfaceSpecs& keys)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
