#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Wind.h"
#include "GlobalSynced.h"
#include "Sim/Units/Unit.h"
#include "System/creg/STL_Map.h"
#include "System/myMath.h"

CR_BIND(CWind, )

CR_REG_METADATA(CWind,
                (CR_MEMBER(maxWind),
                 CR_MEMBER(minWind),

                 CR_MEMBER(curWind),
                 CR_MEMBER(curStrength),
                 CR_MEMBER(curDir),

                 CR_MEMBER(newWind),
                 CR_MEMBER(oldWind),
                 CR_MEMBER(status),

                 CR_MEMBER(windGens)))

// update all units every 15 secs
static const int WIND_UPDATE_RATE = 15 * GAME_SPEED;

CWind wind;

CWind::CWind()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CWind::~CWind()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWind::LoadWind(float minw, float maxw)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWind::ResetState()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWind::AddUnit(CUnit* u)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CWind::DelUnit(CUnit* u)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CWind::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
