// TODO: Substitue CGuiElement with your actual class name
void CGuiElement::Draw(){}
bool CGuiElement::HandleEvent(const SDL_Event & ev){}
bool CGuiElement::MouseOver(int x, int y){}
bool CGuiElement::MouseOver(float x, float y){}
void CGuiElement::UpdateDisplayGeo(int x, int y, int offsetX, int offsetY){}
float CGuiElement::PixelToGlX(int x){}
float CGuiElement::PixelToGlY(int y){}
float CGuiElement::GlToPixelX(float x){}
float CGuiElement::GlToPixelY(float y){}
void CGuiElement::AddChild(agui::GuiElement * elem){}
void CGuiElement::SetPos(float x, float y){}
void CGuiElement::SetSize(float x, float y, bool fixed){}
void CGuiElement::SetSize(float x, float y){}
void CGuiElement::GeometryChange(){}
float CGuiElement::DefaultOpacity(){}
void CGuiElement::Move(float x, float y){}
void CGuiElement::DrawBox(int how){}
agui::GuiElement CGuiElement::parent(){}
std::list<(p.agui::GuiElement)> CGuiElement::ChildList(){}
agui::GuiElement::ChildList CGuiElement::children(){}
int CGuiElement::screensize(){}
int CGuiElement::screenoffset(){}
bool CGuiElement::fixedSize(){}
float CGuiElement::pos(){}
float CGuiElement::size(){}
unsigned int CGuiElement::weight(){}
