#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MoveDefHandler.h"
#include "Lua/LuaParser.h"
#include "Map/ReadMap.h"
#include "Map/MapInfo.h"
#include "MoveMath/MoveMath.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/creg/STL_Deque.h"
#include "System/creg/STL_Map.h"
#include "System/Exceptions.h"
#include "System/CRC.h"
#include "System/myMath.h"
#include "System/Util.h"

CR_BIND(MoveDef, ())
CR_BIND(MoveDefHandler, (NULL))

CR_REG_METADATA(MoveDef, (
	CR_MEMBER(name),

	CR_MEMBER(speedModClass),
	CR_MEMBER(terrainClass),

	CR_MEMBER(xsize),
	CR_MEMBER(xsizeh),
	CR_MEMBER(zsize),
	CR_MEMBER(zsizeh),
	CR_MEMBER(depth),
	CR_MEMBER(depthModParams),
	CR_MEMBER(maxSlope),
	CR_MEMBER(slopeMod),
	CR_MEMBER(crushStrength),
	CR_MEMBER(speedModMults),

	CR_MEMBER(pathType),
	CR_MEMBER(udRefCount),

	CR_MEMBER(followGround),
	CR_MEMBER(subMarine),

	CR_MEMBER(avoidMobilesOnPath),
	CR_MEMBER(allowTerrainCollisions),

	CR_MEMBER(heatMapping),
	CR_MEMBER(flowMapping),
	CR_MEMBER(heatMod),
	CR_MEMBER(flowMod),
	CR_MEMBER(heatProduced)
))

CR_REG_METADATA(MoveDefHandler, (
	CR_MEMBER(moveDefs),
	CR_MEMBER(moveDefNames),
	CR_MEMBER(checksum)
))


MoveDefHandler* moveDefHandler;

// FIXME: do something with these magic numbers
static const float MAX_ALLOWED_WATER_DAMAGE_GMM = 1e3f;
static const float MAX_ALLOWED_WATER_DAMAGE_HMM = 1e4f;

