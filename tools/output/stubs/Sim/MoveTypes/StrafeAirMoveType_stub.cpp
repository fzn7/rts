/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "StrafeAirMoveType.h"
#include "Game/Players/Player.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/GeometricObjects.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/ModInfo.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Misc/SmoothHeightMesh.h"
#include "Rendering/Env/Particles/Classes/SmokeProjectile.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/CommandAI/CommandAI.h"
#include "Sim/Weapons/Weapon.h"
#include "System/myMath.h"
#include "System/Sync/HsiehHash.h"

CR_BIND_DERIVED(CStrafeAirMoveType, AAirMoveType, (nullptr))

CR_REG_METADATA(CStrafeAirMoveType, (
	CR_MEMBER(maneuverState),
	CR_MEMBER(maneuverSubState),

	CR_MEMBER(loopbackAttack),
	CR_MEMBER(isFighter),

	CR_MEMBER(wingDrag),
	CR_MEMBER(wingAngle),
	CR_MEMBER(invDrag),
	CR_MEMBER(crashDrag),
	CR_MEMBER(frontToSpeed),
	CR_MEMBER(speedToFront),
	CR_MEMBER(myGravity),

	CR_MEMBER(maxBank),
	CR_MEMBER(maxPitch),
	CR_MEMBER(turnRadius),

	CR_MEMBER(maxAileron),
	CR_MEMBER(maxElevator),
	CR_MEMBER(maxRudder),
	CR_MEMBER(attackSafetyDistance),

	CR_MEMBER(crashAileron),
	CR_MEMBER(crashElevator),
	CR_MEMBER(crashRudder),

	CR_MEMBER(lastRudderPos),
	CR_MEMBER(lastElevatorPos),
	CR_MEMBER(lastAileronPos)
))



static float TurnRadius(const float rawRadius, const float rawSpeed) {
	return (std::min(1000.0f, rawRadius * rawSpeed));
}

static float GetAileronDeflection(
	const CUnit* owner,
	const CUnit* collidee,
	const float3& pos,
	const float4& spd,
	const SyncedFloat3& rightdir,
	const SyncedFloat3& updir,
	const SyncedFloat3& frontdir,
	const float3& goalDir,
	float groundHeight,
	float wantedHeight,
	float maxAileron,
	float maxBank,
	float goalDotRight,
	float aGoalDotFront,
	bool avoidCollision,
	bool attacking
) {
	float aileron = 0.0f;

	if (attacking) {
		const float maxAileronSpeedf = maxAileron * spd.w;
		const float maxAileronSpeedf2 = maxAileronSpeedf * 4.0f;
		const float minPredictedHeight = pos.y + spd.y * 60.0f * math::fabs(frontdir.y) + std::min(0.0f, updir.y * 1.0f) * (GAME_SPEED * 5);
		const float maxPredictedHeight = groundHeight + 60.0f + math::fabs(rightdir.y) * (GAME_SPEED * 5);

		if (spd.w > 0.45f && minPredictedHeight > maxPredictedHeight) {
			const float goalBankDif = goalDotRight + rightdir.y * 0.2f;

			if (goalBankDif > maxAileronSpeedf2) {
				aileron = 1.0f;
			} else if (goalBankDif < -maxAileronSpeedf2) {
				aileron = -1.0f;
			} else if (maxAileronSpeedf2 > 0.0f) {
				aileron = goalBankDif / maxAileronSpeedf2;
			}
		} else {
			if (rightdir.y > 0.0f) {
				if (rightdir.y > maxAileronSpeedf || frontdir.y < -0.7f) {
					aileron = 1.0f;
				} else {
					if (maxAileronSpeedf > 0.0f) {
						aileron = rightdir.y / maxAileronSpeedf;
					}
				}
			} else {
				if (rightdir.y < -maxAileronSpeedf || frontdir.y < -0.7f) {
					aileron = -1.0f;
				} else {
					if (maxAileronSpeedf > 0.0f) {
						aileron = rightdir.y / maxAileronSpeedf;
					}
				}
			}
		}
	} else {
		if (spd.w > 1.5f && ((pos.y + spd.y * 10.0f) > (groundHeight + wantedHeight * 0.6f))) {
			const float goalBankDif = goalDotRight + rightdir.y * 0.5f;
			const float maxAileronSpeedf = maxAileron * spd.w * 4.0f;

			if (goalBankDif > maxAileronSpeedf && rightdir.y > -maxBank) {
				aileron = 1.0f;
			} else if (goalBankDif < -maxAileronSpeedf && rightdir.y < maxBank) {
				aileron = -1.0f;
			} else {
				if (math::fabs(rightdir.y) < maxBank && maxAileronSpeedf > 0.0f) {
					aileron = goalBankDif / maxAileronSpeedf;
				} else {
					if (rightdir.y < 0.0f && goalBankDif < 0.0f) {
						aileron = -1.0f;
					} else if (rightdir.y > 0.0f && goalBankDif > 0.0f) {
						aileron = 1.0f;
					}
				}
			}
		} else {
			if (rightdir.y > 0.01f) {
				aileron = 1.0f;
			} else if (rightdir.y < -0.01f) {
				aileron = -1.0f;
			}
		}
	}

	return aileron;
}

