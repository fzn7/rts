#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FlyingPiece.h"

#include "Game/GlobalUnsynced.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Models/3DModel.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Rendering/UnitDrawer.h"
#include "System/myMath.h"

static const float EXPLOSION_SPEED = 2.f;

/////////////////////////////////////////////////////////////////////
/// NEW S3O,OBJ,ASSIMP,... IMPLEMENTATION
///

FlyingPiece::FlyingPiece(const S3DModelPiece* _piece,
                         const CMatrix44f& _pieceMatrix,
                         const float3 pos,
                         const float3 speed,
                         const float2 _pieceParams, // (.x=radius, .y=chance)
                         const int2 _renderParams   // (.x=texType, .y=team)
                         )
  : pos0(pos)
  , pieceMatrix(_pieceMatrix)
  , age(0)
  , piece(_piece)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FlyingPiece::InitCommon(const float3 _pos,
                        const float3 _speed,
                        const float _radius,
                        int _team,
                        int _texture)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
FlyingPiece::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
FlyingPiece::GetDragFactors() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CMatrix44f
FlyingPiece::GetMatrixOf(const SplitterData& cp, const float3 dragFactors) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FlyingPiece::CheckDrawStateChange(const FlyingPiece* prev) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FlyingPiece::EndDraw() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
FlyingPiece::Draw(const FlyingPiece* prev) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
