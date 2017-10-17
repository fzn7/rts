// TODO: Substitue CProcessHelper with your actual class name
void CProcessHelper::Assimp::ConvertListToStrings(const std::string & in, std::list<(std::string)> & out){}
void CProcessHelper::Assimp::FindAABBTransformed(const aiMesh * mesh, aiVector3D & min, aiVector3D & max, const aiMatrix4x4 & m){}
void CProcessHelper::Assimp::FindMeshCenter(aiMesh * mesh, aiVector3D & out, aiVector3D & min, aiVector3D & max){}
void CProcessHelper::Assimp::FindSceneCenter(aiScene * scene, aiVector3D & out, aiVector3D & min, aiVector3D & max){}
void CProcessHelper::Assimp::FindMeshCenterTransformed(aiMesh * mesh, aiVector3D & out, aiVector3D & min, aiVector3D & max, const aiMatrix4x4 & m){}
void CProcessHelper::Assimp::FindMeshCenter(aiMesh * mesh, aiVector3D & out){}
void CProcessHelper::Assimp::FindMeshCenterTransformed(aiMesh * mesh, aiVector3D & out, const aiMatrix4x4 & m){}
ai_real CProcessHelper::Assimp::ComputePositionEpsilon(const aiMesh * pMesh){}
ai_real CProcessHelper::Assimp::ComputePositionEpsilon(const const aiMesh ** pMeshes, size_t num){}
unsigned int CProcessHelper::Assimp::GetMeshVFormatUnique(const aiMesh * pcMesh){}
std::pair<(unsigned int,float)> CProcessHelper::Assimp::PerVertexWeight(){}
std::vector<(Assimp::PerVertexWeight)> CProcessHelper::Assimp::VertexWeightTable(){}
Assimp::VertexWeightTable CProcessHelper::Assimp::ComputeVertexBoneWeightTable(const aiMesh * pMesh){}
q(const).char CProcessHelper::Assimp::TextureTypeToString(aiTextureType in){}
q(const).char CProcessHelper::Assimp::MappingTypeToString(aiTextureMapping in){}
aiMesh CProcessHelper::Assimp::MakeSubmesh(const aiMesh * superMesh, const std::vector<(unsigned int)> & subMeshFaces, unsigned int subFlags){}
