// TODO: Substitue CMiniMap with your actual class name
bool CMiniMap::MousePress(int x, int y, int button){}
void CMiniMap::MouseMove(int x, int y, int dx, int dy, int button){}
void CMiniMap::MouseRelease(int x, int y, int button){}
void CMiniMap::MoveView(int x, int y){}
bool CMiniMap::IsAbove(int x, int y){}
std::string CMiniMap::GetTooltip(int x, int y){}
void CMiniMap::Draw(){}
void CMiniMap::DrawForReal(bool useGeom, bool updateTex){}
void CMiniMap::DrawForReal(bool useGeom){}
void CMiniMap::DrawForReal(){}
void CMiniMap::Update(){}
void CMiniMap::ConfigCommand(const std::string & command){}
float3 CMiniMap::GetMapPosition(int x, int y){}
CUnit CMiniMap::GetSelectUnit(const float3 & pos){}
void CMiniMap::UpdateGeometry(){}
void CMiniMap::SetGeometry(int px, int py, int sx, int sy){}
void CMiniMap::AddNotification(float3 pos, float3 color, float alpha){}
void CMiniMap::SetSlaveMode(bool value){}
void CMiniMap::ApplyConstraintsMatrix(){}
void CMiniMap::ParseGeometry(const std::string & geostr){}
void CMiniMap::ToggleMaximized(bool maxspect){}
void CMiniMap::SetMaximizedGeometry(){}
void CMiniMap::SelectUnits(int x, int y){}
void CMiniMap::ProxyMousePress(int x, int y, int button){}
void CMiniMap::ProxyMouseRelease(int x, int y, int button){}
bool CMiniMap::RenderCachedTexture(bool useGeom){}
void CMiniMap::DrawBackground(){}
void CMiniMap::DrawUnitIcons(){}
void CMiniMap::DrawUnitRanges(){}
void CMiniMap::DrawWorldStuff(){}
void CMiniMap::DrawCameraFrustumAndMouseSelection(){}
void CMiniMap::SetClipPlanes(const bool lua){}
void CMiniMap::DrawFrame(){}
void CMiniMap::DrawNotes(){}
void CMiniMap::DrawButtons(){}
void CMiniMap::DrawMinimizedButton(){}
void CMiniMap::DrawUnitHighlight(const CUnit * unit){}
void CMiniMap::DrawCircle(const float3 & pos, float radius){}
void CMiniMap::DrawSquare(const float3 & pos, float xsize, float zsize){}
q(const).icon::CIconData CMiniMap::GetUnitIcon(const CUnit * unit, float & scale){}
void CMiniMap::UpdateTextureCache(){}
void CMiniMap::ResizeTextureCache(){}
void CMiniMap::DrawSurfaceCircle(const float3 & pos, float radius, unsigned int resolution){}
void CMiniMap::DrawSurfaceSquare(const float3 & pos, float xsize, float zsize){}
int2 CMiniMap::curPos(){}
int2 CMiniMap::curDim(){}
int2 CMiniMap::tmpPos(){}
int2 CMiniMap::oldPos(){}
int2 CMiniMap::oldDim(){}
float CMiniMap::unitBaseSize(){}
float CMiniMap::unitExponent(){}
float CMiniMap::unitSizeX(){}
float CMiniMap::unitSizeY(){}
float CMiniMap::unitSelectRadius(){}
bool CMiniMap::fullProxy(){}
bool CMiniMap::proxyMode(){}
bool CMiniMap::selecting(){}
bool CMiniMap::maxspect(){}
bool CMiniMap::maximized(){}
bool CMiniMap::minimized(){}
bool CMiniMap::mouseLook(){}
bool CMiniMap::mouseMove(){}
bool CMiniMap::mouseResize(){}
bool CMiniMap::slaveDrawMode(){}
int CMiniMap::buttonSize(){}
bool CMiniMap::showButtons(){}
CMiniMap::IntBox CMiniMap::mapBox(){}
CMiniMap::IntBox CMiniMap::buttonBox(){}
CMiniMap::IntBox CMiniMap::moveBox(){}
CMiniMap::IntBox CMiniMap::resizeBox(){}
CMiniMap::IntBox CMiniMap::minimizeBox(){}
CMiniMap::IntBox CMiniMap::maximizeBox(){}
int CMiniMap::lastWindowSizeX(){}
int CMiniMap::lastWindowSizeY(){}
bool CMiniMap::drawProjectiles(){}
bool CMiniMap::useIcons(){}
int CMiniMap::drawCommands(){}
float CMiniMap::cursorScale(){}
bool CMiniMap::simpleColors(){}
SColor CMiniMap::myColor(){}
SColor CMiniMap::allyColor(){}
SColor CMiniMap::enemyColor(){}
bool CMiniMap::renderToTexture(){}
FBO CMiniMap::fbo(){}
FBO CMiniMap::fboResolve(){}
bool CMiniMap::multisampledFBO(){}
GLuint CMiniMap::minimapTex(){}
int2 CMiniMap::minimapTexSize(){}
float CMiniMap::minimapRefreshRate(){}
GLuint CMiniMap::buttonsTexture(){}
GLuint CMiniMap::circleLists(){}
q(const).int CMiniMap::circleListsCount(){}
std::deque<(CMiniMap::Notification)> CMiniMap::notes(){}
CUnit CMiniMap::lastClicked(){}
CMiniMap CMiniMap::minimap(){}
