// TODO: Substitue CAdvSky with your actual class name
void CAdvSky::Update(){}
void CAdvSky::Draw(){}
void CAdvSky::DrawSun(){}
void CAdvSky::UpdateSunDir(){}
void CAdvSky::UpdateSkyTexture(){}
void CAdvSky::CreateSkyDomeList(){}
void CAdvSky::InitSun(){}
void CAdvSky::UpdateSunFlare(){}
void CAdvSky::CreateCover(int baseX, int baseY, float * buf){}
void CAdvSky::CreateTransformVectors(){}
void CAdvSky::CreateRandMatrix(int ** matrix, float mod){}
void CAdvSky::CreateRandDetailMatrix(unsigned char * matrix, int size){}
void CAdvSky::CreateClouds(){}
void CAdvSky::UpdatePart(int ast, int aed, int a3cstart, int a4cstart){}
void CAdvSky::UpdateTexPartDot3(int x, int y, unsigned char * texp){}
void CAdvSky::UpdateTexPart(int x, int y, unsigned char * texp){}
void CAdvSky::UpdateSkyDir(){}
float3 CAdvSky::GetDirFromTexCoord(float x, float y){}
float CAdvSky::GetTexCoordFromDir(const float3 & dir){}
float3 CAdvSky::GetCoord(int x, int y){}
void CAdvSky::CreateDetailTex(){}
FBO CAdvSky::fbo(){}
float3 CAdvSky::skydir1(){}
float3 CAdvSky::skydir2(){}
GLuint CAdvSky::cdtex(){}
unsigned int CAdvSky::cloudFP(){}
bool CAdvSky::drawFlare(){}
GLuint CAdvSky::detailTextures(){}
bool CAdvSky::cloudDetailDown(){}
unsigned char CAdvSky::cloudTexMem(){}
unsigned int CAdvSky::skyTex(){}
unsigned int CAdvSky::skyDot3Tex(){}
unsigned int CAdvSky::cloudDot3Tex(){}
unsigned int CAdvSky::sunTex(){}
unsigned int CAdvSky::sunFlareTex(){}
unsigned char CAdvSky::skytexpart(){}
unsigned int CAdvSky::skyTexUpdateIter(){}
unsigned int CAdvSky::skyDomeList(){}
unsigned int CAdvSky::sunFlareList(){}
float CAdvSky::skyAngle(){}
float CAdvSky::domeheight(){}
float CAdvSky::domeWidth(){}
float CAdvSky::sunTexCoordX(){}
float CAdvSky::sunTexCoordY(){}
int CAdvSky::randMatrix(){}
int CAdvSky::rawClouds(){}
int CAdvSky::blendMatrix(){}
unsigned char CAdvSky::cloudThickness(){}
float CAdvSky::covers(){}
int CAdvSky::oldCoverBaseX(){}
int CAdvSky::oldCoverBaseY(){}
unsigned char CAdvSky::alphaTransform(){}
unsigned char CAdvSky::thicknessTransform(){}
bool CAdvSky::cloudDown(){}
int CAdvSky::ydif(){}
int CAdvSky::updatecounter(){}
