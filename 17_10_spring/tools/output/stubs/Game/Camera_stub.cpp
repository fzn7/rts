#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <string.h>

#include "Camera.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "System/Config/ConfigHandler.h"
#include "System/Matrix44f.h"
#include "System/float3.h"
#include "System/myMath.h"
#include "UI/MouseHandler.h"

CONFIG(float, EdgeMoveWidth)
  .defaultValue(0.02f)
  .minimumValue(0.0f)
  .description(
    "The width (in percent of screen size) of the EdgeMove scrolling area.");
CONFIG(bool, EdgeMoveDynamic)
  .defaultValue(true)
  .description("If EdgeMove scrolling speed should fade with edge distance.");

CCamera* CCamera::camTypes[CCamera::CAMTYPE_COUNT] = { nullptr };

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
  , frustumScales(0.0f,
                  0.0f,
                  CGlobalRendering::NEAR_PLANE,
                  CGlobalRendering::MAX_VIEW_RANGE)
  , posOffset(ZeroVector)
  , tiltOffset(ZeroVector)

  , camType(cameraType)
  , projType((cameraType == CAMTYPE_SHADOW) ? PROJTYPE_ORTHO : PROJTYPE_PERSP)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::CopyState(const CCamera* cam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::CopyStateReflect(const CCamera* cam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::Update(bool updateDirs, bool updateMats, bool updatePort)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::UpdateFrustum()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::UpdateMatrices(unsigned int vsx, unsigned int vsy, float var)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::UpdateViewPort(int px, int py, int sx, int sy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::UpdateLoadViewPort(int px, int py, int sx, int sy)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::LoadMatrices() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::LoadViewPort() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::UpdateViewRange()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
AABBInOriginPlane(const float3& camPos,
                  const float3& mins,
                  const float3& maxs,
                  const float3& normal,
                  const float offset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCamera::InView(const float3& mins, const float3& maxs) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CCamera::InView(const float3& p, float radius) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::SetVFOV(const float angle)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float
CCamera::GetHFOV() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CCamera::GetRotFromDir(float3 fwd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CCamera::GetFwdFromRot(const float3 r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CCamera::GetRgtFromRot(const float3 r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::UpdateDirsFromRot(const float3 r)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::SetDir(const float3 dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CCamera::CalcPixelDir(int x, int y) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CCamera::CalcWindowCoordinates(const float3& objPos) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
CCamera::gluPerspectiveSpring(float aspect, float zn, float zf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
CCamera::glFrustumSpring(const float l,
                         const float r,
                         const float b,
                         const float t,
                         const float zn,
                         const float zf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// same as glOrtho(-1, 1, -1, 1, zn, zf) plus glScalef(sx, sy, 1)
inline void
CCamera::glOrthoScaledSpring(const float sx,
                             const float sy,
                             const float zn,
                             const float zf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
CCamera::glOrthoSpring(const float l,
                       const float r,
                       const float b,
                       const float t,
                       const float zn,
                       const float zf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

inline void
CCamera::gluLookAtSpring(const float3& eye,
                         const float3& center,
                         const float3& up)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::GetFrustumSides(float miny, float maxy, float scale, bool negOnly)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::GetFrustumSide(const float3& normal,
                        const float3& offset,
                        float miny,
                        float maxy,
                        float scale,
                        unsigned int side)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCamera::ClipFrustumLines(bool neg, const float zmin, const float zmax)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CCamera::GetMoveVectorFromState(bool fromKeyState) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
