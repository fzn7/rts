#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "glExtra.h"
#include "Map/Ground.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/ThreadPool.h"
#include "VertexArray.h"

/**
 *  Draws a trigonometric circle in 'resolution' steps.
 */
static void
defSurfaceCircle(const float3& center, float radius, unsigned int res)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
defSurfaceSquare(const float3& center, float xsize, float zsize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

SurfaceCircleFunc glSurfaceCircle = defSurfaceCircle;
SurfaceSquareFunc glSurfaceSquare = defSurfaceSquare;

void
setSurfaceCircleFunc(SurfaceCircleFunc func)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
setSurfaceSquareFunc(SurfaceSquareFunc func)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
 *  Draws a trigonometric circle in 'resolution' steps, with a slope modifier
 */
void
glBallisticCircle(const float3& center,
                  const float radius,
                  const CWeapon* weapon,
                  unsigned int resolution,
                  float slope)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
glDrawVolume(DrawVolumeFunc drawFunc, const void* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/

void
glWireCube(unsigned int* listID)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
glWireCylinder(unsigned int* listID, unsigned int numDivs, float zSize)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
glWireSphere(unsigned int* listID, unsigned int numRows, unsigned int numCols)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
