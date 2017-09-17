/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "NullUnitScript.h"
#include "Sim/Units/Unit.h"
#include "System/Log/ILog.h"


// keep one global copy so we don't need to allocate a lot of
// near empty objects for mods that use Lua unit scripts.
CNullUnitScript CNullUnitScript::value(nullptr);

CR_BIND_DERIVED(CNullUnitScript, CUnitScript, (nullptr))

CR_REG_METADATA(CNullUnitScript, (
	CR_POSTLOAD(PostLoad)
))

CNullUnitScript::CNullUnitScript(CUnit *u)
	: CUnitScript(u)
{
    //stub method
}

void CNullUnitScript::ShowScriptError(const std::string& msg)
{
    //stub method
}

