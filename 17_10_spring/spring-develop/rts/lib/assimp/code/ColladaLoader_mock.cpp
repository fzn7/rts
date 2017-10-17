// TODO: Substitue CColladaLoader with your actual class name
std::string CColladaLoader::mMeshID(){}
size_t CColladaLoader::mSubMesh(){}
std::string CColladaLoader::mMaterial(){}
bool CColladaLoader::CanRead(const std::string & pFile, IOSystem * pIOHandler, bool checkSig){}
q(const).aiImporterDesc CColladaLoader::GetInfo(){}
void CColladaLoader::SetupProperties(const Importer * pImp){}
void CColladaLoader::InternReadFile(const std::string & pFile, aiScene * pScene, IOSystem * pIOHandler){}
aiNode CColladaLoader::BuildHierarchy(const ColladaParser & pParser, const Collada::Node * pNode){}
void CColladaLoader::ResolveNodeInstances(const ColladaParser & pParser, const Collada::Node * pNode, const Collada::Node)> & resolved){}
void CColladaLoader::BuildMeshesForNode(const ColladaParser & pParser, const Collada::Node * pNode, aiNode * pTarget){}
aiMesh CColladaLoader::CreateMesh(const ColladaParser & pParser, const Collada::Mesh * pSrcMesh, const Collada::SubMesh & pSubMesh, const Collada::Controller * pSrcController, size_t pStartVertex, size_t pStartFace){}
void CColladaLoader::BuildCamerasForNode(const ColladaParser & pParser, const Collada::Node * pNode, aiNode * pTarget){}
void CColladaLoader::BuildLightsForNode(const ColladaParser & pParser, const Collada::Node * pNode, aiNode * pTarget){}
void CColladaLoader::StoreSceneMeshes(aiScene * pScene){}
void CColladaLoader::StoreSceneMaterials(aiScene * pScene){}
void CColladaLoader::StoreSceneLights(aiScene * pScene){}
void CColladaLoader::StoreSceneCameras(aiScene * pScene){}
void CColladaLoader::StoreSceneTextures(aiScene * pScene){}
void CColladaLoader::StoreAnimations(aiScene * pScene, const ColladaParser & pParser){}
void CColladaLoader::StoreAnimations(aiScene * pScene, const ColladaParser & pParser, const Collada::Animation * pSrcAnim, const std::string & pPrefix){}
void CColladaLoader::CreateAnimation(aiScene * pScene, const ColladaParser & pParser, const Collada::Animation * pSrcAnim, const std::string & pName){}
void CColladaLoader::BuildMaterials(ColladaParser & pParser, aiScene * pScene){}
void CColladaLoader::FillMaterials(const ColladaParser & pParser, aiScene * pScene){}
void CColladaLoader::ApplyVertexToEffectSemanticMapping(Collada::Sampler & sampler, const Collada::SemanticMappingTable & table){}
void CColladaLoader::AddTexture(aiMaterial & mat, const ColladaParser & pParser, const Collada::Effect & effect, const Collada::Sampler & sampler, aiTextureType type, unsigned int idx){}
void CColladaLoader::AddTexture(aiMaterial & mat, const ColladaParser & pParser, const Collada::Effect & effect, const Collada::Sampler & sampler, aiTextureType type){}
aiString CColladaLoader::FindFilenameForEffectTexture(const ColladaParser & pParser, const Collada::Effect & pEffect, const std::string & pName){}
void CColladaLoader::ConvertPath(aiString & ss){}
ai_real CColladaLoader::ReadFloat(const Collada::Accessor & pAccessor, const Collada::Data & pData, size_t pIndex, size_t pOffset){}
q(const).std::string CColladaLoader::ReadString(const Collada::Accessor & pAccessor, const Collada::Data & pData, size_t pIndex){}
void CColladaLoader::CollectNodes(const aiNode * pNode, const aiNode)> & poNodes){}
q(const).Collada::Node CColladaLoader::FindNode(const Collada::Node * pNode, const std::string & pName){}
q(const).Collada::Node CColladaLoader::FindNodeBySID(const Collada::Node * pNode, const std::string & pSID){}
std::string CColladaLoader::FindNameForNode(const Collada::Node * pNode){}
std::string CColladaLoader::mFileName(){}
std::map<(Assimp::ColladaMeshIndex,size_t)> CColladaLoader::mMeshIndexByID(){}
std::map<(std::string,size_t)> CColladaLoader::mMaterialIndexByName(){}
std::vector<(p.aiMesh)> CColladaLoader::mMeshes(){}
std::vector<(std::pair<(p.Collada::Effect,p.aiMaterial)>)> CColladaLoader::newMats(){}
std::vector<(p.aiCamera)> CColladaLoader::mCameras(){}
std::vector<(p.aiLight)> CColladaLoader::mLights(){}
std::vector<(p.aiTexture)> CColladaLoader::mTextures(){}
std::vector<(p.aiAnimation)> CColladaLoader::mAnims(){}
bool CColladaLoader::noSkeletonMesh(){}
bool CColladaLoader::ignoreUpDirection(){}
unsigned int CColladaLoader::mNodeNameCounter(){}
