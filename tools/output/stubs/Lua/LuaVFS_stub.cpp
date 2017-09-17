#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <cmath>
#include <zlib.h>
#include <boost/regex.hpp>

#include "LuaVFS.h"

#include "LuaInclude.h"

#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaIO.h"
#include "LuaUtils.h"
#include "LuaZip.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/ArchiveScanner.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"
#include "../tools/pr-downloader/src/pr-downloader.h"

using std::min;


/******************************************************************************/
/******************************************************************************/

bool LuaVFS::PushCommon(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaVFS::PushSynced(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaVFS::PushUnsynced(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

const string LuaVFS::GetModes(lua_State* L, int index, bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

static bool LoadFileWithModes(const string& filename, string& data,
                             const string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaVFS::Include(lua_State* L, bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::SyncInclude(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::UnsyncInclude(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaVFS::LoadFile(lua_State* L, bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::SyncLoadFile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::UnsyncLoadFile(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaVFS::FileExists(lua_State* L, bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::SyncFileExists(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::UnsyncFileExists(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaVFS::DirList(lua_State* L, bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::SyncDirList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::UnsyncDirList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

int LuaVFS::SubDirs(lua_State* L, bool synced)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::SyncSubDirs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::UnsyncSubDirs(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

int LuaVFS::UseArchive(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaVFS::MapArchive(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaVFS::UnmapArchive(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/

int LuaVFS::CompressFolder(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int LuaVFS::SevenZipFolder(lua_State* L, const string& folderPath, const string& zipFilePath, bool includeFolder, const string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::ZlibCompress(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::ZlibDecompress(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int LuaVFS::CalculateHash(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  NOTE: Endianess should be handled
//

template <typename T>
int PackType(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::PackU8(lua_State*  L) { return PackType<boost::uint8_t>(L);  }
int LuaVFS::PackU16(lua_State* L) { return PackType<boost::uint16_t>(L); }
int LuaVFS::PackU32(lua_State* L) { return PackType<boost::uint32_t>(L); }
int LuaVFS::PackS8(lua_State*  L) { return PackType<boost::int8_t>(L);   }
int LuaVFS::PackS16(lua_State* L) { return PackType<boost::int16_t>(L);  }
int LuaVFS::PackS32(lua_State* L) { return PackType<boost::int32_t>(L);  }
int LuaVFS::PackF32(lua_State* L) { return PackType<float>(L);           }


/******************************************************************************/

template <typename T>
int UnpackType(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaVFS::UnpackU8(lua_State*  L) { return UnpackType<boost::uint8_t>(L);  }
int LuaVFS::UnpackU16(lua_State* L) { return UnpackType<boost::uint16_t>(L); }
int LuaVFS::UnpackU32(lua_State* L) { return UnpackType<boost::uint32_t>(L); }
int LuaVFS::UnpackS8(lua_State*  L) { return UnpackType<boost::int8_t>(L);   }
int LuaVFS::UnpackS16(lua_State* L) { return UnpackType<boost::int16_t>(L);  }
int LuaVFS::UnpackS32(lua_State* L) { return UnpackType<boost::int32_t>(L);  }
int LuaVFS::UnpackF32(lua_State* L) { return UnpackType<float>(L);           }


/******************************************************************************/
/******************************************************************************/

