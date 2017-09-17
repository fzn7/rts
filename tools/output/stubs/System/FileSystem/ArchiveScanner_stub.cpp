#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include <list>
#include <algorithm>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <boost/scoped_ptr.hpp>

#include "ArchiveNameResolver.h"
#include "ArchiveScanner.h"
#include "ArchiveLoader.h"
#include "DataDirLocater.h"
#include "Archives/IArchive.h"
#include "FileFilter.h"
#include "DataDirsAccess.h"
#include "FileSystem.h"
#include "FileQueryFlags.h"
#include "Lua/LuaParser.h"
#include "System/Log/ILog.h"
#include "System/CRC.h"
#include "System/Util.h"
#include "System/Exceptions.h"
#include "System/ThreadPool.h"
#include "System/Config/ConfigHandler.h"
#include "System/FileSystem/RapidHandler.h"

#if !defined(DEDICATED) && !defined(UNITSYNC)
	#include "System/TimeProfiler.h"
	#include "System/Platform/Watchdog.h"
#endif


#define LOG_SECTION_ARCHIVESCANNER "ArchiveScanner"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_ARCHIVESCANNER)


/*
 * The archive scanner is used to find stuff in archives
 * which are needed before building the virtual filesystem.
 * This currently includes maps and mods.
 * It uses caching to speed up the process.
 *
 * It only retrieves info that is used in an initial listing.
 * For detailed info when selecting a map for example,
 * the more specialized parsers will be used.
 * (mapping one archive when selecting a map is not slow,
 * but mapping them all, every time to make the list is)
 */

const int INTERNAL_VER = 10;
CArchiveScanner* archiveScanner = NULL;

CONFIG(bool, FastArchiveScan).defaultValue(true).description("If enabled, only generate archive checksums on-demand.");


/*
 * Engine known (and used?) tags in [map|mod]info.lua
 */
struct KnownInfoTag {
	std::string name;
	std::string desc;
	bool must_have;
};

const KnownInfoTag knownTags[] = {
	{"name",        "example: Original Total Annihilation", true},
	{"shortname",   "example: OTA", false},
	{"version",     "example: v2.3", false},
	{"mutator",     "example: deployment", false},
	{"game",        "example: Total Annihilation", false},
	{"shortgame",   "example: TA", false},
	{"description", "example: Little units blowing up other little units", false},
	{"mapfile",     "in case its a map, store location of smf/sm3 file", false}, //FIXME is this ever used in the engine?! or does it auto calc the location?
	{"modtype",     "1=primary, 0=hidden, 3=map", true},
	{"depend",      "a table with all archives that needs to be loaded for this one", false},
	{"replace",     "a table with archives that got replaced with this one", false}
};

/*
 * CArchiveScanner::ArchiveData
 */
CArchiveScanner::ArchiveData::ArchiveData(const LuaTable& archiveTable, bool fromCache)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CArchiveScanner::ArchiveData::GetKeyDescription(const std::string& keyLower)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CArchiveScanner::ArchiveData::IsReservedKey(const std::string& keyLower)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CArchiveScanner::ArchiveData::IsValid(std::string& err) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


InfoItem* CArchiveScanner::ArchiveData::GetInfoItem(const std::string& key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const InfoItem* CArchiveScanner::ArchiveData::GetInfoItem(const std::string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

InfoItem& CArchiveScanner::ArchiveData::EnsureInfoItem(const std::string& key)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CArchiveScanner::ArchiveData::SetInfoItemValueString(const std::string& key, const std::string& value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CArchiveScanner::ArchiveData::SetInfoItemValueInteger(const std::string& key, int value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CArchiveScanner::ArchiveData::SetInfoItemValueFloat(const std::string& key, float value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CArchiveScanner::ArchiveData::SetInfoItemValueBool(const std::string& key, bool value)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::vector<InfoItem> CArchiveScanner::ArchiveData::GetInfoItems() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::string CArchiveScanner::ArchiveData::GetInfoValueString(const std::string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int CArchiveScanner::ArchiveData::GetInfoValueInteger(const std::string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

float CArchiveScanner::ArchiveData::GetInfoValueFloat(const std::string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CArchiveScanner::ArchiveData::GetInfoValueBool(const std::string& key) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}





/*
 * CArchiveScanner
 */

CArchiveScanner::CArchiveScanner()
: isDirty(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CArchiveScanner::~CArchiveScanner()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


const std::string& CArchiveScanner::GetFilepath() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CArchiveScanner::ScanAllDirs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CArchiveScanner::ScanDirs(const std::vector<std::string>& scanDirs, bool doChecksum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CArchiveScanner::ScanDir(const std::string& curPath, std::list<std::string>* foundArchives)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void AddDependency(std::vector<std::string>& deps, const std::string& dependency)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool CArchiveScanner::CheckCompression(const IArchive* ar,const std::string& fullName, std::string& error)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CArchiveScanner::SearchMapFile(const IArchive* ar, std::string& error)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static bool IsBaseContent(const std::string& fileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CArchiveScanner::ScanArchive(const std::string& fullName, bool doChecksum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CArchiveScanner::CheckCachedData(const std::string& fullName, unsigned* modified, bool doChecksum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CArchiveScanner::ScanArchiveLua(IArchive* ar, const std::string& fileName, ArchiveInfo& ai, std::string& err)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

IFileFilter* CArchiveScanner::CreateIgnoreFilter(IArchive* ar)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/// used below
struct CRCPair {
	std::string* filename;
	unsigned int nameCRC;
	unsigned int dataCRC;
};



/**
 * Get CRC of the data in the specified archive.
 * Returns 0 if file could not be opened.
 */
unsigned int CArchiveScanner::GetCRC(const std::string& arcName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CArchiveScanner::ComputeChecksumForArchive(const std::string& filePath)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CArchiveScanner::ReadCacheData(const std::string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline void SafeStr(FILE* out, const char* prefix, const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void FilterDep(std::vector<std::string>& deps, const std::string& exclude)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CArchiveScanner::WriteCacheData(const std::string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


static void sortByName(std::vector<CArchiveScanner::ArchiveData>& data)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<CArchiveScanner::ArchiveData> CArchiveScanner::GetPrimaryMods() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::vector<CArchiveScanner::ArchiveData> CArchiveScanner::GetAllMods() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::vector<CArchiveScanner::ArchiveData> CArchiveScanner::GetAllArchives() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::vector<std::string> CArchiveScanner::GetAllArchivesUsedBy(const std::string& root, int depth) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::vector<std::string> CArchiveScanner::GetMaps() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CArchiveScanner::MapNameToMapFile(const std::string& s) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int CArchiveScanner::GetSingleArchiveChecksum(const std::string& filePath)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned int CArchiveScanner::GetArchiveCompleteChecksum(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CArchiveScanner::CheckArchive(const std::string& name, unsigned checksum)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CArchiveScanner::GetArchivePath(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CArchiveScanner::ArchiveFromName(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

std::string CArchiveScanner::NameFromArchive(const std::string& archiveName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CArchiveScanner::ArchiveData CArchiveScanner::GetArchiveData(const std::string& name) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CArchiveScanner::ArchiveData CArchiveScanner::GetArchiveDataByArchive(const std::string& archive) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

unsigned char CArchiveScanner::GetMetaFileClass(const std::string& filePath)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

