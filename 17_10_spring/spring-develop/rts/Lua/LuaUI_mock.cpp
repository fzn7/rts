// TODO: Substitue CLuaUI with your actual class name
bool CLuaUI::LoadHandler(){}
bool CLuaUI::FreeHandler(){}
void CLuaUI::UpdateTeams(){}
bool CLuaUI::HasCallIn(lua_State * L, const string & name){}
bool CLuaUI::LayoutButtons(int & xButtons, int & yButtons, const vector<(SCommandDescription)> & cmds, vector<(int)> & removeCmds, vector<(SCommandDescription)> & customCmds, vector<(int)> & onlyTextureCmds, vector<(CLuaUI::ReStringPair)> & reTextureCmds, vector<(CLuaUI::ReStringPair)> & reNamedCmds, vector<(CLuaUI::ReStringPair)> & reTooltipCmds, vector<(CLuaUI::ReParamsPair)> & reParamsCmds, spring::unordered_map<(int,int)> & iconList, string & menuName){}
bool CLuaUI::ConfigCommand(const string & command){}
void CLuaUI::ShockFront(const float3 & pos, float power, float areaOfEffect, const float * distMod){}
void CLuaUI::ShockFront(const float3 & pos, float power, float areaOfEffect){}
string CLuaUI::LoadFile(const string & name, const std::string & mode){}
bool CLuaUI::LoadCFunctions(lua_State * L){}
void CLuaUI::InitLuaSocket(lua_State * L){}
bool CLuaUI::BuildCmdDescTable(lua_State * L, const vector<(SCommandDescription)> & cmds){}
bool CLuaUI::GetLuaIntMap(lua_State * L, int index, spring::unordered_map<(int,int)> & intList){}
bool CLuaUI::GetLuaIntList(lua_State * L, int index, vector<(int)> & intList){}
bool CLuaUI::GetLuaReStringList(lua_State * L, int index, vector<(CLuaUI::ReStringPair)> & reStringCmds){}
bool CLuaUI::GetLuaReParamsList(lua_State * L, int index, vector<(CLuaUI::ReParamsPair)> & reParamsCmds){}
bool CLuaUI::GetLuaCmdDescList(lua_State * L, int index, vector<(SCommandDescription)> & customCmds){}
CLuaUI::QueuedAction CLuaUI::queuedAction(){}
bool CLuaUI::haveShockFront(){}
float CLuaUI::shockFrontMinArea(){}
float CLuaUI::shockFrontMinPower(){}
float CLuaUI::shockFrontDistAdj(){}
int CLuaUI::SetShockFrontFactors(lua_State * L){}
CLuaUI CLuaUI::luaUI(){}
