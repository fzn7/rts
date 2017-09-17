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
 *  - write(...) : writes data to the open file within the zipFile (similar to io.write)
 */

/**
 * @class LuaZipFileReader
 *
 * @brief A Lua userdatum to read zip files
 *
 * This class defines functions for a Lua userdatum to read archive files.
 * The type is currently forced to a zip-file, while allowing any file extension.
 * Such a userdatum supports the following methods:
 *  - close()    : close the archive, after this open and read raise an error
 *  - open(name) : opens a new file within the archive (for reading)
 *  - read(...)  : reads data from the open file within the archive (similar to io.read)
 */

#include "LuaZip.h"
#include "LuaInclude.h"
#include "LuaHashString.h"
#include "System/FileSystem/Archives/IArchive.h"
#include "System/FileSystem/ArchiveLoader.h"
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


static int pushresult(lua_State* L, bool result, const char* msg)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

bool LuaZipFileWriter::PushSynced(lua_State* L)
{
    //stub method
}


bool LuaZipFileWriter::PushUnsynced(lua_State* L)
{
    //stub method
}


bool LuaZipFileWriter::CreateMetatable(lua_State* L)
{
    //stub method
}


struct ZipFileWriterUserdata {
	zipFile zip;
	bool fileOpen;
	bool dontClose;
};


static bool FileExists(string filename)
{
    //stub method
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
bool LuaZipFileWriter::PushNew(lua_State* L, const string& filename, zipFile zip)
{
    //stub method
}


int LuaZipFileWriter::open(lua_State* L)
{
    //stub method
}


static ZipFileWriterUserdata* towriter(lua_State* L)
{
    //stub method
}


int LuaZipFileWriter::meta_gc(lua_State* L)
{
    //stub method
}


int LuaZipFileWriter::meta_open(lua_State* L)
{
    //stub method
}


int LuaZipFileWriter::meta_write(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

bool LuaZipFileReader::PushSynced(lua_State* L)
{
    //stub method
}


bool LuaZipFileReader::PushUnsynced(lua_State* L)
{
    //stub method
}


bool LuaZipFileReader::CreateMetatable(lua_State* L)
{
    //stub method
}


struct ZipFileReaderUserdata {
	IArchive* archive;
	std::stringstream* stream;
	bool dontClose;
};


/**
 * @brief Pushes a new ZipFileReader userdatum on the Lua stack.
 *
 * If archive != NULL:
 *  - the userdatum is made to point to the archive,
 *  - the archive will never be closed by Lua (close()->no-op, GC->no-op)
 * Otherwise:
 *  - a new archive is opened
 *  - the type is currently forced to a zip-file, while allowing any file extension
 *  - this archive may be closed by Lua (close() or GC)
 */
bool LuaZipFileReader::PushNew(lua_State* L, const string& filename, IArchive* archive)
{
    //stub method
}


int LuaZipFileReader::open(lua_State* L)
{
    //stub method
}


static ZipFileReaderUserdata* toreader(lua_State* L)
{
    //stub method
}


int LuaZipFileReader::meta_gc(lua_State* L)
{
    //stub method
}


int LuaZipFileReader::meta_open(lua_State* L)
{
    //stub method
}


static int test_eof (lua_State* L, ZipFileReaderUserdata* f)
{
    //stub method
}


static int read_chars(lua_State* L, ZipFileReaderUserdata* f, size_t n)
{
    //stub method
}


/**
 * Similar to Lua's built-in (I/O library) read function.
 *
 * Except that "*number" and *line" aren't supported; only "*all" and \<num\> are
 * supported. The special case read(0) (test for end of file) is handled.
 *
 * Note that reading is only possible after a chunk has been opened using
 * openchunk().
 */
int LuaZipFileReader::meta_read(lua_State* L)
{
    //stub method
}

/******************************************************************************/

// generates the info for the zipped version of the file
static zip_fileinfo* GenerateZipFileInfo(const string& path) {
	string fileModificationDate = FileSystem::GetFileModificationDate(path);

	zip_fileinfo* zipfi = new zip_fileinfo();
	zipfi->dosDate = 0;
	// FIXME: the year 10k problem :)
	zipfi->tmz_date.tm_year = atoi(fileModificationDate.substr(0, 4).c_str()) - 1900;
	zipfi->tmz_date.tm_mon = atoi(fileModificationDate.substr(4, 2).c_str());
	zipfi->tmz_date.tm_mday = atoi(fileModificationDate.substr(6, 2).c_str());
	zipfi->tmz_date.tm_hour = atoi(fileModificationDate.substr(8, 2).c_str());
	zipfi->tmz_date.tm_min = atoi(fileModificationDate.substr(10, 2).c_str());
	zipfi->tmz_date.tm_sec = atoi(fileModificationDate.substr(12, 2).c_str());

	return zipfi;
}

void RecurseZipFolder(const string& folderPath, zipFile& zip, const string& zipFolderPath, const string& modes) {
	// recurse through all the subdirs
	vector<string> folderPaths = CFileHandler::SubDirs(folderPath, "*", modes);
	for (vector<string>::iterator it = folderPaths.begin(); it != folderPaths.end(); ++it) {
		const string& childFolderPath = *it;
		const string childFolderName = FileSystem::GetFilename(childFolderPath.substr(0, childFolderPath.length() - 1));
		const string childZipFolderPath = zipFolderPath + childFolderName + "/";

		zip_fileinfo* zipfi = GenerateZipFileInfo(childFolderPath);
		// write a special file for the dir, so empty folders get added
		zipOpenNewFileInZip(zip, childZipFolderPath.c_str(), zipfi, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_BEST_COMPRESSION);
		zipWriteInFileInZip(zip, "", 0);
		zipCloseFileInZip(zip);
		delete zipfi;

        // recurse
		RecurseZipFolder(*it, zip, childZipFolderPath, modes);
	}

	//iterate through all the files and write them
	vector<string> filePaths = CFileHandler::DirList(folderPath, "*", modes);
	for (vector<string>::iterator it = filePaths.begin(); it != filePaths.end(); ++it) {
		const string& filePath = *it;
		const string& fileName = FileSystem::GetFilename(filePath);
		const string zipFilePath = zipFolderPath + fileName;

		string fileData;
		CFileHandler fh(filePath, modes);
		fh.LoadStringData(fileData);

		zip_fileinfo* zipfi = GenerateZipFileInfo(filePath);
		zipOpenNewFileInZip(zip, zipFilePath.c_str(), zipfi, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_BEST_COMPRESSION);
		zipWriteInFileInZip(zip, fileData.c_str(), fileData.length());
		zipCloseFileInZip(zip);
		delete zipfi;
	}
}

int LuaZipFolder::ZipFolder(lua_State* L, const string& folderPath, const string& zipFilePath, bool includeFolder, const string& modes)
{
    //stub method
}