static float GetRudderDeflection(
	const CUnit* owner,
	const CUnit* collidee,
	const float3& pos,
	const float4& spd,
	const SyncedFloat3& rightdir,
	const SyncedFloat3& updir,
	const SyncedFloat3& frontdir,
	const float3& goalDir,
	float groundHeight,
	float wantedHeight,
	float maxRudder,
	float,
	float goalDotRight,
	float aGoalDotFront,
	bool avoidCollision,
	bool attacking
) {
	float rudder = 0.0f;

	if (attacking) {
		if (pos.y > (groundHeight + 30.0f)) {
			const float maxRudderSpeedf = maxRudder * spd.w;

			if (goalDotRight < -maxRudderSpeedf) {
				rudder = -1.0f;
			} else if (goalDotRight > maxRudderSpeedf) {
				rudder = 1.0f;
			} else {
				if (maxRudderSpeedf > 0.0f) {
					rudder = goalDotRight / maxRudderSpeedf;

					if (math::fabs(rudder) < 0.01f && aGoalDotFront < 0.0f) {
						// target almost straight behind us, we have to choose a direction
						rudder = (goalDotRight < 0.0f) ? -0.01f : 0.01f;
					}
				}
			}
		}
	} else {
		if (pos.y > (groundHeight + 15.0f)) {
			const float maxRudderSpeedf = maxRudder * spd.w * 2.0f;

			if (goalDotRight < -maxRudderSpeedf) {
				rudder = -1.0f;
			} else if (goalDotRight > maxRudderSpeedf) {
				rudder = 1.0f;
			} else {
				if (maxRudderSpeedf > 0.0f) {
					rudder = goalDotRight / maxRudderSpeedf;

					if (math::fabs(rudder) < 0.01f && aGoalDotFront < 0.0f) {
						// target almost straight behind us, we have to choose a direction
						rudder = (goalDotRight < 0.0f) ? -0.01f : 0.01f;
					}
				} else {
					rudder = 0.0f;
				}
			}
		}
	}

	return rudder;
}

