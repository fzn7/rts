// TODO: Substitue CTerrainTexEnvCombine with your actual class name
terrain::TexEnvStage::Operation CTerrainTexEnvCombine::operation(){}
terrain::TexEnvStage::Source CTerrainTexEnvCombine::source(){}
BaseTexture CTerrainTexEnvCombine::srcTexture(){}
std::string CTerrainTexEnvCombine::GetDebugDesc(){}
uint CTerrainTexEnvCombine::GetVertexDataRequirements(){}
void CTerrainTexEnvCombine::GetTextureUnits(BaseTexture * tex, int & imageUnit, int & coordUnit){}
int CTerrainTexEnvCombine::usedTexUnits(){}
std::vector<(terrain::TexEnvStage)> CTerrainTexEnvCombine::stages(){}
void CTerrainTexEnvCombine::SetTexCoordGen(float * tgv){}
void CTerrainTexEnvCombine::BeginTexturing(){}
void CTerrainTexEnvCombine::EndTexturing(){}
void CTerrainTexEnvCombine::BeginPass(const terrain::Blendmap)> & blendmaps, const terrain::TiledTexture)> & textures, int pass){}
void CTerrainTexEnvCombine::BuildNodeSetup(ShaderDef * shaderDef, RenderSetup * renderSetup){}
bool CTerrainTexEnvCombine::SetupShader(IShaderSetup * shadercfg, NodeSetupParams & params){}
int CTerrainTexEnvCombine::MaxTextureUnits(){}
int CTerrainTexEnvCombine::MaxTextureCoords(){}
int CTerrainTexEnvCombine::maxtu(){}
bool CTerrainTexEnvCombine::hasDot3(){}
GLuint CTerrainTexEnvCombine::whiteTexture(){}
terrain::NodeTexEnvSetup CTerrainTexEnvCombine::lastShader(){}
terrain::NodeTexEnvSetup CTerrainTexEnvCombine::curSetup(){}
