#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cstdio>

using std::sprintf;

#include "SAIInterfaceCallbackImpl.h"

#include "ExternalAI/AIInterfaceLibraryInfo.h"
#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/Interface/AISCommands.h"     // for ABI version
#include "ExternalAI/Interface/AISEvents.h"       // for ABI version
#include "ExternalAI/Interface/ELevelOfSupport.h" // for ABI version
#include "ExternalAI/Interface/SAIInterfaceLibrary.h" // for ABI version and AI_INTERFACE_PROPERTY_*
#include "ExternalAI/Interface/SSkirmishAILibrary.h" // for ABI version
#include "ExternalAI/SkirmishAIHandler.h"
#include "Game/GameVersion.h"
#include "Sim/Misc/GlobalConstants.h" // for MAX_TEAMS
#include "Sim/Misc/TeamHandler.h"     // ActiveTeams()
#include "System/FileSystem/DataDirLocater.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/Log/ILog.h"
#include "System/SafeCStrings.h"

#include <cstring>
#include <sstream>  // ostringstream
#include <stdlib.h> // malloc(), calloc(), free()
#include <vector>

static const char* AI_INTERFACES_VERSION_COMMON = "common";

static std::vector<const CAIInterfaceLibraryInfo*> infos;

void
CHECK_INTERFACE_ID(const int interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(int)
aiInterfaceCallback_Engine_AIInterface_ABIVersion_getFailPart(
  int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(int)
aiInterfaceCallback_Engine_AIInterface_ABIVersion_getWarningPart(
  int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getMajor(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getMinor(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getPatchset(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getCommits(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getHash(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getBranch(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getAdditional(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getBuildTime(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(bool)
aiInterfaceCallback_Engine_Version_isRelease(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getNormal(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getSync(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
EXPORT(const char*)
aiInterfaceCallback_Engine_Version_getFull(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(int) aiInterfaceCallback_AIInterface_Info_getSize(int interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(const char*)
aiInterfaceCallback_AIInterface_Info_getKey(int interfaceId, int infoIndex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(const char*)
aiInterfaceCallback_AIInterface_Info_getValue(int interfaceId, int infoIndex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(const char*)
aiInterfaceCallback_AIInterface_Info_getDescription(int interfaceId,
                                                    int infoIndex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(const char*)
aiInterfaceCallback_AIInterface_Info_getValueByKey(int interfaceId,
                                                   const char* const key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(int) aiInterfaceCallback_Teams_getSize(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(int) aiInterfaceCallback_SkirmishAIs_getSize(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(int) aiInterfaceCallback_SkirmishAIs_getMax(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(const char*)
aiInterfaceCallback_SkirmishAIs_Info_getValueByKey(int UNUSED_interfaceId,
                                                   const char* const shortName,
                                                   const char* const version,
                                                   const char* const key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(void) aiInterfaceCallback_Log_log(int interfaceId, const char* const msg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(void)
aiInterfaceCallback_Log_logsl(int interfaceId,
                              const char* section,
                              int loglevel,
                              const char* const msg)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(void)
aiInterfaceCallback_Log_exception(int interfaceId,
                                  const char* const msg,
                                  int severety,
                                  bool die)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(char)
aiInterfaceCallback_DataDirs_getPathSeparator(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(int) aiInterfaceCallback_DataDirs_Roots_getSize(int UNUSED_interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(bool)
aiInterfaceCallback_DataDirs_Roots_getDir(int UNUSED_interfaceId,
                                          char* path,
                                          int pathMaxSize,
                                          int dirIndex)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(bool)
aiInterfaceCallback_DataDirs_Roots_locatePath(int UNUSED_interfaceId,
                                              char* path,
                                              int pathMaxSize,
                                              const char* const relPath,
                                              bool writeable,
                                              bool create,
                                              bool dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(char*)
aiInterfaceCallback_DataDirs_Roots_allocatePath(int UNUSED_interfaceId,
                                                const char* const relPath,
                                                bool writeable,
                                                bool create,
                                                bool dir)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(const char*) aiInterfaceCallback_DataDirs_getConfigDir(int interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(bool)
aiInterfaceCallback_DataDirs_locatePath(int interfaceId,
                                        char* path,
                                        int pathMaxSize,
                                        const char* const relPath,
                                        bool writeable,
                                        bool create,
                                        bool dir,
                                        bool common)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

EXPORT(char*)
aiInterfaceCallback_DataDirs_allocatePath(int interfaceId,
                                          const char* const relPath,
                                          bool writeable,
                                          bool create,
                                          bool dir,
                                          bool common)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static std::vector<std::string> writeableDataDirs;

EXPORT(const char*)
aiInterfaceCallback_DataDirs_getWriteableDir(int interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
aiInterfaceCallback_init(struct SAIInterfaceCallback* callback)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
aiInterfaceCallback_getInstanceFor(const CAIInterfaceLibraryInfo* info,
                                   struct SAIInterfaceCallback* callback)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
aiInterfaceCallback_release(int interfaceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
