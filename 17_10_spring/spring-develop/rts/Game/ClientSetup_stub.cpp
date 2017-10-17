#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "ClientSetup.h"

#include "System/Config/ConfigHandler.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/MsgStrings.h"
#include "System/TdfParser.h"
#include "System/Util.h"
#ifdef DEDICATED
#include "System/Platform/errorhandler.h"
#endif

CONFIG(std::string, HostIPDefault)
  .defaultValue("localhost")
  .dedicatedValue("")
  .description("Default IP to use for hosting if not specified in script.txt");
CONFIG(int, HostPortDefault)
  .defaultValue(8452)
  .minimumValue(0)
  .maximumValue(65535)
  .description(
    "Default Port to use for hosting if not specified in script.txt");

ClientSetup::ClientSetup()
  : hostIP(configHandler->GetString("HostIPDefault"))
  , hostPort(configHandler->GetInt("HostPortDefault"))
  , isHost(false)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
ClientSetup::LoadFromStartScript(const std::string& setup)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
