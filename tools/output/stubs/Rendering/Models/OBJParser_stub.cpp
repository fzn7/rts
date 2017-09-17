/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/regex.hpp>

#include "OBJParser.h"

#include "Lua/LuaParser.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Util.h"

#include <cassert>
#include <sstream>

#define LOG_SECTION_OBJ_PARSER "OBJParser"
LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_OBJ_PARSER)

// use the specific section for all LOG*() calls in this source file
#ifdef LOG_SECTION_CURRENT
	#undef LOG_SECTION_CURRENT
#endif
#define LOG_SECTION_CURRENT LOG_SECTION_OBJ_PARSER

S3DModel* COBJParser::Load(const std::string& modelFileName)
{
    //stub method
}

bool COBJParser::ParseModelData(S3DModel* model, const std::string& modelData, const LuaTable& metaData)
{
    //stub method
}


bool COBJParser::BuildModelPieceTree(
	S3DModel* model,
	const PieceMap& pieceMap,
	const LuaTable& piecesTable,
	bool globalVertexOffsets,
	bool localPieceOffsets
) {
	std::vector<std::string> rootPieceNames;
	std::vector<int> rootPieceNumbers;

	piecesTable.GetKeys(rootPieceNames);
	piecesTable.GetKeys(rootPieceNumbers);

	SOBJPiece* rootPiece = nullptr;

	// there must be exactly one root-piece defined by name or number
	if ((rootPieceNames.size() + rootPieceNumbers.size()) != 1)
		return false;

	if (!rootPieceNames.empty()) {
		const std::string& rootPieceName = rootPieceNames[0];
		const LuaTable& rootPieceTable = piecesTable.SubTable(rootPieceName);
		const PieceMap::const_iterator rootPieceIt = pieceMap.find(rootPieceName);

		if (rootPieceIt != pieceMap.end()) {
			rootPiece = rootPieceIt->second;
			model->SetRootPiece(rootPiece);

			BuildModelPieceTreeRec(model, rootPiece, pieceMap, rootPieceTable, globalVertexOffsets, localPieceOffsets);
			return true;
		}
	}

	if (!rootPieceNumbers.empty()) {
		const LuaTable& rootPieceTable = piecesTable.SubTable(rootPieceNumbers[0]);
		const std::string& rootPieceName = rootPieceTable.GetString("name", "");
		const PieceMap::const_iterator rootPieceIt = pieceMap.find(rootPieceName);

		if (rootPieceIt != pieceMap.end()) {
			rootPiece = rootPieceIt->second;
			model->SetRootPiece(rootPiece);

			BuildModelPieceTreeRec(model, rootPiece, pieceMap, rootPieceTable, globalVertexOffsets, localPieceOffsets);
			return true;
		}
	}

	return false;
}

void COBJParser::BuildModelPieceTreeRec(
	S3DModel* model,
	SOBJPiece* piece,
	const PieceMap& pieceMap,
	const LuaTable& pieceTable,
	bool globalVertexOffsets,
	bool localPieceOffsets
) {
	const S3DModelPiece* parentPiece = piece->parent;

	// first read user-set extrema; trust that mins < maxs (for SMME)
	piece->mins = pieceTable.GetFloat3("mins", DEF_MIN_SIZE);
	piece->maxs = pieceTable.GetFloat3("maxs", DEF_MAX_SIZE);

	// always convert <offset> to local coordinates
	piece->offset = pieceTable.GetFloat3("offset", ZeroVector);
	piece->goffset = (localPieceOffsets)?
		(piece->offset + ((parentPiece != nullptr)? parentPiece->goffset: ZeroVector)):
		(piece->offset);
	piece->offset = (localPieceOffsets)?
		(piece->offset):
		(piece->offset - ((parentPiece != nullptr)? parentPiece->offset: ZeroVector));

	piece->SetVertexTangents();
	piece->SetMinMaxExtends(globalVertexOffsets);

	model->mins = float3::min(piece->goffset + piece->mins, model->mins);
	model->maxs = float3::max(piece->goffset + piece->maxs, model->maxs);

	piece->SetCollisionVolume(CollisionVolume("box", piece->maxs - piece->mins, (piece->maxs + piece->mins) * 0.5f));

	std::vector<int> childPieceNumbers;
	std::vector<std::string> childPieceNames;

	pieceTable.GetKeys(childPieceNumbers);
	pieceTable.GetKeys(childPieceNames);

	if (!childPieceNames.empty()) {
		for (std::vector<std::string>::const_iterator it = childPieceNames.begin(); it != childPieceNames.end(); ++it) {
			// NOTE: handle these better?
			if ((*it) == "offset" || (*it) == "name") {
				continue;
			}

			const std::string& childPieceName = *it;
			const LuaTable& childPieceTable = pieceTable.SubTable(childPieceName);

			PieceMap::const_iterator pieceIt = pieceMap.find(childPieceName);

			if (pieceIt == pieceMap.end()) {
				throw content_error("[OBJParser] meta-data piece named \"" + childPieceName + "\" not defined in model");
			} else {
				SOBJPiece* childPiece = pieceIt->second;

				assert(childPieceName == childPiece->name);

				childPiece->parent = piece;
				piece->children.push_back(childPiece);

				BuildModelPieceTreeRec(model, childPiece, pieceMap, childPieceTable, globalVertexOffsets, localPieceOffsets);
			}
		}
	}

	if (!childPieceNumbers.empty()) {
		for (std::vector<int>::const_iterator it = childPieceNumbers.begin(); it != childPieceNumbers.end(); ++it) {
			const LuaTable& childPieceTable = pieceTable.SubTable(*it);
			const std::string& childPieceName = childPieceTable.GetString("name", "");

			PieceMap::const_iterator pieceIt = pieceMap.find(childPieceName);

			if (pieceIt == pieceMap.end()) {
				throw content_error("[OBJParser] meta-data piece named \"" + childPieceName + "\" not defined in model");
			} else {
				SOBJPiece* childPiece = pieceIt->second;

				assert(childPieceName == childPiece->name);

				childPiece->parent = piece;
				piece->children.push_back(childPiece);

				BuildModelPieceTreeRec(model, childPiece, pieceMap, childPieceTable, globalVertexOffsets, localPieceOffsets);
			}
		}
	}
}






void SOBJPiece::UploadGeometryVBOs()
{
    //stub method
}


void SOBJPiece::BindVertexAttribVBOs() const
{
    //stub method
}


void SOBJPiece::UnbindVertexAttribVBOs() const
{
    //stub method
}


void SOBJPiece::DrawForList() const
{
    //stub method
}

void SOBJPiece::SetMinMaxExtends(bool globalVertexOffsets)
{
    //stub method
}

void SOBJPiece::SetVertexTangents()
{
    //stub method
}

