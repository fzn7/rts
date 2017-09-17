/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "restrictions.h"

#include <map>
#include <string>

#include "System/Log/ILog.h"
#include "System/Config/ConfigHandler.h"

#define WILDCARD_HOST "*"
#define WILDCARD_PORT -1

#ifndef TEST
#define LOG_SECTION_LUASOCKET "LuaSocket"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_LUASOCKET)
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_LUASOCKET

CONFIG(std::string, TCPAllowConnect).defaultValue(WILDCARD_HOST).readOnly(true);
CONFIG(std::string, TCPAllowListen).defaultValue(WILDCARD_HOST).readOnly(true);
CONFIG(std::string, UDPAllowConnect).defaultValue("").readOnly(true);
CONFIG(std::string, UDPAllowListen).defaultValue(WILDCARD_HOST).readOnly(true);
#endif

CLuaSocketRestrictions* luaSocketRestrictions=0;

CLuaSocketRestrictions::CLuaSocketRestrictions()
{
    //stub method
}

void CLuaSocketRestrictions::addRule(RestrictType type, const std::string& hostname, int port, bool allowed)
{
    //stub method
}

void CLuaSocketRestrictions::addRule(RestrictType type, const std::string& rule)
{
    //stub method
}

void CLuaSocketRestrictions::addRules(RestrictType type, const std::string& configstr)
{
    //stub method
}

/*
bool isValidIpAddress(char *ipAddress)
{
    //stub method
}
*/

bool CLuaSocketRestrictions::isAllowed(RestrictType type, const char* hostname, int port) {
	const TSocketRule* rule = getRule(type, hostname, port);
	if (rule==NULL) {
		return false;
	}
	return rule->allowed;
}

const TSocketRule* CLuaSocketRestrictions::getRule(RestrictType type, const char* hostname, int port) {
{
    //stub method
}

void CLuaSocketRestrictions::addIP(const char* hostname, const char* ip)
{
    //stub method
}

const char* CLuaSocketRestrictions::ruleToStr(RestrictType type) {
	switch(type) {
		case TCP_CONNECT:
			return "TCP_CONNECT";
		case TCP_LISTEN:
			return "TCP_LISTEN ";
		case UDP_LISTEN:
			return "UDP_LISTEN ";
		case UDP_CONNECT:
			return "UDP_CONNECT";
		default:
			return "INVALID";
	}
}

CLuaSocketRestrictions::~CLuaSocketRestrictions()
{
    //stub method
}

