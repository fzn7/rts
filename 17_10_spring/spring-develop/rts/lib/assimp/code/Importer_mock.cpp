// TODO: Substitue CImporter with your actual class name
unsigned int CImporter::KeyType(){}
std::map<(Assimp::ImporterPimpl::KeyType,int)> CImporter::IntPropertyMap(){}
std::map<(Assimp::ImporterPimpl::KeyType,ai_real)> CImporter::FloatPropertyMap(){}
std::map<(Assimp::ImporterPimpl::KeyType,std::string)> CImporter::StringPropertyMap(){}
std::map<(Assimp::ImporterPimpl::KeyType,aiMatrix4x4)> CImporter::MatrixPropertyMap(){}
Assimp::IOSystem CImporter::mIOHandler(){}
bool CImporter::mIsDefaultHandler(){}
Assimp::ProgressHandler CImporter::mProgressHandler(){}
bool CImporter::mIsDefaultProgressHandler(){}
std::vector<(p.Assimp::BaseImporter)> CImporter::mImporter(){}
std::vector<(p.Assimp::BaseProcess)> CImporter::mPostProcessingSteps(){}
aiScene CImporter::mScene(){}
std::string CImporter::mErrorString(){}
Assimp::ImporterPimpl::IntPropertyMap CImporter::mIntProperties(){}
Assimp::ImporterPimpl::FloatPropertyMap CImporter::mFloatProperties(){}
Assimp::ImporterPimpl::StringPropertyMap CImporter::mStringProperties(){}
Assimp::ImporterPimpl::MatrixPropertyMap CImporter::mMatrixProperties(){}
bool CImporter::bExtraVerbose(){}
Assimp::SharedPostProcessInfo CImporter::mPPShared(){}
unsigned int CImporter::AddLoadRequest(const std::string & file, unsigned int steps, const Assimp::BatchLoader::PropertyMap * map){}
unsigned int CImporter::AddLoadRequest(const std::string & file, unsigned int steps){}
unsigned int CImporter::AddLoadRequest(const std::string & file){}
aiScene CImporter::GetImport(unsigned int which){}
void CImporter::LoadAll(){}
Assimp::BatchData CImporter::data(){}
