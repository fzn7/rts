#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "AIInterfaceLibraryInfo.h"

#include "AIInterfaceKey.h"
#include "Interface/SAIInterfaceLibrary.h"
#include "Interface/aidefines.h"
#include "System/Info.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include "System/FileSystem/VFSModes.h"

static const char* BAD_CHARS = "\t _#";
static const std::string DEFAULT_VALUE = "";

CAIInterfaceLibraryInfo::CAIInterfaceLibraryInfo(
  const CAIInterfaceLibraryInfo& interfaceInfo)
  : keys(interfaceInfo.keys)
  , keyLower_key(interfaceInfo.keyLower_key)
  , key_value(interfaceInfo.key_value)
  , key_description(interfaceInfo.key_description)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CAIInterfaceLibraryInfo::~CAIInterfaceLibraryInfo() {}

size_t
CAIInterfaceLibraryInfo::size() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetKeyAt(size_t index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetValueAt(size_t index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetDescriptionAt(size_t index) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

AIInterfaceKey
CAIInterfaceLibraryInfo::GetKey() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const std::string&
CAIInterfaceLibraryInfo::GetDataDir() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetDataDirCommon() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetShortName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetVersion() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetName() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetDescription() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetURL() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CAIInterfaceLibraryInfo::IsLookupSupported() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
const std::string&
CAIInterfaceLibraryInfo::GetInfo(const std::string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CAIInterfaceLibraryInfo::SetDataDir(const std::string& dataDir)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CAIInterfaceLibraryInfo::SetDataDirCommon(const std::string& dataDirCommon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CAIInterfaceLibraryInfo::SetShortName(const std::string& shortName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CAIInterfaceLibraryInfo::SetVersion(const std::string& version)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CAIInterfaceLibraryInfo::SetName(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CAIInterfaceLibraryInfo::SetDescription(const std::string& description)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void
CAIInterfaceLibraryInfo::SetURL(const std::string& url)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
bool
CAIInterfaceLibraryInfo::SetInfo(const std::string& key,
                                 const std::string& value,
                                 const std::string& description)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
