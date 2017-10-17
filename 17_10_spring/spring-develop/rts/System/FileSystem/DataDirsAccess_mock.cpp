// TODO: Substitue CDataDirsAccess with your actual class name
std::vector<(std::string)> CDataDirsAccess::FindFilesInternal(const std::string & dir, const std::string & pattern, int flags){}
std::string CDataDirsAccess::LocateFileInternal(const std::string & file){}
std::string CDataDirsAccess::LocateFile(std::string file, int flags){}
std::string CDataDirsAccess::LocateFile(std::string file){}
std::string CDataDirsAccess::LocateDir(std::string dir, int flags){}
std::string CDataDirsAccess::LocateDir(std::string dir){}
std::vector<(std::string)> CDataDirsAccess::LocateDirs(std::string dir){}
std::vector<(std::string)> CDataDirsAccess::FindDirsInDirectSubDirs(const std::string & relPath){}
std::vector<(std::string)> CDataDirsAccess::FindFiles(std::string dir, const std::string & pattern, int flags){}
std::vector<(std::string)> CDataDirsAccess::FindFiles(std::string dir, const std::string & pattern){}
bool CDataDirsAccess::InReadDir(const std::string & path){}
bool CDataDirsAccess::InWriteDir(const std::string & path){}
void CDataDirsAccess::FindFilesSingleDir(std::vector<(std::string)> & matches, const std::string & datadir, const std::string & dir, const std::string & pattern, int flags){}
DataDirsAccess CDataDirsAccess::dataDirsAccess(){}
