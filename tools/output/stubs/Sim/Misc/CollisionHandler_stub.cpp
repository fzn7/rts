/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "CollisionHandler.h"
#include "CollisionVolume.h"
#include "Map/ReadMap.h" // mapDims
#include "Rendering/Models/3DModel.h"
#include "Sim/Misc/GroundBlockingObjectMap.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/FastMath.h"
#include "System/Matrix44f.h"
#include "System/Log/ILog.h"

unsigned int CCollisionHandler::numDiscTests = 0;
unsigned int CCollisionHandler::numContTests = 0;



void CCollisionHandler::PrintStats()
{
    //stub method
}



bool CCollisionHandler::DetectHit(
	const CSolidObject* o,
	const CMatrix44f& m,
	const float3 p0,
	const float3 p1,
	CollisionQuery* cq,
	bool forceTrace)
{
    //stub method
}

bool CCollisionHandler::DetectHit(
	const CSolidObject* o,
	const CollisionVolume* v, // can be a foreign CV
	const CMatrix44f& m,
	const float3 p0,
	const float3 p1,
	CollisionQuery* cq,
	bool forceTrace
) {
	bool hit = false;

	if (cq != nullptr)
		cq->Reset();

	if (o->IsInVoid())
		return hit;

	// test *only* for ray intersections with the piece tree
	// (whether or not the object's regular volume is disabled)
	//
	// overrides forceTrace, which itself overrides testType
	if (v->DefaultToPieceTree())
		return (CCollisionHandler::IntersectPieceTree(o, m, p0, p1, cq));
	if (v->IgnoreHits())
		return hit;

	if (forceTrace || v->UseContHitTest()) {
		hit = CCollisionHandler::Intersect(o, v, m, p0, p1, cq);
	} else {
		// Collision() does not need p1 (no ray, no ray-endpoint)
		hit = CCollisionHandler::Collision(o, v, m, p0,     cq);
	}

	return hit;
}



bool CCollisionHandler::Collision(
	const CSolidObject* o,
	const CollisionVolume* v,
	const CMatrix44f& m,
	const float3 p,
	CollisionQuery* cq
) {
	bool hit = false;

	// if <v> is a sphere, then the bounding radius is just its own radius -->
	// we do not need to test the COLVOL_TYPE_SPHERE case again when this fails
	if ((v->GetWorldSpacePos(o) - p).SqLength() > v->GetBoundingRadiusSq())
		return hit;

	if (v->DefaultToFootPrint()) {
		hit = CCollisionHandler::CollisionFootPrint(o, p);
	} else {
		hit = (v->GetVolumeType() == CollisionVolume::COLVOL_TYPE_SPHERE);

		if (!hit) {
			// transform into midpos-relative space
			CMatrix44f mr = m;
			mr.Translate(o->relMidPos * WORLD_TO_OBJECT_SPACE);
			mr.Translate(v->GetOffsets());

			hit = CCollisionHandler::Collision(v, mr, p);
		}
	}

	if (cq != nullptr && hit) {
		// same as the special cases for the continuous tests
		// (but here p is a valid coordinate and safe to use)
		cq->b0 = CQ_POINT_IN_VOL; cq->t0 = 0.0f; cq->p0 = p;
	}

	return hit;
}


bool CCollisionHandler::CollisionFootPrint(const CSolidObject* o, const float3& p)
{
    //stub method
}


bool CCollisionHandler::Collision(const CollisionVolume* v, const CMatrix44f& m, const float3& p)
{
    //stub method
}


bool CCollisionHandler::MouseHit(
	const CSolidObject* o,
	const CMatrix44f& m,
	const float3& p0,
	const float3& p1,
	const CollisionVolume* v,
	CollisionQuery* cq
) {
	if (cq != nullptr)
		cq->Reset();

	if (o->IsInVoid())
		return false;

	if (v->DefaultToPieceTree())
		return (CCollisionHandler::IntersectPieceTree(o, m, p0, p1, cq));
	if (v->IgnoreHits())
		return false;

	// note: should mouse-rays care about
	// IgnoreHits if object is not in void?
	return (CCollisionHandler::Intersect(v, m, p0, p1, cq));
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

		if ((ret = CCollisionHandler::Intersect(lmpVol, volMat, p0, p1, &cq))) {
			cq.SetHitPiece(lmp); cqs->push_back(cq);
		}

		volMat.Translate(-lmpVol->GetOffsets());
	}

	for (unsigned int i = 0; i < lmp->children.size(); i++) {
		ret |= IntersectPieceTreeHelper(lmp->children[i], mat, p0, p1, cqs);
	}

	return ret;
}
*/

