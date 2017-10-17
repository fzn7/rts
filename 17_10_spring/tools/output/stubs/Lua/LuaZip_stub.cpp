#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/**
 * @class LuaZipFileWriter
 *
 * @brief A Lua userdatum to write zip files
 *
 * This class defines functions for a Lua userdatum to write to zip files.
 * Such a userdatum supports the following methods:
 *  - close()    : close the zipFile, after this open and write raise an error
 *  - open(name) : opens a new file within the zipFile (for writing)
 *  - write(...) : writes data to the open file within the zipFile (similar to
 * io.write)
 */

/**
 * @class LuaZipFileReader
 *
 * @brief A Lua userdatum to read zip files
 *
 * This class defines functions for a Lua userdatum to read archive files.
 * The type is currently forced to a zip-file, while allowing any file
 * extension. Such a userdatum supports the following methods:
 *  - close()    : close the archive, after this open and read raise an error
 *  - open(name) : opens a new file within the archive (for reading)
 *  - read(...)  : reads data from the open file within the archive (similar to
 * io.read)
 */

#include "LuaZip.h"
#include "LuaHashString.h"
#include "LuaInclude.h"
#include "System/FileSystem/ArchiveLoader.h"
#include "System/FileSystem/Archives/IArchive.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileQueryFlags.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Util.h"
#include "minizip/zip.h"
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

static int
pushresult(lua_State* L, bool result, const char* msg)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
LuaZipFileWriter::PushSynced(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaZipFileWriter::PushUnsynced(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaZipFileWriter::CreateMetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct ZipFileWriterUserdata
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * @brief Pushes a new ZipFileWriter userdatum on the Lua stack.
 *
 * If zip != NULL:
 *  - the userdatum is made to point to the zipFile,
 *  - the zipFile will never be closed by Lua (close()->no-op, GC->no-op)
 * Otherwise:
 *  - a new zipFile is opened (without overwrite, with directory creation)
 *  - this zipFile may be closed by Lua (close() or GC)
 */
bool
LuaZipFileWriter::PushNew(lua_State* L, const string& filename, zipFile zip)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaZipFileWriter::open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static ZipFileWriterUserdata*
towriter(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaZipFileWriter::meta_gc(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaZipFileWriter::meta_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaZipFileWriter::meta_write(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

bool
LuaZipFileReader::PushSynced(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaZipFileReader::PushUnsynced(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
LuaZipFileReader::CreateMetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct ZipFileReaderUserdata
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaZipFileReader::open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static ZipFileReaderUserdata*
toreader(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaZipFileReader::meta_gc(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaZipFileReader::meta_open(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
test_eof(lua_State* L, ZipFileReaderUserdata* f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
read_chars(lua_State* L, ZipFileReaderUserdata* f, size_t n)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/**
 * Similar to Lua's built-in (I/O library) read function.
 *
 * Except that "*number" and *line" aren't supported; only "*all" and \<num\>
 * are supported. The special case read(0) (test for end of file) is handled.
 *
 * Note that reading is only possible after a chunk has been opened using
 * openchunk().
 */
int
LuaZipFileReader::meta_read(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

// generates the info for the zipped version of the file
static zip_fileinfo*
GenerateZipFileInfo(const string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
RecurseZipFolder(const string& folderPath,
                 zipFile& zip,
                 const string& zipFolderPath,
                 const string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaZipFolder::ZipFolder(lua_State* L,
                        const string& folderPath,
                        const string& zipFilePath,
                        bool includeFolder,
                        const string& modes)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
