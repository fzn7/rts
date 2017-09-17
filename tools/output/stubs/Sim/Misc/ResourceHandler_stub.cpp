#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ResourceHandler.h"

#include "ResourceMapAnalyzer.h"
#include "Map/MapInfo.h" // for the metal extractor radius
#include "Map/ReadMap.h" // for the metal map
#include "Map/MetalMap.h"
#include "GlobalSynced.h" // for the map size
#include <float.h>


CR_BIND(CResourceHandler, )
CR_REG_METADATA(CResourceHandler, (
	CR_MEMBER(resources),
	CR_IGNORED(resourceMapAnalyzers),
	CR_MEMBER(metalResourceId),
	CR_MEMBER(energyResourceId),

	CR_POSTLOAD(PostLoad)
))


CResourceHandler* CResourceHandler::instance = NULL;

CResourceHandler* CResourceHandler::GetInstance() {
	assert(instance != NULL);
	return instance;
}

void CResourceHandler::CreateInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void CResourceHandler::FreeInstance()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CResourceHandler::CResourceHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int CResourceHandler::AddResource(const CResourceDescription& resource)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CResourceHandler::PostLoad()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CResourceDescription* CResourceHandler::GetResource(int resourceId) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CResourceDescription* CResourceHandler::GetResourceByName(const std::string& resourceName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CResourceHandler::GetResourceId(const std::string& resourceName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const unsigned char* CResourceHandler::GetResourceMap(int resourceId) const {
	if (resourceId == GetMetalId())
		return (readMap->metalMap->GetDistributionMap());

	return NULL;
}

size_t CResourceHandler::GetResourceMapSize(int resourceId) const {
	if (resourceId == GetMetalId())
		return (GetResourceMapWidth(resourceId) * GetResourceMapHeight(resourceId));

	return 0;
}

size_t CResourceHandler::GetResourceMapWidth(int resourceId) const {
	if (resourceId == GetMetalId())
		return mapDims.hmapx;

	return 0;
}

size_t CResourceHandler::GetResourceMapHeight(int resourceId) const {
	if (resourceId == GetMetalId())
		return mapDims.hmapy;

	return 0;
}

const CResourceMapAnalyzer* CResourceHandler::GetResourceMapAnalyzer(int resourceId) {

	if (!IsValidId(resourceId))
		return NULL;

	CResourceMapAnalyzer*& rma = resourceMapAnalyzers[resourceId];

	if (rma == nullptr)
		rma = new CResourceMapAnalyzer(resourceId);

	return rma;
}



bool CResourceHandler::IsValidId(int resourceId) const {
	return (resourceId >= 0) && (static_cast<size_t>(resourceId) < resources.size());
}

