/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "FileHandler.h"

#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <limits.h>
#include <boost/regex.hpp>

#include "FileQueryFlags.h"
#include "FileSystem.h"

#ifndef TOOLS
	#include "VFSHandler.h"
	#include "DataDirsAccess.h"
	#include "System/Util.h"
	#include "System/Platform/Misc.h"
#endif

using std::string;



/******************************************************************************/
/******************************************************************************/

CFileHandler::CFileHandler(const char* fileName, const char* modes)
	: filePos(0), fileSize(-1)
{
    //stub method
}


CFileHandler::CFileHandler(const string& fileName, const string& modes)
	: filePos(0), fileSize(-1)
{
    //stub method
}


CFileHandler::~CFileHandler()
{
    //stub method
}


/******************************************************************************/

bool CFileHandler::TryReadFromPWD(const string& fileName)
{
    //stub method
}


bool CFileHandler::TryReadFromRawFS(const string& fileName)
{
    //stub method
}


bool CFileHandler::TryReadFromModFS(const string& fileName)
{
    //stub method
}


bool CFileHandler::TryReadFromMapFS(const string& fileName)
{
    //stub method
}


bool CFileHandler::TryReadFromBaseFS(const string& fileName)
{
    //stub method
}


void CFileHandler::Open(const string& fileName, const string& modes)
{
    //stub method
}


/******************************************************************************/

bool CFileHandler::FileExists(const std::string& filePath, const std::string& modes)
{
    //stub method
}


bool CFileHandler::FileExists() const
{
    //stub method
}


int CFileHandler::Read(void* buf, int length)
{
    //stub method
}


int CFileHandler::ReadString(void* buf, int length)
{
    //stub method
}


void CFileHandler::Seek(int length, std::ios_base::seekdir where)
{
    //stub method
}

bool CFileHandler::Eof() const
{
    //stub method
}


int CFileHandler::FileSize() const
{
    //stub method
}


int CFileHandler::GetPos()
{
    //stub method
}


bool CFileHandler::LoadStringData(string& data)
{
    //stub method
}

std::string CFileHandler::GetFileExt() const
{
    //stub method
}

/******************************************************************************/

std::vector<string> CFileHandler::FindFiles(const string& path,
		const string& pattern)
{
    //stub method
}


/******************************************************************************/

std::vector<string> CFileHandler::DirList(const string& path,
		const string& pattern, const string& modes)
{
    //stub method
}


bool CFileHandler::InsertRawFiles(std::set<string>& fileSet,
		const string& path, const string& pattern)
{
    //stub method
}


bool CFileHandler::InsertModFiles(std::set<string>& fileSet,
		const string& path, const string& pattern)
{
    //stub method
}


bool CFileHandler::InsertMapFiles(std::set<string>& fileSet,
		const string& path, const string& pattern)
{
    //stub method
}


bool CFileHandler::InsertBaseFiles(std::set<string>& fileSet,
		const string& path, const string& pattern)
{
    //stub method
}


/******************************************************************************/

std::vector<string> CFileHandler::SubDirs(const string& path,
		const string& pattern, const string& modes)
{
    //stub method
}


bool CFileHandler::InsertRawDirs(std::set<string>& dirSet,
		const string& path, const string& pattern)
{
    //stub method
}


bool CFileHandler::InsertModDirs(std::set<string>& dirSet,
		const string& path, const string& pattern)
{
    //stub method
}


bool CFileHandler::InsertMapDirs(std::set<string>& dirSet,
		const string& path, const string& pattern)
{
    //stub method
}


bool CFileHandler::InsertBaseDirs(std::set<string>& dirSet,
		const string& path, const string& pattern)
{
    //stub method
}


/******************************************************************************/

string CFileHandler::AllowModes(const string& modes, const string& allowed)
{
    //stub method
}


string CFileHandler::ForbidModes(const string& modes, const string& forbidden)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/
