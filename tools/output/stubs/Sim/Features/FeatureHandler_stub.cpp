/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "FeatureHandler.h"

#include "FeatureDef.h"
#include "FeatureDefHandler.h"
#include "Map/Ground.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Units/CommandAI/BuilderCAI.h"
#include "System/creg/STL_Set.h"
#include "System/EventHandler.h"
#include "System/TimeProfiler.h"
#include "System/Util.h"

CFeatureHandler* featureHandler = NULL;

/******************************************************************************/

CR_BIND(CFeatureHandler, )
CR_REG_METADATA(CFeatureHandler, (
	CR_MEMBER(idPool),
	CR_MEMBER(toBeFreedFeatureIDs),
	CR_MEMBER(activeFeatures),
	CR_MEMBER(features),
	CR_MEMBER(updateFeatures)
))

/******************************************************************************/

CFeatureHandler::~CFeatureHandler()
{
    //stub method
}


void CFeatureHandler::LoadFeaturesFromMap()
{
    //stub method
}


CFeature* CFeatureHandler::LoadFeature(const FeatureLoadParams& params) {
	// need to check this BEFORE creating the instance
	if (!CanAddFeature(params.featureID))
		return nullptr;

	// Initialize() calls AddFeature -> no memory-leak
	CFeature* feature = new CFeature();
	feature->Initialize(params);
	return feature;
}


bool CFeatureHandler::NeedAllocateNewFeatureIDs(const CFeature* feature) const
{
    //stub method
}

void CFeatureHandler::AllocateNewFeatureIDs(const CFeature* feature)
{
    //stub method
}

void CFeatureHandler::InsertActiveFeature(CFeature* feature)
{
    //stub method
}



bool CFeatureHandler::AddFeature(CFeature* feature)
{
    //stub method
}


void CFeatureHandler::DeleteFeature(CFeature* feature)
{
    //stub method
}

CFeature* CFeatureHandler::GetFeature(int id)
{
    //stub method
}


CFeature* CFeatureHandler::CreateWreckage(
	const FeatureLoadParams& cparams,
	const int numWreckLevels,
	bool emitSmoke)
{
    //stub method
}



void CFeatureHandler::Update()
{
    //stub method
}


bool CFeatureHandler::TryFreeFeatureID(int id)
{
    //stub method
}


bool CFeatureHandler::UpdateFeature(CFeature* feature)
{
    //stub method
}


void CFeatureHandler::SetFeatureUpdateable(CFeature* feature)
{
    //stub method
}


void CFeatureHandler::TerrainChanged(int x1, int y1, int x2, int y2)
{
    //stub method
}

