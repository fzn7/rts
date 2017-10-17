#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CollisionHandler.h"
#include "CollisionVolume.h"
#include "Map/ReadMap.h" // mapDims
#include "Rendering/Models/3DModel.h"
#include "Sim/Misc/GlobalConstants.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "System/FastMath.h"
#include "System/Log/ILog.h"
#include "System/Matrix44f.h"

unsigned int CCollisionHandler::numDiscTests = 0;
unsigned int CCollisionHandler::numContTests = 0;

void
CCollisionHandler::PrintStats()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::DetectHit(const CSolidObject* o,
                             const CMatrix44f& m,
                             const float3 p0,
                             const float3 p1,
                             CollisionQuery* cq,
                             bool forceTrace)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::DetectHit(const CSolidObject* o,
                             const CollisionVolume* v, // can be a foreign CV
                             const CMatrix44f& m,
                             const float3 p0,
                             const float3 p1,
                             CollisionQuery* cq,
                             bool forceTrace)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::Collision(const CSolidObject* o,
                             const CollisionVolume* v,
                             const CMatrix44f& m,
                             const float3 p,
                             CollisionQuery* cq)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::CollisionFootPrint(const CSolidObject* o, const float3& p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::Collision(const CollisionVolume* v,
                             const CMatrix44f& m,
                             const float3& p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::MouseHit(const CSolidObject* o,
                            const CMatrix44f& m,
                            const float3& p0,
                            const float3& p1,
                            const CollisionVolume* v,
                            CollisionQuery* cq)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
bool CCollisionHandler::IntersectPieceTreeHelper(
        LocalModelPiece* lmp,
        const CMatrix44f& mat,
        const float3& p0,
        const float3& p1,
        std::vector<CollisionQuery>* cqs
) {
        bool ret = false;

        CollisionVolume* lmpVol = lmp->GetCollisionVolume();
        CMatrix44f volMat = lmp->GetModelSpaceMatrix() * mat;

        if (lmp->scriptSetVisible && !lmpVol->IgnoreHits()) {
                volMat.Translate(lmpVol->GetOffsets());

                CollisionQuery cq;

                if ((ret = CCollisionHandler::Intersect(lmpVol, volMat, p0, p1,
&cq))) { cq.SetHitPiece(lmp); cqs->push_back(cq);
                }

                volMat.Translate(-lmpVol->GetOffsets());
        }

        for (unsigned int i = 0; i < lmp->children.size(); i++) {
                ret |= IntersectPieceTreeHelper(lmp->children[i], mat, p0, p1,
cqs);
        }

        return ret;
}
*/

bool
CCollisionHandler::IntersectPiecesHelper(const CSolidObject* o,
                                         const CMatrix44f& m,
                                         const float3& p0,
                                         const float3& p1,
                                         CollisionQuery* cq)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::IntersectPieceTree(const CSolidObject* o,
                                      const CMatrix44f& m,
                                      const float3& p0,
                                      const float3& p1,
                                      CollisionQuery* cq)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline bool
CCollisionHandler::Intersect(const CSolidObject* o,
                             const CollisionVolume* v,
                             const CMatrix44f& m,
                             const float3 p0,
                             const float3 p1,
                             CollisionQuery* cq,
                             float s)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::Intersect(const CollisionVolume* v,
                             const CMatrix44f& m,
                             const float3& p0,
                             const float3& p1,
                             CollisionQuery* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::IntersectEllipsoid(const CollisionVolume* v,
                                      const float3& pi0,
                                      const float3& pi1,
                                      CollisionQuery* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::IntersectCylinder(const CollisionVolume* v,
                                     const float3& pi0,
                                     const float3& pi1,
                                     CollisionQuery* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCollisionHandler::IntersectBox(const CollisionVolume* v,
                                const float3& pi0,
                                const float3& pi1,
                                CollisionQuery* q)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
