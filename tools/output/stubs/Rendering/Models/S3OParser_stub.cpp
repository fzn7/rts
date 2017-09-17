/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <cctype>
#include <stdexcept>

#include "S3OParser.h"
#include "s3o.h"
#include "Game/GlobalUnsynced.h"
#include "Rendering/GlobalRendering.h"
#include "Rendering/Textures/S3OTextureHandler.h"
#include "Sim/Misc/CollisionVolume.h"
#include "System/Exceptions.h"
#include "System/Util.h"
#include "System/Log/ILog.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Platform/byteorder.h"



S3DModel* CS3OParser::Load(const std::string& name)
{
    //stub method
}

SS3OPiece* CS3OParser::LoadPiece(S3DModel* model, SS3OPiece* parent, unsigned char* buf, int offset)
{
    //stub method
}






void SS3OPiece::UploadGeometryVBOs()
{
    //stub method
}

void SS3OPiece::BindVertexAttribVBOs() const
{
    //stub method
}


void SS3OPiece::UnbindVertexAttribVBOs() const
{
    //stub method
}


void SS3OPiece::DrawForList() const
{
    //stub method
}


void SS3OPiece::SetMinMaxExtends()
{
    //stub method
}


void SS3OPiece::Trianglize()
{
    //stub method
}


void SS3OPiece::SetVertexTangents()
{
    //stub method
}
