// TODO: Substitue CAssParser with your actual class name
SVertexData CAssParser::SAssVertex(){}
void CAssParser::DrawForList(){}
void CAssParser::UploadGeometryVBOs(){}
void CAssParser::BindVertexAttribVBOs(){}
void CAssParser::UnbindVertexAttribVBOs(){}
std::vector<(SAssVertex)> CAssParser::vertices(){}
std::vector<(unsigned int)> CAssParser::indices(){}
unsigned int CAssParser::numTexCoorChannels(){}
spring::unordered_map<(std::string,p.S3DModelPiece)> CAssParser::ModelPieceMap(){}
spring::unordered_map<(std::string,std::string)> CAssParser::ParentNameMap(){}
S3DModel CAssParser::Load(const std::string & modelFileName){}
unsigned int CAssParser::maxIndices(){}
unsigned int CAssParser::maxVertices(){}
void CAssParser::SetPieceName(SAssPiece * piece, const S3DModel * model, const aiNode * pieceNode, CAssParser::ModelPieceMap & pieceMap){}
void CAssParser::SetPieceParentName(SAssPiece * piece, const S3DModel * model, const aiNode * pieceNode, const LuaTable & pieceTable, CAssParser::ParentNameMap & parentMap){}
void CAssParser::LoadPieceTransformations(SAssPiece * piece, const S3DModel * model, const aiNode * pieceNode, const LuaTable & pieceTable){}
void CAssParser::LoadPieceGeometry(SAssPiece * piece, const aiNode * pieceNode, const aiScene * scene){}
SAssPiece CAssParser::LoadPiece(S3DModel * model, const aiNode * pieceNode, const aiScene * scene, const LuaTable & modelTable, CAssParser::ModelPieceMap & pieceMap, CAssParser::ParentNameMap & parentMap){}
void CAssParser::BuildPieceHierarchy(S3DModel * model, CAssParser::ModelPieceMap & pieceMap, const CAssParser::ParentNameMap & parentMap){}
void CAssParser::CalculateModelDimensions(S3DModel * model, S3DModelPiece * piece){}
void CAssParser::CalculateModelProperties(S3DModel * model, const LuaTable & pieceTable){}
void CAssParser::FindTextures(S3DModel * model, const aiScene * scene, const LuaTable & pieceTable, const std::string & modelPath, const std::string & modelName){}
