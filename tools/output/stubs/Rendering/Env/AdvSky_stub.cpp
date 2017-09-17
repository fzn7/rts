/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "AdvSky.h"

#include "Game/Camera.h"
#include "Map/MapInfo.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Textures/Bitmap.h"
#include "Sim/Misc/GlobalSynced.h"
#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/TimeProfiler.h"
#include "System/Matrix44f.h"
#include "System/myMath.h"

#define Y_PART 10.0
#define X_PART 10.0

#define CLOUD_DETAIL 6
#define CLOUD_MASK (CLOUD_SIZE-1)


CAdvSky::CAdvSky()
	: skydir1(ZeroVector)
	, skydir2(ZeroVector)
	, cdtex(0)
	, cloudFP(0)
	, drawFlare(false)
	, cloudTexMem(NULL)
	, skyTex(0)
	, skyDot3Tex(0)
	, cloudDot3Tex(0)
	, sunTex(0)
	, sunFlareTex(0)
	, skyTexUpdateIter(0)
	, skyDomeList(0)
	, sunFlareList(0)
	, skyAngle(0.0f)
	, domeheight(0.0f)
	, domeWidth(0.0f)
	, sunTexCoordX(0.0f)
	, sunTexCoordY(0.0f)
	, randMatrix(NULL)
	, rawClouds(NULL)
	, blendMatrix(NULL)
	, cloudThickness(NULL)
	, oldCoverBaseX(-5)
	, oldCoverBaseY(0)
	, updatecounter(0)
{
    //stub method
}

void CAdvSky::CreateSkyDomeList()
{
    //stub method
}

CAdvSky::~CAdvSky()
{
    //stub method
}

void CAdvSky::Draw()
{
    //stub method
}

float3 CAdvSky::GetCoord(int x, int y)
{
    //stub method
}

void CAdvSky::CreateClouds()
{
    //stub method
}

inline void CAdvSky::UpdatePart(int ast, int aed, int a3cstart, int a4cstart) {
	int* rc = *rawClouds + ast;
	unsigned char* ct = cloudTexMem + 4 * ast;

	int yam2 = ydif[(ast - 2) & CLOUD_MASK];
	int yam1 = ydif[(ast - 1) & CLOUD_MASK];
	int yaa  = ydif[(ast)     & CLOUD_MASK];
	int ap1  = (ast + 1) & CLOUD_MASK;

	int a3c  = ast + a3cstart;
	int a4c  = ast + a4cstart;

	for (int a = ast; a < aed; ++rc, ++ct) {
		int yap1 = ydif[ap1] += (int) cloudThickness[++a3c] - cloudThickness[++a] * 2 + cloudThickness[++a4c];

		ap1++;
		ap1 = (ap1 & CLOUD_MASK);
		int dif =
			(yam2 >> 2) +
			(yam1 >> 1) +
			(yaa) +
			(yap1 >> 1) +
			(ydif[ap1] >> 2);
		dif >>= 4;

		yam2 = yam1;
		yam1 = yaa;
		yaa  = yap1;

		*ct++ = 128 + dif;
		*ct++ = thicknessTransform[(*rc) >> 7];
		*ct++ = 255;
	}
}

void CAdvSky::Update()
{
    //stub method
}

void CAdvSky::CreateRandMatrix(int **matrix,float mod)
{
    //stub method
}

void CAdvSky::CreateRandDetailMatrix(unsigned char* matrix,int size)
{
    //stub method
}

void CAdvSky::CreateTransformVectors()
{
    //stub method
}

void CAdvSky::DrawSun()
{
    //stub method
}

void CAdvSky::UpdateSunFlare() {
	if (sunFlareList != 0)
		glDeleteLists(sunFlareList, 1);

	const float3 zdir = skyLight->GetLightDir();
	const float3 xdir = zdir.cross(UpVector).ANormalize();
	const float3 ydir = zdir.cross(xdir);

	sunFlareList = glGenLists(1);
	glNewList(sunFlareList, GL_COMPILE);
		glDisable(GL_FOG);
		glBindTexture(GL_TEXTURE_2D, sunFlareTex);
		glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ONE);
		glBegin(GL_TRIANGLE_STRIP);

		for (int x = 0; x < 257; ++x) {
			const float dx = std::sin(x * 2.0f * PI / 256.0f);
			const float dy = std::cos(x * 2.0f * PI / 256.0f);
			const float dz = 5.0f;

			glTexCoord2f(x / 256.0f, 0.125f); glVertexf3(zdir * dz + xdir * dx * 0.0014f + ydir * dy * 0.0014f);
			glTexCoord2f(x / 256.0f, 0.875f); glVertexf3(zdir * dz + xdir * dx * 1.0000f + ydir * dy * 1.0000f);
		}

		glEnd();

		if (globalRendering->drawFog)
			glEnable(GL_FOG);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	glEndList();
}



