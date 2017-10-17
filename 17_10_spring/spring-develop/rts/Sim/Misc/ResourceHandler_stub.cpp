#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ResourceHandler.h"

#include "GlobalSynced.h" // for the map size
#include "Map/MapInfo.h"  // for the metal extractor radius
#include "Map/MetalMap.h"
#include "Map/ReadMap.h" // for the metal map
#include "ResourceMapAnalyzer.h"
#include <float.h>

CR_BIND(CResourceHandler, )
CR_REG_METADATA(CResourceHandler,
                (CR_MEMBER(resources),
                 CR_IGNORED(resourceMapAnalyzers),
                 CR_MEMBER(metalResourceId),
                 CR_MEMBER(energyResourceId),

                 CR_POSTLOAD(PostLoad)))

CResourceHandler* CResourceHandler::instance = NULL;

CResourceHandler*
CResourceHandler::GetInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CResourceHandler::CreateInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
void
CResourceHandler::FreeInstance()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CResourceHandler::CResourceHandler()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CResourceHandler::AddResource(const CResourceDescription& resource)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CResourceHandler::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const CResourceDescription*
CResourceHandler::GetResource(int resourceId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const CResourceDescription*
CResourceHandler::GetResourceByName(const std::string& resourceName) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CResourceHandler::GetResourceId(const std::string& resourceName) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const unsigned char*
CResourceHandler::GetResourceMap(int resourceId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

size_t
CResourceHandler::GetResourceMapSize(int resourceId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

size_t
CResourceHandler::GetResourceMapWidth(int resourceId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

size_t
CResourceHandler::GetResourceMapHeight(int resourceId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const CResourceMapAnalyzer*
CResourceHandler::GetResourceMapAnalyzer(int resourceId)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
CResourceHandler::IsValidId(int resourceId) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
