// TODO: Substitue CMouseCursor with your actual class name
CMouseCursor CMouseCursor::operator =(const CMouseCursor & mc){}
void CMouseCursor::Update(){}
void CMouseCursor::Draw(int x, int y, float scale){}
void CMouseCursor::DrawQuad(int x, int y){}
void CMouseCursor::BindTexture(){}
void CMouseCursor::BindHwCursor(){}
bool CMouseCursor::LoadCursorImage(const std::string & name, CMouseCursor::ImageData & image){}
bool CMouseCursor::BuildFromSpecFile(const std::string & name){}
bool CMouseCursor::BuildFromFileNames(const std::string & name, int lastFrame){}
std::vector<(CMouseCursor::ImageData)> CMouseCursor::images(){}
std::vector<(CMouseCursor::FrameData)> CMouseCursor::frames(){}
IHwCursor CMouseCursor::hwCursor(){}
CMouseCursor::HotSpot CMouseCursor::hotSpot(){}
float CMouseCursor::animTime(){}
float CMouseCursor::animPeriod(){}
int CMouseCursor::currentFrame(){}
int CMouseCursor::xmaxsize(){}
int CMouseCursor::ymaxsize(){}
int CMouseCursor::xofs(){}
int CMouseCursor::yofs(){}
bool CMouseCursor::hwValid(){}
q(const).float CMouseCursor::minFrameLength(){}
q(const).float CMouseCursor::defFrameLength(){}
