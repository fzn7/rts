// TODO: Substitue CGrassDrawer with your actual class name
void CGrassDrawer::Draw(){}
void CGrassDrawer::DrawShadow(){}
void CGrassDrawer::AddGrass(const float3 & pos){}
void CGrassDrawer::ResetPos(const float3 & pos){}
void CGrassDrawer::RemoveGrass(const float3 & pos){}
unsigned char CGrassDrawer::GetGrass(const float3 & pos){}
void CGrassDrawer::ChangeDetail(int detail){}
void CGrassDrawer::ConfigNotify(const std::string & key, const std::string & value){}
void CGrassDrawer::UnsyncedHeightMapUpdate(const SRectangle & rect){}
void CGrassDrawer::Update(){}
void CGrassDrawer::LoadGrassShaders(){}
void CGrassDrawer::CreateGrassBladeTex(unsigned char * buf){}
void CGrassDrawer::CreateFarTex(){}
void CGrassDrawer::CreateGrassDispList(int listNum){}
void CGrassDrawer::EnableShader(const CGrassDrawer::GrassShaderProgram type){}
void CGrassDrawer::SetupGlStateNear(){}
void CGrassDrawer::ResetGlStateNear(){}
void CGrassDrawer::SetupGlStateFar(){}
void CGrassDrawer::ResetGlStateFar(){}
void CGrassDrawer::DrawNear(const std::vector<(CGrassDrawer::InviewNearGrass)> & inviewGrass){}
void CGrassDrawer::DrawFarBillboards(const CGrassDrawer::GrassStruct)> & inviewGrass){}
void CGrassDrawer::DrawNearBillboards(const std::vector<(CGrassDrawer::InviewNearGrass)> & inviewNearGrass){}
void CGrassDrawer::DrawBillboard(const int x, const int y, const float dist, VA_TYPE_TN * va_tn){}
void CGrassDrawer::ResetPos(const int grassBlockX, const int grassBlockZ){}
int CGrassDrawer::blocksX(){}
int CGrassDrawer::blocksY(){}
unsigned int CGrassDrawer::grassDL(){}
unsigned int CGrassDrawer::grassBladeTex(){}
unsigned int CGrassDrawer::farTex(){}
CVertexArray CGrassDrawer::farnearVA(){}
std::vector<(CGrassDrawer::GrassStruct)> CGrassDrawer::grass(){}
std::vector<(unsigned char)> CGrassDrawer::grassMap(){}
std::vector<(p.Shader::IProgramObject)> CGrassDrawer::grassShaders(){}
Shader::IProgramObject CGrassDrawer::grassShader(){}
float CGrassDrawer::maxGrassDist(){}
float CGrassDrawer::maxDetailedDist(){}
int CGrassDrawer::detailedBlocks(){}
int CGrassDrawer::numTurfs(){}
int CGrassDrawer::strawPerTurf(){}
float3 CGrassDrawer::oldCamPos(){}
float3 CGrassDrawer::oldCamDir(){}
int CGrassDrawer::lastVisibilityUpdate(){}
bool CGrassDrawer::grassOff(){}
bool CGrassDrawer::updateBillboards(){}
bool CGrassDrawer::updateVisibility(){}
CGrassDrawer CGrassDrawer::grassDrawer(){}
