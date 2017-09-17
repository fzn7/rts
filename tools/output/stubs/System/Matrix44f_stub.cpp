#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Matrix44f.h"
#include "System/myMath.h"

#include <algorithm>
#include <memory.h>

CR_BIND(CMatrix44f, )

CR_REG_METADATA(CMatrix44f, CR_MEMBER(m))

CMatrix44f::CMatrix44f()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f::CMatrix44f(const CMatrix44f& mat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f::CMatrix44f(const float3 pos,
                       const float3 x,
                       const float3 y,
                       const float3 z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f::CMatrix44f(const float rotX, const float rotY, const float rotZ)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f::CMatrix44f(const float3 p)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CMatrix44f::IsOrthoNormal() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CMatrix44f::IsIdentity() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::LoadIdentity()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::RotateX(float angle)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::RotateY(float angle)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::RotateZ(float angle)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::Rotate(float angle, const float3 axis)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::RotateEulerXYZ(const float3 angles)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::RotateEulerYXZ(const float3 angles)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::RotateEulerZXY(const float3 angles)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::RotateEulerZYX(const float3 angles)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// multiply M by the scale-matrix (SX, SY, SZ, ST)
//
//  [SX][SY][SZ][ST]
//  ----------------
//  [sx   0   0   0]
//  [ 0  sy   0   0]
//  [ 0   0  sz   0]
//  [ 0   0   0   1]
//
CMatrix44f&
CMatrix44f::Scale(const float3 scales)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::Translate(const float x, const float y, const float z)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
static inline void
MatrixMatrixMultiplySSE(const CMatrix44f& m1,
                        const CMatrix44f& m2,
                        CMatrix44f* mout)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f CMatrix44f::operator*(const CMatrix44f& m2) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::operator>>=(const CMatrix44f& m2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::operator<<=(const CMatrix44f& m2)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
float3 CMatrix44f::operator*(const float3 v) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

__FORCE_ALIGN_STACK__
float4 CMatrix44f::operator*(const float4 v) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMatrix44f::SetUpVector(const float3 up)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f&
CMatrix44f::Transpose()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//! note: assumes this matrix only
//! does translation and rotation
CMatrix44f&
CMatrix44f::InvertAffineInPlace()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMatrix44f
CMatrix44f::InvertAffine() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

template<typename T>
static inline T
CalculateCofactor(const T m[4][4], const int ei, const int ej)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//! generalized inverse for non-orthonormal 4x4 matrices
//! A^-1 = (1 / det(A)) (C^T)_{ij} = (1 / det(A)) C_{ji}
bool
CMatrix44f::InvertInPlace()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//! generalized inverse for non-orthonormal 4x4 matrices
//! A^-1 = (1 / det(A)) (C^T)_{ij} = (1 / det(A)) C_{ji}
CMatrix44f
CMatrix44f::Invert(bool* status) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// adapted from
// stackoverflow.com/questions/18433801/converting-a-3x3-matrix-to-euler-tait-bryan-angles-pitch-yaw-roll
//
// NOTE:
//   this assumes a RIGHT-handed coordinate system, but
//   in Spring all SolidObjects use LEFT-handed systems
//   instead
//
//   therefore (if called on an object's transform matrix)
//   the angles {a,b,c} returned here actually correspond
//   to values as though RotateEulerZYX(-a,-b,-c) had been
//   called, *NOT* RotateEulerXYZ(a,b,c) as in the case of
//   a right-handed matrix
//
//   however, since
//
//     1)           RotateEulerZYX(-a,-b,-c)  ==
//     Transpose(RotateEulerXYZ(a,b,c)) 2) Transpose(RotateEulerZYX(-a,-b,-c))
//     ==           RotateEulerXYZ(a,b,c)
//
//   we can easily convert them back to left-handed form
//
//   all angles are in radians and returned in PYR order
//
float3
CMatrix44f::GetEulerAnglesRgtHand(float eps) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float3
CMatrix44f::GetEulerAnglesLftHand(float eps) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
