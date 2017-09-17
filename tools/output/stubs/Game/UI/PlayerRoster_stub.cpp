#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "PlayerRoster.h"

#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Game/GlobalUnsynced.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Util.h"

#include <cassert>
#include <cstring>

static int CompareAllies     (const void* a, const void* b);
static int CompareTeamIDs    (const void* a, const void* b);
static int ComparePlayerNames(const void* a, const void* b);
static int ComparePlayerCPUs (const void* a, const void* b);
static int ComparePlayerPings(const void* a, const void* b);


PlayerRoster playerRoster;


/******************************************************************************/

PlayerRoster::PlayerRoster()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void PlayerRoster::SetCompareFunc()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool PlayerRoster::SetSortTypeByName(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool PlayerRoster::SetSortTypeByCode(SortType type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const char* PlayerRoster::GetSortName()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

const std::vector<int>& PlayerRoster::GetIndices(int* count, bool includePathingFlag) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static inline int CompareBasics(const CPlayer* aP, const CPlayer* bP)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int CompareAllies(const void* a, const void* b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int CompareTeamIDs(const void* a, const void* b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int ComparePlayerNames(const void* a, const void* b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int ComparePlayerCPUs(const void* a, const void* b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static int ComparePlayerPings(const void* a, const void* b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
