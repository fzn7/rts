// TODO: Substitue CFlyingPiece with your actual class name
bool CFlyingPiece::Update(){}
void CFlyingPiece::Draw(const FlyingPiece * prev){}
void CFlyingPiece::EndDraw(){}
void CFlyingPiece::InitCommon(const float3 _pos, const float3 _speed, const float _radius, int _team, int _texture){}
void CFlyingPiece::CheckDrawStateChange(const FlyingPiece * prev){}
float3 CFlyingPiece::GetDragFactors(){}
CMatrix44f CFlyingPiece::GetMatrixOf(const SplitterData & cp, const float3 dragFactors){}
float3 CFlyingPiece::pos0(){}
float3 CFlyingPiece::pos(){}
float3 CFlyingPiece::speed(){}
CMatrix44f CFlyingPiece::pieceMatrix(){}
int CFlyingPiece::team(){}
int CFlyingPiece::texture(){}
unsigned int CFlyingPiece::age(){}
float CFlyingPiece::pieceRadius(){}
float CFlyingPiece::drawRadius(){}
q(const).S3DModelPiece CFlyingPiece::piece(){}
std::vector<(SplitterData)> CFlyingPiece::splitterParts(){}
