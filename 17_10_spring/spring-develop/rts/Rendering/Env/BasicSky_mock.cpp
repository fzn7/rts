// TODO: Substitue CBasicSky with your actual class name
void CBasicSky::Update(){}
void CBasicSky::Draw(){}
void CBasicSky::DrawSun(){}
void CBasicSky::UpdateSunDir(){}
void CBasicSky::UpdateSkyTexture(){}
void CBasicSky::CreateSkyDomeList(){}
void CBasicSky::InitSun(){}
void CBasicSky::UpdateSunFlare(){}
void CBasicSky::CreateCover(int baseX, int baseY, float * buf){}
void CBasicSky::CreateTransformVectors(){}
void CBasicSky::CreateRandMatrix(int ** matrix, float mod){}
void CBasicSky::CreateClouds(){}
void CBasicSky::UpdatePart(int ast, int aed, int a3cstart, int a4cstart){}
void CBasicSky::UpdateTexPartDot3(int x, int y, unsigned char * texp){}
void CBasicSky::UpdateTexPart(int x, int y, unsigned char * texp){}
void CBasicSky::UpdateSkyDir(){}
float3 CBasicSky::GetDirFromTexCoord(float x, float y){}
float CBasicSky::GetTexCoordFromDir(const float3 & dir){}
float3 CBasicSky::GetCoord(int x, int y){}
unsigned char CBasicSky::GetCloudThickness(int x, int y){}
float3 CBasicSky::skydir1(){}
float3 CBasicSky::skydir2(){}
unsigned int CBasicSky::skyTex(){}
unsigned int CBasicSky::skyDot3Tex(){}
unsigned int CBasicSky::cloudDot3Tex(){}
unsigned int CBasicSky::sunFlareTex(){}
unsigned char CBasicSky::skytexpart(){}
unsigned int CBasicSky::skyTexUpdateIter(){}
unsigned int CBasicSky::skyDomeList(){}
unsigned int CBasicSky::sunFlareList(){}
float CBasicSky::skyAngle(){}
float CBasicSky::domeheight(){}
float CBasicSky::domeWidth(){}
float CBasicSky::sunTexCoordX(){}
float CBasicSky::sunTexCoordY(){}
int CBasicSky::randMatrix(){}
int CBasicSky::rawClouds(){}
int CBasicSky::blendMatrix(){}
unsigned char CBasicSky::cloudThickness(){}
float CBasicSky::covers(){}
int CBasicSky::oldCoverBaseX(){}
int CBasicSky::oldCoverBaseY(){}
unsigned char CBasicSky::alphaTransform(){}
unsigned char CBasicSky::thicknessTransform(){}
bool CBasicSky::cloudDown(){}
int CBasicSky::ydif(){}
int CBasicSky::updatecounter(){}
