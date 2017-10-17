// TODO: Substitue CCacheDir with your actual class name
q(const).std::string CCacheDir::tagFile_name(){}
q(const).std::string CCacheDir::tagFile_content(){}
q(const).size_t CCacheDir::tagFile_content_size(){}
q(const).std::string CCacheDir::defaultAdditionalText(){}
bool CCacheDir::IsCacheDir(const std::string & dir){}
bool CCacheDir::SetCacheDir(const std::string & dir, bool wantedCacheState, const std::string & additionalText, bool forceRewrite){}
bool CCacheDir::SetCacheDir(const std::string & dir, bool wantedCacheState, const std::string & additionalText){}
bool CCacheDir::SetCacheDir(const std::string & dir, bool wantedCacheState){}
bool CCacheDir::FileContentStartsWith(const std::string & filePath, const std::string & content, size_t content_size){}
bool CCacheDir::WriteCacheTagFile(const std::string & filePath, const std::string & additionalText){}
std::string CCacheDir::GetCacheTagFilePath(const std::string & dir){}
