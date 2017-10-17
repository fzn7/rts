#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "3DOParser.h"

#include "Sim/Misc/CollisionVolume.h"
#include "System/Exceptions.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/SimpleParser.h"
#include "System/FileSystem/VFSHandler.h"
#include "System/Log/ILog.h"
#include "System/Platform/byteorder.h"
#include "System/Sync/HsiehHash.h"
#include "System/Util.h"

#include <boost/cstdint.hpp>
#include <cctype>

#define SCALE_FACTOR_3DO (1.0f / 65536.0f)

//////////////////////////////////////////////////////////////////////
// Helpers
//////////////////////////////////////////////////////////////////////

static void
STREAM_READ(void* buf,
            int length,
            const std::vector<unsigned char>& fileBuf,
            int& curOffset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static std::string
GET_TEXT(int pos, const std::vector<unsigned char>& fileBuf, int& curOffset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
READ_3DOBJECT(C3DOParser::_3DObject& o,
              const std::vector<unsigned char>& fileBuf,
              int& curOffset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
READ_VERTEX(float3& v,
            const std::vector<unsigned char>& fileBuf,
            int& curOffset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
READ_PRIMITIVE(C3DOParser::_Primitive& p,
               const std::vector<unsigned char>& fileBuf,
               int& curOffset)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

C3DOParser::C3DOParser()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

S3DModel*
C3DOParser::Load(const std::string& name)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
C3DOParser::GetVertexes(_3DObject* o,
                        S3DOPiece* object,
                        const std::vector<unsigned char>& fileBuf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
C3DOParser::IsBasePlate(S3DOPiece* obj, S3DOPrimitive* face)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

C3DOTextureHandler::UnitTexture*
C3DOParser::GetTexture(S3DOPiece* obj,
                       _Primitive* p,
                       const std::vector<unsigned char>& fileBuf) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
C3DOParser::GetPrimitives(S3DOPiece* obj,
                          int pos,
                          int num,
                          int excludePrim,
                          const std::vector<unsigned char>& fileBuf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

S3DOPiece*
C3DOParser::LoadPiece(S3DModel* model,
                      int pos,
                      S3DOPiece* parent,
                      int* numobj,
                      const std::vector<unsigned char>& fileBuf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
S3DOPiece::UploadGeometryVBOs()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
S3DOPiece::BindVertexAttribVBOs() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
S3DOPiece::UnbindVertexAttribVBOs() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
S3DOPiece::DrawForList() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
S3DOPiece::CalcNormals()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
S3DOPiece::SetMinMaxExtends()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
