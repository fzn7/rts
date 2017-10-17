// TODO: Substitue C3DOParser with your actual class name
float3 C3DOParser::pos(){}
float3 C3DOParser::normal(){}
float2 C3DOParser::texCoord(){}
std::vector<(int)> C3DOParser::indices(){}
std::vector<(float3)> C3DOParser::vnormals(){}
float3 C3DOParser::primNormal(){}
C3DOTextureHandler::UnitTexture C3DOParser::texture(){}
void C3DOParser::UploadGeometryVBOs(){}
void C3DOParser::DrawForList(){}
void C3DOParser::BindVertexAttribVBOs(){}
void C3DOParser::UnbindVertexAttribVBOs(){}
void C3DOParser::SetMinMaxExtends(){}
void C3DOParser::CalcNormals(){}
std::vector<(float3)> C3DOParser::vertexPos(){}
std::vector<(S3DOPrimitive)> C3DOParser::prims(){}
float3 C3DOParser::emitPos(){}
float3 C3DOParser::emitDir(){}
std::vector<(S3DOVertex)> C3DOParser::vertexAttribs(){}
std::vector<(unsigned int)> C3DOParser::vertexIndices(){}
C3DOParser::_3DObject C3DOParser::_3DObject(){}
C3DOParser::_Primitive C3DOParser::_Primitive(){}
S3DModel C3DOParser::Load(const std::string & name){}
S3DOPiece C3DOParser::LoadPiece(S3DModel * model, int pos, S3DOPiece * parent, int * numobj, const std::vector<(unsigned char)> & fileBuf){}
C3DOTextureHandler::UnitTexture C3DOParser::GetTexture(S3DOPiece * obj, C3DOParser::_Primitive * p, const std::vector<(unsigned char)> & fileBuf){}
bool C3DOParser::IsBasePlate(S3DOPiece * obj, S3DOPrimitive * face){}
void C3DOParser::GetPrimitives(S3DOPiece * obj, int pos, int num, int excludePrim, const std::vector<(unsigned char)> & fileBuf){}
void C3DOParser::GetVertexes(C3DOParser::_3DObject * o, S3DOPiece * object, const std::vector<(unsigned char)> & fileBuf){}
spring::unordered_set<(std::string)> C3DOParser::teamtex(){}
