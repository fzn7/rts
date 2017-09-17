#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "IconHandler.h"

#include <algorithm>
#include <assert.h>
#include <locale>
#include <cctype>
#include <cmath>

#include "Rendering/GL/myGL.h"
#include "Rendering/GL/VertexArray.h"
#include "System/Log/ILog.h"
#include "Lua/LuaParser.h"
#include "Textures/Bitmap.h"
#include "System/Exceptions.h"

namespace icon {
using std::string;

CIconHandler* iconHandler = NULL;
CIconData CIconHandler::safetyData;


/******************************************************************************/
//
//  CIconHandler
//

CIconHandler::CIconHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CIconHandler::~CIconHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CIconHandler::LoadIcons(const string& filename)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CIconHandler::AddIcon(const string& iconName, const string& textureName,
                           float size, float distance, bool radAdj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool CIconHandler::FreeIcon(const string& iconName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CIcon CIconHandler::GetIcon(const string& iconName) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


unsigned int CIconHandler::GetDefaultTexture()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
//
//  CIcon
//

CIcon::CIcon() 
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CIcon::CIcon(CIconData* d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CIcon::CIcon(const CIcon& icon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CIcon& CIcon::operator=(const CIcon& icon)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


CIcon::~CIcon()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}





/******************************************************************************/
//
//  CIconData
//

CIconData::CIconData() :
	ownTexture(false),
	refCount(123456),
	name("safety"),
	texID(0),
	xsize(1),
	ysize(1),
	size(1.0f),
	distance(1.0f),
	distSqr(1.0f),
	radiusAdjust(false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CIconData::CIconData(const std::string& _name, unsigned int _texID,
                     float _size, float _distance, bool radAdj, bool ownTex,
                     int _xsize, int _ysize)
: ownTexture(ownTex), refCount(0),
  name(_name), texID(_texID),
  xsize(_xsize), ysize(_ysize),
  size(_size), distance(_distance),
  radiusAdjust(radAdj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

CIconData::~CIconData()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void CIconData::Ref()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CIconData::UnRef()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CIconData::CopyData(const CIconData* iconData)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CIconData::BindTexture() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CIconData::DrawArray(CVertexArray* va, float x0, float y0, float x1, float y1, const unsigned char* c) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CIconData::Draw(float x0, float y0, float x1, float y1) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void CIconData::Draw(const float3& botLeft, const float3& botRight,
                     const float3& topLeft, const float3& topRight) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/

}
