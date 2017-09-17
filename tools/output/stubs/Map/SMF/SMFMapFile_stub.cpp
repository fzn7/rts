#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "SMFMapFile.h"
#include "Map/ReadMap.h"
#include "System/Exceptions.h"
#include "System/Platform/byteorder.h"

#include <cassert>
#include <cstring>

using std::string;


CSMFMapFile::CSMFMapFile(const string& mapFileName)
	: ifs(mapFileName), featureFileOffset(0)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CSMFMapFile::ReadMinimap(void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CSMFMapFile::ReadMinimap(std::vector<boost::uint8_t>& data, unsigned miplevel)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


// used only by ReadInfoMap (for unitsync)
void CSMFMapFile::ReadHeightmap(unsigned short* heightmap)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSMFMapFile::ReadHeightmap(float* sHeightMap, float* uHeightMap, float base, float mod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSMFMapFile::ReadFeatureInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSMFMapFile::ReadFeatureInfo(MapFeatureInfo* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const char* CSMFMapFile::GetFeatureTypeName(int typeID) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CSMFMapFile::GetInfoMapSize(const string& name, MapBitmapInfo* info) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSMFMapFile::ReadInfoMap(const string& name, void* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CSMFMapFile::ReadGrassMap(void *data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// read a float from file (endian aware)
static float ReadFloat(CFileHandler& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// read an int from file (endian aware)
static int ReadInt(CFileHandler& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// Read SMFHeader head from file
void CSMFMapFile::ReadMapHeader(SMFHeader& head, CFileHandler& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// Read MapFeatureHeader head from file
void CSMFMapFile::ReadMapFeatureHeader(MapFeatureHeader& head, CFileHandler& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// Read MapFeatureStruct head from file
void CSMFMapFile::ReadMapFeatureStruct(MapFeatureStruct& head, CFileHandler& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// Read MapTileHeader head from file
void CSMFMapFile::ReadMapTileHeader(MapTileHeader& head, CFileHandler& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/// Read TileFileHeader head from file src
void CSMFMapFile::ReadMapTileFileHeader(TileFileHeader& head, CFileHandler& file)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

