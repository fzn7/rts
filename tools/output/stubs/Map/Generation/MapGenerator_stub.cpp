/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MapGenerator.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Exceptions.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/Archives/VirtualArchive.h"
#include "Map/SMF/SMFFormat.h"
#include "Game/LoadScreen.h"
#include "Rendering/GL/myGL.h"

#include <boost/algorithm/string.hpp>
#include <fstream>

CMapGenerator::CMapGenerator(const CGameSetup* setup) : setup(setup)
{
    //stub method
}

CMapGenerator::~CMapGenerator()
{
    //stub method
}

void CMapGenerator::Generate()
{
    //stub method
}

void CMapGenerator::AppendToBuffer(CVirtualFile* file, const void* data, int size)
{
    //stub method
}

void CMapGenerator::SetToBuffer(CVirtualFile* file, const void* data, int size, int position)
{
    //stub method
}

void CMapGenerator::GenerateSMF(CVirtualArchive* archive)
{
    //stub method
}

void CMapGenerator::GenerateMapInfo(CVirtualArchive* archive)
{
    //stub method
}

void CMapGenerator::GenerateSMT(CVirtualArchive* archive)
{
    //stub method
}
