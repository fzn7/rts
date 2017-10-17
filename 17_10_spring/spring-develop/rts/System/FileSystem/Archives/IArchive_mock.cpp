// TODO: Substitue CIArchive with your actual class name
bool CIArchive::IsOpen(){}
unsigned int CIArchive::NumFiles(){}
unsigned int CIArchive::FindFile(const std::string & filePath){}
bool CIArchive::GetFile(unsigned int fid, std::vector<(std::uint8_t)> & buffer){}
bool CIArchive::GetFile(const std::string & name, std::vector<(std::uint8_t)> & buffer){}
void CIArchive::FileInfo(unsigned int fid, std::string & name, int & size){}
unsigned int CIArchive::GetCrc32(unsigned int fid){}
std::map<(std::string,unsigned int)> CIArchive::lcNameIndex(){}
q(const).std::string CIArchive::archiveFile(){}
