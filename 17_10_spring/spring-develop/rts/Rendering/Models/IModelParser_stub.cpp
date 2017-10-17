#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IModelParser.h"
#include "3DModel.h"
#include "3DModelLog.h"
#include "3DOParser.h"
#include "AssParser.h"
#include "OBJParser.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "S3OParser.h"
#include "Sim/Misc/CollisionVolume.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/ThreadPool.h"
#include "System/Util.h"
#include "System/maindefines.h"
#include "lib/assimp/include/assimp/Importer.hpp"
#include <mutex>

static void
RegisterAssimpModelFormats(CModelLoader::FormatMap& formats)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static S3DModel*
CreateDummyModel()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

static void
CheckPieceNormals(const S3DModel* model, const S3DModelPiece* modelPiece)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModelLoader::Init()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModelLoader::Kill()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModelLoader::KillModels()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModelLoader::KillParsers()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CModelLoader&
CModelLoader::GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
CModelLoader::FindModelPath(std::string name) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModelLoader::PreloadModel(const std::string& modelName)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

S3DModel*
CModelLoader::LoadModel(std::string name, bool preload)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

S3DModel*
CModelLoader::LoadCachedModel(const std::string& name, bool preload)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

S3DModel*
CModelLoader::CreateModel(const std::string& name,
                          const std::string& path,
                          bool preload)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

IModelParser*
CModelLoader::GetFormatParser(const std::string& pathExt)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

S3DModel*
CModelLoader::ParseModel(const std::string& name, const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModelLoader::AddModelToCache(S3DModel* model,
                              const std::string& name,
                              const std::string& path)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModelLoader::CreateListsNow(S3DModelPiece* o)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CModelLoader::CreateLists(S3DModel* model)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
