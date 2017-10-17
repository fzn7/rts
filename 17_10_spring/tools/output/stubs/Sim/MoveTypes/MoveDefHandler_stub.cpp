#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MoveDefHandler.h"
#include "Lua/LuaParser.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "MoveMath/MoveMath.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/CRC.h"
#include "System/Exceptions.h"
#include "System/Util.h"
#include "System/creg/STL_Deque.h"
#include "System/creg/STL_Map.h"
#include "System/myMath.h"

CR_BIND(MoveDef, ())
CR_BIND(MoveDefHandler, (NULL))

CR_REG_METADATA(MoveDef,
                (CR_MEMBER(name),

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
                 CR_MEMBER(heatProduced)))

CR_REG_METADATA(MoveDefHandler,
                (CR_MEMBER(moveDefs),
                 CR_MEMBER(moveDefNames),
                 CR_MEMBER(checksum)))

MoveDefHandler* moveDefHandler;

// FIXME: do something with these magic numbers
static const float MAX_ALLOWED_WATER_DAMAGE_GMM = 1e3f;
static const float MAX_ALLOWED_WATER_DAMAGE_HMM = 1e4f;

static float
DegreesToMaxSlope(float degrees)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static MoveDef::SpeedModClass
ParseSpeedModClass(const std::string& moveDefName, const LuaTable& moveDefTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

MoveDefHandler::MoveDefHandler(LuaParser* defsParser)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

MoveDef*
MoveDefHandler::GetMoveDefByName(const std::string& name)
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

MoveDef::MoveDef(const LuaTable& moveDefTable, int moveDefID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
MoveDef::TestMoveSquare(const CSolidObject* collider,
                        const int xTestMoveSqr,
                        const int zTestMoveSqr,
                        const float3 testMoveDir,
                        bool testTerrain,
                        bool testObjects,
                        bool centerOnly,
                        float* minSpeedModPtr,
                        int* maxBlockBitPtr) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
MoveDef::TestMoveSquare(const CSolidObject* collider,
                        const float3 testMovePos,
                        const float3 testMoveDir,
                        bool testTerrain,
                        bool testObjects,
                        bool centerOnly,
                        float* minSpeedMod,
                        int* maxBlockBit) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
MoveDef::GetDepthMod(const float height) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int
MoveDef::GetCheckSum() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
