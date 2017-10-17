/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DefinitionTag.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include <iostream>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif

using std::cout;

/**
 * @brief Log an error about a DefTagMetaData
 */
#define LOG_VAR(data, fmt, ...)                                                \
    LOG_L(L_ERROR,                                                             \
          "%s:%d: " fmt,                                                       \
          data->GetDeclarationFile().Get().c_str(),                            \
          data->GetDeclarationLine().Get(),                                    \
          ##__VA_ARGS__)

DefType::~DefType()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::vector<const DefType*>&
DefType::GetTypes()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

DefType::DefType(const std::string& n)
  : name(n)
  , luaTable(NULL)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DefType::AddMetaData(const DefTagMetaData* data)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const DefTagMetaData*
DefType::GetMetaDataByInternalKey(const string& key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const DefTagMetaData*
DefType::GetMetaDataByExternalKey(const string& key)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

std::string
DefTagMetaData::GetTypeName(const std::type_info& typeInfo)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Call Quote if type is not bool, float or int.
 */
static inline string
Quote(const string& type, const string& value)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Write a DefTagMetaData to a stream.
 */
static std::ostream&
operator<<(std::ostream& out, const DefTagMetaData* d)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/**
 * @brief Output config variable meta data as JSON to stdout.
 *
 * This can be tested using, for example:
 *
 *	./spring --list-def-tags |
 *		python -c 'import json, sys; json.dump(json.load(sys.stdin),
 *sys.stdout)'
 */
void
DefType::OutputMetaDataMap() const
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DefType::OutputTagMap()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DefType::CheckType(const DefTagMetaData* meta, const std::type_info& want)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DefType::ReportUnknownTags(const std::string& instanceName,
                           const LuaTable& luaTable,
                           const std::string pre)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
DefType::Load(void* instance, const LuaTable& luaTable)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
