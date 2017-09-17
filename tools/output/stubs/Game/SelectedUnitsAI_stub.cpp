/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SelectedUnitsAI.h"

#include "SelectedUnitsHandler.h"
#include "GlobalUnsynced.h"
#include "WaitCommandsAI.h"
#include "Game/Players/Player.h"
#include "Game/Players/PlayerHandler.h"
#include "Map/Ground.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/TeamHandler.h"
#include "Sim/MoveTypes/MoveType.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Net/Protocol/NetProtocol.h"

const int CMDPARAM_MOVE_X = 0;
const int CMDPARAM_MOVE_Y = 1;
const int CMDPARAM_MOVE_Z = 2;


// Global object
CSelectedUnitsHandlerAI selectedUnitsAI;

CSelectedUnitsHandlerAI::CSelectedUnitsHandlerAI()
	: centerPos(ZeroVector)
	, rightPos(ZeroVector)
	, sumLength(0)
	, avgLength(0.0f)
	, frontLength(0.0f)
	, addSpace(0.0f)
	, minCoor(ZeroVector)
	, maxCoor(ZeroVector)
	, centerCoor(ZeroVector)
	, minMaxSpeed(0.0f)

	, frontDir(ZeroVector)
	, sideDir(ZeroVector)
	, columnDist(64.0f)
	, numColumns(0)
{
    //stub method
}


inline void CSelectedUnitsHandlerAI::AddUnitSetMaxSpeedCommand(CUnit* unit,
                                                        unsigned char options)
{
    //stub method
}

inline void CSelectedUnitsHandlerAI::AddGroupSetMaxSpeedCommand(CUnit* unit,
                                                         unsigned char options)
{
    //stub method
}


static inline bool MayRequireSetMaxSpeedCommand(const Command &c)
{
    //stub method
}

void CSelectedUnitsHandlerAI::GiveCommandNet(Command &c, int player)
{
    //stub method
}


//
// Calculate the outer limits and the center of the group coordinates.
//
void CSelectedUnitsHandlerAI::CalculateGroupData(int player, bool queueing) {
	//Finding the highest, lowest and weighted central positional coordinates among the selected units.
	float3 sumCoor, minCoor, maxCoor;
	float3 mobileSumCoor = sumCoor;
	sumLength = 0; ///
	int mobileUnits = 0;
	minMaxSpeed = 1e9f;
	for(std::vector<int>::iterator ui = selectedUnitsHandler.netSelected[player].begin(); ui != selectedUnitsHandler.netSelected[player].end(); ++ui) {
		CUnit* unit=unitHandler->units[*ui];
		if(unit){
			const UnitDef* ud = unit->unitDef;
			sumLength += (int)((ud->xsize + ud->zsize)/2);

			float3 unitPos;
			if (queueing) {
				unitPos = LastQueuePosition(unit);
			} else {
				unitPos = unit->midPos;
			}
			if(unitPos.x < minCoor.x)
				minCoor.x = unitPos.x;
			else if(unitPos.x > maxCoor.x)
				maxCoor.x = unitPos.x;
			if(unitPos.y < minCoor.y)
				minCoor.y = unitPos.y;
			else if(unitPos.y > maxCoor.y)
				maxCoor.y = unitPos.y;
			if(unitPos.z < minCoor.z)
				minCoor.z = unitPos.z;
			else if(unitPos.z > maxCoor.z)
				maxCoor.z = unitPos.z;
			sumCoor += unitPos;

			if (unit->commandAI->CanSetMaxSpeed()) {
				mobileUnits++;
				mobileSumCoor += unitPos;

				const float maxSpeed = unit->moveType->GetMaxSpeed();

				if (maxSpeed < minMaxSpeed) {
					minMaxSpeed = maxSpeed;
				}
			}
		}
	}
	avgLength = sumLength/selectedUnitsHandler.netSelected[player].size();
	//Weighted center
	if(mobileUnits > 0)
		centerCoor = mobileSumCoor / mobileUnits;
	else
		centerCoor = sumCoor / selectedUnitsHandler.netSelected[player].size();
}


void CSelectedUnitsHandlerAI::MakeFrontMove(Command* c,int player)
{
    //stub method
}


void CSelectedUnitsHandlerAI::CreateUnitOrder(std::multimap<float,int>& out,int player)
{
    //stub method
}


float3 CSelectedUnitsHandlerAI::MoveToPos(int unit, float3 nextCornerPos, float3 dir, Command* command, std::vector<std::pair<int,Command> >* frontcmds, bool* newline)
{
    //stub method
}


struct DistInfo {
	bool operator<(const DistInfo& di) const { return dist < di.dist; }
	float dist;
	int unitID;
};


void CSelectedUnitsHandlerAI::SelectAttack(const Command& cmd, int player)
{
    //stub method
}


void CSelectedUnitsHandlerAI::SelectCircleUnits(
	const float3& pos,
	float radius,
	int player,
	std::vector<int>& units
) {
	units.clear();

	if (!playerHandler->IsValidPlayer(player))
		return;

	const CPlayer* p = playerHandler->Player(player);

	if (p == NULL)
		return;

	const std::vector<CUnit*>& tmpUnits = quadField->GetUnitsExact(pos, radius, false);

	const float radiusSqr = radius * radius;
	const unsigned int count = tmpUnits.size();
	const int allyTeam = teamHandler->AllyTeam(p->team);

	units.reserve(count);

	for (unsigned int i = 0; i < count; i++) {
		CUnit* unit = tmpUnits[i];

		if (unit == NULL)
			continue;
		if (unit->allyteam == allyTeam)
			continue;
		if (!(unit->losStatus[allyTeam] & (LOS_INLOS | LOS_INRADAR)))
			continue;

		const float dx = (pos.x - unit->midPos.x);
		const float dz = (pos.z - unit->midPos.z);

		if (((dx * dx) + (dz * dz)) > radiusSqr)
			continue;

		units.push_back(unit->id);
	}
}


void CSelectedUnitsHandlerAI::SelectRectangleUnits(
	const float3& pos0,
	const float3& pos1,
	int player,
	std::vector<int>& units
) {
	units.clear();

	if (!playerHandler->IsValidPlayer(player))
		return;

	const CPlayer* p = playerHandler->Player(player);

	if (p == NULL)
		return;

	const float3 mins(std::min(pos0.x, pos1.x), 0.0f, std::min(pos0.z, pos1.z));
	const float3 maxs(std::max(pos0.x, pos1.x), 0.0f, std::max(pos0.z, pos1.z));

	const std::vector<CUnit*>& tmpUnits = quadField->GetUnitsExact(mins, maxs);

	const unsigned int count = tmpUnits.size();
	const int allyTeam = teamHandler->AllyTeam(p->team);

	units.reserve(count);

	for (unsigned int i = 0; i < count; i++) {
		const CUnit* unit = tmpUnits[i];

		if (unit == NULL)
			continue;
		if (unit->allyteam == allyTeam)
			continue;
		if (!(unit->losStatus[allyTeam] & (LOS_INLOS | LOS_INRADAR)))
			continue;

		units.push_back(unit->id);
	}
}


float3 CSelectedUnitsHandlerAI::LastQueuePosition(const CUnit* unit)
{
    //stub method
}
