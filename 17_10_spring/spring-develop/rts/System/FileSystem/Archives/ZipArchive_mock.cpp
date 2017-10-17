// TODO: Substitue CZipArchive with your actual class name
IArchive CZipArchive::DoCreateArchive(const std::string & filePath){}
bool CZipArchive::IsOpen(){}
unsigned int CZipArchive::NumFiles(){}
void CZipArchive::FileInfo(unsigned int fid, std::string & name, int & size){}
unsigned int CZipArchive::GetCrc32(unsigned int fid){}
unzFile CZipArchive::zip(){}
std::vector<(CZipArchive::FileData)> CZipArchive::fileData(){}
bool CZipArchive::GetFileImpl(unsigned int fid, std::vector<(std::uint8_t)> & buffer){}
