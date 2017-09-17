#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AdvTreeDrawer.h"
#include "AdvTreeGenerator.h"
#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h"
#include "Map/BaseGroundDrawer.h"
#include "Map/Ground.h"
#include "Map/MapInfo.h"
#include "Map/ReadMap.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Env/ISky.h"
#include "Rendering/Env/SunLighting.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GL/VertexArray.h"
#include "Rendering/Shaders/ShaderHandler.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Textures/Bitmap.h"
#include "Rendering/ShadowHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Features/Feature.h"
#include "Sim/Misc/LosHandler.h"
#include "System/Matrix44f.h"

static const float TEX_LEAF_START_Y1 = 0.001f;
static const float TEX_LEAF_END_Y1   = 0.124f;
static const float TEX_LEAF_START_Y2 = 0.126f;
static const float TEX_LEAF_END_Y2   = 0.249f;
static const float TEX_LEAF_START_Y3 = 0.251f;
static const float TEX_LEAF_END_Y3   = 0.374f;
static const float TEX_LEAF_START_Y4 = 0.376f;
static const float TEX_LEAF_END_Y4   = 0.499f;

static const float TEX_LEAF_START_X1 = 0.0f;
static const float TEX_LEAF_END_X1   = 0.125f;
static const float TEX_LEAF_START_X2 = 0.0f;
static const float TEX_LEAF_END_X2   = 0.125f;
static const float TEX_LEAF_START_X3 = 0.0f;
static const float TEX_LEAF_END_X3   = 0.125f;

static const float PART_MAX_TREE_HEIGHT   = MAX_TREE_HEIGHT * 0.4f;
static const float HALF_MAX_TREE_HEIGHT   = MAX_TREE_HEIGHT * 0.5f;


