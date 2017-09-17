#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AssParser.h"
#include "3DModel.h"
#include "3DModelLog.h"
#include "AssIO.h"

#include "Lua/LuaParser.h"
#include "Sim/Misc/CollisionVolume.h"
#include "System/Util.h"
#include "System/Log/ILog.h"
#include "System/Platform/errorhandler.h"
#include "System/Exceptions.h"
#include "System/ScopedFPUSettings.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"

#include "lib/assimp/include/assimp/config.h"
#include "lib/assimp/include/assimp/defs.h"
#include "lib/assimp/include/assimp/types.h"
#include "lib/assimp/include/assimp/scene.h"
#include "lib/assimp/include/assimp/postprocess.h"
#include "lib/assimp/include/assimp/Importer.hpp"
#include "lib/assimp/include/assimp/DefaultLogger.hpp"
#include "Rendering/Textures/S3OTextureHandler.h"
#ifndef BITMAP_NO_OPENGL
	#include "Rendering/GL/myGL.h"
#endif


#define IS_QNAN(f) (f != f)
static const float DEGTORAD = PI / 180.0f;
static const float RADTODEG = 180.0f / PI;

// triangulate guarantees the most complex mesh is a triangle
// sortbytype ensure only 1 type of primitive type per mesh is used
static const unsigned int ASS_POSTPROCESS_OPTIONS =
	  aiProcess_RemoveComponent
	| aiProcess_FindInvalidData
	| aiProcess_CalcTangentSpace
	| aiProcess_GenSmoothNormals
	| aiProcess_Triangulate
	| aiProcess_GenUVCoords
	| aiProcess_SortByPType
	| aiProcess_JoinIdenticalVertices
	//| aiProcess_ImproveCacheLocality // FIXME crashes in an assert in VertexTriangleAdjancency.h (date 04/2011)
	| aiProcess_SplitLargeMeshes;

static const unsigned int ASS_IMPORTER_OPTIONS =
	aiComponent_CAMERAS |
	aiComponent_LIGHTS |
	aiComponent_TEXTURES |
	aiComponent_ANIMATIONS;
static const unsigned int ASS_LOGGING_OPTIONS =
	Assimp::Logger::Debugging |
	Assimp::Logger::Info |
	Assimp::Logger::Err |
	Assimp::Logger::Warn;



