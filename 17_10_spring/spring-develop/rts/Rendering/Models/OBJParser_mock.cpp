// TODO: Substitue COBJParser with your actual class name
int COBJParser::vIndices(){}
int COBJParser::nIndices(){}
int COBJParser::tIndices(){}
void COBJParser::UploadGeometryVBOs(){}
void COBJParser::DrawForList(){}
void COBJParser::SetMinMaxExtends(bool globalVertexOffsets){}
void COBJParser::SetVertexTangents(){}
void COBJParser::BindVertexAttribVBOs(){}
void COBJParser::UnbindVertexAttribVBOs(){}
VBO COBJParser::vboPositions(){}
VBO COBJParser::vboNormals(){}
VBO COBJParser::vboTexcoords(){}
VBO COBJParser::vbosTangents(){}
VBO COBJParser::vbotTangents(){}
std::vector<(float3)> COBJParser::vertices(){}
std::vector<(float3)> COBJParser::vnormals(){}
std::vector<(float2)> COBJParser::texcoors(){}
std::vector<(float3)> COBJParser::sTangents(){}
std::vector<(float3)> COBJParser::tTangents(){}
std::vector<(SOBJTriangle)> COBJParser::triangles(){}
std::vector<(unsigned int)> COBJParser::indices(){}
S3DModel COBJParser::Load(const std::string & modelFileName){}
spring::unordered_map<(std::string,p.SOBJPiece)> COBJParser::PieceMap(){}
bool COBJParser::ParseModelData(S3DModel * model, const std::string & modelData, const LuaTable & metaData){}
bool COBJParser::BuildModelPieceTree(S3DModel * model, const COBJParser::PieceMap & pieceMap, const LuaTable & piecesTable, bool globalVertexOffsets, bool localPieceOffsets){}
void COBJParser::BuildModelPieceTreeRec(S3DModel * model, SOBJPiece * piece, const COBJParser::PieceMap & pieceMap, const LuaTable & pieceTable, bool globalVertexOffsets, bool localPieceOffsets){}
