// TODO: Substitue CLuaFBOs with your actual class name
q(const).LuaFBOs::FBO CLuaFBOs::GetLuaFBO(lua_State * L, int index){}
bool CLuaFBOs::PushEntries(lua_State * L){}
std::vector<(p.LuaFBOs::FBO)> CLuaFBOs::fbos(){}
bool CLuaFBOs::CreateMetatable(lua_State * L){}
bool CLuaFBOs::AttachObject(lua_State * L, int index, LuaFBOs::FBO * fbo, GLenum attachID, GLenum attachTarget, GLenum attachLevel){}
bool CLuaFBOs::AttachObject(lua_State * L, int index, LuaFBOs::FBO * fbo, GLenum attachID, GLenum attachTarget){}
bool CLuaFBOs::AttachObject(lua_State * L, int index, LuaFBOs::FBO * fbo, GLenum attachID){}
bool CLuaFBOs::ApplyAttachment(lua_State * L, int index, LuaFBOs::FBO * fbo, GLenum attachID){}
bool CLuaFBOs::ApplyDrawBuffers(lua_State * L, int index){}
int CLuaFBOs::meta_gc(lua_State * L){}
int CLuaFBOs::meta_index(lua_State * L){}
int CLuaFBOs::meta_newindex(lua_State * L){}
int CLuaFBOs::CreateFBO(lua_State * L){}
int CLuaFBOs::DeleteFBO(lua_State * L){}
int CLuaFBOs::IsValidFBO(lua_State * L){}
int CLuaFBOs::ActiveFBO(lua_State * L){}
int CLuaFBOs::UnsafeSetFBO(lua_State * L){}
int CLuaFBOs::BlitFBO(lua_State * L){}
