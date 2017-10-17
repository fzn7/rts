// TODO: Substitue CLuaTextures with your actual class name
q(const).char CLuaTextures::prefix(){}
std::string CLuaTextures::Create(const LuaTextures::Texture & tex){}
bool CLuaTextures::Bind(const std::string & name){}
bool CLuaTextures::Free(const std::string & name){}
bool CLuaTextures::FreeFBO(const std::string & name){}
void CLuaTextures::FreeAll(){}
size_t CLuaTextures::GetIdx(const std::string & name){}
q(const).LuaTextures::Texture CLuaTextures::GetInfo(const std::string & name){}
int CLuaTextures::lastCode(){}
spring::unordered_map<(std::string,size_t)> CLuaTextures::textureMap(){}
std::vector<(LuaTextures::Texture)> CLuaTextures::textureVec(){}
std::vector<(size_t)> CLuaTextures::freeIndices(){}
