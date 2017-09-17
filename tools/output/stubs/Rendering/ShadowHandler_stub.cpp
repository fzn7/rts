#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */
#include <cfloat>

#include "ShadowHandler.h"
#include "Game/Camera.h"
#include "Game/GameVersion.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/FeatureDrawer.h"
#include "Rendering/Env/Particles/ProjectileDrawer.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/Env/GrassDrawer.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/ITreeDrawer.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "System/Config/ConfigHandler.h"
#include "System/EventHandler.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"
#include "System/Log/ILog.h"

#define SHADOWMATRIX_NONLINEAR 0

CONFIG(int, Shadows).defaultValue(2).headlessValue(-1).minimumValue(-1).safemodeValue(-1).description("Sets whether shadows are rendered.\n-1:=forceoff, 0:=off, 1:=full, 2:=fast (skip terrain)"); //FIXME document bitmask
CONFIG(int, ShadowMapSize).defaultValue(CShadowHandler::DEF_SHADOWMAP_SIZE).minimumValue(32).description("Sets the resolution of shadows. Higher numbers increase quality at the cost of performance.");
CONFIG(int, ShadowProjectionMode).defaultValue(CShadowHandler::SHADOWPROMODE_CAM_CENTER);

CShadowHandler* shadowHandler = NULL;

bool CShadowHandler::shadowsSupported = false;
bool CShadowHandler::firstInit = true;


void CShadowHandler::Reload(const char* argv)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::Kill()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::FreeTextures() {
	if (fb.IsValid()) {
		fb.Bind();
		fb.DetachAll();
		fb.Unbind();
	}

	glDeleteTextures(1, &shadowTexture    ); shadowTexture     = 0;
	glDeleteTextures(1, &dummyColorTexture); dummyColorTexture = 0;
}



