// TODO: Substitue CFileHandler with your actual class name
void CFileHandler::Open(const std::string & fileName, const std::string & modes){}
void CFileHandler::Open(const std::string & fileName){}
void CFileHandler::Close(){}
int CFileHandler::Read(void * buf, int length){}
int CFileHandler::ReadString(void * buf, int length){}
void CFileHandler::Seek(int pos, std::ios_base::seekdir where){}
void CFileHandler::Seek(int pos){}
bool CFileHandler::FileExists(const std::string & filePath, const std::string & modes){}
bool CFileHandler::FileExists(){}
bool CFileHandler::Eof(){}
int CFileHandler::GetPos(){}
int CFileHandler::FileSize(){}
bool CFileHandler::LoadStringData(std::string & data){}
std::string CFileHandler::GetFileExt(){}
bool CFileHandler::InReadDir(const std::string & path){}
bool CFileHandler::InWriteDir(const std::string & path){}
std::vector<(std::string)> CFileHandler::FindFiles(const std::string & path, const std::string & pattern){}
std::vector<(std::string)> CFileHandler::DirList(const std::string & path, const std::string & pattern, const std::string & modes){}
std::vector<(std::string)> CFileHandler::SubDirs(const std::string & path, const std::string & pattern, const std::string & modes){}
std::string CFileHandler::AllowModes(const std::string & modes, const std::string & allowed){}
std::string CFileHandler::ForbidModes(const std::string & modes, const std::string & forbidden){}
bool CFileHandler::TryReadFromPWD(const std::string & fileName){}
bool CFileHandler::TryReadFromRawFS(const std::string & fileName){}
bool CFileHandler::TryReadFromVFS(const std::string & fileName, int section){}
bool CFileHandler::InsertRawFiles(std::set<(std::string)> & fileSet, const std::string & path, const std::string & pattern){}
bool CFileHandler::InsertVFSFiles(std::set<(std::string)> & fileSet, const std::string & path, const std::string & pattern, int section){}
bool CFileHandler::InsertRawDirs(std::set<(std::string)> & dirSet, const std::string & path, const std::string & pattern){}
bool CFileHandler::InsertVFSDirs(std::set<(std::string)> & dirSet, const std::string & path, const std::string & pattern, int section){}
std::string CFileHandler::fileName(){}
std::ifstream CFileHandler::ifs(){}
std::vector<(std::uint8_t)> CFileHandler::fileBuffer(){}
int CFileHandler::filePos(){}
int CFileHandler::fileSize(){}
