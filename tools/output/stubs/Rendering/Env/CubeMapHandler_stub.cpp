/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "Game/Camera.h"
#include "Game/Game.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Map/MapInfo.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/UnitDrawer.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/Env/CubeMapHandler.h"
#include "System/Config/ConfigHandler.h"

CONFIG(int, CubeTexSizeSpecular).defaultValue(128).minimumValue(1);
CONFIG(int, CubeTexSizeReflection).defaultValue(128).minimumValue(1);

CubeMapHandler* cubeMapHandler = NULL;

CubeMapHandler::CubeMapHandler() {
	envReflectionTexID = 0;
	skyReflectionTexID = 0;
	specularTexID = 0;

	reflTexSize = 0;
	specTexSize = 0;

	currReflectionFace = 0;
	specularTexIter = 0;
	mapSkyReflections = false;
}

bool CubeMapHandler::Init() {
	specTexSize = configHandler->GetInt("CubeTexSizeSpecular");
	reflTexSize = configHandler->GetInt("CubeTexSizeReflection");
	specTexBuf.resize(specTexSize * 4, 0);

	mapSkyReflections = !(mapInfo->smf.skyReflectModTexName.empty());

	{
		glGenTextures(1, &specularTexID);
		glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, specularTexID);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		CreateSpecularFace(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, specTexSize, float3( 1,  1,  1), float3( 0, 0, -2), float3(0, -2,  0));
		CreateSpecularFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB, specTexSize, float3(-1,  1, -1), float3( 0, 0,  2), float3(0, -2,  0));
		CreateSpecularFace(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB, specTexSize, float3(-1,  1, -1), float3( 2, 0,  0), float3(0,  0,  2));
		CreateSpecularFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB, specTexSize, float3(-1, -1,  1), float3( 2, 0,  0), float3(0,  0, -2));
		CreateSpecularFace(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB, specTexSize, float3(-1,  1,  1), float3( 2, 0,  0), float3(0, -2,  0));
		CreateSpecularFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB, specTexSize, float3( 1,  1, -1), float3(-2, 0,  0), float3(0, -2,  0));
	}

	{
		glGenTextures(1, &envReflectionTexID);
		glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, envReflectionTexID);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	}

	if (mapSkyReflections) {
		glGenTextures(1, &skyReflectionTexID);
		glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, skyReflectionTexID);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_EXT, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB, 0, GL_RGBA8, reflTexSize, reflTexSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	}


	if (reflectionCubeFBO.IsValid()) {
		reflectionCubeFBO.Bind();
		reflectionCubeFBO.CreateRenderBuffer(GL_DEPTH_ATTACHMENT_EXT, GL_DEPTH_COMPONENT, reflTexSize, reflTexSize);
		reflectionCubeFBO.Unbind();
	}

	if (!reflectionCubeFBO.IsValid()) {
		Free();
		return false;
	}

	return true;
}

void CubeMapHandler::Free() {
	if (specularTexID != 0) {
		glDeleteTextures(1, &specularTexID);
		specularTexID = 0;
	}
	if (envReflectionTexID != 0) {
		glDeleteTextures(1, &envReflectionTexID);
		envReflectionTexID = 0;
	}
	if (skyReflectionTexID != 0) {
		glDeleteTextures(1, &skyReflectionTexID);
		skyReflectionTexID = 0;
	}
}



void CubeMapHandler::UpdateReflectionTexture()
{
    //stub method
}

void CubeMapHandler::CreateReflectionFace(unsigned int glType, const float3& camDir, bool skyOnly)
{
    //stub method
}


void CubeMapHandler::UpdateSpecularTexture()
{
    //stub method
}

void CubeMapHandler::CreateSpecularFacePart(
	unsigned int texType,
	unsigned int size,
	const float3& cdir,
	const float3& xdif,
	const float3& ydif,
	unsigned int y,
	unsigned char* buf)
{
    //stub method
}

void CubeMapHandler::CreateSpecularFace(
	unsigned int texType,
	unsigned int size,
	const float3& cdir,
	const float3& xdif,
	const float3& ydif)
{
    //stub method
}

void CubeMapHandler::UpdateSpecularFace(
	unsigned int texType,
	unsigned int size,
	const float3& cdir,
	const float3& xdif,
	const float3& ydif,
	unsigned int y,
	unsigned char* buf)
{
    //stub method
}