void CShadowHandler::LoadShadowGenShaderProgs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool CShadowHandler::InitDepthTarget()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CShadowHandler::WorkaroundUnsupportedFboRenderTargets()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CShadowHandler::DrawShadowPasses()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::SetShadowMapSizeFactors()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static CMatrix44f ComposeLightMatrix(const ISkyLight* light)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static CMatrix44f ComposeScaleMatrix(const float4 scales)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::SetShadowMatrix(CCamera* playerCam, CCamera* shadowCam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::SetShadowCamera(CCamera* shadowCam)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CShadowHandler::SetupShadowTexSampler(unsigned int texUnit, bool enable) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::SetupShadowTexSamplerRaw() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::ResetShadowTexSampler(unsigned int texUnit, bool disable) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CShadowHandler::ResetShadowTexSamplerRaw() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CShadowHandler::CreateShadows()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



float4 CShadowHandler::GetShadowProjectionScales(CCamera* cam, const float3& projDir) {
	float4 projScales;
	float2 projRadius;

	// NOTE:
	//   the xy-scaling factors from CalcMinMaxView do not change linearly
	//   or smoothly with camera movements, creating visible artefacts (eg.
	//   large jumps in shadow resolution)
	//
	//   therefore, EITHER use "fixed" scaling values such that the entire
	//   map barely fits into the sun's frustum (by pretending it is embedded
	//   in a sphere and taking its diameter), OR variable scaling such that
	//   everything that can be seen by the camera maximally fills the sun's
	//   frustum (choice of projection-style is left to the user and can be
	//   changed at run-time)
	//
	//   the first option means larger maps will have more blurred/aliased
	//   shadows if the depth buffer is kept at the same size, but no (map)
	//   geometry is ever omitted
	//
	//   the second option means shadows have higher average resolution, but
	//   become less sharp as the viewing volume increases (through eg.camera
	//   rotations) and geometry can be omitted in some cases
	//
	// NOTE:
	//   when DynamicSun is enabled, the orbit is always circular in the xz
	//   plane, instead of elliptical when the map has an aspect-ratio != 1
	//
	switch (shadowProMode) {
		case SHADOWPROMODE_CAM_CENTER: {
			projScales.x = GetOrthoProjectedFrustumRadius(cam, projMidPos[2]);
		} break;
		case SHADOWPROMODE_MAP_CENTER: {
			projScales.x = GetOrthoProjectedMapRadius(projDir, projMidPos[2]);
		} break;
		case SHADOWPROMODE_MIX_CAMMAP: {
			projRadius.x = GetOrthoProjectedFrustumRadius(cam, projMidPos[0]);
			projRadius.y = GetOrthoProjectedMapRadius(projDir, projMidPos[1]);
			projScales.x = std::min(projRadius.x, projRadius.y);

			// pick the center position (0 or 1) for which radius is smallest
			projMidPos[2] = projMidPos[projRadius.x >= projRadius.y];
		} break;
	}

	projScales.y = projScales.x;
	projScales.z = globalRendering->zNear;
	projScales.w = globalRendering->viewRange;
	return (shadowProjScales = projScales);
}

float CShadowHandler::GetOrthoProjectedMapRadius(const float3& sunDir, float3& projPos) {
	// to fit the map inside the frustum, we need to know
	// the distance from one corner to its opposing corner
	//
	// this distance is maximal when the sun direction is
	// orthogonal to the diagonal, but in other cases we
	// can gain some precision by projecting the diagonal
	// onto a vector orthogonal to the sun direction and
	// using the length of that projected vector instead
	//
	const float maxMapDiameter = readMap->GetBoundingRadius() * 2.0f;
	static float curMapDiameter = 0.0f;

	// recalculate pos only if the sun-direction has changed
	if (sunProjDir != sunDir) {
		sunProjDir = sunDir;

		float3 sunDirXZ = (sunDir * XZVector).ANormalize();
		float3 mapVerts[2];

		if (sunDirXZ.x >= 0.0f) {
			if (sunDirXZ.z >= 0.0f) {
				// use diagonal vector from top-right to bottom-left
				mapVerts[0] = float3(mapDims.mapx * SQUARE_SIZE, 0.0f,                       0.0f);
				mapVerts[1] = float3(                      0.0f, 0.0f, mapDims.mapy * SQUARE_SIZE);
			} else {
				// use diagonal vector from top-left to bottom-right
				mapVerts[0] = float3(                      0.0f, 0.0f,                       0.0f);
				mapVerts[1] = float3(mapDims.mapx * SQUARE_SIZE, 0.0f, mapDims.mapy * SQUARE_SIZE);
			}
		} else {
			if (sunDirXZ.z >= 0.0f) {
				// use diagonal vector from bottom-right to top-left
				mapVerts[0] = float3(mapDims.mapx * SQUARE_SIZE, 0.0f, mapDims.mapy * SQUARE_SIZE);
				mapVerts[1] = float3(                      0.0f, 0.0f,                       0.0f);
			} else {
				// use diagonal vector from bottom-left to top-right
				mapVerts[0] = float3(                      0.0f, 0.0f, mapDims.mapy * SQUARE_SIZE);
				mapVerts[1] = float3(mapDims.mapx * SQUARE_SIZE, 0.0f,                       0.0f);
			}
		}

		const float3 v1 = (mapVerts[1] - mapVerts[0]).ANormalize();
		const float3 v2 = float3(-sunDirXZ.z, 0.0f, sunDirXZ.x);

		curMapDiameter = maxMapDiameter * v2.dot(v1);

		projPos.x = (mapDims.mapx * SQUARE_SIZE) * 0.5f;
		projPos.z = (mapDims.mapy * SQUARE_SIZE) * 0.5f;
		projPos.y = CGround::GetHeightReal(projPos.x, projPos.z, false);
	}

	return curMapDiameter;
}

float CShadowHandler::GetOrthoProjectedFrustumRadius(CCamera* cam, float3& projPos) {
	cam->GetFrustumSides(0.0f, 0.0f, 1.0f, true);
	cam->ClipFrustumLines(true, -100.0f, mapDims.mapy * SQUARE_SIZE + 100.0f);

	const std::vector<CCamera::FrustumLine>& sides = cam->GetNegFrustumSides();

	if (sides.empty())
		return 0.0f;

	// two sides, two points per side
	float3 frustumPoints[2 * 2];

	// .w := radius
	float4 frustumCenter;

	// only need points on these lines
	const unsigned int planes[] = {CCamera::FRUSTUM_PLANE_LFT, CCamera::FRUSTUM_PLANE_RGT};

	for (unsigned int n = 0; n < 2; n++) {
		const CCamera::FrustumLine& line = sides[ planes[n] ];

		// calculate xz-coordinates
		const float z0 = line.minz, x0 = line.base + (line.dir * z0);
		const float z1 = line.maxz, x1 = line.base + (line.dir * z1);

		// clamp points to map edges
		const float cx0 = Clamp(x0, 0.0f, float3::maxxpos);
		const float cz0 = Clamp(z0, 0.0f, float3::maxzpos);
		const float cx1 = Clamp(x1, 0.0f, float3::maxxpos);
		const float cz1 = Clamp(z1, 0.0f, float3::maxzpos);

		frustumPoints[n * 2 + 0] = float3(cx0, CGround::GetHeightReal(cx0, cz0, false), cz0); // far-point
		frustumPoints[n * 2 + 1] = float3(cx1, CGround::GetHeightReal(cx1, cz1, false), cz1); // near-point

		frustumCenter += frustumPoints[n * 2 + 0];
		frustumCenter += frustumPoints[n * 2 + 1];
	}

	projPos.x = frustumCenter.x / 4.0f;
	projPos.z = frustumCenter.z / 4.0f;
	projPos.y = CGround::GetHeightReal(projPos.x, projPos.z, false);

	// calculate the radius of the minimally-bounding sphere around the projected frustum
	for (unsigned int n = 0; n < 4; n++) {
		frustumCenter.w = std::max(frustumCenter.w, (frustumPoints[n] - projPos).SqLength());
	}

	const float maxMapDiameter = readMap->GetBoundingRadius() * 2.0f;
	const float frustumDiameter = std::sqrt(frustumCenter.w) * 2.0f;

	return (std::min(maxMapDiameter, frustumDiameter));
}



#if 0
void CShadowHandler::CalcMinMaxView()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

