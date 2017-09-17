#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MoveMath.h"

#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/MoveTypes/MoveDefHandler.h"
#include "Sim/Objects/SolidObject.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/CommandAI/CommandAI.h"

bool CMoveMath::noHoverWaterMove = false;
float CMoveMath::waterDamageCost = 0.0f;



float CMoveMath::yLevel(const MoveDef& moveDef, int xSqr, int zSqr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float CMoveMath::yLevel(const MoveDef& moveDef, const float3& pos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/* calculate the local speed-modifier for this MoveDef */
float CMoveMath::GetPosSpeedMod(const MoveDef& moveDef, unsigned xSquare, unsigned zSquare)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float CMoveMath::GetPosSpeedMod(const MoveDef& moveDef, unsigned xSquare, unsigned zSquare, float3 moveDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* Check if a given square-position is accessable by the MoveDef footprint. */
CMoveMath::BlockType CMoveMath::IsBlockedNoSpeedModCheck(const MoveDef& moveDef, int xSquare, int zSquare, const CSolidObject* collider)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CMoveMath::CrushResistant(const MoveDef& colliderMD, const CSolidObject* collidee)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CMoveMath::IsNonBlocking(const MoveDef& colliderMD, const CSolidObject* collidee, const CSolidObject* collider)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CMoveMath::IsNonBlocking(const CSolidObject* collidee, const CSolidObject* collider)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMoveMath::BlockType CMoveMath::ObjectBlockType(const MoveDef& moveDef, const CSolidObject* collidee, const CSolidObject* collider)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMoveMath::BlockType CMoveMath::SquareIsBlocked(const MoveDef& moveDef, int xSquare, int zSquare, const CSolidObject* collider)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMoveMath::BlockType CMoveMath::RangeIsBlocked(const MoveDef& moveDef, int xmin, int xmax, int zmin, int zmax, const CSolidObject* collider)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