static float DegreesToMaxSlope(float degrees)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static MoveDef::SpeedModClass ParseSpeedModClass(const std::string& moveDefName, const LuaTable& moveDefTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



MoveDefHandler::MoveDefHandler(LuaParser* defsParser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


MoveDef* MoveDefHandler::GetMoveDefByName(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



MoveDef::MoveDef()
	: name("")

	, speedModClass(MoveDef::Tank)
	, terrainClass(MoveDef::Mixed)

	, xsize(0)
	, xsizeh(0)
	, zsize(0)
	, zsizeh(0)

	, depth(0.0f)
	, maxSlope(1.0f)
	, slopeMod(0.0f)

	, crushStrength(0.0f)

	, pathType(0)
	, udRefCount(0)

	, heatMod(0.05f)
	, flowMod(1.0f)

	, heatProduced(GAME_SPEED)

	, followGround(true)
	, subMarine(false)

	, avoidMobilesOnPath(true)
	, allowTerrainCollisions(true)

	, heatMapping(true)
	, flowMapping(true)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

MoveDef::MoveDef(const LuaTable& moveDefTable, int moveDefID) {
	*this = MoveDef();

	name          = StringToLower(moveDefTable.GetString("name", ""));
	pathType      = moveDefID - 1;
	crushStrength = moveDefTable.GetFloat("crushStrength", 10.0f);

	const LuaTable& depthModTable = moveDefTable.SubTable("depthModParams");
	const LuaTable& speedModMultsTable = moveDefTable.SubTable("speedModMults");

	const float minWaterDepth = moveDefTable.GetFloat("minWaterDepth", GetDefaultMinWaterDepth());
	const float maxWaterDepth = moveDefTable.GetFloat("maxWaterDepth", GetDefaultMaxWaterDepth());

	switch ((speedModClass = ParseSpeedModClass(name, moveDefTable))) {
		case MoveDef::Tank: {
			// fall-through
		}
		case MoveDef::KBot: {
			depthModParams[DEPTHMOD_MIN_HEIGHT] = std::max(0.00f, depthModTable.GetFloat("minHeight",                                        0.0f ));
			depthModParams[DEPTHMOD_MAX_HEIGHT] =         (       depthModTable.GetFloat("maxHeight",           std::numeric_limits<float>::max() ));
			depthModParams[DEPTHMOD_MAX_SCALE ] = std::max(0.01f, depthModTable.GetFloat("maxScale",            std::numeric_limits<float>::max() ));
			depthModParams[DEPTHMOD_QUA_COEFF ] = std::max(0.00f, depthModTable.GetFloat("quadraticCoeff",                                   0.0f ));
			depthModParams[DEPTHMOD_LIN_COEFF ] = std::max(0.00f, depthModTable.GetFloat("linearCoeff",    moveDefTable.GetFloat("depthMod", 0.1f)));
			depthModParams[DEPTHMOD_CON_COEFF ] = std::max(0.00f, depthModTable.GetFloat("constantCoeff",                                    1.0f ));

			// ensure [depthModMinHeight, depthModMaxHeight] is a valid range
			depthModParams[DEPTHMOD_MAX_HEIGHT] = std::max(depthModParams[DEPTHMOD_MIN_HEIGHT], depthModParams[DEPTHMOD_MAX_HEIGHT]);

			depth    = maxWaterDepth;
			maxSlope = DegreesToMaxSlope(moveDefTable.GetFloat("maxSlope", 60.0f));
		} break;

		case MoveDef::Hover: {
			depth    = maxWaterDepth;
			maxSlope = DegreesToMaxSlope(moveDefTable.GetFloat("maxSlope", 15.0f));
		} break;

		case MoveDef::Ship: {
			depth     = minWaterDepth;
			subMarine = moveDefTable.GetBool("subMarine", false);
		} break;
	}

	speedModMults[SPEEDMOD_MOBILE_BUSY_MULT] = std::max(0.01f, speedModMultsTable.GetFloat("mobileBusyMult", 1.0f /*0.10f*/));
	speedModMults[SPEEDMOD_MOBILE_IDLE_MULT] = std::max(0.01f, speedModMultsTable.GetFloat("mobileIdleMult", 1.0f /*0.35f*/));
	speedModMults[SPEEDMOD_MOBILE_MOVE_MULT] = std::max(0.01f, speedModMultsTable.GetFloat("mobileMoveMult", 1.0f /*0.65f*/));

	avoidMobilesOnPath = moveDefTable.GetBool("avoidMobilesOnPath", true);
	allowTerrainCollisions = moveDefTable.GetBool("allowTerrainCollisions", true);

	heatMapping = moveDefTable.GetBool("heatMapping", false);
	flowMapping = moveDefTable.GetBool("flowMapping", true);

	heatMod = moveDefTable.GetFloat("heatMod", (1.0f / (GAME_SPEED * 2)) * 0.25f);
	flowMod = moveDefTable.GetFloat("flowMod", 1.0f);

	// by default heat decays to zero after N=2 seconds
	//
	// the cost contribution to a square from heat must
	// be on the same order as its normal movement cost
	// PER FRAME, i.e. such that heatMod * heatProduced
	// ~= O(1 / (GAME_SPEED * N)) because unit behavior
	// in groups quickly becomes FUBAR if heatMod >>> 1
	//
	heatProduced = moveDefTable.GetInt("heatProduced", GAME_SPEED * 2);

	//  <maxSlope> ranges from 0.0 to 60 * 1.5 degrees, ie. from 0.0 to
	//  0.5 * PI radians, ie. from 1.0 - cos(0.0) to 1.0 - cos(0.5 * PI)
	//  = [0, 1] --> DEFAULT <slopeMod> values range from (4 / 0.001) to
	//  (4 / 1.001) = [4000.0, 3.996]
	//
	// speedMod values for a terrain-square slope in [0, 1] are given by
	// (1.0 / (1.0 + slope * slopeMod)) and therefore have a MAXIMUM at
	// <slope=0, slopeMod=...> and a MINIMUM at <slope=1, slopeMod=4000>
	// (of 1.0 / (1.0 + 0.0 * ...) = 1.0 and 1.0 / (1.0 + 1.0 * 4000.0)
	// = 0.00025 respectively)
	//
	slopeMod = moveDefTable.GetFloat("slopeMod", 4.0f / (maxSlope + 0.001f));

	// ground units hug the ocean floor when in water,
	// ships stay at a "fixed" level (their waterline)
	followGround = (speedModClass == MoveDef::Tank || speedModClass == MoveDef::KBot);

	// TODO:
	//   remove terrainClass, not used anywhere
	//   and only AI's MIGHT have benefit from it
	//
	// tank or bot that cannot get its threads / feet
	// wet, or hovercraft (which doesn't touch ground
	// or water)
	if ((followGround && maxWaterDepth <= 0.0f) || speedModClass == MoveDef::Hover)
		terrainClass = MoveDef::Land;
	// ship (or sub) that cannot crawl onto shore, OR tank
	// or bot restricted to snorkling (strange but possible)
	if ((speedModClass == MoveDef::Ship && minWaterDepth > 0.0f) || (followGround && minWaterDepth > 0.0f))
		terrainClass = MoveDef::Water;
	// tank or kbot that CAN go skinny-dipping (amph.),
	// or ship that CAN sprout legs when at the beach
	if ((followGround && maxWaterDepth > 0.0f) || (speedModClass == MoveDef::Ship && minWaterDepth < 0.0f))
		terrainClass = MoveDef::Mixed;

	const int xsizeDef = std::max(1, moveDefTable.GetInt("footprintX",        1));
	const int zsizeDef = std::max(1, moveDefTable.GetInt("footprintZ", xsizeDef));

	// make all mobile footprints point-symmetric in heightmap space
	// (meaning that only non-even dimensions are possible and each
	// footprint always has a unique center square)
	xsize = xsizeDef * SPRING_FOOTPRINT_SCALE;
	zsize = zsizeDef * SPRING_FOOTPRINT_SCALE;
	xsize -= ((xsize & 1)? 0: 1);
	zsize -= ((zsize & 1)? 0: 1);
	// precalculated data for MoveMath
	xsizeh = xsize >> 1;
	zsizeh = zsize >> 1;
	assert((xsize & 1) == 1);
	assert((zsize & 1) == 1);
}


bool MoveDef::TestMoveSquare(
	const CSolidObject* collider,
	const int xTestMoveSqr,
	const int zTestMoveSqr,
	const float3 testMoveDir,
	bool testTerrain,
	bool testObjects,
	bool centerOnly,
	float* minSpeedModPtr,
	int* maxBlockBitPtr
) const {
	bool retTestMove = true;

	assert(testTerrain || testObjects);

	float                minSpeedMod = std::numeric_limits<float>::max();;
	CMoveMath::BlockType maxBlockBit = CMoveMath::BLOCK_NONE;

	const int zMin = -zsizeh * (1 - centerOnly), zMax = zsizeh * (1 - centerOnly);
	const int xMin = -xsizeh * (1 - centerOnly), xMax = xsizeh * (1 - centerOnly);

	float3 testMoveDir2D = testMoveDir;
	testMoveDir2D.SafeNormalize2D();

	for (int z = zMin; (z <= zMax) && retTestMove; z++) {
		for (int x = xMin; (x <= xMax) && retTestMove; x++) {
			const float speedMod = CMoveMath::GetPosSpeedMod(*this, xTestMoveSqr + x, zTestMoveSqr + z, testMoveDir2D);

			minSpeedMod = std::min(minSpeedMod, speedMod);
			retTestMove &= (!testTerrain || (speedMod > 0.0f));
		}
	}

	// GetPosSpeedMod only checks *one* square of terrain
	// (heightmap/slopemap/typemap), not the blocking-map
	if (retTestMove) {
		const CMoveMath::BlockType blockBits = CMoveMath::RangeIsBlocked(*this, xTestMoveSqr + xMin, xTestMoveSqr + xMax, zTestMoveSqr + zMin, zTestMoveSqr + zMax, collider);
		maxBlockBit |= blockBits;
		retTestMove &= (!testObjects || (blockBits & CMoveMath::BLOCK_STRUCTURE) == 0);
	}

	// don't use std::min or |= because the values might be garbage
	if (minSpeedModPtr != nullptr) *minSpeedModPtr = minSpeedMod;
	if (maxBlockBitPtr != nullptr) *maxBlockBitPtr = maxBlockBit;
	return retTestMove;
}


bool MoveDef::TestMoveSquare(
	const CSolidObject* collider,
	const float3 testMovePos,
	const float3 testMoveDir,
	bool testTerrain,
	bool testObjects,
	bool centerOnly,
	float* minSpeedMod,
	int* maxBlockBit
) const {
	const int xTestMoveSqr = testMovePos.x / SQUARE_SIZE;
	const int zTestMoveSqr = testMovePos.z / SQUARE_SIZE;

	return (TestMoveSquare(collider, xTestMoveSqr, zTestMoveSqr, testMoveDir, testTerrain, testObjects, centerOnly, minSpeedMod, maxBlockBit));
}


float MoveDef::GetDepthMod(const float height) const {
	// [DEPTHMOD_{MIN, MAX}_HEIGHT] are always >= 0,
	// so we return early for positive height values
	// only negative heights ("depths") are allowed
	if (height > -depthModParams[DEPTHMOD_MIN_HEIGHT]) { return 1.0f; }
	if (height < -depthModParams[DEPTHMOD_MAX_HEIGHT]) { return 0.0f; }

	const float a = depthModParams[DEPTHMOD_QUA_COEFF];
	const float b = depthModParams[DEPTHMOD_LIN_COEFF];
	const float c = depthModParams[DEPTHMOD_CON_COEFF];

	const float minScale = 0.01f;
	const float maxScale = depthModParams[DEPTHMOD_MAX_SCALE];

	const float depth = -height;
	const float scale = Clamp((a * depth * depth + b * depth + c), minScale, maxScale);

	// NOTE:
	//   <maxScale> is guaranteed to be >= 0.01, so the
	//   depth-mod range is [1.0 / 0.01, 1.0 / +infinity]
	//
	//   if minScale <= scale <       1.0, speedup
	//   if      1.0 <  scale <= maxScale, slowdown
	return (1.0f / scale);
}

unsigned int MoveDef::GetCheckSum() const {
	unsigned int sum = 0;

	const unsigned char* minByte = reinterpret_cast<const unsigned char*>(&speedModClass);
	const unsigned char* maxByte = reinterpret_cast<const unsigned char*>(&flowMapping) + sizeof(flowMapping);

	assert(minByte < maxByte);

	// NOTE:
	//   safe so long as MoveDef has no virtuals and we
	//   make sure we do not checksum any padding bytes
	for (const unsigned char* byte = minByte; byte != maxByte; byte++) {
		sum ^= ((((byte + 1) - minByte) << 8) * (*byte));
	}

	return sum;
}