CAdvTreeDrawer::CAdvTreeDrawer(): ITreeDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAdvTreeDrawer::~CAdvTreeDrawer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CAdvTreeDrawer::LoadTreeShaders() {
	treeShaders.resize(TREE_PROGRAM_LAST, NULL);

	const static std::string shaderNames[TREE_PROGRAM_LAST] = {
		"treeNearDefShader", // no-shadow default shader
		"treeNearAdvShader",
		"treeDistAdvShader",
	};
	const static std::string shaderDefines[TREE_PROGRAM_LAST] = {
		"#define TREE_NEAR_BASIC\n",
		"#define TREE_NEAR_SHADOW\n",
		"#define TREE_DIST_SHADOW\n"
	};

	const static int numUniformNamesNDNA = 6;
	const static std::string uniformNamesNDNA[numUniformNamesNDNA] = {
		"cameraDirX",          // VP
		"cameraDirY",          // VP
		"treeOffset",          // VP
		"groundAmbientColor",  // VP + FP
		"groundDiffuseColor",  // VP
		"alphaModifiers",      // VP
	};
	const static int numUniformNamesNADA = 5;
	const std::string uniformNamesNADA[numUniformNamesNADA] = {
		"shadowMatrix",        // VP
		"shadowParams",        // VP
		"groundShadowDensity", // FP
		"shadowTex",           // FP
		"diffuseTex",          // FP
	};

	if (globalRendering->haveGLSL) {
		treeShaders[TREE_PROGRAM_NEAR_BASIC] =
			shaderHandler->CreateProgramObject("[TreeDrawer]", shaderNames[TREE_PROGRAM_NEAR_BASIC] + "GLSL", false);
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->AttachShaderObject(
			shaderHandler->CreateShaderObject("GLSL/TreeVertProg.glsl", shaderDefines[TREE_PROGRAM_NEAR_BASIC], GL_VERTEX_SHADER)
		);
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->Link();

		treeShaders[TREE_PROGRAM_NEAR_SHADOW] = shaderHandler->CreateProgramObject("[TreeDrawer]", shaderNames[TREE_PROGRAM_NEAR_SHADOW] + "GLSL", false);
		treeShaders[TREE_PROGRAM_DIST_SHADOW] = shaderHandler->CreateProgramObject("[TreeDrawer]", shaderNames[TREE_PROGRAM_DIST_SHADOW] + "GLSL", false);

		if (CShadowHandler::ShadowsSupported()) {
			treeShaders[TREE_PROGRAM_NEAR_SHADOW]->AttachShaderObject(
				shaderHandler->CreateShaderObject("GLSL/TreeVertProg.glsl", shaderDefines[TREE_PROGRAM_NEAR_SHADOW], GL_VERTEX_SHADER)
			);
			treeShaders[TREE_PROGRAM_NEAR_SHADOW]->AttachShaderObject(
				shaderHandler->CreateShaderObject("GLSL/TreeFragProg.glsl", shaderDefines[TREE_PROGRAM_NEAR_SHADOW], GL_FRAGMENT_SHADER)
			);

			treeShaders[TREE_PROGRAM_DIST_SHADOW]->AttachShaderObject(
				shaderHandler->CreateShaderObject("GLSL/TreeVertProg.glsl", shaderDefines[TREE_PROGRAM_DIST_SHADOW], GL_VERTEX_SHADER)
			);
			treeShaders[TREE_PROGRAM_DIST_SHADOW]->AttachShaderObject(
				shaderHandler->CreateShaderObject("GLSL/TreeFragProg.glsl", shaderDefines[TREE_PROGRAM_DIST_SHADOW], GL_FRAGMENT_SHADER)
			);
		}

		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->Link();
		treeShaders[TREE_PROGRAM_DIST_SHADOW]->Link();

		// ND, NA: indices [0, numUniformNamesNDNA - 1]
		for (int i = 0; i < numUniformNamesNDNA; i++) {
			treeShaders[TREE_PROGRAM_NEAR_BASIC ]->SetUniformLocation(uniformNamesNDNA[i]);
			treeShaders[TREE_PROGRAM_NEAR_SHADOW]->SetUniformLocation(uniformNamesNDNA[i]);
			treeShaders[TREE_PROGRAM_DIST_SHADOW]->SetUniformLocation((i != 3)? "$UNUSED$": uniformNamesNDNA[i]);
		}

		// ND: index <numUniformNamesNDNA>
		treeShaders[TREE_PROGRAM_NEAR_BASIC ]->SetUniformLocation("invMapSizePO2");
		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->SetUniformLocation("$UNUSED$");
		treeShaders[TREE_PROGRAM_DIST_SHADOW]->SetUniformLocation("$UNUSED$");

		// NA, DA: indices [numUniformNamesNDNA + 1, numUniformNamesNDNA + numUniformNamesNADA]
		for (int i = 0; i < numUniformNamesNADA; i++) {
			treeShaders[TREE_PROGRAM_NEAR_BASIC ]->SetUniformLocation("$UNUSED$");
			treeShaders[TREE_PROGRAM_NEAR_SHADOW]->SetUniformLocation(uniformNamesNADA[i]);
			treeShaders[TREE_PROGRAM_DIST_SHADOW]->SetUniformLocation(uniformNamesNADA[i]);
		}

		treeShaders[TREE_PROGRAM_NEAR_BASIC]->Enable();
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->SetUniform3fv(3, &sunLighting->groundAmbientColor[0]);
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->SetUniform3fv(4, &sunLighting->groundDiffuseColor[0]);
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->SetUniform4f(6, 1.0f / (mapDims.pwr2mapx * SQUARE_SIZE), 1.0f / (mapDims.pwr2mapy * SQUARE_SIZE), 1.0f / (mapDims.pwr2mapx * SQUARE_SIZE), 1.0f);
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->Disable();
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->Validate();

		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->Enable();
		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->SetUniform3fv(3, &sunLighting->groundAmbientColor[0]);
		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->SetUniform3fv(4, &sunLighting->groundDiffuseColor[0]);
		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->SetUniform1f(9, 1.0f - (sky->GetLight()->GetGroundShadowDensity() * 0.5f));
		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->SetUniform1i(10, 0);
		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->SetUniform1i(11, 1);
		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->Disable();
		treeShaders[TREE_PROGRAM_NEAR_SHADOW]->Validate();

		treeShaders[TREE_PROGRAM_DIST_SHADOW]->Enable();
		treeShaders[TREE_PROGRAM_DIST_SHADOW]->SetUniform3fv(3, &sunLighting->groundAmbientColor[0]);
		treeShaders[TREE_PROGRAM_DIST_SHADOW]->SetUniform1f(9, 1.0f - (sky->GetLight()->GetGroundShadowDensity() * 0.5f));
		treeShaders[TREE_PROGRAM_DIST_SHADOW]->SetUniform1i(10, 0);
		treeShaders[TREE_PROGRAM_DIST_SHADOW]->SetUniform1i(11, 1);
		treeShaders[TREE_PROGRAM_DIST_SHADOW]->Disable();
		treeShaders[TREE_PROGRAM_DIST_SHADOW]->Validate();
	} else {
		treeShaders[TREE_PROGRAM_NEAR_BASIC] = shaderHandler->CreateProgramObject("[TreeDrawer]", shaderNames[TREE_PROGRAM_NEAR_BASIC] + "ARB", true);
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->AttachShaderObject(shaderHandler->CreateShaderObject("ARB/treeNS.vp", "", GL_VERTEX_PROGRAM_ARB));
		treeShaders[TREE_PROGRAM_NEAR_BASIC]->Link();

		if (CShadowHandler::ShadowsSupported()) {
			treeShaders[TREE_PROGRAM_NEAR_SHADOW] = shaderHandler->CreateProgramObject("[TreeDrawer]", shaderNames[TREE_PROGRAM_NEAR_SHADOW] + "ARB", true);
			treeShaders[TREE_PROGRAM_NEAR_SHADOW]->AttachShaderObject(shaderHandler->CreateShaderObject("ARB/tree.vp", "", GL_VERTEX_PROGRAM_ARB));
			treeShaders[TREE_PROGRAM_NEAR_SHADOW]->AttachShaderObject(shaderHandler->CreateShaderObject("ARB/treeFPshadow.fp", "", GL_FRAGMENT_PROGRAM_ARB));
			treeShaders[TREE_PROGRAM_NEAR_SHADOW]->Link();
			treeShaders[TREE_PROGRAM_DIST_SHADOW] = shaderHandler->CreateProgramObject("[TreeDrawer]", shaderNames[TREE_PROGRAM_DIST_SHADOW] + "ARB", true);
			treeShaders[TREE_PROGRAM_DIST_SHADOW]->AttachShaderObject(shaderHandler->CreateShaderObject("ARB/treeFar.vp", "", GL_VERTEX_PROGRAM_ARB));
			treeShaders[TREE_PROGRAM_DIST_SHADOW]->AttachShaderObject(shaderHandler->CreateShaderObject("ARB/treeFPshadow.fp", "", GL_FRAGMENT_PROGRAM_ARB));
			treeShaders[TREE_PROGRAM_DIST_SHADOW]->Link();
		}
	}
}



