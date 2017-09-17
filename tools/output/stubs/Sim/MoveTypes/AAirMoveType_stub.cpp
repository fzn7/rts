#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AAirMoveType.h"
#include "MoveMath/MoveMath.h"

#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Units/Scripts/UnitScript.h"

CR_BIND_DERIVED_INTERFACE(AAirMoveType, AMoveType)

CR_REG_METADATA(AAirMoveType, (
	CR_MEMBER(aircraftState),

	CR_MEMBER(oldGoalPos),
	CR_MEMBER(reservedLandingPos),

	CR_MEMBER(landRadiusSq),
	CR_MEMBER(wantedHeight),
	CR_MEMBER(orgWantedHeight),

	CR_MEMBER(accRate),
	CR_MEMBER(decRate),
	CR_MEMBER(altitudeRate),

	CR_MEMBER(collide),
	CR_MEMBER(useSmoothMesh),
	CR_MEMBER(autoLand),

	CR_MEMBER(lastColWarning),

	CR_MEMBER(lastColWarningType)
))

AAirMoveType::AAirMoveType(CUnit* unit):
	AMoveType(unit),
	aircraftState(AIRCRAFT_LANDED),

	reservedLandingPos(-1.0f, -1.0f, -1.0f),

	landRadiusSq(0.0f),
	wantedHeight(80.0f),
	orgWantedHeight(0.0f),

	accRate(1.0f),
	decRate(1.0f),
	altitudeRate(3.0f),

	collide(true),
	useSmoothMesh(false),
	autoLand(true),

	lastColWarning(nullptr),

	lastColWarningType(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

AAirMoveType::~AAirMoveType()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AAirMoveType::DependentDied(CObject* o) {
	if (o == lastColWarning) {
		lastColWarning = NULL;
		lastColWarningType = 0;
	}
}

bool AAirMoveType::Update() {
	// NOTE: useHeading is never true by default for aircraft (AAirMoveType
	// forces it to false, TransportUnit::{Attach,Detach}Unit manipulate it
	// specifically for HoverAirMoveType's)
	if (useHeading) {
		SetState(AIRCRAFT_TAKEOFF);
	}

	// this return value is never used
	return (useHeading = false);
}

void AAirMoveType::UpdateLanded()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AAirMoveType::LandAt(float3 pos, float distanceSq)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void AAirMoveType::UpdateLandingHeight()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void AAirMoveType::UpdateLanding()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AAirMoveType::SetWantedAltitude(float altitude)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void AAirMoveType::SetDefaultAltitude(float altitude)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void AAirMoveType::CheckForCollision()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