static float GetElevatorDeflection(
	const CUnit* owner,
	const CUnit* collidee,
	const float3& pos,
	const float4& spd,
	const SyncedFloat3& rightdir,
	const SyncedFloat3& updir,
	const SyncedFloat3& frontdir,
	const float3& goalDir,
	float groundHeight,
	float wantedHeight,
	float maxElevator,
	float maxPitch,
	float goalDotRight,
	float aGoalDotFront,
	bool avoidCollision,
	bool attacking
) {
	float elevator = 0.0f;
	float upside = (updir.y >= -0.3f) * 2.0f - 1.0f;

	if (attacking) {
		if (spd.w < 1.5f) {
			if (frontdir.y < 0.0f) {
				elevator = upside;
			} else if (frontdir.y > 0.0f) {
				elevator = -upside;
			}
		} else {
			const float gHeightR = CGround::GetHeightAboveWater(pos.x + spd.x * 40.0f, pos.z + spd.z * 40.0f);
			const float hdif = std::max(gHeightR, groundHeight) + 60 - pos.y - frontdir.y * spd.w * 20.0f;

			const float maxElevatorSpeedf = maxElevator * spd.w;
			const float maxElevatorSpeedf2 = maxElevatorSpeedf * spd.w * 20.0f;

			float minPitch = 1.0f; // min(1.0f, hdif / (maxElevator * spd.w * spd.w * 20));

			if (hdif < -maxElevatorSpeedf2) {
				minPitch = -1.0f;
			} else if (hdif > maxElevatorSpeedf2) {
				minPitch = 1.0f;
			} else if (maxElevatorSpeedf2 > 0.0f) {
				minPitch = hdif / maxElevatorSpeedf2;
			}

			if (collidee != NULL && avoidCollision && frontdir.dot(collidee->pos + collidee->speed * 20.0f - pos - spd * 20.0f) < 0.0f) {
				elevator = (updir.dot(collidee->midPos - owner->midPos) > 0.0f)? -1 : 1;
			} else {
				const float hdif = goalDir.dot(updir);

				if (hdif < -maxElevatorSpeedf) {
					elevator = -1.0f;
				} else if (hdif > maxElevatorSpeedf) {
					elevator = 1.0f;
				} else if (maxElevatorSpeedf > 0.0f) {
					elevator = hdif / maxElevatorSpeedf;
				}
			}

			if ((elevator * upside) < minPitch) {
				elevator = minPitch * upside;
			}
		}
	} else {
		if (spd.w > 0.8f) {
			bool notColliding = true;

			if (avoidCollision) {
				const float3 dir = collidee->midPos - owner->midPos;
				const float3 sdir = collidee->speed - spd;

				if (frontdir.dot(dir + sdir * 20) < 0) {
					elevator = updir.dot(dir) > 0 ? -1 : 1;
					notColliding = false;
				}
			}

			if (notColliding) {
				const float maxElevatorSpeedf = maxElevator * 20.0f * spd.w * spd.w;
				const float gHeightAW = CGround::GetHeightAboveWater(pos.x + spd.x * 40.0f, pos.z + spd.z * 40.0f);
				const float hdif = std::max(groundHeight, gHeightAW) + wantedHeight - pos.y - frontdir.y * spd.w * 20.0f;

				if (hdif < -maxElevatorSpeedf && frontdir.y > -maxPitch) {
					elevator = -1.0f;
				} else if (hdif > maxElevatorSpeedf && frontdir.y < maxPitch) {
					elevator = 1.0f;
				} else if (maxElevatorSpeedf > 0.0f) {
					if (math::fabs(frontdir.y) < maxPitch) {
						elevator = hdif / maxElevatorSpeedf;
					}
				}
			}
		} else {
			if (frontdir.y < -0.1f) {
				elevator = 1.0f;
			} else if (frontdir.y > 0.15f) {
				elevator = -1.0f;
			}
		}
	}

	return elevator;
}

static int SelectLoopBackManeuver(
	const SyncedFloat3& frontdir,
	const SyncedFloat3& rightdir,
	const float4& spd,
	float turnRadius,
	float groundDist
) {
	// do not start looping if already banked
	if (math::fabs(rightdir.y) > 0.05f)
		return CStrafeAirMoveType::MANEUVER_FLY_STRAIGHT;

	if (groundDist > TurnRadius(turnRadius, spd.w)) {
		if (math::fabs(frontdir.y) <= 0.2f && gs->randFloat() > 0.3f) {
			return CStrafeAirMoveType::MANEUVER_IMMELMAN_INV;
		}
	} else {
		if (frontdir.y > -0.2f && gs->randFloat() > 0.7f) {
			return CStrafeAirMoveType::MANEUVER_IMMELMAN;
		}
	}

	return CStrafeAirMoveType::MANEUVER_FLY_STRAIGHT;
}



CStrafeAirMoveType::CStrafeAirMoveType(CUnit* owner):
	AAirMoveType(owner),
	maneuverState(MANEUVER_FLY_STRAIGHT),
	maneuverSubState(0),
	loopbackAttack(false),
	isFighter(false),
	wingDrag(0.07f),
	wingAngle(0.1f),
	invDrag(0.995f),
	crashDrag(0.995f),
	frontToSpeed(0.04f),
	speedToFront(0.01f),
	myGravity(0.8f),
	maxBank(0.55f),
	maxPitch(0.35f),
	turnRadius(150),
	maxAileron(0.04f),
	maxElevator(0.02f),
	maxRudder(0.01f)
{
    //stub method
}



bool CStrafeAirMoveType::Update()
{
    //stub method
}




