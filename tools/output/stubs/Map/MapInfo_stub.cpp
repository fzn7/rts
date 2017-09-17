#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "MapInfo.h"

#include "Sim/Misc/GlobalConstants.h"
#include "Rendering/GlobalRendering.h"

#include "MapParser.h"
#include "Lua/LuaParser.h"
#include "System/Log/ILog.h"
#include "System/Exceptions.h"
#include "System/myMath.h"
#include "System/Util.h"
#include "System/FileSystem/FileHandler.h"

#if !defined(HEADLESS) && !defined(NO_SOUND)
#include "System/Sound/OpenAL/EFX.h"
#include "System/Sound/OpenAL/EFXPresets.h"
#endif

#include <cassert>
#include <cfloat>


// Before delete, the const is const_cast'ed away. There are
// no (other) situations where mapInfo may be modified, except
//   LuaUnsyncedCtrl may change water
//   LuaSyncedCtrl may change terrainTypes
const CMapInfo* mapInfo = NULL;


static void FIND_MAP_TEXTURE(std::string* filePath, const std::string& defaultDir = "maps/")
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



CMapInfo::CMapInfo(const std::string& mapInfoFile, const string& mapName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CMapInfo::~CMapInfo()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CMapInfo::GetStringValue(const std::string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMapInfo::ReadGlobal()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMapInfo::ReadGui()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMapInfo::ReadAtmosphere()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMapInfo::ReadSplats()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMapInfo::ReadGrass()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMapInfo::ReadLight()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMapInfo::ReadWater()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


template<typename T>
static bool ParseSplatDetailNormalTexture(const LuaTable& table, const T key, std::vector<std::string>& texNames)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMapInfo::ReadSMF()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMapInfo::ReadSM3()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CMapInfo::ReadTerrainTypes()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMapInfo::ReadPFSConstants()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CMapInfo::ReadSound()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