void CAdvSky::InitSun()
{
    //stub method
}

void CAdvSky::CreateCover(int baseX, int baseY, float *buf) const
{
    //stub method
}

void CAdvSky::CreateDetailTex()
{
    //stub method
}

void CAdvSky::UpdateSunDir() {
	const float3& L = skyLight->GetLightDir();

	sundir2 = L;
	sundir2.y = 0.0f;

	if (sundir2.SqLength() == 0.0f)
		sundir2.x = 1.0f;

	sundir2.ANormalize();
	sundir1 = sundir2.cross(UpVector);

	modSunDir.x = 0.0f;
	modSunDir.y = L.y;
	modSunDir.z = std::sqrt(L.x * L.x + L.z * L.z);

	sunTexCoordX = 0.5f;
	sunTexCoordY = GetTexCoordFromDir(modSunDir);

	UpdateSunFlare();
}

void CAdvSky::UpdateSkyDir() {
	skydir2 = mapInfo->atmosphere.skyDir;
	skydir2.y = 0.0f;

	if (skydir2.SqLength() == 0.0f)
		skydir2.x = 1.0f;

	skydir2.ANormalize();
	skydir1 = skydir2.cross(UpVector);
	skyAngle = GetRadFromXY(skydir2.x, skydir2.z) + PI / 2.0f;
}

void CAdvSky::UpdateSkyTexture() {
	const int mod = skyTexUpdateIter % 3;

	if (mod <= 1) {
		const int y = (skyTexUpdateIter / 3) * 2 + mod;
		for (int x = 0; x < 512; x++) {
			UpdateTexPart(x, y, skytexpart);
		}
		glBindTexture(GL_TEXTURE_2D, skyTex);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, y, 512, 1, GL_RGBA, GL_UNSIGNED_BYTE, skytexpart[0]);
	} else {
		const int y = (skyTexUpdateIter / 3);
		for (int x = 0; x < 256; x++) {
			UpdateTexPartDot3(x, y, skytexpart);
		}
		glBindTexture(GL_TEXTURE_2D, skyDot3Tex);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, y, 256, 1, GL_RGBA, GL_UNSIGNED_BYTE, skytexpart[0]);
	}

	skyTexUpdateIter = (skyTexUpdateIter + 1) % (512 + 256);
}



float3 CAdvSky::GetDirFromTexCoord(float x, float y)
{
    //stub method
}

// should be improved
// only take stuff in yz plane
float CAdvSky::GetTexCoordFromDir(const float3& dir)
{
    //stub method
}

void CAdvSky::UpdateTexPartDot3(int x, int y, unsigned char (*texp)[4]) {
	const float3& dir = GetDirFromTexCoord(x / 256.0f, (255.0f - y) / 256.0f);

	const float sunInt = skyLight->GetLightIntensity();
	const float sunDist = std::acos(dir.dot(skyLight->GetLightDir())) * 50;
	const float sunMod = sunInt * (0.3f / std::sqrt(sunDist) + 3.0f / (1 + sunDist));

	const float green = std::min(1.0f, (0.55f + sunMod));
	const float blue  = 203 - sunInt * (40.0f / (3 + sunDist));

	texp[x][0] = (unsigned char) (sunInt * (255 - std::min(255.0f, sunDist))); // sun on borders
	texp[x][1] = (unsigned char) (green * 255); // sun light through
	texp[x][2] = (unsigned char)  blue; // ambient
	texp[x][3] = 255;
}

void CAdvSky::UpdateTexPart(int x, int y, unsigned char (*texp)[4]) {
	const float3& dir = GetDirFromTexCoord(x / 512.0f, (511.0f - y) / 512.0f);

	const float sunDist = std::acos(dir.dot(skyLight->GetLightDir())) * 70;
	const float sunMod = skyLight->GetLightIntensity() * 12.0f / (12 + sunDist);

	const float red   = std::min(skyColor.x + sunMod * sunColor.x, 1.0f);
	const float green = std::min(skyColor.y + sunMod * sunColor.y, 1.0f);
	const float blue  = std::min(skyColor.z + sunMod * sunColor.z, 1.0f);

	texp[x][0] = (unsigned char)(red   * 255);
	texp[x][1] = (unsigned char)(green * 255);
	texp[x][2] = (unsigned char)(blue  * 255);
	texp[x][3] = 255;
}
