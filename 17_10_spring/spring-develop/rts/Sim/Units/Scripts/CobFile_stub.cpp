#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CobFile.h"
#include "Sim/Misc/GlobalConstants.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/byteorder.h"
#include "System/Sound/ISound.h"
#include "System/Util.h"

#include <algorithm>
#include <cctype>
#include <locale>
#include <string.h>

// The following structure is taken from
// http://visualta.tauniverse.com/Downloads/ta-cob-fmt.txt  Information on missing
// fields from Format_Cob.pas
typedef struct tagCOBHeader
{
        int VersionSignature;
        int NumberOfScripts;
        int NumberOfPieces;
        int TotalScriptLen;
        int NumberOfStaticVars;
        int Unknown_2; /* Always seems to be 0 */
        int OffsetToScriptCodeIndexArray;
        int OffsetToScriptNameOffsetArray;
        int OffsetToPieceNameOffsetArray;
        int OffsetToScriptCode;
        int Unknown_3; /* Always seems to point to first script name */

        int OffsetToSoundNameArray;		// These two are only found in TA:K scripts
        int NumberOfSounds;
} COBHeader;
CCobFile::~CCobFile()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

int
CCobFile::GetFunctionId(const string& name)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
