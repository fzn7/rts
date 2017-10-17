// TODO: Substitue CFileSystemAbstraction with your actual class name
bool CFileSystemAbstraction::MkDir(const std::string & dir){}
bool CFileSystemAbstraction::DeleteFile(const std::string & file){}
bool CFileSystemAbstraction::FileExists(const std::string & file){}
bool CFileSystemAbstraction::DirExists(const std::string & dir){}
bool CFileSystemAbstraction::DirIsWritable(const std::string & dir){}
bool CFileSystemAbstraction::ComparePaths(const std::string & path1, const std::string & path2){}
std::string CFileSystemAbstraction::GetCwd(){}
void CFileSystemAbstraction::ChDir(const std::string & dir){}
std::string CFileSystemAbstraction::RemoveLocalPathPrefix(const std::string & path){}
bool CFileSystemAbstraction::IsFSRoot(const std::string & path){}
bool CFileSystemAbstraction::IsPathSeparator(char aChar){}
bool CFileSystemAbstraction::IsNativePathSeparator(char aChar){}
bool CFileSystemAbstraction::HasPathSepAtEnd(const std::string & path){}
std::string CFileSystemAbstraction::EnsurePathSepAtEnd(std::string & path){}
std::string CFileSystemAbstraction::EnsurePathSepAtEnd(const std::string & path){}
void CFileSystemAbstraction::EnsureNoPathSepAtEnd(std::string & path){}
std::string CFileSystemAbstraction::EnsureNoPathSepAtEnd(const std::string & path){}
std::string CFileSystemAbstraction::StripTrailingSlashes(const std::string & path){}
std::string CFileSystemAbstraction::GetParent(const std::string & path){}
size_t CFileSystemAbstraction::GetFileSize(const std::string & file){}
bool CFileSystemAbstraction::IsReadableFile(const std::string & file){}
unsigned int CFileSystemAbstraction::GetFileModificationTime(const std::string & file){}
std::string CFileSystemAbstraction::GetFileModificationDate(const std::string & file){}
char CFileSystemAbstraction::GetNativePathSeparator(){}
bool CFileSystemAbstraction::IsAbsolutePath(const std::string & path){}
void CFileSystemAbstraction::FindFiles(std::vector<(std::string)> & matches, const std::string & dataDir, const std::string & dir, const std::string & regex, int flags){}
