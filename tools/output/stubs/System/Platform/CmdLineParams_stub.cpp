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
    std::cout << _FUNCTION_ << std::endl;
}

CmdLineParams::~CmdLineParams()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CmdLineParams::GetInputFile() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CmdLineParams::AddSwitch(const char shortopt, std::string longopt, std::string desc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CmdLineParams::AddString(const char shortopt, std::string longopt, std::string desc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CmdLineParams::AddInt(const char shortopt, std::string longopt, std::string desc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CmdLineParams::Parse()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CmdLineParams::PrintUsage() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CmdLineParams::GetCmdLine() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CmdLineParams::IsSet(const std::string& var) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CmdLineParams::GetString(const std::string& var) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CmdLineParams::GetInt(const std::string& var) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
