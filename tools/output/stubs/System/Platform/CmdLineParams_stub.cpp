/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CmdLineParams.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "Game/GameVersion.h"
#include "System/Util.h"

namespace po = boost::program_options;

CmdLineParams::CmdLineParams(int _argc, char* _argv[]) : desc("Allowed options")
{
    //stub method
}

CmdLineParams::~CmdLineParams()
{
    //stub method
}

std::string CmdLineParams::GetInputFile() const
{
    //stub method
}

void CmdLineParams::AddSwitch(const char shortopt, std::string longopt, std::string desc)
{
    //stub method
}

void CmdLineParams::AddString(const char shortopt, std::string longopt, std::string desc)
{
    //stub method
}

void CmdLineParams::AddInt(const char shortopt, std::string longopt, std::string desc)
{
    //stub method
}

void CmdLineParams::Parse()
{
    //stub method
}

void CmdLineParams::PrintUsage() const
{
    //stub method
}

std::string CmdLineParams::GetCmdLine() const
{
    //stub method
}

bool CmdLineParams::IsSet(const std::string& var) const
{
    //stub method
}

std::string CmdLineParams::GetString(const std::string& var) const
{
    //stub method
}

int CmdLineParams::GetInt(const std::string& var) const
{
    //stub method
}
