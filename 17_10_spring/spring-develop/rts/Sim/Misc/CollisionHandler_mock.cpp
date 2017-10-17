// TODO: Substitue CCollisionHandler with your actual class name
int CCollisionHandler::b0(){}
int CCollisionHandler::b1(){}
float CCollisionHandler::t0(){}
float CCollisionHandler::t1(){}
float3 CCollisionHandler::p0(){}
float3 CCollisionHandler::p1(){}
q(const).LocalModelPiece CCollisionHandler::lmp(){}
void CCollisionHandler::PrintStats(){}
bool CCollisionHandler::DetectHit(const CSolidObject * o, const CMatrix44f & m, const float3 p0, const float3 p1, CollisionQuery * cq, bool forceTrace){}
bool CCollisionHandler::DetectHit(const CSolidObject * o, const CMatrix44f & m, const float3 p0, const float3 p1, CollisionQuery * cq){}
bool CCollisionHandler::DetectHit(const CSolidObject * o, const CMatrix44f & m, const float3 p0, const float3 p1){}
bool CCollisionHandler::DetectHit(const CSolidObject * o, const CollisionVolume * v, const CMatrix44f & m, const float3 p0, const float3 p1, CollisionQuery * cq, bool forceTrace){}
bool CCollisionHandler::DetectHit(const CSolidObject * o, const CollisionVolume * v, const CMatrix44f & m, const float3 p0, const float3 p1, CollisionQuery * cq){}
bool CCollisionHandler::DetectHit(const CSolidObject * o, const CollisionVolume * v, const CMatrix44f & m, const float3 p0, const float3 p1){}
bool CCollisionHandler::MouseHit(const CSolidObject * o, const CMatrix44f & m, const float3 & p0, const float3 & p1, const CollisionVolume * v, CollisionQuery * cq){}
bool CCollisionHandler::MouseHit(const CSolidObject * o, const CMatrix44f & m, const float3 & p0, const float3 & p1, const CollisionVolume * v){}
bool CCollisionHandler::Collision(const CSolidObject * o, const CollisionVolume * v, const CMatrix44f & m, const float3 p, CollisionQuery * cq){}
bool CCollisionHandler::Intersect(const CSolidObject * o, const CollisionVolume * v, const CMatrix44f & m, const float3 p0, const float3 p1, CollisionQuery * cq, float s){}
bool CCollisionHandler::Intersect(const CSolidObject * o, const CollisionVolume * v, const CMatrix44f & m, const float3 p0, const float3 p1, CollisionQuery * cq){}
bool CCollisionHandler::Collision(const CollisionVolume * v, const CMatrix44f & m, const float3 & p){}
bool CCollisionHandler::CollisionFootPrint(const CSolidObject * o, const float3 & p){}
bool CCollisionHandler::Intersect(const CollisionVolume * v, const CMatrix44f & m, const float3 & p0, const float3 & p1, CollisionQuery * cq){}
bool CCollisionHandler::IntersectPieceTree(const CSolidObject * o, const CMatrix44f & m, const float3 & p0, const float3 & p1, CollisionQuery * cq){}
bool CCollisionHandler::IntersectPiecesHelper(const CSolidObject * o, const CMatrix44f & m, const float3 & p0, const float3 & p1, CollisionQuery * cqp){}
bool CCollisionHandler::IntersectEllipsoid(const CollisionVolume * v, const float3 & pi0, const float3 & pi1, CollisionQuery * cq){}
bool CCollisionHandler::IntersectCylinder(const CollisionVolume * v, const float3 & pi0, const float3 & pi1, CollisionQuery * cq){}
bool CCollisionHandler::IntersectBox(const CollisionVolume * v, const float3 & pi0, const float3 & pi1, CollisionQuery * cq){}
unsigned int CCollisionHandler::numDiscTests(){}
unsigned int CCollisionHandler::numContTests(){}
