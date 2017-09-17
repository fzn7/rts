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
}


void PlayerRoster::SetCompareFunc()
{
    //stub method
}


bool PlayerRoster::SetSortTypeByName(const std::string& name)
{
    //stub method
}


bool PlayerRoster::SetSortTypeByCode(SortType type)
{
    //stub method
}


const char* PlayerRoster::GetSortName()
{
    //stub method
}


/******************************************************************************/

const std::vector<int>& PlayerRoster::GetIndices(int* count, bool includePathingFlag) const
{
    //stub method
}


/******************************************************************************/

static inline int CompareBasics(const CPlayer* aP, const CPlayer* bP)
{
    //stub method
}


/******************************************************************************/

static int CompareAllies(const void* a, const void* b)
{
    //stub method
}


/******************************************************************************/

static int CompareTeamIDs(const void* a, const void* b)
{
    //stub method
}


/******************************************************************************/

static int ComparePlayerNames(const void* a, const void* b)
{
    //stub method
}


/******************************************************************************/

static int ComparePlayerCPUs(const void* a, const void* b)
{
    //stub method
}


/******************************************************************************/

static int ComparePlayerPings(const void* a, const void* b)
{
    //stub method
}


/******************************************************************************/
