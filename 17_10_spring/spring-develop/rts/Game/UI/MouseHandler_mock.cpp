// TODO: Substitue CMouseHandler with your actual class name
q(const).int CMouseHandler::NUM_BUTTONS(){}
CMouseHandler CMouseHandler::GetOrReloadInstance(){}
void CMouseHandler::ChangeCursor(const std::string & cmdName, const float scale){}
void CMouseHandler::ChangeCursor(const std::string & cmdName){}
void CMouseHandler::ReloadCursors(){}
void CMouseHandler::Update(){}
void CMouseHandler::UpdateCursors(){}
std::string CMouseHandler::GetCurrentTooltip(){}
void CMouseHandler::HideMouse(){}
void CMouseHandler::ShowMouse(){}
void CMouseHandler::ToggleMiddleClickScroll(){}
void CMouseHandler::WarpMouse(int x, int y){}
void CMouseHandler::DrawSelectionBox(){}
void CMouseHandler::DrawCursor(){}
void CMouseHandler::MouseRelease(int x, int y, int button){}
void CMouseHandler::MousePress(int x, int y, int button){}
void CMouseHandler::MouseMove(int x, int y, int dx, int dy){}
void CMouseHandler::MouseWheel(float delta){}
bool CMouseHandler::AssignMouseCursor(const std::string & cmdName, const std::string & fileName, CMouseCursor::HotSpot hotSpot, bool overwrite){}
bool CMouseHandler::ReplaceMouseCursor(const std::string & oldName, const std::string & newName, CMouseCursor::HotSpot hotSpot){}
void CMouseHandler::ToggleHwCursor(const bool & enable){}
void CMouseHandler::ConfigNotify(const std::string & key, const std::string & value){}
void CMouseHandler::SetCursor(const std::string & cmdName, const bool forceRebind){}
void CMouseHandler::SetCursor(const std::string & cmdName){}
void CMouseHandler::GetSelectionBoxCoeff(const float3 & pos1, const float3 & dir1, const float3 & pos2, const float3 & dir2, float2 & topright, float2 & btmleft){}
void CMouseHandler::DrawScrollCursor(){}
void CMouseHandler::DrawFPSCursor(){}
int CMouseHandler::lastx(){}
int CMouseHandler::lasty(){}
int CMouseHandler::activeButtonIdx(){}
int CMouseHandler::activeCursorIdx(){}
bool CMouseHandler::locked(){}
bool CMouseHandler::wasLocked(){}
bool CMouseHandler::offscreen(){}
bool CMouseHandler::hide(){}
bool CMouseHandler::hwHide(){}
bool CMouseHandler::hardwareCursor(){}
bool CMouseHandler::invertMouse(){}
float CMouseHandler::cursorScale(){}
float CMouseHandler::dragScrollThreshold(){}
float CMouseHandler::scrollx(){}
float CMouseHandler::scrolly(){}
float CMouseHandler::doubleClickTime(){}
float CMouseHandler::scrollWheelSpeed(){}
float CMouseHandler::crossSize(){}
float CMouseHandler::crossAlpha(){}
float CMouseHandler::crossMoveScale(){}
CMouseHandler::ButtonPressEvt CMouseHandler::buttons(){}
float3 CMouseHandler::dir(){}
std::string CMouseHandler::newCursor(){}
std::string CMouseHandler::cursorText(){}
std::vector<(CMouseCursor)> CMouseHandler::loadedCursors(){}
spring::unordered_map<(std::string,size_t)> CMouseHandler::cursorFileMap(){}
spring::unordered_map<(std::string,size_t)> CMouseHandler::cursorCommandMap(){}
q(const).CUnit CMouseHandler::lastClicked(){}
CMouseHandler CMouseHandler::mouse(){}
