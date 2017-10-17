// TODO: Substitue CDirArchive with your actual class name
IArchive CDirArchive::DoCreateArchive(const std::string & filePath){}
bool CDirArchive::IsOpen(){}
unsigned int CDirArchive::NumFiles(){}
bool CDirArchive::GetFile(unsigned int fid, std::vector<(std::uint8_t)> & buffer){}
void CDirArchive::FileInfo(unsigned int fid, std::string & name, int & size){}
std::string CDirArchive::dirName(){}
std::vector<(std::string)> CDirArchive::searchFiles(){}
