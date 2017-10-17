#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AIInterfaceKey.h"

#include "System/creg/creg_cond.h"
#include <string>

CR_BIND(AIInterfaceKey, )

CR_REG_METADATA(AIInterfaceKey, (CR_MEMBER(shortName), CR_MEMBER(version)))


AIInterfaceKey::AIInterfaceKey(const AIInterfaceKey& toCopy)
		: shortName(toCopy.shortName),
		version(toCopy.version) {}

AIInterfaceKey::~AIInterfaceKey() {}

AIInterfaceKey::AIInterfaceKey(const std::string& shortName,
                               const std::string& version)
  : shortName(shortName)
  , version(version)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
AIInterfaceKey::isLessThen(const AIInterfaceKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const std::string&
AIInterfaceKey::GetShortName() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
const std::string&
AIInterfaceKey::GetVersion() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
AIInterfaceKey::IsUnspecified() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
AIInterfaceKey::ToString() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

bool
AIInterfaceKey::operator==(const AIInterfaceKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
AIInterfaceKey::operator!=(const AIInterfaceKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
AIInterfaceKey::operator<(const AIInterfaceKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
AIInterfaceKey::operator>(const AIInterfaceKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
AIInterfaceKey::operator<=(const AIInterfaceKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
bool
AIInterfaceKey::operator>=(const AIInterfaceKey& otherKey) const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
