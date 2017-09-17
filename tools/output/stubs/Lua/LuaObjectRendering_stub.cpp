#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaObjectRendering.h"
#include "LuaMaterial.h"

#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaInclude.h"
#include "LuaUtils.h"

#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/Models/3DModel.h"
// see ParseUnitTexture
// #include "Rendering/Textures/3DOTextureHandler.h"
// #include "Rendering/Textures/S3OTextureHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"

static int
material_index(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
material_newindex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
material_gc(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
//
//  Parsing helpers
//

static inline CSolidObject*
ParseSolidObject(lua_State* L, const char* caller, int index, int objType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline CUnit*
ParseUnit(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline CFeature*
ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

std::vector<LuaObjType> LuaObjectRenderingImpl::objectTypeStack;

void
LuaObjectRenderingImpl::CreateMatRefMetatable(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaObjectRenderingImpl::PushFunction(lua_State* L,
                                     int (*fnPntr)(lua_State*),
                                     const char* fnName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::GetLODCount(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::SetLODCount(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static int
SetLODLengthCommon(lua_State* L, CSolidObject* obj, float scale)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::SetLODLength(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::SetLODDistance(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

int
LuaObjectRenderingImpl::SetPieceList(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static const map<string, LuaMatType>&
GetMatNameMap()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static LuaMatType
ParseMaterialType(const string& matName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static LuaObjectMaterial*
GetObjectMaterial(CSolidObject* obj, const string& matName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

static void
ParseShader(lua_State* L, int index, LuaMatShader& shader)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
ParseTexture(lua_State* L, int index, LuaMatTexture& texUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static GLuint
ParseDisplayList(lua_State* L, int index)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static LuaMatRef
ParseMaterial(lua_State* L, int index, LuaMatType matType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaObjectRenderingImpl::GetMaterial(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

int
LuaObjectRenderingImpl::SetMaterial(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::SetMaterialLastLOD(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::SetMaterialDisplayLists(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static int
SetObjectLuaDraw(lua_State* L, CSolidObject* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::SetUnitLuaDraw(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::SetFeatureLuaDraw(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/

static void
PrintObjectLOD(const CSolidObject* obj, int lod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
LuaObjectRenderingImpl::Debug(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/
/******************************************************************************/