bool CCollisionHandler::IntersectPiecesHelper(
	const CSolidObject* o,
	const CMatrix44f& m,
	const float3& p0,
	const float3& p1,
	CollisionQuery* cq
) {
	CMatrix44f volMat;

	float minDistSq = std::numeric_limits<float>::max();
	float curDistSq = minDistSq;

	for (unsigned int n = 0; n < o->localModel.pieces.size(); n++) {
		const LocalModelPiece* lmp = o->localModel.GetPiece(n);
		const CollisionVolume* lmpVol = lmp->GetCollisionVolume();

		if (!lmp->scriptSetVisible || lmpVol->IgnoreHits())
			continue;

		volMat = m * lmp->GetModelSpaceMatrix();
		volMat.Translate(lmpVol->GetOffsets());

		CollisionQuery cqn;
		if (!CCollisionHandler::Intersect(lmpVol, volMat, p0, p1, &cqn))
			continue;

		// skip if neither an ingress nor an egress hit
		if (!cqn.AnyHit())
			continue;

		// save the closest intersection (others are not needed)
		if ((curDistSq = (cqn.GetHitPos()).SqDistance(p0)) >= minDistSq)
			continue;

		minDistSq = curDistSq;

		// return early if caller only wants to know a collision exists
		if (cq == nullptr)
			return true;

		*cq = cqn;
		cq->SetHitPiece(lmp);
	}

	// true iff at least one piece was intersected
	// (query must have been reset by calling code)
	return (cq != nullptr && cq->GetHitPiece() != nullptr);
}


bool CCollisionHandler::IntersectPieceTree(
	const CSolidObject* o,
	const CMatrix44f& m,
	const float3& p0,
	const float3& p1,
	CollisionQuery* cq
) {
	const LocalModel& lm = o->localModel;
	const CollisionVolume* bv = lm.GetBoundingVolume();

	// defer to IntersectBox for the early-out test; align OOBB
	// to object's axes (unlike a regular CV this is positioned
	// relative to o->pos, so do NOT include the extra relMidPos
	// translation by scaling it to 0)
	if (!CCollisionHandler::Intersect(o, bv, m, p0, p1, cq, 0.0f))
		return false;

	return (IntersectPiecesHelper(o, m, p0, p1, cq));
}

inline bool CCollisionHandler::Intersect(
	const CSolidObject* o,
	const CollisionVolume* v,
	const CMatrix44f& m,
	const float3 p0,
	const float3 p1,
	CollisionQuery* cq,
	float s
) {
	// transform into midpos-relative space (where the CV
	// is positioned); we have to translate by relMidPos to
	// get to midPos because GetTransformMatrix() only uses
	// pos for all CSolidObject types
	//
	CMatrix44f mr = m;
	mr.Translate(o->relMidPos * WORLD_TO_OBJECT_SPACE * s);
	mr.Translate(v->GetOffsets());

	return (CCollisionHandler::Intersect(v, mr, p0, p1, cq));
}

bool CCollisionHandler::Intersect(const CollisionVolume* v, const CMatrix44f& m, const float3& p0, const float3& p1, CollisionQuery* q)
{
    //stub method
}

bool CCollisionHandler::IntersectEllipsoid(const CollisionVolume* v, const float3& pi0, const float3& pi1, CollisionQuery* q)
{
    //stub method
}

bool CCollisionHandler::IntersectCylinder(const CollisionVolume* v, const float3& pi0, const float3& pi1, CollisionQuery* q)
{
    //stub method
}

bool CCollisionHandler::IntersectBox(const CollisionVolume* v, const float3& pi0, const float3& pi1, CollisionQuery* q)
{
    //stub method
}

