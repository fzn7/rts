#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <boost/regex.hpp>

#include "OBJParser.h"

#include "Lua/LuaParser.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Log/ILog.h"
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

S3DModel*
COBJParser::Load(const std::string& modelFileName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
COBJParser::ParseModelData(S3DModel* model,
                           const std::string& modelData,
                           const LuaTable& metaData)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
COBJParser::BuildModelPieceTree(S3DModel* model,
                                const PieceMap& pieceMap,
                                const LuaTable& piecesTable,
                                bool globalVertexOffsets,
                                bool localPieceOffsets)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
COBJParser::BuildModelPieceTreeRec(S3DModel* model,
                                   SOBJPiece* piece,
                                   const PieceMap& pieceMap,
                                   const LuaTable& pieceTable,
                                   bool globalVertexOffsets,
                                   bool localPieceOffsets)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SOBJPiece::UploadGeometryVBOs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SOBJPiece::BindVertexAttribVBOs() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SOBJPiece::UnbindVertexAttribVBOs() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SOBJPiece::DrawForList() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SOBJPiece::SetMinMaxExtends(bool globalVertexOffsets)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
SOBJPiece::SetVertexTangents()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
