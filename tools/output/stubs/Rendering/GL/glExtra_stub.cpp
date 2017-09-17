#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "glExtra.h"
#include "VertexArray.h"
#include "Map/Ground.h"
#include "Sim/Weapons/Weapon.h"
#include "Sim/Weapons/WeaponDef.h"
#include "System/ThreadPool.h"

/**
 *  Draws a trigonometric circle in 'resolution' steps.
 */
static void defSurfaceCircle(const float3& center, float radius, unsigned int res)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void defSurfaceSquare(const float3& center, float xsize, float zsize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


SurfaceCircleFunc glSurfaceCircle = defSurfaceCircle;
SurfaceSquareFunc glSurfaceSquare = defSurfaceSquare;

void setSurfaceCircleFunc(SurfaceCircleFunc func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void setSurfaceSquareFunc(SurfaceSquareFunc func)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/*
 *  Draws a trigonometric circle in 'resolution' steps, with a slope modifier
 */
void glBallisticCircle(const float3& center, const float radius,
                       const CWeapon* weapon,
                       unsigned int resolution, float slope)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

void glDrawVolume(DrawVolumeFunc drawFunc, const void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/

void glWireCube(unsigned int* listID) {
	static const float3 vertices[8] = {
		float3( 0.5f,  0.5f,  0.5f),
		float3( 0.5f, -0.5f,  0.5f),
		float3(-0.5f, -0.5f,  0.5f),
		float3(-0.5f,  0.5f,  0.5f),

		float3( 0.5f,  0.5f, -0.5f),
		float3( 0.5f, -0.5f, -0.5f),
		float3(-0.5f, -0.5f, -0.5f),
		float3(-0.5f,  0.5f, -0.5f),
	};

	if ((*listID) != 0) {
		glCallList(*listID);
		return;
	}

	glNewList(((*listID) = glGenLists(1)), GL_COMPILE);
	glPushAttrib(GL_POLYGON_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_QUADS);
		glVertex3f(vertices[0].x, vertices[0].y, vertices[0].z);
		glVertex3f(vertices[1].x, vertices[1].y, vertices[1].z);
		glVertex3f(vertices[2].x, vertices[2].y, vertices[2].z);
		glVertex3f(vertices[3].x, vertices[3].y, vertices[3].z);

		glVertex3f(vertices[4].x, vertices[4].y, vertices[4].z);
		glVertex3f(vertices[5].x, vertices[5].y, vertices[5].z);
		glVertex3f(vertices[6].x, vertices[6].y, vertices[6].z);
		glVertex3f(vertices[7].x, vertices[7].y, vertices[7].z);
	glEnd();
	glBegin(GL_QUAD_STRIP);
		glVertex3f(vertices[4].x, vertices[4].y, vertices[4].z);
		glVertex3f(vertices[0].x, vertices[0].y, vertices[0].z);

		glVertex3f(vertices[5].x, vertices[5].y, vertices[5].z);
		glVertex3f(vertices[1].x, vertices[1].y, vertices[1].z);

		glVertex3f(vertices[6].x, vertices[6].y, vertices[6].z);
		glVertex3f(vertices[2].x, vertices[2].y, vertices[2].z);

		glVertex3f(vertices[7].x, vertices[7].y, vertices[7].z);
		glVertex3f(vertices[3].x, vertices[3].y, vertices[3].z);

		glVertex3f(vertices[4].x, vertices[4].y, vertices[4].z);
		glVertex3f(vertices[0].x, vertices[0].y, vertices[0].z);
	glEnd();

	glPopAttrib();
	glEndList();
}

void glWireCylinder(unsigned int* listID, unsigned int numDivs, float zSize) {
	if ((*listID) != 0) {
		glCallList(*listID);
		return;
	}

	assert(numDivs > 2);
	assert(zSize > 0.0f);

	std::vector<float3> vertices(numDivs * 2);

	glNewList(((*listID) = glGenLists(1)), GL_COMPILE);
	glPushAttrib(GL_POLYGON_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// front end-cap
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0f, 0.0f, 0.0f);

		for (unsigned int n = 0; n <= numDivs; n++) {
			const unsigned int i = n % numDivs;

			vertices[i].x = std::cos(i * ((PI + PI) / numDivs));
			vertices[i].y = std::sin(i * ((PI + PI) / numDivs));
			vertices[i].z = 0.0f;

			glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
		}
	glEnd();

	// back end-cap
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0f, 0.0f, zSize);

		for (unsigned int n = 0; n <= numDivs; n++) {
			const unsigned int i = n % numDivs;

			vertices[i + numDivs].x = vertices[i].x;
			vertices[i + numDivs].y = vertices[i].y;
			vertices[i + numDivs].z = zSize;

			glVertex3f(vertices[i + numDivs].x, vertices[i + numDivs].y, vertices[i + numDivs].z);
		}
	glEnd();

	glBegin(GL_QUAD_STRIP);
		for (unsigned int n = 0; n < numDivs; n++) {
			glVertex3f(vertices[n          ].x, vertices[n          ].y, vertices[n          ].z);
			glVertex3f(vertices[n + numDivs].x, vertices[n + numDivs].y, vertices[n + numDivs].z);
		}

		glVertex3f(vertices[0          ].x, vertices[0          ].y, vertices[0          ].z);
		glVertex3f(vertices[0 + numDivs].x, vertices[0 + numDivs].y, vertices[0 + numDivs].z);
	glEnd();

	glPopAttrib();
	glEndList();
}

void glWireSphere(unsigned int* listID, unsigned int numRows, unsigned int numCols) {
	if ((*listID) != 0) {
		glCallList(*listID);
		return;
	}

	assert(numRows > 2);
	assert(numCols > 2);

	std::vector<float3> vertices((numRows + 1) * numCols);

	for (unsigned int row = 0; row <= numRows; row++) {
		for (unsigned int col = 0; col < numCols; col++) {
			const float a = (col * ((PI + PI) / numCols));
			const float b = (row * ((PI     ) / numRows));

			float3& v = vertices[row * numCols + col];

			v.x = std::cos(a) * std::sin(b);
			v.y = std::sin(a) * std::sin(b);
			v.z = std::cos(b);
		}
	}

	glNewList(((*listID) = glGenLists(1)), GL_COMPILE);
	glPushAttrib(GL_POLYGON_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	const float3& v0 = vertices.front();
	const float3& v1 = vertices.back();

	// top slice
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(v0.x, v0.y, v0.z);

		for (unsigned int col = 0; col <= numCols; col++) {
			const unsigned int i = 1 * numCols + (col % numCols);
			const float3& v = vertices[i];

			glVertex3f(v.x, v.y, v.z);
		}
	glEnd();

	// bottom slice
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(v1.x, v1.y, v1.z);

		for (unsigned int col = 0; col <= numCols; col++) {
			const unsigned int i = ((numRows - 1) * numCols) + (col % numCols);
			const float3& v = vertices[i];

			glVertex3f(v.x, v.y, v.z);
		}
	glEnd();

	for (unsigned int row = 1; row < numRows - 1; row++) {
		glBegin(GL_QUAD_STRIP);

		for (unsigned int col = 0; col < numCols; col++) {
			const float3& v0 = vertices[(row + 0) * numCols + col];
			const float3& v1 = vertices[(row + 1) * numCols + col];

			glVertex3f(v0.x, v0.y, v0.z);
			glVertex3f(v1.x, v1.y, v1.z);
		}

		const float3& v0 = vertices[(row + 0) * numCols];
		const float3& v1 = vertices[(row + 1) * numCols];

		glVertex3f(v0.x, v0.y, v0.z);
		glVertex3f(v1.x, v1.y, v1.z);
		glEnd();
	}

	glPopAttrib();
	glEndList();
}
