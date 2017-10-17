// TODO: Substitue CVirtualArchive with your actual class name
CVirtualArchive CVirtualArchive::AddArchive(const std::string & fileName){}
IArchive CVirtualArchive::DoCreateArchive(const std::string & fileName){}
std::vector<(p.CVirtualArchive)> CVirtualArchive::archives(){}
CVirtualArchiveFactory CVirtualArchive::virtualArchiveFactory(){}
std::vector<(std::uint8_t)> CVirtualArchive::buffer(){}
q(const).std::string CVirtualArchive::name(){}
int CVirtualArchive::fid(){}
bool CVirtualArchive::IsOpen(){}
unsigned int CVirtualArchive::NumFiles(){}
bool CVirtualArchive::GetFile(unsigned int fid, std::vector<(std::uint8_t)> & buffer){}
void CVirtualArchive::FileInfo(unsigned int fid, std::string & name, int & size){}
CVirtualArchive CVirtualArchive::archive(){}
CVirtualArchiveOpen CVirtualArchive::Open(){}
CVirtualFile CVirtualArchive::AddFile(const std::string & file){}
unsigned int CVirtualArchive::NumFiles(){}
bool CVirtualArchive::GetFile(unsigned int fid, std::vector<(std::uint8_t)> & buffer){}
void CVirtualArchive::FileInfo(unsigned int fid, std::string & name, int & size){}
void CVirtualArchive::WriteToFile(){}
std::vector<(p.CVirtualFile)> CVirtualArchive::files(){}
std::string CVirtualArchive::fileName(){}
std::map<(std::string,unsigned int)> CVirtualArchive::lcNameIndex(){}
