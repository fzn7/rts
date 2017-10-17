// TODO: Substitue CColladaExporter with your actual class name
void CColladaExporter::WriteFile(){}
void CColladaExporter::WriteHeader(){}
void CColladaExporter::WriteTextures(){}
void CColladaExporter::WriteMaterials(){}
void CColladaExporter::WriteCamerasLibrary(){}
void CColladaExporter::WriteCamera(size_t pIndex){}
void CColladaExporter::WriteLightsLibrary(){}
void CColladaExporter::WriteLight(size_t pIndex){}
void CColladaExporter::WritePointLight(const const aiLight * light){}
void CColladaExporter::WriteDirectionalLight(const const aiLight * light){}
void CColladaExporter::WriteSpotLight(const const aiLight * light){}
void CColladaExporter::WriteAmbienttLight(const const aiLight * light){}
void CColladaExporter::WriteGeometryLibrary(){}
void CColladaExporter::WriteGeometry(size_t pIndex){}
void CColladaExporter::WriteFloatArray(const std::string & pIdString, Assimp::ColladaExporter::FloatDataType pType, const ai_real * pData, size_t pElementCount){}
void CColladaExporter::WriteSceneLibrary(){}
void CColladaExporter::WriteNode(const aiScene * scene, aiNode * pNode){}
std::stringstream CColladaExporter::mOutput(){}
IOSystem CColladaExporter::mIOSystem(){}
q(const).std::string CColladaExporter::mPath(){}
q(const).std::string CColladaExporter::mFile(){}
q(const).aiScene CColladaExporter::mScene(){}
bool CColladaExporter::mSceneOwned(){}
std::string CColladaExporter::startstr(){}
std::string CColladaExporter::endstr(){}
std::vector<(Assimp::ColladaExporter::Material)> CColladaExporter::materials(){}
std::map<(unsigned int,std::string)> CColladaExporter::textures(){}
void CColladaExporter::ReadMaterialSurface(Assimp::ColladaExporter::Surface & poSurface, const aiMaterial * pSrcMat, aiTextureType pTexture, const char * pKey, size_t pType, size_t pIndex){}
void CColladaExporter::WriteImageEntry(const Assimp::ColladaExporter::Surface & pSurface, const std::string & pNameAdd){}
void CColladaExporter::WriteTextureParamEntry(const Assimp::ColladaExporter::Surface & pSurface, const std::string & pTypeName, const std::string & pMatName){}
void CColladaExporter::WriteTextureColorEntry(const Assimp::ColladaExporter::Surface & pSurface, const std::string & pTypeName, const std::string & pImageName){}
void CColladaExporter::WriteFloatEntry(const Assimp::ColladaExporter::Property & pProperty, const std::string & pTypeName){}
