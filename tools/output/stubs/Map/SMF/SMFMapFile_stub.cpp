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
}

void CSMFMapFile::ReadMinimap(void* data)
{
    //stub method
}

int CSMFMapFile::ReadMinimap(std::vector<boost::uint8_t>& data, unsigned miplevel)
{
    //stub method
}


// used only by ReadInfoMap (for unitsync)
void CSMFMapFile::ReadHeightmap(unsigned short* heightmap)
{
    //stub method
}


void CSMFMapFile::ReadHeightmap(float* sHeightMap, float* uHeightMap, float base, float mod)
{
    //stub method
}


void CSMFMapFile::ReadFeatureInfo()
{
    //stub method
}


void CSMFMapFile::ReadFeatureInfo(MapFeatureInfo* f)
{
    //stub method
}


const char* CSMFMapFile::GetFeatureTypeName(int typeID) const
{
    //stub method
}


void CSMFMapFile::GetInfoMapSize(const string& name, MapBitmapInfo* info) const
{
    //stub method
}


bool CSMFMapFile::ReadInfoMap(const string& name, void* data)
{
    //stub method
}


bool CSMFMapFile::ReadGrassMap(void *data)
{
    //stub method
}

/// read a float from file (endian aware)
static float ReadFloat(CFileHandler& file)
{
    //stub method
}

/// read an int from file (endian aware)
static int ReadInt(CFileHandler& file)
{
    //stub method
}

/// Read SMFHeader head from file
void CSMFMapFile::ReadMapHeader(SMFHeader& head, CFileHandler& file)
{
    //stub method
}

/// Read MapFeatureHeader head from file
void CSMFMapFile::ReadMapFeatureHeader(MapFeatureHeader& head, CFileHandler& file)
{
    //stub method
}

/// Read MapFeatureStruct head from file
void CSMFMapFile::ReadMapFeatureStruct(MapFeatureStruct& head, CFileHandler& file)
{
    //stub method
}

/// Read MapTileHeader head from file
void CSMFMapFile::ReadMapTileHeader(MapTileHeader& head, CFileHandler& file)
{
    //stub method
}

/// Read TileFileHeader head from file src
void CSMFMapFile::ReadMapTileFileHeader(TileFileHeader& head, CFileHandler& file)
{
    //stub method
}

