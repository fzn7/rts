#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <mutex>
#include "IModelParser.h"
#include "3DModel.h"
#include "3DModelLog.h"
#include "3DOParser.h"
#include "S3OParser.h"
#include "OBJParser.h"
#include "AssParser.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include "System/Exceptions.h"
#include "System/maindefines.h"
#include "System/ThreadPool.h"
#include "lib/assimp/include/assimp/Importer.hpp"


static void RegisterAssimpModelFormats(CModelLoader::FormatMap& formats) {
	std::set<std::string> whitelist;
	std::string extension;
	std::string extensions;
	std::string enabledExtensions;

	whitelist.insert("3ds"  ); // 3DSMax
	whitelist.insert("dae"  ); // Collada
	whitelist.insert("lwo"  ); // LightWave
	whitelist.insert("blend"); // Blender

	Assimp::Importer importer;
	// get a ";" separated list of format extensions ("*.3ds;*.lwo;*.mesh.xml;...")
	importer.GetExtensionList(extensions);

	// do not ignore the last extension
	extensions += ";";

	size_t curIdx = 0;
	size_t nxtIdx = 0;

	// split the list, strip off the "*." extension prefixes
	while ((nxtIdx = extensions.find(";", curIdx)) != std::string::npos) {
		extension = extensions.substr(curIdx, nxtIdx - curIdx);
		extension = extension.substr(extension.find("*.") + 2);
		extension = StringToLower(extension);

		curIdx = nxtIdx + 1;

		if (whitelist.find(extension) == whitelist.end())
			continue;
		if (formats.find(extension) != formats.end())
			continue;

		formats[extension] = MODELTYPE_ASS;
		enabledExtensions += "*." + extension + ";";
	}

	LOG("[%s] supported Assimp model formats: %s", __FUNCTION__, enabledExtensions.c_str());
}

static S3DModel* CreateDummyModel()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void CheckPieceNormals(const S3DModel* model, const S3DModelPiece* modelPiece)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CModelLoader::Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CModelLoader::Kill()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CModelLoader::KillModels()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CModelLoader::KillParsers()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CModelLoader& CModelLoader::GetInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



std::string CModelLoader::FindModelPath(std::string name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CModelLoader::PreloadModel(const std::string& modelName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


S3DModel* CModelLoader::LoadModel(std::string name, bool preload)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

S3DModel* CModelLoader::LoadCachedModel(const std::string& name, bool preload)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



S3DModel* CModelLoader::CreateModel(
	const std::string& name,
	const std::string& path,
	bool preload
) {
	S3DModel* model = ParseModel(name, path);

	if (model == nullptr)
		model = CreateDummyModel();

	assert(model->GetRootPiece() != nullptr);

	if (!preload)
		CreateLists(model);

	AddModelToCache(model, name, path);
	return model;
}



IModelParser* CModelLoader::GetFormatParser(const std::string& pathExt)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

S3DModel* CModelLoader::ParseModel(const std::string& name, const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void CModelLoader::AddModelToCache(
	S3DModel* model,
	const std::string& name,
	const std::string& path
) {
	model->id = models.size(); // IDs start at 1
	models.push_back(model);

	assert(models[model->id] == model);

	cache[name] = model->id;
	cache[path] = model->id;
}



void CModelLoader::CreateListsNow(S3DModelPiece* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CModelLoader::CreateLists(S3DModel* model) {
	S3DModelPiece* rootPiece = model->GetRootPiece();

	if (rootPiece->GetDisplayListID() != 0)
		return;

	CreateListsNow(rootPiece);

	if (model->type == MODELTYPE_3DO)
		return;

	// make sure textures (already preloaded) are fully loaded
	texturehandlerS3O->LoadTexture(model);

	// warn about models with bad normals (they break lighting)
	// skip for 3DO's since they are auto-calculated there
	CheckPieceNormals(model, model->GetRootPiece());
}

/******************************************************************************/
/******************************************************************************/
