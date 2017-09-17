/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ConfigVariable.h"
#include "System/Log/ILog.h"
#include "System/Util.h"
#include <iostream>

using std::cout;
using std::map;
using std::string;

/**
 * @brief Log an error about a ConfigVariableMetaData
 */
#define LOG_VAR(data, fmt, ...) \
	LOG_L(L_ERROR, "%s:%d: " fmt, data->GetDeclarationFile().Get().c_str(), data->GetDeclarationLine().Get(), ## __VA_ARGS__) \


ConfigVariable::MetaDataMap& ConfigVariable::GetMutableMetaDataMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const ConfigVariable::MetaDataMap& ConfigVariable::GetMetaDataMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void ConfigVariable::AddMetaData(const ConfigVariableMetaData* data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const ConfigVariableMetaData* ConfigVariable::GetMetaData(const string& key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

#ifdef DEBUG
CONFIG(std::string, test)
	.defaultValue("x y z")
	.description("\"quoted\", escaped: \\, \b, \f, \n, \r, \t");
#endif


/**
 * @brief Call Quote if type is not bool, float or int.
 */
static inline string Quote(const string& type, const string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Write a ConfigVariableMetaData to a stream.
 */
static std::ostream& operator<< (std::ostream& out, const ConfigVariableMetaData* d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Output config variable meta data as JSON to stdout.
 *
 * This can be tested using, for example:
 *
 *	./spring --list-config-vars |
 *		python -c 'import json, sys; json.dump(json.load(sys.stdin), sys.stdout)'
 */
void ConfigVariable::OutputMetaDataMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
