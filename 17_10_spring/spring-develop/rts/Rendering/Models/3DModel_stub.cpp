#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "3DModel.h"

#include "3DOParser.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GL/myGL.h"
#include "S3OParser.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "System/Exceptions.h"
#include "System/Util.h"

#include <algorithm>
#include <cctype>

CR_BIND(LocalModelPiece, (NULL))
CR_REG_METADATA(LocalModelPiece,
                (CR_MEMBER(pos),
                 CR_MEMBER(rot),
                 CR_MEMBER(dir),
                 CR_MEMBER(colvol),
                 CR_MEMBER(scriptSetVisible),
                 CR_MEMBER(lmodelPieceIndex),
                 CR_MEMBER(scriptPieceIndex),
                 CR_MEMBER(parent),
                 CR_MEMBER(children),

                 // reload
                 CR_IGNORED(dispListID),
                 CR_IGNORED(original),

                 CR_IGNORED(dirty),
                 CR_IGNORED(modelSpaceMat),
                 CR_IGNORED(pieceSpaceMat),

                 CR_IGNORED(lodDispLists) // FIXME GL idx!
                 ))

CR_BIND(LocalModel, )
CR_REG_METADATA(LocalModel,
                (CR_IGNORED(lodCount), // FIXME?
                 CR_MEMBER(pieces),

                 CR_IGNORED(boundingVolume),
                 CR_IGNORED(luaMaterialData)))

/**
 * ****************************************************************************************************
 * S3DModel
 */
void
S3DModel::DeletePieces(S3DModelPiece* piece)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * ****************************************************************************************************
 * S3DModelPiece
 */

S3DModelPiece::S3DModelPiece()
  : parent(NULL)
  , axisMapType(AXIS_MAPPING_XYZ)
  , scales(OnesVector)
  , mins(DEF_MIN_SIZE)
  , maxs(DEF_MAX_SIZE)
  , rotAxisSigns(-OnesVector)
  , hasIdentityRot(true)
  , dispListID(0)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
S3DModelPiece::CreateDispList()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
S3DModelPiece::DrawStatic() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
S3DModelPiece::GetEmitPos() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

float3
S3DModelPiece::GetEmitDir() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
S3DModelPiece::CreateShatterPieces()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
S3DModelPiece::CreateShatterPiecesVariation(const int num)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
S3DModelPiece::Shatter(float pieceChance,
                       int modelType,
                       int texType,
                       int team,
                       const float3 pos,
                       const float3 speed,
                       const CMatrix44f& m) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * ****************************************************************************************************
 * LocalModel
 */

void
LocalModel::DrawPieces() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModel::DrawPiecesLOD(unsigned int lod) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModel::SetLODCount(unsigned int count)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModel::SetOriginalPieces(const S3DModelPiece* mp, int& idx)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModel::SetModel(const S3DModel* model, bool initialize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

LocalModelPiece*
LocalModel::CreateLocalModelPieces(const S3DModelPiece* mpParent)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModel::UpdateBoundingVolume()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * ****************************************************************************************************
 * LocalModelPiece
 */

LocalModelPiece::LocalModelPiece(const S3DModelPiece* piece)
  : colvol(piece->GetCollisionVolume())

  , dirty(true)

  , scriptSetVisible(piece->HasGeometryData())

  , lmodelPieceIndex(-1)
  , scriptPieceIndex(-1)

  , original(piece)
  , parent(NULL) // set later
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModelPiece::SetDirty()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModelPiece::UpdateMatrix() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModelPiece::UpdateMatricesRec(bool updateChildMatrices) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModelPiece::UpdateParentMatricesRec() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModelPiece::Draw() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModelPiece::DrawLOD(unsigned int lod) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
LocalModelPiece::SetLODCount(unsigned int count)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
LocalModelPiece::GetEmitDirPos(float3& emitPos, float3& emitDir) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
