/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "SkirmishAILibrary.h"

#include "ExternalAI/IAILibraryManager.h"
#include "ExternalAI/SkirmishAIHandler.h"
#include "ExternalAI/AIInterfaceKey.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/Log/ILog.h"

#include <string>


CSkirmishAILibrary::CSkirmishAILibrary(
	const SSkirmishAILibrary& ai,
	const SkirmishAIKey& key
):
	sSAI(ai),
	key(key)
{
    //stub method
}



LevelOfSupport CSkirmishAILibrary::GetLevelOfSupportFor(
	const std::string& engineVersionString,
	const int engineVersionNumber,
	const AIInterfaceKey& interfaceKey
) const {
	if (sSAI.getLevelOfSupportFor != nullptr) {
		const char* ksn = key.GetShortName().c_str();
		const char* kv  = key.GetVersion().c_str();
		const char* ev  = engineVersionString.c_str();
		const char* isn = interfaceKey.GetShortName().c_str();
		const char* iv  = interfaceKey.GetVersion().c_str();

		return sSAI.getLevelOfSupportFor(ksn, kv, ev, engineVersionNumber, isn, iv);
	}

	return LOS_Unknown;
}

bool CSkirmishAILibrary::Init(int skirmishAIId, const SSkirmishAICallback* c_callback) const
{
    //stub method
}

bool CSkirmishAILibrary::Release(int skirmishAIId) const
{
    //stub method
}

int CSkirmishAILibrary::HandleEvent(int skirmishAIId, int topic, const void* data) const
{
    //stub method
}

