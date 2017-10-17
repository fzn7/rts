// TODO: Substitue CIModelParser with your actual class name
S3DModel CIModelParser::Load(const std::string & name){}
CModelLoader CIModelParser::GetInstance(){}
void CIModelParser::Init(){}
void CIModelParser::Kill(){}
S3DModel CIModelParser::LoadModel(std::string name, bool preload){}
S3DModel CIModelParser::LoadModel(std::string name){}
std::string CIModelParser::FindModelPath(std::string name){}
void CIModelParser::PreloadModel(const std::string & name){}
spring::unordered_map<(std::string,unsigned int)> CIModelParser::ModelMap(){}
spring::unordered_map<(std::string,unsigned int)> CIModelParser::FormatMap(){}
spring::unordered_map<(unsigned int,p.IModelParser)> CIModelParser::ParserMap(){}
S3DModel CIModelParser::ParseModel(const std::string & name, const std::string & path){}
S3DModel CIModelParser::CreateModel(const std::string & name, const std::string & path, bool preload){}
S3DModel CIModelParser::LoadCachedModel(const std::string & name, bool preload){}
IModelParser CIModelParser::GetFormatParser(const std::string & pathExt){}
void CIModelParser::KillModels(){}
void CIModelParser::KillParsers(){}
void CIModelParser::CreateLists(S3DModel * o){}
CModelLoader::ModelMap CIModelParser::cache(){}
CModelLoader::FormatMap CIModelParser::formats(){}
CModelLoader::ParserMap CIModelParser::parsers(){}
spring::mutex CIModelParser::mutex(){}
std::deque<(S3DModel)> CIModelParser::models(){}
