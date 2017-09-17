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
#define LOG_VAR(data, fmt, ...) \
	LOG_L(L_ERROR, "%s:%d: " fmt, data->GetDeclarationFile().Get().c_str(), data->GetDeclarationLine().Get(), ## __VA_ARGS__) \


DefType::~DefType() {
	for (const DefTagMetaData* md: tags)
		delete md;
}

std::vector<const DefType*>& DefType::GetTypes()
{
    //stub method
}


DefType::DefType(const std::string& n) : name(n), luaTable(NULL) {
	GetTypes().push_back(this);
}


void DefType::AddMetaData(const DefTagMetaData* data)
{
    //stub method
}


const DefTagMetaData* DefType::GetMetaDataByInternalKey(const string& key)
{
    //stub method
}


const DefTagMetaData* DefType::GetMetaDataByExternalKey(const string& key)
{
    //stub method
}


std::string DefTagMetaData::GetTypeName(const std::type_info& typeInfo)
{
    //stub method
}


/**
 * @brief Call Quote if type is not bool, float or int.
 */
static inline string Quote(const string& type, const string& value)
{
    //stub method
}


/**
 * @brief Write a DefTagMetaData to a stream.
 */
static std::ostream& operator<< (std::ostream& out, const DefTagMetaData* d)
{
    //stub method
}

/**
 * @brief Output config variable meta data as JSON to stdout.
 *
 * This can be tested using, for example:
 *
 *	./spring --list-def-tags |
 *		python -c 'import json, sys; json.dump(json.load(sys.stdin), sys.stdout)'
 */
void DefType::OutputMetaDataMap() const
{
    //stub method
}

void DefType::OutputTagMap()
{
    //stub method
}


void DefType::CheckType(const DefTagMetaData* meta, const std::type_info& want)
{
    //stub method
}


void DefType::ReportUnknownTags(const std::string& instanceName, const LuaTable& luaTable, const std::string pre)
{
    //stub method
}


void DefType::Load(void* instance, const LuaTable& luaTable)
{
    //stub method
}
