#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DemoRecorder.h"
#include "Game/GameVersion.h"
#include "Sim/Misc/TeamStatistics.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileSystem.h"
#include "System/TimeUtil.h"
#include "System/Util.h"

#include "System/Log/ILog.h"

#include <cassert>
#include <cerrno>
#include <cstring>

CDemoRecorder::CDemoRecorder(const std::string& mapName,
                             const std::string& modName,
                             bool serverDemo)
  : demoStream(std::ios::binary | std::ios::out)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CDemoRecorder::~CDemoRecorder()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::SetFileHeader()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::WriteDemoFile()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::WriteSetupText(const std::string& text)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::SaveToDemo(const unsigned char* buf,
                          const unsigned length,
                          const float modGameTime)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::SetName(const std::string& mapName,
                       const std::string& modName,
                       bool serverDemo)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::SetGameID(const unsigned char* buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::SetTime(int gameTime, int wallclockTime)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::InitializeStats(int numPlayers, int numTeams)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CDemoRecorder::AddNewPlayer(const std::string& name, int playerNum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** @brief Set (overwrite) the CPlayer::Statistics for player playerNum */
void
CDemoRecorder::SetPlayerStats(int playerNum, const PlayerStatistics& stats)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** @brief Set (overwrite) the TeamStatistics history for team teamNum */
void
CDemoRecorder::SetTeamStats(int teamNum, const std::list<TeamStatistics>& stats)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** @brief Set (overwrite) the list of winning allyTeams */
void
CDemoRecorder::SetWinningAllyTeams(
  const std::vector<unsigned char>& winningAllyTeamIDs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** @brief Write DemoFileHeader
Write the DemoFileHeader at the start of the file and restores the original
position in the file afterwards. */
unsigned int
CDemoRecorder::WriteFileHeader(bool updateStreamLength)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** @brief Write the CPlayer::Statistics at the current position in the file. */
void
CDemoRecorder::WritePlayerStats()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** @brief Write the winningAllyTeams at the current position in the file. */
void
CDemoRecorder::WriteWinnerList()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/** @brief Write the TeamStatistics at the current position in the file. */
void
CDemoRecorder::WriteTeamStats()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
