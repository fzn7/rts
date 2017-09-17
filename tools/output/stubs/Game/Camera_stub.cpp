#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string.h>

#include "Camera.h"
#include "UI/MouseHandler.h"
#include "Map/ReadMap.h"
#include "System/myMath.h"
#include "System/float3.h"
#include "System/Matrix44f.h"
#include "Rendering/GlobalRendering.h"
#include "System/Config/ConfigHandler.h"


CONFIG(float, EdgeMoveWidth)
	.defaultValue(0.02f)
	.minimumValue(0.0f)
	.description("The width (in percent of screen size) of the EdgeMove scrolling area.");
CONFIG(bool, EdgeMoveDynamic)
	.defaultValue(true)
	.description("If EdgeMove scrolling speed should fade with edge distance.");


CCamera* CCamera::camTypes[CCamera::CAMTYPE_COUNT] = {nullptr};


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCamera::CCamera(unsigned int cameraType)
	: pos(ZeroVector)
	, rot(ZeroVector)
	, forward(RgtVector)
	, up(UpVector)
	, fov(0.0f)
	, halfFov(0.0f)
	, tanHalfFov(0.0f)
	, lppScale(0.0f)
	, frustumScales(0.0f, 0.0f, CGlobalRendering::NEAR_PLANE, CGlobalRendering::MAX_VIEW_RANGE)
	, posOffset(ZeroVector)
	, tiltOffset(ZeroVector)

	, camType(cameraType)
	, projType((cameraType == CAMTYPE_SHADOW)? PROJTYPE_ORTHO: PROJTYPE_PERSP)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::CopyState(const CCamera* cam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::CopyStateReflect(const CCamera* cam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::Update(bool updateDirs, bool updateMats, bool updatePort)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::UpdateFrustum()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::UpdateMatrices(unsigned int vsx, unsigned int vsy, float var)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::UpdateViewPort(int px, int py, int sx, int sy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::UpdateLoadViewPort(int px, int py, int sx, int sy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CCamera::LoadMatrices() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::LoadViewPort() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CCamera::UpdateViewRange()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




static inline bool AABBInOriginPlane(
	const float3& camPos,
	const float3& mins,
	const float3& maxs,
	const float3& normal,
	const float offset
) {
	float3 fp; // far point
	fp.x = (normal.x > 0.0f) ? mins.x : maxs.x;
	fp.y = (normal.y > 0.0f) ? mins.y : maxs.y;
	fp.z = (normal.z > 0.0f) ? mins.z : maxs.z;
	return (normal.dot(fp - camPos) < offset);
}


bool CCamera::InView(const float3& mins, const float3& maxs) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CCamera::InView(const float3& p, float radius) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CCamera::SetVFOV(const float angle)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float CCamera::GetHFOV() const {
	const float hAspect = (viewport[2] * 1.0f) / viewport[3];
	const float fovFact = math::tan(fov * 0.5f) * hAspect;
	return (2.0f * math::atan(fovFact) * (180.0f / PI));
}



float3 CCamera::GetRotFromDir(float3 fwd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 CCamera::GetFwdFromRot(const float3 r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3 CCamera::GetRgtFromRot(const float3 r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CCamera::UpdateDirsFromRot(const float3 r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CCamera::SetDir(const float3 dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



float3 CCamera::CalcPixelDir(int x, int y) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


float3 CCamera::CalcWindowCoordinates(const float3& objPos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




inline void CCamera::gluPerspectiveSpring(float aspect, float zn, float zf) {
	const float t = zn * tanHalfFov;
	const float b = -t;
	const float l = b * aspect;
	const float r = t * aspect;

	glFrustumSpring(l, r,  b, t,  zn, zf);
}

inline void CCamera::glFrustumSpring(
	const float l,
	const float r,
	const float b,
	const float t,
	const float zn,
	const float zf
) {
	projectionMatrix[ 0] = (2.0f * zn) / (r - l);
	projectionMatrix[ 1] =  0.0f;
	projectionMatrix[ 2] =  0.0f;
	projectionMatrix[ 3] =  0.0f;

	projectionMatrix[ 4] =  0.0f;
	projectionMatrix[ 5] = (2.0f * zn) / (t - b);
	projectionMatrix[ 6] =  0.0f;
	projectionMatrix[ 7] =  0.0f;

	projectionMatrix[ 8] = (r + l) / (r - l);
	projectionMatrix[ 9] = (t + b) / (t - b);
	projectionMatrix[10] = -(zf + zn) / (zf - zn);
	projectionMatrix[11] = -1.0f;

	projectionMatrix[12] =   0.0f;
	projectionMatrix[13] =   0.0f;
	projectionMatrix[14] = -(2.0f * zf * zn) / (zf - zn);
	projectionMatrix[15] =   0.0f;
}

// same as glOrtho(-1, 1, -1, 1, zn, zf) plus glScalef(sx, sy, 1)
inline void CCamera::glOrthoScaledSpring(
	const float sx,
	const float sy,
	const float zn,
	const float zf
) {
	const float l = -1.0f * sx;
	const float r =  1.0f * sx;
	const float b = -1.0f * sy;
	const float t =  1.0f * sy;

	glOrthoSpring(l, r,  b, t,  zn, zf);
}

inline void CCamera::glOrthoSpring(
	const float l,
	const float r,
	const float b,
	const float t,
	const float zn,
	const float zf
) {
	const float tx = -(( r +  l) / ( r -  l));
	const float ty = -(( t +  b) / ( t -  b));
	const float tz = -((zf + zn) / (zf - zn));

	projectionMatrix[ 0] =  2.0f / (r - l);
	projectionMatrix[ 1] =  0.0f;
	projectionMatrix[ 2] =  0.0f;
	projectionMatrix[ 3] =  0.0f;

	projectionMatrix[ 4] =  0.0f;
	projectionMatrix[ 5] =  2.0f / (t - b);
	projectionMatrix[ 6] =  0.0f;
	projectionMatrix[ 7] =  0.0f;

	projectionMatrix[ 8] =  0.0f;
	projectionMatrix[ 9] =  0.0f;
	projectionMatrix[10] = -2.0f / (zf - zn);
	projectionMatrix[11] =  0.0f;

	projectionMatrix[12] = tx;
	projectionMatrix[13] = ty;
	projectionMatrix[14] = tz;
	projectionMatrix[15] = 1.0f;
}

inline void CCamera::gluLookAtSpring(const float3& eye, const float3& center, const float3& up)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




void CCamera::GetFrustumSides(float miny, float maxy, float scale, bool negOnly) {

	frustumLines[FRUSTUM_SIDE_POS].clear();
	frustumLines[FRUSTUM_SIDE_NEG].clear();

	// only non-zero for orthographic cameras
	const float3 posOffsets[FRUSTUM_PLANE_FRN] = {
		-right * frustumScales.x,
		 right * frustumScales.x,
		    up * frustumScales.y,
		   -up * frustumScales.y,
	};

	// note: order does not matter
	for (unsigned int i = 0; i < FRUSTUM_PLANE_FRN; i++) {
		GetFrustumSide(frustumPlanes[i], posOffsets[i],  miny, maxy, scale, negOnly? FRUSTUM_SIDE_NEG: FRUSTUM_SIDE_POS);
	}
}

void CCamera::GetFrustumSide(
	const float3& normal,
	const float3& offset,
	float miny,
	float maxy,
	float scale,
	unsigned int side
) {
	// compose an orthonormal axis-system around <normal>
	float3 xdir = (normal.cross(UpVector)).UnsafeANormalize();
	float3 ydir = (normal.cross(xdir)).UnsafeANormalize();

	// intersection of vector from <pos> along <ydir> with xz-plane
	float3 pInt;

	// prevent DIV0 when calculating line.dir
	if (math::fabs(xdir.z) < 0.001f)
		xdir.z = 0.001f;

	if (ydir.y != 0.0f) {
		// if normal is angled toward the sky instead of the ground,
		// subtract <miny> from the camera's y-position, else <maxy>
		if (normal.y > 0.0f) {
			pInt = (pos + offset) - ydir * (((pos.y + offset.y) - miny) / ydir.y);
		} else {
			pInt = (pos + offset) - ydir * (((pos.y + offset.y) - maxy) / ydir.y);
		}
	}

	// <line.dir> is the direction coefficient (0 ==> parallel to z-axis, inf ==> parallel to x-axis)
	// in the xz-plane; <line.base> is the x-coordinate at which line intersects x-axis; <line.sign>
	// indicates line direction, ie. left-to-right (whenever <xdir.z> is negative) or right-to-left
	// NOTE:
	//   (b.x / b.z) is actually the reciprocal of the DC (ie. the number of steps along +x for
	//   one step along +y); the world z-axis is inverted wrt. a regular Carthesian grid, so the
	//   DC is also inverted
	FrustumLine line;
	line.dir  = (xdir.x / xdir.z);
	line.base = (pInt.x - (pInt.z * line.dir)) / scale;
	line.sign = Sign(int(xdir.z <= 0.0f));
	line.minz = (                      0.0f) - (mapDims.mapy);
	line.maxz = (mapDims.mapy * SQUARE_SIZE) + (mapDims.mapy);

	// store all lines in [NEG] (regardless of actual sign) if wanted by caller
	frustumLines[line.sign == 1 || side == FRUSTUM_SIDE_NEG].push_back(line);
}

void CCamera::ClipFrustumLines(bool neg, const float zmin, const float zmax) {

	std::vector<FrustumLine>& lines = frustumLines[neg];
	std::vector<FrustumLine>::iterator fli, fli2;

	for (fli = lines.begin(); fli != lines.end(); ++fli) {
		for (fli2 = lines.begin(); fli2 != lines.end(); ++fli2) {
			if (fli == fli2)
				continue;

			const float dbase = fli->base - fli2->base;
			const float ddir = fli->dir - fli2->dir;

			if (ddir == 0.0f)
				continue;

			const float colz = -(dbase / ddir);

			if ((fli2->sign * ddir) > 0.0f) {
				if ((colz > fli->minz) && (colz < zmax))
					fli->minz = colz;
			} else {
				if ((colz < fli->maxz) && (colz > zmin))
					fli->maxz = colz;
			}
		}
	}
}


float3 CCamera::GetMoveVectorFromState(bool fromKeyState) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

