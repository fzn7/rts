// TODO: Substitue CTerrainTextureGLSL with your actual class name
void CTerrainTextureGLSL::Setup(NodeSetupParams & params){}
void CTerrainTextureGLSL::Cleanup(){}
void CTerrainTextureGLSL::Setup(){}
void CTerrainTextureGLSL::Cleanup(){}
terrain::BufferTexture CTerrainTextureGLSL::source(){}
GLhandleARB CTerrainTextureGLSL::vertexShader(){}
GLhandleARB CTerrainTextureGLSL::fragmentShader(){}
GLhandleARB CTerrainTextureGLSL::program(){}
terrain::SimpleCopyShader CTerrainTextureGLSL::shader(){}
std::string CTerrainTextureGLSL::GetDebugDesc(){}
uint CTerrainTextureGLSL::GetVertexDataRequirements(){}
void CTerrainTextureGLSL::GetTextureUnits(BaseTexture * tex, int & imageUnit, int & coordUnit){}
void CTerrainTextureGLSL::BindTSM(Vector3 * buf, uint vertexSize){}
void CTerrainTextureGLSL::UnbindTSM(){}
std::vector<(p.BaseTexture)> CTerrainTextureGLSL::texUnits(){}
std::vector<(p.BaseTexture)> CTerrainTextureGLSL::texCoordGen(){}
GLhandleARB CTerrainTextureGLSL::vertexShader(){}
GLhandleARB CTerrainTextureGLSL::fragmentShader(){}
GLhandleARB CTerrainTextureGLSL::program(){}
GLint CTerrainTextureGLSL::tsmAttrib(){}
GLint CTerrainTextureGLSL::wsLightDirLocation(){}
GLint CTerrainTextureGLSL::wsEyePosLocation(){}
uint CTerrainTextureGLSL::vertBufReq(){}
std::string CTerrainTextureGLSL::debugstr(){}
GLint CTerrainTextureGLSL::shadowMapLocation(){}
GLint CTerrainTextureGLSL::shadowMatrixLocation(){}
GLint CTerrainTextureGLSL::shadowParamsLocation(){}
terrain::BufferTexture CTerrainTextureGLSL::renderBuffer(){}
void CTerrainTextureGLSL::Setup(NodeSetupParams & params){}
void CTerrainTextureGLSL::Cleanup(){}
void CTerrainTextureGLSL::BeginPass(const terrain::Blendmap)> & blendmaps, const terrain::TiledTexture)> & textures, int pass){}
void CTerrainTextureGLSL::BeginTexturing(){}
void CTerrainTextureGLSL::EndTexturing(){}
void CTerrainTextureGLSL::BuildNodeSetup(ShaderDef * shaderDef, RenderSetup * renderSetup){}
bool CTerrainTextureGLSL::SetupShader(IShaderSetup * shadercfg, NodeSetupParams & params){}
void CTerrainTextureGLSL::BeginBuild(){}
void CTerrainTextureGLSL::EndBuild(){}
int CTerrainTextureGLSL::MaxTextureUnits(){}
int CTerrainTextureGLSL::MaxTextureCoords(){}
terrain::GLSLBaseShader CTerrainTextureGLSL::curShader(){}
terrain::BufferTexture CTerrainTextureGLSL::buffer(){}
std::vector<(p.RenderSetup)> CTerrainTextureGLSL::renderSetups(){}
terrain::SimpleCopyShader CTerrainTextureGLSL::scShader(){}
