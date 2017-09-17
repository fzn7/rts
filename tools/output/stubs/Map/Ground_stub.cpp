/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "Ground.h"
#include "ReadMap.h"
#include "System/myMath.h"

#include <cassert>
#include <limits>

#undef far // avoid collision with windef.h
#undef near

static inline float InterpolateHeight(float x, float z, const float* heightmap)
{
    //stub method
}


static inline float LineGroundSquareCol(
	const float* heightmap,
	const float3* normalmap,
	const float3& from,
	const float3& to,
	const int xs,
	const int ys)
{
    //stub method
}



/*
void CGround::CheckColSquare(CProjectile* p, int x, int y)
{
    //stub method
}
*/

inline static bool ClampInMapHeight(float3& from, float3& to)
{
    //stub method
}


float CGround::LineGroundCol(float3 from, float3 to, bool synced)
{
    //stub method
}

float CGround::LineGroundCol(const float3 pos, const float3 dir, float len, bool synced)
{
    //stub method
}


float CGround::LinePlaneCol(const float3 pos, const float3 dir, float len, float hgt)
{
    //stub method
}


float CGround::GetApproximateHeight(float x, float z, bool synced)
{
    //stub method
}


float CGround::GetApproximateHeightUnsafe(int x, int z, bool synced)
{
    //stub method
}


float CGround::GetHeightAboveWater(float x, float z, bool synced)
{
    //stub method
}

float CGround::GetHeightReal(float x, float z, bool synced)
{
    //stub method
}

float CGround::GetOrigHeight(float x, float z)
{
    //stub method
}


const float3& CGround::GetNormal(float x, float z, bool synced)
{
    //stub method
}

const float3& CGround::GetNormalAboveWater(float x, float z, bool synced)
{
    //stub method
}


float CGround::GetSlope(float x, float z, bool synced)
{
    //stub method
}


float3 CGround::GetSmoothNormal(float x, float z, bool synced)
{
    //stub method
}

float CGround::TrajectoryGroundCol(float3 from, const float3& flatdir, float length, float linear, float quadratic)
{
    //stub method
}


int CGround::GetSquare(const float3& pos) {
	const int x = Clamp((int(pos.x) / SQUARE_SIZE), 0, mapDims.mapxm1);
	const int z = Clamp((int(pos.z) / SQUARE_SIZE), 0, mapDims.mapym1);

	return (x + z * mapDims.mapx);
};

