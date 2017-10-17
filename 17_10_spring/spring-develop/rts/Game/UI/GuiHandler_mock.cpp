// TODO: Substitue CGuiHandler with your actual class name
void CGuiHandler::Update(){}
void CGuiHandler::Draw(){}
void CGuiHandler::DrawMapStuff(bool onMinimap){}
void CGuiHandler::DrawCentroidCursor(){}
bool CGuiHandler::AboveGui(int x, int y){}
bool CGuiHandler::KeyPressed(int key, bool isRepeat){}
bool CGuiHandler::KeyReleased(int key){}
bool CGuiHandler::MousePress(int x, int y, int button){}
void CGuiHandler::MouseRelease(int x, int y, int button, const float3 & cameraPos, const float3 & mouseDir){}
bool CGuiHandler::IsAbove(int x, int y){}
std::string CGuiHandler::GetTooltip(int x, int y){}
std::string CGuiHandler::GetBuildTooltip(){}
Command CGuiHandler::GetOrderPreview(){}
Command CGuiHandler::GetCommand(int mouseX, int mouseY, int buttonHint, bool preview, const float3 & cameraPos, const float3 & mouseDir){}
std::vector<(BuildInfo)> CGuiHandler::GetBuildPos(const BuildInfo & startInfo, const BuildInfo & endInfo, const float3 & cameraPos, const float3 & mouseDir){}
bool CGuiHandler::EnableLuaUI(bool enableCommand){}
bool CGuiHandler::DisableLuaUI(bool layoutIcons){}
bool CGuiHandler::DisableLuaUI(){}
bool CGuiHandler::LoadConfig(const std::string & cfg){}
bool CGuiHandler::ReloadConfigFromFile(const std::string & fileName){}
bool CGuiHandler::ReloadConfigFromString(const std::string & cfg){}
void CGuiHandler::RunLayoutCommand(const std::string & command){}
void CGuiHandler::RunCustomCommands(const std::vector<(std::string)> & cmds, bool rightMouseButton){}
bool CGuiHandler::GetQueueKeystate(){}
int CGuiHandler::GetDefaultCommand(int x, int y, const float3 & cameraPos, const float3 & mouseDir){}
bool CGuiHandler::SetActiveCommand(int cmdIndex, bool rightMouseButton){}
bool CGuiHandler::SetActiveCommand(int cmdIndex, int button, bool leftMouseButton, bool rightMouseButton, bool alt, bool ctrl, bool meta, bool shift){}
bool CGuiHandler::SetActiveCommand(const Action & action, const CKeySet & ks, int actionIndex){}
void CGuiHandler::SetBuildFacing(unsigned int facing){}
void CGuiHandler::SetBuildSpacing(int spacing){}
void CGuiHandler::LayoutIcons(bool useSelectionPage){}
std::vector<(SCommandDescription)> CGuiHandler::commands(){}
int CGuiHandler::inCommand(){}
int CGuiHandler::buildFacing(){}
int CGuiHandler::buildSpacing(){}
void CGuiHandler::GiveCommand(Command & cmd, bool fromUser){}
void CGuiHandler::GiveCommand(Command & cmd){}
void CGuiHandler::GiveCommandsNow(){}
bool CGuiHandler::LayoutCustomIcons(bool useSelectionPage){}
void CGuiHandler::ResizeIconArray(size_t size){}
void CGuiHandler::AppendPrevAndNext(std::vector<(SCommandDescription)> & cmds){}
void CGuiHandler::ConvertCommands(std::vector<(SCommandDescription)> & cmds){}
int CGuiHandler::FindInCommandPage(){}
void CGuiHandler::RevertToCmdDesc(const SCommandDescription & cmdDesc, bool defaultCommand, bool samePage){}
unsigned char CGuiHandler::CreateOptions(bool rightMouseButton){}
unsigned char CGuiHandler::CreateOptions(int button){}
void CGuiHandler::FinishCommand(int button){}
void CGuiHandler::SetShowingMetal(bool show){}
float CGuiHandler::GetNumberInput(const SCommandDescription & cmdDesc){}
void CGuiHandler::ProcessFrontPositions(float3 & pos0, const float3 & pos1){}
void CGuiHandler::DrawButtons(){}
void CGuiHandler::DrawCustomButton(const CGuiHandler::IconInfo & icon, bool highlight){}
bool CGuiHandler::DrawUnitBuildIcon(const CGuiHandler::IconInfo & icon, int unitDefID){}
bool CGuiHandler::DrawTexture(const CGuiHandler::IconInfo & icon, const std::string & texName){}
void CGuiHandler::DrawName(const CGuiHandler::IconInfo & icon, const std::string & text, bool offsetForLEDs){}
void CGuiHandler::DrawNWtext(const CGuiHandler::IconInfo & icon, const std::string & text){}
void CGuiHandler::DrawSWtext(const CGuiHandler::IconInfo & icon, const std::string & text){}
void CGuiHandler::DrawNEtext(const CGuiHandler::IconInfo & icon, const std::string & text){}
void CGuiHandler::DrawSEtext(const CGuiHandler::IconInfo & icon, const std::string & text){}
void CGuiHandler::DrawPrevArrow(const CGuiHandler::IconInfo & icon){}
void CGuiHandler::DrawNextArrow(const CGuiHandler::IconInfo & icon){}
void CGuiHandler::DrawHilightQuad(const CGuiHandler::IconInfo & icon){}
void CGuiHandler::DrawIconFrame(const CGuiHandler::IconInfo & icon){}
void CGuiHandler::DrawOptionLEDs(const CGuiHandler::IconInfo & icon){}
void CGuiHandler::DrawMenuName(){}
void CGuiHandler::DrawSelectionInfo(){}
void CGuiHandler::DrawNumberInput(){}
void CGuiHandler::DrawMiniMapMarker(const float3 & cameraPos){}
void CGuiHandler::DrawFront(int button, float maxSize, float sizeDiv, bool onMinimap, const float3 & cameraPos, const float3 & mouseDir){}
void CGuiHandler::DrawArea(float3 pos, float radius, const float * color){}
void CGuiHandler::DrawSelectBox(const float3 & start, const float3 & end, const float3 & cameraPos){}
void CGuiHandler::DrawSelectCircle(const float3 & pos, float radius, const float * color){}
void CGuiHandler::DrawStencilCone(const float3 & pos, float radius, float height){}
void CGuiHandler::DrawStencilRange(const float3 & pos, float radius){}
int CGuiHandler::IconAtPos(int x, int y){}
void CGuiHandler::SetCursorIcon(){}
bool CGuiHandler::TryTarget(const SCommandDescription & cmdDesc){}
void CGuiHandler::LoadDefaults(){}
void CGuiHandler::SanitizeConfig(){}
void CGuiHandler::ParseFillOrder(const std::string & text){}
bool CGuiHandler::ProcessLocalActions(const Action & action){}
bool CGuiHandler::ProcessBuildActions(const Action & action){}
int CGuiHandler::GetIconPosCommand(int slot){}
int CGuiHandler::ParseIconSlot(const std::string & text){}
bool CGuiHandler::needShift(){}
bool CGuiHandler::showingMetal(){}
bool CGuiHandler::autoShowMetal(){}
bool CGuiHandler::invertQueueKey(){}
bool CGuiHandler::activeMousePress(){}
bool CGuiHandler::forceLayoutUpdate(){}
int CGuiHandler::maxPage(){}
int CGuiHandler::activePage(){}
int CGuiHandler::defaultCmdMemory(){}
int CGuiHandler::explicitCommand(){}
int CGuiHandler::curIconCommand(){}
int CGuiHandler::actionOffset(){}
CKeySet CGuiHandler::lastKeySet(){}
std::string CGuiHandler::menuName(){}
int CGuiHandler::xIcons(){}
int CGuiHandler::yIcons(){}
float CGuiHandler::xPos(){}
float CGuiHandler::yPos(){}
float CGuiHandler::textBorder(){}
float CGuiHandler::iconBorder(){}
float CGuiHandler::frameBorder(){}
float CGuiHandler::xIconSize(){}
float CGuiHandler::yIconSize(){}
float CGuiHandler::xSelectionPos(){}
float CGuiHandler::ySelectionPos(){}
int CGuiHandler::deadIconSlot(){}
int CGuiHandler::prevPageSlot(){}
int CGuiHandler::nextPageSlot(){}
bool CGuiHandler::dropShadows(){}
bool CGuiHandler::useOptionLEDs(){}
bool CGuiHandler::selectGaps(){}
bool CGuiHandler::selectThrough(){}
bool CGuiHandler::outlineFonts(){}
bool CGuiHandler::drawSelectionInfo(){}
float CGuiHandler::frameAlpha(){}
float CGuiHandler::textureAlpha(){}
std::vector<(int)> CGuiHandler::fillOrder(){}
bool CGuiHandler::gatherMode(){}
bool CGuiHandler::miniMapMarker(){}
bool CGuiHandler::newAttackMode(){}
bool CGuiHandler::attackRect(){}
bool CGuiHandler::invColorSelect(){}
bool CGuiHandler::frontByEnds(){}
bool CGuiHandler::useStencil(){}
int CGuiHandler::iconsPerPage(){}
float CGuiHandler::xIconStep(){}
float CGuiHandler::yIconStep(){}
float CGuiHandler::xBpos(){}
float CGuiHandler::yBpos(){}
Box CGuiHandler::buttonBox(){}
std::vector<(CGuiHandler::IconInfo)> CGuiHandler::icons(){}
int CGuiHandler::iconsCount(){}
int CGuiHandler::failedSound(){}
std::vector<(std::string)> CGuiHandler::layoutCommands(){}
std::vector<(std::pair<(Command,bool)>)> CGuiHandler::commandsToGive(){}
CGuiHandler CGuiHandler::guihandler(){}
