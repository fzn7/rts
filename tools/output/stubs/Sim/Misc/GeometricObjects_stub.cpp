/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "System/creg/STL_Map.h"
#include "GeometricObjects.h"
#include "Map/ReadMap.h"
#include "Sim/Projectiles/ProjectileHandler.h"
#include "Rendering/Env/Particles/Classes/GeoSquareProjectile.h"

CR_BIND(CGeometricObjects, )
CR_BIND(CGeometricObjects::GeoGroup, )

CR_REG_METADATA(CGeometricObjects, (
	CR_MEMBER(geoGroups),
	CR_MEMBER(toBeDeleted),
	CR_MEMBER(firstFreeGroup)
))

CR_REG_METADATA_SUB(CGeometricObjects, GeoGroup, (CR_MEMBER(squares)))


CGeometricObjects* geometricObjects;

CGeometricObjects::CGeometricObjects()
	: firstFreeGroup(1)
{
    //stub method
}


CGeometricObjects::~CGeometricObjects()
{
    //stub method
}

int CGeometricObjects::AddSpline(float3 b1, float3 b2, float3 b3, float3 b4, float width, int arrow, int lifeTime, int group)
{
    //stub method
}


void CGeometricObjects::DeleteGroup(int group)
{
    //stub method
}


void CGeometricObjects::SetColor(int group, float r, float g, float b, float a)
{
    //stub method
}


float3 CGeometricObjects::CalcSpline(float i, const float3& p1, const float3& p2, const float3& p3, const float3& p4)
{
    //stub method
}


int CGeometricObjects::AddLine(float3 start, float3 end, float width, int arrow, int lifetime, int group)
{
    //stub method
}


void CGeometricObjects::Update()
{
    //stub method
}


void CGeometricObjects::MarkSquare(int mapSquare) {

	float3 startPos;
	startPos.x = (int) (mapSquare * SQUARE_SIZE) % mapDims.mapx;
	startPos.z = (int) (mapSquare * SQUARE_SIZE) / mapDims.mapx;
	startPos.y = readMap->GetCenterHeightMapSynced()[mapSquare];

	float3 endPos = startPos;
	endPos.x += SQUARE_SIZE;
	endPos.z += SQUARE_SIZE;

	AddLine(startPos, endPos, 3, 0, 1000);

	startPos.x += SQUARE_SIZE;
	endPos.x -= SQUARE_SIZE;
	AddLine(startPos, endPos, 3, 0, 1000);
}

