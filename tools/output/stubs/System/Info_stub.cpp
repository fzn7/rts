/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Info.h"

#include "System/Util.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "Lua/LuaParser.h"

#include <assert.h>

static const char* InfoItem_badKeyChars = " =;\r\n\t";

std::string InfoItem::GetValueAsString(const bool convBooltoInt) const {
	std::string stringValue = "";

	switch (valueType) {
		case INFO_VALUE_TYPE_STRING: {
			stringValue = valueTypeString;
		} break;
		case INFO_VALUE_TYPE_INTEGER: {
			stringValue = IntToString(value.typeInteger);
		} break;
		case INFO_VALUE_TYPE_FLOAT: {
			stringValue = FloatToString(value.typeFloat);
		} break;
		case INFO_VALUE_TYPE_BOOL: {
			if (convBooltoInt) {
				stringValue = IntToString((int)value.typeBool);
			} else {
				stringValue = (value.typeBool) ? "true" : "false";
			}
		} break;
		default: {
			stringValue = "unknown_error";
		}
	}

	return stringValue;
}

void info_convertToStringValue(InfoItem* infoItem) {

	assert(infoItem != NULL);

	infoItem->valueTypeString = infoItem->GetValueAsString();
	infoItem->valueType = INFO_VALUE_TYPE_STRING;
}

const char* info_convertTypeToString(InfoValueType infoValueType) {

	const char* typeString = NULL;

	switch (infoValueType) {
		case INFO_VALUE_TYPE_STRING: {
			typeString = "string";
		} break;
		case INFO_VALUE_TYPE_INTEGER: {
			typeString = "integer";
		} break;
		case INFO_VALUE_TYPE_FLOAT: {
			typeString = "float";
		} break;
		case INFO_VALUE_TYPE_BOOL: {
			typeString = "bool";
		} break;
	}

	return typeString;
}

static bool info_parseInfoItem(const LuaTable& root, int index, InfoItem& inf,
		std::set<string>& infoSet)
{
    //stub method
}


void info_parseInfo(
		std::vector<InfoItem>& info,
		const std::string& fileName,
		const std::string& fileModes,
		const std::string& accessModes,
		std::set<std::string>* infoSet)
{
    //stub method
}

std::vector<InfoItem> info_parseInfo(
		const std::string& fileName,
		const std::string& fileModes,
		const std::string& accessModes,
		std::set<std::string>* infoSet)
{
    //stub method
}
