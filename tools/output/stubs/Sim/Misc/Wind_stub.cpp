#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Wind.h"
#include "GlobalSynced.h"
#include "Sim/Units/Unit.h"
#include "System/creg/STL_Map.h"
#include "System/myMath.h"

CR_BIND(CWind, )

CR_REG_METADATA(CWind, (
	CR_MEMBER(maxWind),
	CR_MEMBER(minWind),

	CR_MEMBER(curWind),
	CR_MEMBER(curStrength),
	CR_MEMBER(curDir),

	CR_MEMBER(newWind),
	CR_MEMBER(oldWind),
	CR_MEMBER(status),

	CR_MEMBER(windGens)
))


// update all units every 15 secs
static const int WIND_UPDATE_RATE = 15 * GAME_SPEED;

CWind wind;

CWind::CWind()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CWind::~CWind()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CWind::LoadWind(float minw, float maxw)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CWind::ResetState()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CWind::AddUnit(CUnit* u) {
	std::map<int, CUnit*>::iterator it = windGens.find(u->id);

	if (it != windGens.end())
		return false;

	windGens[u->id] = u;
	// start pointing in direction of wind
	u->UpdateWind(curDir.x, curDir.z, curStrength);
	return true;
}

bool CWind::DelUnit(CUnit* u) {
	std::map<int, CUnit*>::iterator it = windGens.find(u->id);

	if (it == windGens.end())
		return false;

	windGens.erase(it);
	return true;
}



void CWind::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

