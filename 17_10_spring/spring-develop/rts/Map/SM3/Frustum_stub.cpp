#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Frustum.h"

#include "Rendering/GL/myGL.h"
#undef far // avoid collision with windef.h

void
Frustum::InversePlanes()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

// find the box vertices to compare against the plane
static void
BoxPlaneVerts(const Vector3& min,
              const Vector3& max,
              const Vector3& plane,
              Vector3& close,
              Vector3& far)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Frustum::CalcCameraPlanes(Vector3* cbase,
                          Vector3* cright,
                          Vector3* cup,
                          Vector3* cfront,
                          float tanHalfFov,
                          float aspect)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
Frustum::Draw()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Frustum::VisType
Frustum::IsBoxVisible(const Vector3& min, const Vector3& max)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

Frustum::VisType
Frustum::IsPointVisible(const Vector3& pt)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