static inline float3 aiVectorToFloat3(const aiVector3D v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline CMatrix44f aiMatrixToMatrix(const aiMatrix4x4t<float>& m)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/*
static float3 aiQuaternionToRadianAngles(const aiQuaternion q1)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
*/




class AssLogStream : public Assimp::LogStream
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAssParser::~CAssParser()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


S3DModel* CAssParser::Load(const std::string& modelFilePath)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/*
void CAssParser::CalculateModelMeshBounds(S3DModel* model, const aiScene* scene)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
*/


void CAssParser::LoadPieceTransformations(
	SAssPiece* piece,
	const S3DModel* model,
	const aiNode* pieceNode,
	const LuaTable& pieceTable
) {
	aiVector3D aiScaleVec;
	aiVector3D aiTransVec;
	aiQuaternion aiRotateQuat;

	// process transforms
	pieceNode->mTransformation.Decompose(aiScaleVec, aiRotateQuat, aiTransVec);

	// metadata-scaling
	piece->scales   = pieceTable.GetFloat3("scale", aiVectorToFloat3(aiScaleVec));
	piece->scales.x = pieceTable.GetFloat("scalex", piece->scales.x);
	piece->scales.y = pieceTable.GetFloat("scaley", piece->scales.y);
	piece->scales.z = pieceTable.GetFloat("scalez", piece->scales.z);

	if (piece->scales.x != piece->scales.y || piece->scales.y != piece->scales.z) {
		// LOG_SL(LOG_SECTION_MODEL, L_WARNING, "Spring doesn't support non-uniform scaling");
		piece->scales.y = piece->scales.x;
		piece->scales.z = piece->scales.x;
	}

	// metadata-translation
	piece->offset   = pieceTable.GetFloat3("offset", aiVectorToFloat3(aiTransVec));
	piece->offset.x = pieceTable.GetFloat("offsetx", piece->offset.x);
	piece->offset.y = pieceTable.GetFloat("offsety", piece->offset.y);
	piece->offset.z = pieceTable.GetFloat("offsetz", piece->offset.z);

	// metadata-rotation
	// NOTE:
	//   these rotations are "pre-scripting" but "post-modelling"
	//   together with the (baked) aiRotateQuad they determine the
	//   model's pose *before* any animations execute
	//
	// float3 pieceRotAngles = pieceTable.GetFloat3("rotate", aiQuaternionToRadianAngles(aiRotateQuat) * RADTODEG);
	float3 pieceRotAngles = pieceTable.GetFloat3("rotate", ZeroVector);

	pieceRotAngles.x = pieceTable.GetFloat("rotatex", pieceRotAngles.x);
	pieceRotAngles.y = pieceTable.GetFloat("rotatey", pieceRotAngles.y);
	pieceRotAngles.z = pieceTable.GetFloat("rotatez", pieceRotAngles.z);
	pieceRotAngles  *= DEGTORAD;

	LOG_SL(LOG_SECTION_PIECE, L_INFO,
		"(%d:%s) Assimp offset (%f,%f,%f), rotate (%f,%f,%f,%f), scale (%f,%f,%f)",
		model->numPieces, piece->name.c_str(),
		aiTransVec.x, aiTransVec.y, aiTransVec.z,
		aiRotateQuat.w, aiRotateQuat.x, aiRotateQuat.y, aiRotateQuat.z,
		aiScaleVec.x, aiScaleVec.y, aiScaleVec.z
	);
	LOG_SL(LOG_SECTION_PIECE, L_INFO,
		"(%d:%s) Relative offset (%f,%f,%f), rotate (%f,%f,%f), scale (%f,%f,%f)",
		model->numPieces, piece->name.c_str(),
		piece->offset.x, piece->offset.y, piece->offset.z,
		pieceRotAngles.x, pieceRotAngles.y, pieceRotAngles.z,
		piece->scales.x, piece->scales.y, piece->scales.z
	);

	// NOTE:
	//   at least collada (.dae) files generated by Blender are stored
	//   in a coordinate-system that differs from the standard formats
	//   (3DO, S3O, ...) for which existing tools have prior knowledge
	//   of Spring's convention, but AssImp's internal system happens
	//   to match our own so we need no explicit conversion
	//
	//   we allow overriding the (baked) ROOT rotational transform and
	//   the rotation-axis mapping used by animation scripts because it
	//   can be a benefit to create models wrt. a different orientation
	//   than that of the 3D editor (but re-modelling / re-exporting is
	//   always preferred!)
	//
	//   .dae  : x=Rgt, y=-Fwd, z= Up, as=(-1, -1, 1), am=AXIS_XZY (if Z_UP)
	//   .dae  : x=Rgt, y=-Fwd, z= Up, as=(-1, -1, 1), am=AXIS_XZY (if Y_UP) [!?]
	//   .blend: ????
	CMatrix44f bakedMatrix = aiMatrixToMatrix(aiMatrix4x4t<float>(aiRotateQuat.GetMatrix()));

	if (piece == model->GetRootPiece()) {
		const float3 xaxis = pieceTable.GetFloat3("xaxis", bakedMatrix.GetX());
		const float3 yaxis = pieceTable.GetFloat3("yaxis", bakedMatrix.GetY());
		const float3 zaxis = pieceTable.GetFloat3("zaxis", bakedMatrix.GetZ());

		if (math::fabs(xaxis.SqLength() - yaxis.SqLength()) < 0.01f && math::fabs(yaxis.SqLength() - zaxis.SqLength()) < 0.01f) {
			bakedMatrix = CMatrix44f(ZeroVector, xaxis, yaxis, zaxis);
		}
	}

	piece->rotAxisSigns = pieceTable.GetFloat3("rotAxisSigns", float3(-OnesVector));
	piece->axisMapType = AxisMappingType(pieceTable.GetInt("rotAxisMap", AXIS_MAPPING_XYZ));

	// construct 'baked' part of the piece-space matrix
	// AssImp order is translate * rotate * scale * v;
	// we leave the translation and scale parts out and
	// put those in <offset> and <scales> --> transform
	// is just R instead of T * R * S
	//
	// note: for all non-AssImp models this is identity!
	//
	piece->ComposeRotation(bakedMatrix, pieceRotAngles);
	piece->SetModelMatrix(bakedMatrix);
}

void CAssParser::SetPieceName(
	SAssPiece* piece,
	const S3DModel* model,
	const aiNode* pieceNode,
	ModelPieceMap& pieceMap
) {
	assert(piece->name.empty());
	piece->name = std::string(pieceNode->mName.data);

	if (piece->name.empty()) {
		if (piece == model->GetRootPiece()) {
			// root is always the first piece created, so safe to assign this
			piece->name = "$$root$$";
			return;
		} else {
			piece->name = "$$piece$$";
		}
	}

	// find a new name if none given or if a piece with the same name already exists
	ModelPieceMap::const_iterator it = pieceMap.find(piece->name);

	for (unsigned int i = 0; it != pieceMap.end(); i++) {
		const std::string newPieceName = piece->name + IntToString(i, "%02i");

		if ((it = pieceMap.find(newPieceName)) == pieceMap.end()) {
			piece->name = newPieceName; break;
		}
	}

	assert(piece->name != "SpringHeight");
	assert(piece->name != "SpringRadius");
}

void CAssParser::SetPieceParentName(
	SAssPiece* piece,
	const S3DModel* model,
	const aiNode* pieceNode,
	const LuaTable& pieceTable,
	ParentNameMap& parentMap
) {
	// Get parent name from metadata or model
	if (pieceTable.KeyExists("parent")) {
		parentMap[piece] = pieceTable.GetString("parent", "");
		return;
	}

	if (pieceNode->mParent == nullptr)
		return;

	if (pieceNode->mParent->mParent != nullptr) {
		// parent is not the root
		parentMap[piece] = std::string(pieceNode->mParent->mName.data);
	} else {
		// parent is the root (which must already exist)
		assert(model->GetRootPiece() != nullptr);
		parentMap[piece] = (model->GetRootPiece())->name;
	}
}

void CAssParser::LoadPieceGeometry(SAssPiece* piece, const aiNode* pieceNode, const aiScene* scene)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SAssPiece* CAssParser::LoadPiece(
	S3DModel* model,
	const aiNode* pieceNode,
	const aiScene* scene,
	const LuaTable& modelTable,
	ModelPieceMap& pieceMap,
	ParentNameMap& parentMap
) {
	++model->numPieces;

	SAssPiece* piece = new SAssPiece();

	if (pieceNode->mParent == nullptr) {
		// set the model's root piece ASAP, needed later
		assert(pieceNode == scene->mRootNode);
		assert(model->GetRootPiece() == nullptr);
		model->SetRootPiece(piece);
	}

	SetPieceName(piece, model, pieceNode, pieceMap);

	LOG_SL(LOG_SECTION_PIECE, L_INFO, "Converting node '%s' to piece '%s' (%d meshes).", pieceNode->mName.data, piece->name.c_str(), pieceNode->mNumMeshes);

	// Load additional piece properties from metadata
	const LuaTable& pieceTable = modelTable.SubTable("pieces").SubTable(piece->name);

	if (pieceTable.IsValid()) {
		LOG_SL(LOG_SECTION_PIECE, L_INFO, "Found metadata for piece '%s'", piece->name.c_str());
	}


	LoadPieceTransformations(piece, model, pieceNode, pieceTable);
	LoadPieceGeometry(piece, pieceNode, scene);
	SetPieceParentName(piece, model, pieceNode, pieceTable, parentMap);

	{
		// operator[] creates an empty string if piece is not in map
		const auto parentNameIt = parentMap.find(piece);
		const std::string& parentName = (parentNameIt != parentMap.end())? (parentNameIt->second).c_str(): "[null]";

		// Verbose logging of piece properties
		LOG_SL(LOG_SECTION_PIECE, L_INFO, "Loaded model piece: %s with %d meshes", piece->name.c_str(), pieceNode->mNumMeshes);
		LOG_SL(LOG_SECTION_PIECE, L_INFO, "piece->name: %s", piece->name.c_str());
		LOG_SL(LOG_SECTION_PIECE, L_INFO, "piece->parent: %s", parentName.c_str());
	}

	// Recursively process all child pieces
	for (unsigned int i = 0; i < pieceNode->mNumChildren; ++i) {
		LoadPiece(model, pieceNode->mChildren[i], scene, modelTable, pieceMap, parentMap);
	}

	pieceMap[piece->name] = piece;
	return piece;
}


// Because of metadata overrides we don't know the true hierarchy until all pieces have been loaded
void CAssParser::BuildPieceHierarchy(S3DModel* model, ModelPieceMap& pieceMap, const ParentNameMap& parentMap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// Iterate over the model and calculate its overall dimensions
void CAssParser::CalculateModelDimensions(S3DModel* model, S3DModelPiece* piece)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Calculate model radius from the min/max extents
void CAssParser::CalculateModelProperties(S3DModel* model, const LuaTable& modelTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static std::string FindTexture(std::string testTextureFile, const std::string& modelPath, const std::string& fallback)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static std::string FindTextureByRegex(const std::string& regex_path, const std::string& regex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CAssParser::FindTextures(
	S3DModel* model,
	const aiScene* scene,
	const LuaTable& modelTable,
	const std::string& modelPath,
	const std::string& modelName
) {
	// 1. try to find by name (lowest priority)
	model->texs[0] = FindTextureByRegex("unittextures/", modelName);

	if (model->texs[0].empty()) model->texs[0] = FindTextureByRegex("unittextures/", modelName + "1");
	if (model->texs[1].empty()) model->texs[1] = FindTextureByRegex("unittextures/", modelName + "2");
	if (model->texs[0].empty()) model->texs[0] = FindTextureByRegex(modelPath, "tex1");
	if (model->texs[1].empty()) model->texs[1] = FindTextureByRegex(modelPath, "tex2");
	if (model->texs[0].empty()) model->texs[0] = FindTextureByRegex(modelPath, "diffuse");
	if (model->texs[1].empty()) model->texs[1] = FindTextureByRegex(modelPath, "glow"); // lowest-priority name


	// 2. gather model-defined textures of first material (medium priority)
	if (scene->mNumMaterials > 0) {
		constexpr unsigned int texTypes[] = {
			aiTextureType_SPECULAR,
			aiTextureType_UNKNOWN,
			aiTextureType_DIFFUSE,
			/*
			// TODO: support these too (we need to allow constructing tex1 & tex2 from several sources)
			aiTextureType_EMISSIVE,
			aiTextureType_HEIGHT,
			aiTextureType_NORMALS,
			aiTextureType_SHININESS,
			aiTextureType_OPACITY,
			*/
		};
		for (unsigned int texType: texTypes) {
			aiString textureFile;
			if (scene->mMaterials[0]->Get(AI_MATKEY_TEXTURE(texType, 0), textureFile) != aiReturn_SUCCESS)
				continue;

			assert(textureFile.length > 0);
			model->texs[0] = FindTexture(textureFile.data, modelPath, model->texs[0]);
		}
	}

	// 3. try to load from metafile (highest priority)
	model->texs[0] = FindTexture(modelTable.GetString("tex1", ""), modelPath, model->texs[0]);
	model->texs[1] = FindTexture(modelTable.GetString("tex2", ""), modelPath, model->texs[1]);
}


void SAssPiece::UploadGeometryVBOs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void SAssPiece::BindVertexAttribVBOs() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void SAssPiece::UnbindVertexAttribVBOs() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void SAssPiece::DrawForList() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

