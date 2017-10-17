#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

// Used for all metal-extractors.
// Handles the metal-make-process.

#include "ExtractorBuilding.h"
#include "Map/MetalMap.h"
#include "Map/ReadMap.h"
#include "Sim/Misc/QuadField.h"
#include "Sim/Units/Scripts/UnitScript.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitHandler.h"
#include "System/Sync/SyncTracer.h"
#include "System/creg/STL_List.h"
#include "System/myMath.h"
#include <typeinfo>

CR_BIND_DERIVED(CExtractorBuilding, CBuilding, )

CR_REG_METADATA(CExtractorBuilding,
                (CR_MEMBER(extractionRange),
                 CR_MEMBER(extractionDepth),
                 CR_MEMBER(metalAreaOfControl),
                 CR_MEMBER(neighbours)))

CR_BIND(CExtractorBuilding::MetalSquareOfControl, )

CR_REG_METADATA_SUB(CExtractorBuilding,
                    MetalSquareOfControl,
                    (CR_MEMBER(x), CR_MEMBER(z), CR_MEMBER(extractionDepth)))

// TODO: How are class statics incorporated into creg?
float CExtractorBuilding::maxExtractionRange = 0.0f;

CExtractorBuilding::CExtractorBuilding()
  : extractionRange(0.0f)
  , extractionDepth(0.0f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* resets the metalMap and notifies the neighbours */
void
CExtractorBuilding::ResetExtraction()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* determine if two extraction areas overlap */
bool
CExtractorBuilding::IsNeighbour(CExtractorBuilding* other)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* sets the range of extraction for this extractor, also finds overlapping
 * neighbours. */
void
CExtractorBuilding::SetExtractionRangeAndDepth(float range, float depth)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* adds a neighbour for this extractor */
void
CExtractorBuilding::AddNeighbour(CExtractorBuilding* neighboor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* removes a neighboor for this extractor */
void
CExtractorBuilding::RemoveNeighbour(CExtractorBuilding* neighboor)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* recalculate metalExtract for this extractor (eg. when a neighbour dies) */
void
CExtractorBuilding::ReCalculateMetalExtraction()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/* Finds the amount of metal to extract and sets the rotationspeed when the
 * extractor is built. */
void
CExtractorBuilding::FinishedBuilding(bool postInit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