void CAdvTreeDrawer::Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



static inline void SetArrayQ(CVertexArray* va, float t1, float t2, const float3& v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CAdvTreeDrawer::DrawTreeVertexA(CVertexArray* va, float3& ftpos, float dx, float dy) {
	SetArrayQ(va, TEX_LEAF_START_X1 + dx, TEX_LEAF_START_Y1 + dy, ftpos); ftpos.y += MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_START_X1 + dx, TEX_LEAF_END_Y1   + dy, ftpos); ftpos.x -= MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X1   + dx, TEX_LEAF_END_Y1   + dy, ftpos); ftpos.y -= MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X1   + dx, TEX_LEAF_START_Y1 + dy, ftpos); ftpos.x += HALF_MAX_TREE_HEIGHT;

	ftpos.z += HALF_MAX_TREE_HEIGHT;

	SetArrayQ(va, TEX_LEAF_START_X2 + dx, TEX_LEAF_START_Y2 + dy, ftpos); ftpos.y += MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_START_X2 + dx, TEX_LEAF_END_Y2   + dy, ftpos); ftpos.z -= MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X2   + dx, TEX_LEAF_END_Y2   + dy, ftpos); ftpos.y -= MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X2   + dx, TEX_LEAF_START_Y2 + dy, ftpos);

	ftpos.x += HALF_MAX_TREE_HEIGHT;
	ftpos.y += PART_MAX_TREE_HEIGHT;
}