bool CStrafeAirMoveType::HandleCollisions(bool checkCollisions) {
	const float3& pos = owner->pos;

#ifdef DEBUG_AIRCRAFT
	if (lastColWarningType == 1) {
		const int g = geometricObjects->AddLine(pos, lastColWarning->pos, 10, 1, 1);
		geometricObjects->SetColor(g, 0.2f, 1, 0.2f, 0.6f);
	} else if (lastColWarningType == 2) {
		const int g = geometricObjects->AddLine(pos, lastColWarning->pos, 10, 1, 1);
		if (owner->frontdir.dot(lastColWarning->midPos + lastColWarning->speed * 20.0f - owner->midPos - spd * 20.0f) < 0) {
			geometricObjects->SetColor(g, 1, 0.2f, 0.2f, 0.6f);
		} else {
			geometricObjects->SetColor(g, 1, 1, 0.2f, 0.6f);
		}
	}
#endif

	if (pos != oldPos) {
		oldPos = pos;

		bool hitBuilding = false;

		// check for collisions if not being built or not taking off
		if (checkCollisions) {
			// copy on purpose, since the below can call Lua
			const std::vector<CUnit*> nearUnits = quadField->GetUnitsExact(pos, owner->radius + 6);

			for (CUnit* unit: nearUnits) {
				const bool unloadingUnit = (unit->unloadingTransportId == owner->id);
				const bool unloadingOwner = (owner->unloadingTransportId == unit->id);

				if (unloadingUnit)
					unit->unloadingTransportId = -1;

				if (unloadingOwner)
					owner->unloadingTransportId = -1;

				if (unit->id == owner->loadingTransportId || owner->id == unit->loadingTransportId ||
				    unit == owner->transporter || unit->transporter != NULL) {
					continue;
				}

				const float sqDist = (pos - unit->pos).SqLength();
				const float totRad = owner->radius + unit->radius;

				if (sqDist <= 0.1f || sqDist >= (totRad * totRad))
					continue;


				if (unloadingUnit) {
					unit->unloadingTransportId = owner->id;
					continue;
				}

				if (unloadingOwner) {
					owner->unloadingTransportId = unit->id;
					continue;
				}


				const float dist = math::sqrt(sqDist);
				const float3 dif = (pos - unit->pos).Normalize();

				if (unit->immobile) {
					const float damage = ((unit->speed - owner->speed) * 0.1f).SqLength();

					owner->Move(-dif * (dist - totRad), true);
					owner->SetVelocity(owner->speed * 0.99f);

					if (modInfo.allowUnitCollisionDamage) {
						owner->DoDamage(DamageArray(damage), ZeroVector, NULL, -CSolidObject::DAMAGE_COLLISION_OBJECT, -1);
						unit->DoDamage(DamageArray(damage), ZeroVector, NULL, -CSolidObject::DAMAGE_COLLISION_OBJECT, -1);
					}

					hitBuilding = true;
				} else {
					const float part = owner->mass / (owner->mass + unit->mass);
					const float damage = ((unit->speed - owner->speed) * 0.1f).SqLength();

					owner->Move(-dif * (dist - totRad) * (1 - part), true);
					owner->SetVelocity(owner->speed * 0.99f);

					if (!unit->UsingScriptMoveType()) {
						unit->Move(dif * (dist - totRad) * (part), true);
					}

					if (modInfo.allowUnitCollisionDamage) {
						owner->DoDamage(DamageArray(damage), ZeroVector, NULL, -CSolidObject::DAMAGE_COLLISION_OBJECT, -1);
						unit->DoDamage(DamageArray(damage), ZeroVector, NULL, -CSolidObject::DAMAGE_COLLISION_OBJECT, -1);
					}
				}
			}

			// update speed.w
			owner->SetSpeed(owner->speed);
		}

		if (hitBuilding && owner->IsCrashing()) {
			// if crashing and we hit a building, die right now
			// rather than waiting until we are close enough to
			// the ground
			owner->KillUnit(NULL, true, false);
			return true;
		}

		if (pos.x < 0.0f) {
			owner->Move( RgtVector * 1.5f, true);
		} else if (pos.x > float3::maxxpos) {
			owner->Move(-RgtVector * 1.5f, true);
		}

		if (pos.z < 0.0f) {
			owner->Move( FwdVector * 1.5f, true);
		} else if (pos.z > float3::maxzpos) {
			owner->Move(-FwdVector * 1.5f, true);
		}

		return true;
	}

	return false;
}



void CStrafeAirMoveType::SlowUpdate()
{
    //stub method
}



