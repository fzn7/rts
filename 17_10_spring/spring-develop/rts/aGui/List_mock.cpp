// TODO: Substitue CList with your actual class name
bool CList::KeyPressed(int k, bool isRepeat){}
bool CList::MousePress(int x, int y, int button){}
void CList::MouseMove(int x, int y, int dx, int dy, int button){}
void CList::MouseRelease(int x, int y, int button){}
void CList::DrawSelf(){}
bool CList::HandleEventSelf(const SDL_Event & ev){}
void CList::RemoveAllItems(){}
void CList::AddItem(const std::string & name, const std::string & description){}
std::vector<(std::string)> CList::items(){}
std::string CList::name(){}
std::string CList::GetCurrentItem(){}
bool CList::SetCurrentItem(const std::string & item){}
void CList::CenterSelected(){}
int CList::cancelPlace(){}
std::string CList::tooltip(){}
slimsig::signal<(f(void).void)> CList::FinishSelection(){}
void CList::SetFocus(bool focus){}
void CList::RefreshQuery(){}
bool CList::Filter(bool reset){}
void CList::UpOne(){}
void CList::DownOne(){}
void CList::UpPage(){}
void CList::DownPage(){}
bool CList::MouseUpdate(int x, int y){}
void CList::UpdateTopIndex(){}
void CList::ScrollUpOne(){}
void CList::ScrollDownOne(){}
int CList::NumDisplay(){}
float CList::ScaleFactor(){}
spring_time CList::clickedTime(){}
int CList::place(){}
bool CList::activeMousePress(){}
float CList::mx(){}
float CList::my(){}
float CList::borderSpacing(){}
float CList::itemSpacing(){}
float CList::itemHeight(){}
bool CList::hasFocus(){}
int CList::topIndex(){}
GuiElement CList::scrollbar(){}
bool CList::activeScrollbar(){}
float CList::scrollbarGrabPos(){}
std::string CList::query(){}
std::vector<(std::string)> CList::filteredItems(){}
std::vector<(std::string)> CList::temp1(){}
std::vector<(std::string)> CList::temp2(){}
