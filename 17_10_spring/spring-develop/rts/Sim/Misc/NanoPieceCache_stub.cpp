#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "NanoPieceCache.h"
#include "Sim/Misc/GlobalSynced.h"
#include "Sim/Units/Scripts/UnitScript.h"

CR_BIND(NanoPieceCache, )

CR_REG_METADATA(NanoPieceCache,
                (CR_MEMBER(nanoPieces),
                 CR_MEMBER(lastNanoPieceCnt),
                 CR_MEMBER(curBuildPowerMask)))

int
NanoPieceCache::GetNanoPiece(CUnitScript* ownerScript)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
