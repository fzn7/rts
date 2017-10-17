// TODO: Substitue CLuaContextData with your actual class name
luaContextData CLuaContextData::operator =(const luaContextData & lcd){}
luaContextData CLuaContextData::operator =(luaContextData lcd){}
CLuaHandle CLuaContextData::owner(){}
spring::recursive_mutex CLuaContextData::luamutex(){}
LuaMemPool CLuaContextData::memPool(){}
LuaParser CLuaContextData::parser(){}
bool CLuaContextData::synced(){}
bool CLuaContextData::allowChanges(){}
bool CLuaContextData::drawingEnabled(){}
int CLuaContextData::running(){}
bool CLuaContextData::fullCtrl(){}
bool CLuaContextData::fullRead(){}
int CLuaContextData::ctrlTeam(){}
int CLuaContextData::readTeam(){}
int CLuaContextData::readAllyTeam(){}
int CLuaContextData::selectTeam(){}
LuaShaders CLuaContextData::shaders(){}
LuaTextures CLuaContextData::textures(){}
LuaFBOs CLuaContextData::fbos(){}
LuaRBOs CLuaContextData::rbos(){}
CLuaDisplayLists CLuaContextData::displayLists(){}
GLMatrixStateTracker CLuaContextData::glMatrixTracker(){}