void CAdvTreeDrawer::DrawTreeVertex(CVertexArray* va, const float3& pos, float dx, float dy, bool enlarge) {
	if (enlarge)
		va->EnlargeArrays(12, 0, VA_SIZE_T);

	float3 ftpos = pos;
	ftpos.x += HALF_MAX_TREE_HEIGHT;

	DrawTreeVertexA(va, ftpos, dx, dy);

	ftpos.z += MAX_TREE_HEIGHT;

	SetArrayQ(va, TEX_LEAF_START_X3 + dx, TEX_LEAF_START_Y3 + dy, ftpos); ftpos.z -= MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_START_X3 + dx, TEX_LEAF_END_Y3   + dy, ftpos); ftpos.x -= MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X3   + dx, TEX_LEAF_END_Y3   + dy, ftpos); ftpos.z += MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X3   + dx, TEX_LEAF_START_Y3 + dy, ftpos);
}

void CAdvTreeDrawer::DrawTreeVertexMid(CVertexArray* va, const float3& pos, float dx, float dy, bool enlarge) {
	if (enlarge)
		va->EnlargeArrays(12, 0, VA_SIZE_T);

	float3 ftpos = pos;
	ftpos.x += HALF_MAX_TREE_HEIGHT;

	DrawTreeVertexA(va, ftpos, dx, dy);

	ftpos.z += HALF_MAX_TREE_HEIGHT;

	SetArrayQ(va, TEX_LEAF_START_X3 + dx, TEX_LEAF_START_Y3 + dy, ftpos);
		ftpos.x -= HALF_MAX_TREE_HEIGHT;
		ftpos.z -= HALF_MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_START_X3 + dx, TEX_LEAF_END_Y3 + dy,   ftpos);
		ftpos.x -= HALF_MAX_TREE_HEIGHT;
		ftpos.z += HALF_MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X3 + dx,   TEX_LEAF_END_Y3 + dy,   ftpos);
		ftpos.x += HALF_MAX_TREE_HEIGHT;
		ftpos.z += HALF_MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X3 + dx,   TEX_LEAF_START_Y3 + dy, ftpos);
}

void CAdvTreeDrawer::DrawTreeVertexFar(CVertexArray* va, const float3& pos, const float3& swd, float dx, float dy, bool enlarge) {
	if (enlarge)
		va->EnlargeArrays(4, 0, VA_SIZE_T);

	float3 base = pos + swd;

	SetArrayQ(va, TEX_LEAF_START_X1 + dx, TEX_LEAF_START_Y4 + dy, base); base.y += MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_START_X1 + dx, TEX_LEAF_END_Y4   + dy, base); base   -= (swd * 2.0f);
	SetArrayQ(va, TEX_LEAF_END_X1   + dx, TEX_LEAF_END_Y4   + dy, base); base.y -= MAX_TREE_HEIGHT;
	SetArrayQ(va, TEX_LEAF_END_X1   + dx, TEX_LEAF_START_Y4 + dy, base);
}




struct CAdvTreeSquareDrawer : public CReadMap::IQuadDrawer
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




void CAdvTreeDrawer::Draw(float treeDistance, bool drawReflection)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



struct CAdvTreeSquareShadowPassDrawer: public CReadMap::IQuadDrawer
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CAdvTreeDrawer::DrawShadowPass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CAdvTreeDrawer::AddFallingTree(int treeID, int treeType, const float3& pos, const float3& dir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

