#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "HoverAirMoveType.h"
#include "Game/Players/Player.h"
#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "System/myMath.h"
#include "System/Matrix44f.h"
#include "System/Sync/HsiehHash.h"

CR_BIND_DERIVED(CHoverAirMoveType, AAirMoveType, (nullptr))

CR_REG_METADATA(CHoverAirMoveType, (
	CR_MEMBER(flyState),
	CR_MEMBER(bankingAllowed),
	CR_MEMBER(airStrafe),
	CR_MEMBER(wantToStop),

	CR_MEMBER(goalDistance),

	CR_MEMBER(currentBank),
	CR_MEMBER(currentPitch),

	CR_MEMBER(turnRate),
	CR_MEMBER(maxDrift),
	CR_MEMBER(maxTurnAngle),

	CR_MEMBER(wantedSpeed),
	CR_MEMBER(deltaSpeed),

	CR_MEMBER(circlingPos),
	CR_MEMBER(randomWind),

	CR_MEMBER(forceHeading),
	CR_MEMBER(dontLand),

	CR_MEMBER(wantedHeading),
	CR_MEMBER(forceHeadingTo),

	CR_MEMBER(waitCounter),
	CR_MEMBER(lastMoveRate)
))



static bool IsUnitBusy(const CUnit* u) {
	// queued move-commands (or active build/repair/etc-commands) mean unit has to stay airborne
	const auto& cai = u->commandAI;
	return (cai->inCommand || cai->HasMoreMoveCommands(false));
}

CHoverAirMoveType::CHoverAirMoveType(CUnit* owner) :
	AAirMoveType(owner),
	flyState(FLY_CRUISING),

	bankingAllowed(true),
	airStrafe(owner != nullptr ? owner->unitDef->airStrafe : false),
	wantToStop(false),

	goalDistance(1),

	// we want to take off in direction of factory facing
	currentBank(0),
	currentPitch(0),

	turnRate(1),
	maxDrift(1.0f),
	maxTurnAngle(math::cos((owner != nullptr ? owner->unitDef->turnInPlaceAngleLimit : 0.0f) * (PI / 180.0f)) * -1.0f),

	wantedSpeed(ZeroVector),
	deltaSpeed(ZeroVector),
	circlingPos(ZeroVector),
	randomWind(ZeroVector),

	forceHeading(false),
	dontLand(false),

	wantedHeading(owner != nullptr ? GetHeadingFromFacing(owner->buildFacing) : 0),
	forceHeadingTo(wantedHeading),

	waitCounter(0),
	lastMoveRate(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CHoverAirMoveType::SetGoal(const float3& pos, float distance)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::SetState(AircraftState newState)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::SetAllowLanding(bool allowLanding)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::StartMoving(float3 pos, float goalRadius)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::StartMoving(float3 pos, float goalRadius, float speed)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::KeepPointingTo(float3 pos, float distance, bool aggressive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::ExecuteStop()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::StopMoving(bool callScript, bool hardStop)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CHoverAirMoveType::UpdateLanded()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::UpdateTakeoff()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// Move the unit around a bit..
void CHoverAirMoveType::UpdateHovering()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CHoverAirMoveType::UpdateFlying()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CHoverAirMoveType::UpdateLanding()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CHoverAirMoveType::UpdateHeading()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::UpdateBanking(bool noBanking)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CHoverAirMoveType::UpdateVerticalSpeed(const float4& spd, float curRelHeight, float curVertSpeed) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CHoverAirMoveType::UpdateAirPhysics()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CHoverAirMoveType::UpdateMoveRate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CHoverAirMoveType::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::SlowUpdate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// Returns true if indicated position is a suitable landing spot
bool CHoverAirMoveType::CanLandAt(const float3& pos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::ForceHeading(short h)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::Takeoff()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CHoverAirMoveType::Land()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CHoverAirMoveType::HandleCollisions(bool checkCollisions)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CHoverAirMoveType::SetMemberValue(unsigned int memberHash, void* memberValue) {
	// try the generic members first
	if (AMoveType::SetMemberValue(memberHash, memberValue))
		return true;

	#define MEMBER_CHARPTR_HASH(memberName) HsiehHash(memberName, strlen(memberName),     0)
	#define MEMBER_LITERAL_HASH(memberName) HsiehHash(memberName, sizeof(memberName) - 1, 0)

	#define     DONTLAND_MEMBER_IDX 1
	#define WANTEDHEIGHT_MEMBER_IDX 0

	static const unsigned int boolMemberHashes[] = {
		MEMBER_LITERAL_HASH(       "collide"),
		MEMBER_LITERAL_HASH(      "dontLand"),
		MEMBER_LITERAL_HASH(     "airStrafe"),
		MEMBER_LITERAL_HASH( "useSmoothMesh"),
		MEMBER_LITERAL_HASH("bankingAllowed"),
	};
	static const unsigned int floatMemberHashes[] = {
		MEMBER_LITERAL_HASH( "wantedHeight"),
		MEMBER_LITERAL_HASH(      "accRate"),
		MEMBER_LITERAL_HASH(      "decRate"),
		MEMBER_LITERAL_HASH(     "turnRate"),
		MEMBER_LITERAL_HASH( "altitudeRate"),
		MEMBER_LITERAL_HASH(  "currentBank"),
		MEMBER_LITERAL_HASH( "currentPitch"),
		MEMBER_LITERAL_HASH(     "maxDrift"),
	};

	#undef MEMBER_CHARPTR_HASH
	#undef MEMBER_LITERAL_HASH


	// unordered_map etc. perform dynallocs, so KISS here
	bool* boolMemberPtrs[] = {
		&collide,
		&dontLand,
		&airStrafe,

		&useSmoothMesh,
		&bankingAllowed
	};
	float* floatMemberPtrs[] = {
		&wantedHeight,

		&accRate,
		&decRate,

		&turnRate,
		&altitudeRate,

		&currentBank,
		&currentPitch,

		&maxDrift
	};

	// special cases
	if (memberHash == boolMemberHashes[DONTLAND_MEMBER_IDX]) {
		SetAllowLanding(!(*(reinterpret_cast<bool*>(memberValue))));
		return true;
	}
	if (memberHash == floatMemberHashes[WANTEDHEIGHT_MEMBER_IDX]) {
		SetDefaultAltitude(*(reinterpret_cast<float*>(memberValue)));
		return true;
	}

	// note: <memberHash> should be calculated via HsiehHash
	for (unsigned int n = 0; n < sizeof(boolMemberPtrs) / sizeof(boolMemberPtrs[0]); n++) {
		if (memberHash == boolMemberHashes[n]) {
			*(boolMemberPtrs[n]) = *(reinterpret_cast<bool*>(memberValue));
			return true;
		}
	}

	for (unsigned int n = 0; n < sizeof(floatMemberPtrs) / sizeof(floatMemberPtrs[0]); n++) {
		if (memberHash == floatMemberHashes[n]) {
			*(floatMemberPtrs[n]) = *(reinterpret_cast<float*>(memberValue));
			return true;
		}
	}

	return false;
}

