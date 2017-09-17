#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CommandDescription.h"

#include "System/Sync/HsiehHash.h"
#include <cassert>

CR_BIND(SCommandDescription, )
CR_REG_METADATA(SCommandDescription,
                (CR_MEMBER(id),
                 CR_MEMBER(type),

                 CR_MEMBER(name),
                 CR_MEMBER(action),
                 CR_MEMBER(iconname),
                 CR_MEMBER(mouseicon),
                 CR_MEMBER(tooltip),

                 CR_MEMBER(queueing),
                 CR_MEMBER(hidden),
                 CR_MEMBER(disabled),
                 CR_MEMBER(showUnique),
                 CR_MEMBER(onlyTexture),
                 CR_MEMBER(params),
                 CR_MEMBER(refCount)))

bool
SCommandDescription::operator!=(const SCommandDescription& cd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CCommandDescriptionCache* commandDescriptionCache = nullptr;

CR_BIND(CCommandDescriptionCache, )
CR_REG_METADATA(CCommandDescriptionCache, (CR_MEMBER(cache)))

int
CCommandDescriptionCache::CalcHash(const SCommandDescription& cd) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const SCommandDescription*
CCommandDescriptionCache::GetPtr(const SCommandDescription& cd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCommandDescriptionCache::DecRef(const SCommandDescription& cd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CCommandDescriptionCache::DecRef(
  std::vector<const SCommandDescription*>& cmdDescs)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
