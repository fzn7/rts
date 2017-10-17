#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "MapGenerator.h"
#include "Game/LoadScreen.h"
#include "Map/SMF/SMFFormat.h"
#include "Rendering/GL/myGL.h"
#include "System/Exceptions.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/Archives/VirtualArchive.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/VFSHandler.h"

#include <boost/algorithm/string.hpp>
#include <fstream>

CMapGenerator::CMapGenerator(const CGameSetup* setup)
  : setup(setup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMapGenerator::AppendToBuffer(CVirtualFile* file, const void* data, int size)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMapGenerator::SetToBuffer(CVirtualFile* file,
                           const void* data,
                           int size,
                           int position)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMapGenerator::GenerateSMF(CVirtualArchive* archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMapGenerator::GenerateMapInfo(CVirtualArchive* archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CMapGenerator::GenerateSMT(CVirtualArchive* archive)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
