// TODO: Substitue CSevenZipArchive with your actual class name
IArchive CSevenZipArchive::DoCreateArchive(const std::string & filePath){}
bool CSevenZipArchive::IsOpen(){}
unsigned int CSevenZipArchive::NumFiles(){}
bool CSevenZipArchive::GetFileImpl(unsigned int fid, std::vector<(std::uint8_t)> & buffer){}
void CSevenZipArchive::FileInfo(unsigned int fid, std::string & name, int & size){}
bool CSevenZipArchive::HasLowReadingCost(unsigned int fid){}
unsigned int CSevenZipArchive::GetCrc32(unsigned int fid){}
UInt32 CSevenZipArchive::blockIndex(){}
Byte CSevenZipArchive::outBuffer(){}
size_t CSevenZipArchive::outBufferSize(){}
q(const).size_t CSevenZipArchive::COST_LIMIT_UNPACK_OVERSIZE(){}
q(const).size_t CSevenZipArchive::COST_LIMIT_DISC_READ(){}
int CSevenZipArchive::GetFileName(const CSzArEx * db, int i){}
std::vector<(FileData)> CSevenZipArchive::fileData(){}
UInt16 CSevenZipArchive::tempBuf(){}
size_t CSevenZipArchive::tempBufSize(){}
CFileInStream CSevenZipArchive::archiveStream(){}
CSzArEx CSevenZipArchive::db(){}
CLookToRead CSevenZipArchive::lookStream(){}
ISzAlloc CSevenZipArchive::allocImp(){}
ISzAlloc CSevenZipArchive::allocTempImp(){}
bool CSevenZipArchive::isOpen(){}
