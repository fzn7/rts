#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "restrictions.h"

#include <map>
#include <string>

#include "System/Config/ConfigHandler.h"
#include "System/Log/ILog.h"

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

CLuaSocketRestrictions* luaSocketRestrictions = 0;

CLuaSocketRestrictions::CLuaSocketRestrictions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLuaSocketRestrictions::addRule(RestrictType type,
                                const std::string& hostname,
                                int port,
                                bool allowed)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLuaSocketRestrictions::addRule(RestrictType type, const std::string& rule)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLuaSocketRestrictions::addRules(RestrictType type,
                                 const std::string& configstr)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

/*
bool isValidIpAddress(char *ipAddress)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
*/

bool
CLuaSocketRestrictions::isAllowed(RestrictType type,
                                  const char* hostname,
                                  int port)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const TSocketRule*
CLuaSocketRestrictions::getRule(RestrictType type,
                                const char* hostname,
                                int port)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CLuaSocketRestrictions::addIP(const char* hostname, const char* ip)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

const char*
CLuaSocketRestrictions::ruleToStr(RestrictType type)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CLuaSocketRestrictions::~CLuaSocketRestrictions()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
