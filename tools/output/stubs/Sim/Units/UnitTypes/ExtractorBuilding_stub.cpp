/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

// Used for all metal-extractors.
// Handles the metal-make-process.

#include <typeinfo>
#include "ExtractorBuilding.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/UnitHandler.h"
#include "Map/ReadMap.h"
#include "Sim/Units/UnitDef.h"
#include "Map/MetalMap.h"
#include "Sim/Misc/QuadField.h"
#include "System/Sync/SyncTracer.h"
#include "System/creg/STL_List.h"
#include "System/myMath.h"

CR_BIND_DERIVED(CExtractorBuilding, CBuilding, )

CR_REG_METADATA(CExtractorBuilding, (
	CR_MEMBER(extractionRange),
	CR_MEMBER(extractionDepth),
	CR_MEMBER(metalAreaOfControl),
	CR_MEMBER(neighbours)
))

CR_BIND(CExtractorBuilding::MetalSquareOfControl, )

CR_REG_METADATA_SUB(CExtractorBuilding,MetalSquareOfControl, (
	CR_MEMBER(x),
	CR_MEMBER(z),
	CR_MEMBER(extractionDepth)
))

// TODO: How are class statics incorporated into creg?
float CExtractorBuilding::maxExtractionRange = 0.0f;

CExtractorBuilding::CExtractorBuilding():
	extractionRange(0.0f), extractionDepth(0.0f)
{
    //stub method
}

CExtractorBuilding::~CExtractorBuilding()
{
    //stub method
}

/* resets the metalMap and notifies the neighbours */
void CExtractorBuilding::ResetExtraction()
{
    //stub method
}



/* determine if two extraction areas overlap */
bool CExtractorBuilding::IsNeighbour(CExtractorBuilding* other)
{
    //stub method
}

/* sets the range of extraction for this extractor, also finds overlapping neighbours. */
void CExtractorBuilding::SetExtractionRangeAndDepth(float range, float depth)
{
    //stub method
}


/* adds a neighbour for this extractor */
void CExtractorBuilding::AddNeighbour(CExtractorBuilding* neighboor)
{
    //stub method
}


/* removes a neighboor for this extractor */
void CExtractorBuilding::RemoveNeighbour(CExtractorBuilding* neighboor)
{
    //stub method
}


/* recalculate metalExtract for this extractor (eg. when a neighbour dies) */
void CExtractorBuilding::ReCalculateMetalExtraction()
{
    //stub method
}


/* Finds the amount of metal to extract and sets the rotationspeed when the extractor is built. */
void CExtractorBuilding::FinishedBuilding(bool postInit)
{
    //stub method
}
