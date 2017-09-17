#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <stdio.h>

#include "KeyBindings.h"
#include "KeyCodes.h"
#include "KeySet.h"
#include "Sim/Units/UnitDef.h"
#include "Sim/Units/UnitDefHandler.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

#define LOG_SECTION_KEY_BINDINGS "KeyBindings"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_KEY_BINDINGS)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_KEY_BINDINGS

CONFIG(int, KeyChainTimeout)
  .defaultValue(750)
  .minimumValue(0)
  .description("Timeout in milliseconds waiting for a key chain shortcut.");

CKeyBindings* keyBindings = NULL;

struct DefaultBinding
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CKeyBindings::~CKeyBindings()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

const CKeyBindings::ActionList&
CKeyBindings::GetActionList(const CKeySet& ks) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CKeyBindings::ActionList&
CKeyBindings::GetActionList(const CKeyChain& kc) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const CKeyBindings::HotkeyList&
CKeyBindings::GetHotkeys(const std::string& action) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

static bool
ParseSingleChain(const std::string& keystr, CKeyChain* kc)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool
ParseKeyChain(std::string keystr,
              CKeyChain* kc,
              const size_t pos = std::string::npos)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::Bind(const std::string& keystr, const std::string& line)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::UnBind(const std::string& keystr, const std::string& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::UnBindKeyset(const std::string& keystr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::UnBindAction(const std::string& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::SetFakeMetaKey(const std::string& keystr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::AddKeySymbol(const std::string& keysym, const std::string& code)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::RemoveCommandFromList(ActionList& al, const std::string& command)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CKeyBindings::ConfigNotify(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CKeyBindings::LoadDefaults()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CKeyBindings::PushAction(const Action& action)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::ExecuteCommand(const std::string& line)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::Load(const std::string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CKeyBindings::BuildHotkeyMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

void
CKeyBindings::Print() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::Save(const std::string& filename) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CKeyBindings::FileSave(FILE* out) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
