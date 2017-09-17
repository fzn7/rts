#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SkirmishAILibraryInfo.h"

#include "Interface/SSkirmishAILibrary.h"
#include "Interface/aidefines.h"
#include "SkirmishAIKey.h"
#include "System/Info.h"
#include "System/Log/ILog.h"
#include "System/Option.h"
#include "System/Util.h"

#include "System/FileSystem/VFSModes.h"

static const char* BAD_CHARS = "\t _#";
static const std::string DEFAULT_VALUE = "";

CSkirmishAILibraryInfo::CSkirmishAILibraryInfo(
  const CSkirmishAILibraryInfo& aiInfo)
  : info_keys(aiInfo.info_keys)
  , info_keyLower_key(aiInfo.info_keyLower_key)
  , info_key_value(aiInfo.info_key_value)
  , info_key_description(aiInfo.info_key_description)
  , options(aiInfo.options)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CSkirmishAILibraryInfo::CSkirmishAILibraryInfo(
  const std::map<std::string, std::string>& aiInfo,
  const std::string& aiOptionLua)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
CSkirmishAILibraryInfo::GetKeyAt(size_t index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
CSkirmishAILibraryInfo::GetValueAt(size_t index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
CSkirmishAILibraryInfo::GetDescriptionAt(size_t index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SkirmishAIKey
CSkirmishAILibraryInfo::GetKey() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
CSkirmishAILibraryInfo::GetDataDir() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CSkirmishAILibraryInfo::GetDataDirCommon() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CSkirmishAILibraryInfo::GetShortName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CSkirmishAILibraryInfo::GetVersion() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CSkirmishAILibraryInfo::GetName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CSkirmishAILibraryInfo::GetDescription() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CSkirmishAILibraryInfo::GetURL() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAILibraryInfo::IsLuaAI() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
CSkirmishAILibraryInfo::GetInterfaceShortName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CSkirmishAILibraryInfo::GetInterfaceVersion() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
CSkirmishAILibraryInfo::GetInfo(const std::string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAILibraryInfo::SetDataDir(const std::string& dataDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSkirmishAILibraryInfo::SetDataDirCommon(const std::string& dataDirCommon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSkirmishAILibraryInfo::SetShortName(const std::string& shortName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSkirmishAILibraryInfo::SetVersion(const std::string& version)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSkirmishAILibraryInfo::SetName(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSkirmishAILibraryInfo::SetDescription(const std::string& description)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSkirmishAILibraryInfo::SetURL(const std::string& url)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSkirmishAILibraryInfo::SetLuaAI(const std::string& isLua)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CSkirmishAILibraryInfo::SetLuaAI(const bool isLua)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAILibraryInfo::SetInterfaceShortName(
  const std::string& interfaceShortName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CSkirmishAILibraryInfo::SetInterfaceVersion(const std::string& interfaceVersion)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CSkirmishAILibraryInfo::SetInfo(const std::string& key,
                                const std::string& value,
                                const std::string& description)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
