/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FeatureDefHandler.h"

#include "FeatureDef.h"
#include "Lua/LuaParser.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/CollisionVolume.h"
#include "Sim/Objects/SolidObject.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

CFeatureDefHandler* featureDefHandler = NULL;

CFeatureDefHandler::CFeatureDefHandler(LuaParser* defsParser)
{
    //stub method
}

CFeatureDefHandler::~CFeatureDefHandler()
{
    //stub method
}


void CFeatureDefHandler::AddFeatureDef(const std::string& name, FeatureDef* fd, bool isDefaultFeature)
{
    //stub method
}

FeatureDef& CFeatureDefHandler::GetNewFeatureDef()
{
    //stub method
}


FeatureDef* CFeatureDefHandler::CreateFeatureDef(const LuaTable& fdTable, const std::string& mixedCase)
{
    //stub method
}


FeatureDef* CFeatureDefHandler::CreateDefaultTreeFeatureDef(const std::string& name)
{
    //stub method
}

FeatureDef* CFeatureDefHandler::CreateDefaultGeoFeatureDef(const std::string& name)
{
    //stub method
}


const FeatureDef* CFeatureDefHandler::GetFeatureDef(string name, const bool showError) const
{
    //stub method
}


void CFeatureDefHandler::LoadFeatureDefsFromMap()
{
    //stub method
}