void CStrafeAirMoveType::UpdateManeuver()
{
    //stub method
}



void CStrafeAirMoveType::UpdateAttack()
{
    //stub method
}



bool CStrafeAirMoveType::UpdateFlying(float wantedHeight, float engine)
{
    //stub method
}


static float GetVTOLAccelerationSign(float h, float wh, float speedy, bool ascending) {
	const float nxtHeight = h + speedy * 20.0f;
	const float tgtHeight = wh * 1.02f;

	if (ascending) {
		return ((nxtHeight < tgtHeight)?  1.0f: -1.0f);
	} else {
		return ((nxtHeight > tgtHeight)? -1.0f:  1.0f);
	}
}

void CStrafeAirMoveType::UpdateTakeOff()
{
    //stub method
}


void CStrafeAirMoveType::UpdateLanding()
{
    //stub method
}



void CStrafeAirMoveType::UpdateAirPhysics(float rudder, float aileron, float elevator, float engine, const float3& engineThrustVector)
{
    //stub method
}



void CStrafeAirMoveType::SetState(AAirMoveType::AircraftState newState)
{
    //stub method
}



float3 CStrafeAirMoveType::FindLandingPos()
{
    //stub method
}


float CStrafeAirMoveType::BrakingDistance(float speed, float rate) const
{
    //stub method
}


void CStrafeAirMoveType::SetMaxSpeed(float speed)
{
    //stub method
}



void CStrafeAirMoveType::StartMoving(float3 gpos, float goalRadius)
{
    //stub method
}

void CStrafeAirMoveType::StartMoving(float3 pos, float goalRadius, float speed)
{
    //stub method
}

void CStrafeAirMoveType::StopMoving(bool callScript, bool hardStop)
{
    //stub method
}



void CStrafeAirMoveType::Takeoff()
{
    //stub method
}



bool CStrafeAirMoveType::SetMemberValue(unsigned int memberHash, void* memberValue) {
	// try the generic members first
	if (AMoveType::SetMemberValue(memberHash, memberValue))
		return true;

	#define MEMBER_CHARPTR_HASH(memberName) HsiehHash(memberName, strlen(memberName),     0)
	#define MEMBER_LITERAL_HASH(memberName) HsiehHash(memberName, sizeof(memberName) - 1, 0)

	#define WANTEDHEIGHT_MEMBER_IDX 0

	static const unsigned int boolMemberHashes[] = {
		MEMBER_LITERAL_HASH(       "collide"),
		MEMBER_LITERAL_HASH( "useSmoothMesh"),
		MEMBER_LITERAL_HASH("loopbackAttack"),
	};
	static const unsigned int floatMemberHashes[] = {
		MEMBER_LITERAL_HASH(        "wantedHeight"),
		MEMBER_LITERAL_HASH(          "turnRadius"),
		MEMBER_LITERAL_HASH(             "accRate"),
		MEMBER_LITERAL_HASH(             "decRate"),
		MEMBER_LITERAL_HASH(              "maxAcc"), // synonym for accRate
		MEMBER_LITERAL_HASH(              "maxDec"), // synonym for decRate
		MEMBER_LITERAL_HASH(             "maxBank"),
		MEMBER_LITERAL_HASH(            "maxPitch"),
		MEMBER_LITERAL_HASH(          "maxAileron"),
		MEMBER_LITERAL_HASH(         "maxElevator"),
		MEMBER_LITERAL_HASH(           "maxRudder"),
		MEMBER_LITERAL_HASH("attackSafetyDistance"),
		MEMBER_LITERAL_HASH(           "myGravity"),
	};

	#undef MEMBER_CHARPTR_HASH
	#undef MEMBER_LITERAL_HASH


	// unordered_map etc. perform dynallocs, so KISS here
	bool* boolMemberPtrs[] = {
		&collide,
		&useSmoothMesh,
		&loopbackAttack,
	};
	float* floatMemberPtrs[] = {
		&wantedHeight,
		&turnRadius,

		&accRate, // hash("accRate") case
		&decRate, // hash("decRate") case
		&accRate, // hash( "maxAcc") case
		&decRate, // hash( "maxDec") case

		&maxBank,
		&maxPitch,

		&maxAileron,
		&maxElevator,
		&maxRudder,
		&attackSafetyDistance,

		&myGravity,
	};

	// special cases
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

