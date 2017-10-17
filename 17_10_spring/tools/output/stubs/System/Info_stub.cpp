#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Info.h"

#include "Lua/LuaParser.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#include <assert.h>

static const char* InfoItem_badKeyChars = " =;\r\n\t";

std::string
InfoItem::GetValueAsString(const bool convBooltoInt) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
info_convertToStringValue(InfoItem* infoItem)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const char*
info_convertTypeToString(InfoValueType infoValueType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
info_parseInfoItem(const LuaTable& root,
                   int index,
                   InfoItem& inf,
                   std::set<string>& infoSet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
info_parseInfo(std::vector<InfoItem>& info,
               const std::string& fileName,
               const std::string& fileModes,
               const std::string& accessModes,
               std::set<std::string>* infoSet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<InfoItem>
info_parseInfo(const std::string& fileName,
               const std::string& fileModes,
               const std::string& accessModes,
               std::set<std::string>* infoSet)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
