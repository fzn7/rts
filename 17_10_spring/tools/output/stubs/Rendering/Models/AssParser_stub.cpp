#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AssParser.h"
#include "3DModel.h"
#include "3DModelLog.h"
#include "AssIO.h"

#include "Lua/LuaParser.h"
#include "Sim/Misc/CollisionVolume.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Platform/errorhandler.h"
#include "System/ScopedFPUSettings.h"
#include "System/Util.h"

#include "Rendering/Textures/S3OTextureHandler.h"
#include "lib/assimp/include/assimp/DefaultLogger.hpp"
#include "lib/assimp/include/assimp/Importer.hpp"
#include "lib/assimp/include/assimp/config.h"
#include "lib/assimp/include/assimp/defs.h"
#include "lib/assimp/include/assimp/postprocess.h"
#include "lib/assimp/include/assimp/scene.h"
#include "lib/assimp/include/assimp/types.h"
#ifndef BITMAP_NO_OPENGL
#include "Rendering/GL/myGL.h"
#endif

#define IS_QNAN(f) (f != f)
static const float DEGTORAD = PI / 180.0f;
static const float RADTODEG = 180.0f / PI;

// triangulate guarantees the most complex mesh is a triangle
// sortbytype ensure only 1 type of primitive type per mesh is used
static const unsigned int ASS_POSTPROCESS_OPTIONS =
  aiProcess_RemoveComponent | aiProcess_FindInvalidData |
  aiProcess_CalcTangentSpace | aiProcess_GenSmoothNormals |
  aiProcess_Triangulate | aiProcess_GenUVCoords | aiProcess_SortByPType |
  aiProcess_JoinIdenticalVertices
  //| aiProcess_ImproveCacheLocality // FIXME crashes in an assert in
  //VertexTriangleAdjancency.h (date 04/2011)
  | aiProcess_SplitLargeMeshes;

static const unsigned int ASS_IMPORTER_OPTIONS =
  aiComponent_CAMERAS | aiComponent_LIGHTS | aiComponent_TEXTURES |
  aiComponent_ANIMATIONS;
static const unsigned int ASS_LOGGING_OPTIONS =
  Assimp::Logger::Debugging | Assimp::Logger::Info | Assimp::Logger::Err |
  Assimp::Logger::Warn;

static inline float3
aiVectorToFloat3(const aiVector3D v)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline CMatrix44f
aiMatrixToMatrix(const aiMatrix4x4t<float>& m)
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

S3DModel*
CAssParser::Load(const std::string& modelFilePath)
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

void
CAssParser::LoadPieceTransformations(SAssPiece* piece,
                                     const S3DModel* model,
                                     const aiNode* pieceNode,
                                     const LuaTable& pieceTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAssParser::SetPieceName(SAssPiece* piece,
                         const S3DModel* model,
                         const aiNode* pieceNode,
                         ModelPieceMap& pieceMap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAssParser::SetPieceParentName(SAssPiece* piece,
                               const S3DModel* model,
                               const aiNode* pieceNode,
                               const LuaTable& pieceTable,
                               ParentNameMap& parentMap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAssParser::LoadPieceGeometry(SAssPiece* piece,
                              const aiNode* pieceNode,
                              const aiScene* scene)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SAssPiece*
CAssParser::LoadPiece(S3DModel* model,
                      const aiNode* pieceNode,
                      const aiScene* scene,
                      const LuaTable& modelTable,
                      ModelPieceMap& pieceMap,
                      ParentNameMap& parentMap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Because of metadata overrides we don't know the true hierarchy until all
// pieces have been loaded
void
CAssParser::BuildPieceHierarchy(S3DModel* model,
                                ModelPieceMap& pieceMap,
                                const ParentNameMap& parentMap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Iterate over the model and calculate its overall dimensions
void
CAssParser::CalculateModelDimensions(S3DModel* model, S3DModelPiece* piece)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Calculate model radius from the min/max extents
void
CAssParser::CalculateModelProperties(S3DModel* model,
                                     const LuaTable& modelTable)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::string
FindTexture(std::string testTextureFile,
            const std::string& modelPath,
            const std::string& fallback)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::string
FindTextureByRegex(const std::string& regex_path, const std::string& regex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAssParser::FindTextures(S3DModel* model,
                         const aiScene* scene,
                         const LuaTable& modelTable,
                         const std::string& modelPath,
                         const std::string& modelName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SAssPiece::UploadGeometryVBOs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SAssPiece::BindVertexAttribVBOs() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SAssPiece::UnbindVertexAttribVBOs() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SAssPiece::DrawForList() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
