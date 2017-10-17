// TODO: Substitue CSMFRenderState with your actual class name
ISMFRenderState CSMFRenderState::GetInstance(bool haveARB, bool haveGLSL, bool luaShader){}
bool CSMFRenderState::Init(const CSMFGroundDrawer * smfGroundDrawer){}
void CSMFRenderState::Kill(){}
void CSMFRenderState::Update(const CSMFGroundDrawer * smfGroundDrawer, const LuaMapShaderData * luaMapShaderData){}
bool CSMFRenderState::HasValidShader(const DrawPass::e & drawPass){}
bool CSMFRenderState::CanEnable(const CSMFGroundDrawer * smfGroundDrawer){}
bool CSMFRenderState::CanDrawForward(){}
bool CSMFRenderState::CanDrawDeferred(){}
void CSMFRenderState::Enable(const CSMFGroundDrawer * smfGroundDrawer, const DrawPass::e & drawPass){}
void CSMFRenderState::Disable(const CSMFGroundDrawer * smfGroundDrawer, const DrawPass::e & drawPass){}
void CSMFRenderState::SetSquareTexGen(const int sqx, const int sqy){}
void CSMFRenderState::SetCurrentShader(const DrawPass::e & drawPass){}
void CSMFRenderState::UpdateCurrentShaderSky(const ISkyLight * skyLight){}
bool CSMFRenderState::CanEnable(const CSMFGroundDrawer * smfGroundDrawer){}
void CSMFRenderState::Enable(const CSMFGroundDrawer * smfGroundDrawer, const DrawPass::e & drawPass){}
void CSMFRenderState::Disable(const CSMFGroundDrawer * smfGroundDrawer, const DrawPass::e & drawPass){}
void CSMFRenderState::SetSquareTexGen(const int sqx, const int sqy){}
bool CSMFRenderState::Init(const CSMFGroundDrawer * smfGroundDrawer){}
void CSMFRenderState::Kill(){}
bool CSMFRenderState::HasValidShader(const DrawPass::e & drawPass){}
bool CSMFRenderState::CanEnable(const CSMFGroundDrawer * smfGroundDrawer){}
void CSMFRenderState::Enable(const CSMFGroundDrawer * smfGroundDrawer, const DrawPass::e & drawPass){}
void CSMFRenderState::Disable(const CSMFGroundDrawer * smfGroundDrawer, const DrawPass::e & drawPass){}
void CSMFRenderState::SetSquareTexGen(const int sqx, const int sqy){}
void CSMFRenderState::SetCurrentShader(const DrawPass::e & drawPass){}
void CSMFRenderState::UpdateCurrentShaderSky(const ISkyLight * skyLight){}
std::array<(p.Shader::IProgramObject,SMFRenderStateARB::ARB_SHADER_COUNT)> CSMFRenderState::arbShaders(){}
bool CSMFRenderState::Init(const CSMFGroundDrawer * smfGroundDrawer){}
void CSMFRenderState::Kill(){}
void CSMFRenderState::Update(const CSMFGroundDrawer * smfGroundDrawer, const LuaMapShaderData * luaMapShaderData){}
bool CSMFRenderState::HasValidShader(const DrawPass::e & drawPass){}
bool CSMFRenderState::CanEnable(const CSMFGroundDrawer * smfGroundDrawer){}
void CSMFRenderState::Enable(const CSMFGroundDrawer * smfGroundDrawer, const DrawPass::e & drawPass){}
void CSMFRenderState::Disable(const CSMFGroundDrawer * smfGroundDrawer, const DrawPass::e & drawPass){}
void CSMFRenderState::SetSquareTexGen(const int sqx, const int sqy){}
void CSMFRenderState::SetCurrentShader(const DrawPass::e & drawPass){}
void CSMFRenderState::UpdateCurrentShaderSky(const ISkyLight * skyLight){}
std::array<(p.Shader::IProgramObject,SMFRenderStateGLSL::GLSL_SHADER_COUNT)> CSMFRenderState::glslShaders(){}
bool CSMFRenderState::useLuaShaders(){}
