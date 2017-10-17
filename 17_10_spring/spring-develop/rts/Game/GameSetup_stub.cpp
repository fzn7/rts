#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "GameSetup.h"
#include "Map/MapParser.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/RapidHandler.h"
#include "System/Log/ILog.h"
#include "System/Sync/HsiehHash.h"
#include "System/TdfParser.h"
#include "System/UnsyncedRNG.h"
#include "System/Util.h"

#include <algorithm>
#include <boost/format.hpp>
#include <cctype>
#include <cstring>
#include <fstream>
#include <map>
#include <numeric>

CR_BIND(CGameSetup, )
CR_REG_METADATA(CGameSetup,
                (CR_IGNORED(fixedAllies),
                 CR_IGNORED(useLuaGaia),
                 CR_IGNORED(noHelperAIs),

                 CR_IGNORED(ghostedBuildings),
                 CR_IGNORED(disableMapDamage),

                 CR_IGNORED(onlyLocal),
                 CR_IGNORED(hostDemo),

                 CR_IGNORED(mapHash),
                 CR_IGNORED(modHash),
                 CR_IGNORED(mapSeed),

                 CR_IGNORED(gameStartDelay),

                 CR_IGNORED(numDemoPlayers),
                 CR_IGNORED(maxUnitsPerTeam),

                 CR_IGNORED(minSpeed),
                 CR_IGNORED(maxSpeed),

                 CR_IGNORED(startPosType),

                 CR_IGNORED(mapName),
                 CR_IGNORED(modName),
                 CR_IGNORED(gameID),

                 // all other members can be reconstructed from this
                 CR_MEMBER(setupText),

                 CR_IGNORED(recordDemo),
                 CR_IGNORED(demoName),
                 CR_IGNORED(saveName),

                 CR_IGNORED(playerRemap),
                 CR_IGNORED(teamRemap),
                 CR_IGNORED(allyteamRemap),

                 CR_IGNORED(playerStartingData),
                 CR_IGNORED(teamStartingData),
                 CR_IGNORED(allyStartingData),
                 CR_IGNORED(skirmishAIStartingData),
                 CR_IGNORED(mutatorsList),

                 CR_IGNORED(restrictedUnits),

                 CR_IGNORED(mapOptions),
                 CR_IGNORED(modOptions),

                 CR_POSTLOAD(PostLoad)))

CGameSetup* gameSetup = nullptr;

bool
CGameSetup::LoadReceivedScript(const std::string& script, bool isHost)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CGameSetup::LoadSavedScript(const std::string& file, const std::string& script)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::map<std::string, std::string>&
CGameSetup::GetMapOptions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::map<std::string, std::string>&
CGameSetup::GetModOptions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::vector<PlayerBase>&
CGameSetup::GetPlayerStartingData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::vector<TeamBase>&
CGameSetup::GetTeamStartingData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::vector<AllyTeam>&
CGameSetup::GetAllyStartingData()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::ResetState()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::LoadUnitRestrictions(const TdfParser& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::LoadStartPositionsFromMap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::LoadStartPositions(bool withoutMap)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::LoadMutators(const TdfParser& file,
                         std::vector<std::string>& mutatorsList)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::LoadPlayers(const TdfParser& file, std::set<std::string>& nameList)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::LoadSkirmishAIs(const TdfParser& file,
                            std::set<std::string>& nameList)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::LoadTeams(const TdfParser& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::LoadAllyTeams(const TdfParser& file)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::RemapPlayers()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::RemapTeams()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CGameSetup::RemapAllyteams()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// TODO: RemapSkirmishAIs()
bool
CGameSetup::Init(const std::string& buf)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string
CGameSetup::MapFile() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
