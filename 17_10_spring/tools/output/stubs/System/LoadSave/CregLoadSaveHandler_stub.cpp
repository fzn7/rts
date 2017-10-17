#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <sstream>
#include <zlib.h>

#include "CregLoadSaveHandler.h"
#include "ExternalAI/EngineOutHandler.h"
#include "Game/Game.h"
#include "Game/GameSetup.h"
#include "Game/GameVersion.h"
#include "Game/GlobalUnsynced.h"
#include "Game/UI/Groups/GroupHandler.h"
#include "Game/WaitCommandsAI.h"
#include "Map/ReadMap.h"
#include "Net/GameServer.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Misc/CategoryHandler.h"
#include "Sim/Misc/InterceptHandler.h"
#include "Sim/Misc/LosHandler.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/Wind.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Sim/Units/CommandAI/BuilderCAI.h"
#include "Sim/Units/CommandAI/CommandDescription.h"
#include "Sim/Units/Scripts/CobEngine.h"
#include "Sim/Units/Scripts/NullUnitScript.h"
#include "Sim/Units/Scripts/UnitScriptEngine.h"
#include "Sim/Units/UnitHandler.h"

#include "System/Exceptions.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/GZFileHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/errorhandler.h"
#include "System/creg/Serializer.h"

CCregLoadSaveHandler::CCregLoadSaveHandler()
  : iss(nullptr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
WriteString(std::ostream& s, const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
PrintSize(const char* txt, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif // USING_CREG

static void
ReadString(std::istream& s, std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCregLoadSaveHandler::SaveGame(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// this just loads the mapname and some other early stuff
void
CCregLoadSaveHandler::LoadGameStartInfo(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// this should be called on frame 0 when the game has started
void
CCregLoadSaveHandler::LoadGame()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
