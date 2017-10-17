// TODO: Substitue CAssbinLoader with your actual class name
bool CAssbinLoader::shortened(){}
bool CAssbinLoader::compressed(){}
bool CAssbinLoader::CanRead(const std::string & pFile, IOSystem * pIOHandler, bool checkSig){}
q(const).aiImporterDesc CAssbinLoader::GetInfo(){}
void CAssbinLoader::InternReadFile(const std::string & pFile, aiScene * pScene, IOSystem * pIOHandler){}
void CAssbinLoader::ReadBinaryScene(IOStream * stream, aiScene * pScene){}
void CAssbinLoader::ReadBinaryNode(IOStream * stream, aiNode ** mRootNode){}
void CAssbinLoader::ReadBinaryMesh(IOStream * stream, aiMesh * mesh){}
void CAssbinLoader::ReadBinaryBone(IOStream * stream, aiBone * bone){}
void CAssbinLoader::ReadBinaryMaterial(IOStream * stream, aiMaterial * mat){}
void CAssbinLoader::ReadBinaryMaterialProperty(IOStream * stream, aiMaterialProperty * prop){}
void CAssbinLoader::ReadBinaryNodeAnim(IOStream * stream, aiNodeAnim * nd){}
void CAssbinLoader::ReadBinaryAnim(IOStream * stream, aiAnimation * anim){}
void CAssbinLoader::ReadBinaryTexture(IOStream * stream, aiTexture * tex){}
void CAssbinLoader::ReadBinaryLight(IOStream * stream, aiLight * l){}
void CAssbinLoader::ReadBinaryCamera(IOStream * stream, aiCamera * cam){}
