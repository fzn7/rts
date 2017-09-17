#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SkirmishAIKey.h"

#include "System/creg/creg_cond.h"
#include <string>

CR_BIND(SkirmishAIKey, )

CR_REG_METADATA(SkirmishAIKey,
                (CR_MEMBER(shortName),
                 CR_MEMBER(version),
                 CR_MEMBER(interface)))

SkirmishAIKey::SkirmishAIKey(const std::string& shortName,
                             const std::string& version,
                             const AIInterfaceKey& interface)
  : shortName(shortName)
  , version(version)
  , interface(interface)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
SkirmishAIKey::isLessThen(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
SkirmishAIKey::GetShortName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
SkirmishAIKey::GetVersion() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const AIInterfaceKey&
SkirmishAIKey::GetInterface() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
SkirmishAIKey::IsUnspecified() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
SkirmishAIKey::IsFullySpecified() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string
SkirmishAIKey::ToString() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
SkirmishAIKey::operator==(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
SkirmishAIKey::operator!=(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
SkirmishAIKey::operator<(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
SkirmishAIKey::operator>(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
SkirmishAIKey::operator<=(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
SkirmishAIKey::operator>=(const SkirmishAIKey& otherKey) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
