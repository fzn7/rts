#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "TeamBase.h"

#include <cstdlib>
#include <sstream>

#include "System/Util.h"
#include "System/creg/STL_Map.h"

CR_BIND(TeamBase, )
CR_REG_METADATA(TeamBase,
                (CR_MEMBER(leader),
                 CR_MEMBER(color),
                 CR_MEMBER(teamStartNum),
                 CR_MEMBER(teamAllyteam),
                 CR_MEMBER(incomeMultiplier),
                 CR_MEMBER(side),
                 CR_MEMBER(startPos),
                 CR_MEMBER(customValues)))

unsigned char TeamBase::teamDefaultColor[10][4] = {
    { 90, 90, 255, 255 },   // blue
    { 200, 0, 0, 255 },     // red
    { 255, 255, 255, 255 }, // white
    { 38, 155, 32, 255 },   // green
    { 7, 31, 125, 255 },    // blue
    { 150, 10, 180, 255 },  // purple
    { 255, 255, 0, 255 },   // yellow
    { 50, 50, 50, 255 },    // black
    { 152, 200, 220, 255 }, // ltblue
    { 171, 171, 131, 255 }  // tan
};

TeamBase::TeamBase()
  : leader(-1)
  , teamStartNum(-1)
  , teamAllyteam(-1)
  , incomeMultiplier(1.0f)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TeamBase::SetValue(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TeamBase::SetAdvantage(float advantage)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
TeamBase::SetIncomeMultiplier(float incomeMultiplier)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
