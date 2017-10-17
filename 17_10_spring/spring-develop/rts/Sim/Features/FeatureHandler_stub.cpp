#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FeatureHandler.h"

#include "FeatureDef.h"
#include "FeatureDefHandler.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Units/CommandAI/BuilderCAI.h"
#include "System/EventHandler.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"
#include "System/creg/STL_Set.h"

CFeatureHandler* featureHandler = NULL;

/******************************************************************************/

CR_BIND(CFeatureHandler, )
CR_REG_METADATA(CFeatureHandler,
                (CR_MEMBER(idPool),
                 CR_MEMBER(toBeFreedFeatureIDs),
                 CR_MEMBER(activeFeatures),
                 CR_MEMBER(features),
                 CR_MEMBER(updateFeatures)))

/******************************************************************************/

CFeatureHandler::~CFeatureHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeatureHandler::LoadFeaturesFromMap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CFeature*
CFeatureHandler::LoadFeature(const FeatureLoadParams& params)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeatureHandler::NeedAllocateNewFeatureIDs(const CFeature* feature) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeatureHandler::AllocateNewFeatureIDs(const CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeatureHandler::InsertActiveFeature(CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeatureHandler::AddFeature(CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeatureHandler::DeleteFeature(CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CFeature*
CFeatureHandler::GetFeature(int id)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CFeature*
CFeatureHandler::CreateWreckage(const FeatureLoadParams& cparams,
                                const int numWreckLevels,
                                bool emitSmoke)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeatureHandler::Update()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeatureHandler::TryFreeFeatureID(int id)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CFeatureHandler::UpdateFeature(CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeatureHandler::SetFeatureUpdateable(CFeature* feature)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CFeatureHandler::TerrainChanged(int x1, int y1, int x2, int y2)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
