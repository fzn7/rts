#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "DataDirsAccess.h"
#include "DataDirLocater.h"
#include "FileHandler.h"
#include "FileQueryFlags.h"
#include "FileSystem.h"

#include <cassert>
#include <string>
#include <vector>


DataDirsAccess dataDirsAccess;


std::vector<std::string> DataDirsAccess::FindFiles(std::string dir, const std::string& pattern, int flags) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<std::string> DataDirsAccess::FindFilesInternal(const std::string& dir, const std::string& pattern, int flags) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string DataDirsAccess::LocateFileInternal(const std::string& file) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void DataDirsAccess::FindFilesSingleDir(std::vector<std::string>& matches, const std::string& datadir, const std::string& dir, const std::string& pattern, int flags) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



std::string DataDirsAccess::LocateFile(std::string file, int flags) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string DataDirsAccess::LocateDir(std::string dir, int flags) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
std::vector<std::string> DataDirsAccess::LocateDirs(std::string dir) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<std::string> DataDirsAccess::FindDirsInDirectSubDirs(
		const std::string& relPath) const {

	std::vector<std::string> found;

	static const std::string pattern = "*";

	// list of all occurences of the relative path in the data directories
	const std::vector<std::string>& rootDirs = LocateDirs(relPath);

	// list of subdirs in all occurences of the relative path in the data directories
	std::vector<std::string> mainDirs;

	// find all subdirectories in the rootDirs
	for (const std::string& dir: rootDirs) {
		const std::vector<std::string>& localMainDirs = CFileHandler::SubDirs(dir, pattern, SPRING_VFS_RAW);
		mainDirs.insert(mainDirs.end(), localMainDirs.begin(), localMainDirs.end());
	}
	//found.insert(found.end(), mainDirs.begin(), mainDirs.end());

	// and add all subdriectories of these
	for (const std::string& dir: mainDirs) {
		const std::vector<std::string>& subDirs = CFileHandler::SubDirs(dir, pattern, SPRING_VFS_RAW);
		found.insert(found.end(), subDirs.begin(), subDirs.end());
	}

	return found;
}


bool DataDirsAccess::InReadDir(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool DataDirsAccess::InWriteDir(const std::string& path)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
