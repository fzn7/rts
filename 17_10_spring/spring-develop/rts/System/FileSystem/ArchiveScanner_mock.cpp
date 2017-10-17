// TODO: Substitue CArchiveScanner with your actual class name
uint32_t CArchiveScanner::GetNumScannedArchives(){}
std::vector<(std::string)> CArchiveScanner::GetMaps(){}
std::vector<(CArchiveScanner::ArchiveData)> CArchiveScanner::GetPrimaryMods(){}
std::vector<(CArchiveScanner::ArchiveData)> CArchiveScanner::GetAllMods(){}
std::vector<(CArchiveScanner::ArchiveData)> CArchiveScanner::GetAllArchives(){}
std::vector<(std::string)> CArchiveScanner::GetAllArchivesUsedBy(const std::string & rootArchive){}
unsigned int CArchiveScanner::GetSingleArchiveChecksum(const std::string & name){}
unsigned int CArchiveScanner::GetArchiveCompleteChecksum(const std::string & name){}
void CArchiveScanner::CheckArchive(const std::string & name, unsigned int hostChecksum, unsigned int & localChecksum){}
void CArchiveScanner::ScanArchive(const std::string & fullName, bool checksum){}
void CArchiveScanner::ScanArchive(const std::string & fullName){}
void CArchiveScanner::ScanAllDirs(){}
std::string CArchiveScanner::ArchiveFromName(const std::string & s){}
std::string CArchiveScanner::NameFromArchive(const std::string & s){}
std::string CArchiveScanner::GetArchivePath(const std::string & name){}
std::string CArchiveScanner::MapNameToMapFile(const std::string & name){}
CArchiveScanner::ArchiveData CArchiveScanner::GetArchiveData(const std::string & name){}
CArchiveScanner::ArchiveData CArchiveScanner::GetArchiveDataByArchive(const std::string & archive){}
void CArchiveScanner::ScanDirs(const std::vector<(std::string)> & dirs){}
void CArchiveScanner::ScanDir(const std::string & curPath, std::deque<(std::string)> & foundArchives){}
bool CArchiveScanner::ScanArchiveLua(IArchive * ar, const std::string & fileName, ArchiveInfo & ai, std::string & err){}
std::string CArchiveScanner::SearchMapFile(const IArchive * ar, std::string & error){}
void CArchiveScanner::ReadCacheData(const std::string & filename){}
void CArchiveScanner::WriteCacheData(const std::string & filename){}
IFileFilter CArchiveScanner::CreateIgnoreFilter(IArchive * ar){}
unsigned int CArchiveScanner::GetCRC(const std::string & filename){}
void CArchiveScanner::ComputeChecksumForArchive(const std::string & filePath){}
bool CArchiveScanner::CheckCachedData(const std::string & fullName, unsigned int * modified, bool doChecksum){}
int CArchiveScanner::GetMetaFileClass(const std::string & filePath){}
bool CArchiveScanner::CheckCompression(const IArchive * ar, const std::string & fullName, std::string & error){}
std::map<(std::string,ArchiveInfo)> CArchiveScanner::archiveInfos(){}
std::map<(std::string,BrokenArchive)> CArchiveScanner::brokenArchives(){}
bool CArchiveScanner::isDirty(){}
std::string CArchiveScanner::cachefile(){}
CArchiveScanner CArchiveScanner::archiveScanner(){}
