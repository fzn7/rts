/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "LuaObjectRendering.h"
#include "LuaMaterial.h"

#include "LuaInclude.h"
#include "LuaHandle.h"
#include "LuaHashString.h"
#include "LuaUtils.h"

#include "Rendering/LuaObjectDrawer.h"
#include "Rendering/Models/3DModel.h"
// see ParseUnitTexture
// #include "Rendering/Textures/3DOTextureHandler.h"
// #include "Rendering/Textures/S3OTextureHandler.h"
#include "Sim/Units/UnitHandler.h"
#include "Sim/Features/FeatureHandler.h"
#include "System/Log/ILog.h"
#include "System/Util.h"



static int material_index(lua_State* L)
{
    //stub method
}

static int material_newindex(lua_State* L)
{
    //stub method
}

static int material_gc(lua_State* L)
{
    //stub method
}




/******************************************************************************/
/******************************************************************************/
//
//  Parsing helpers
//

static inline CSolidObject* ParseSolidObject(lua_State* L, const char* caller, int index, int objType)
{
    //stub method
}


static inline CUnit* ParseUnit(lua_State* L, const char* caller, int index)
{
    //stub method
}

static inline CFeature* ParseFeature(lua_State* L, const char* caller, int index)
{
    //stub method
}




/******************************************************************************/
/******************************************************************************/

std::vector<LuaObjType> LuaObjectRenderingImpl::objectTypeStack;



void LuaObjectRenderingImpl::CreateMatRefMetatable(lua_State* L)
{
    //stub method
}

void LuaObjectRenderingImpl::PushFunction(lua_State* L, int (*fnPntr)(lua_State*), const char* fnName)
{
    //stub method
}



int LuaObjectRenderingImpl::GetLODCount(lua_State* L)
{
    //stub method
}

int LuaObjectRenderingImpl::SetLODCount(lua_State* L)
{
    //stub method
}


static int SetLODLengthCommon(lua_State* L, CSolidObject* obj, float scale)
{
    //stub method
}

int LuaObjectRenderingImpl::SetLODLength(lua_State* L)
{
    //stub method
}

int LuaObjectRenderingImpl::SetLODDistance(lua_State* L)
{
    //stub method
}


/******************************************************************************/

int LuaObjectRenderingImpl::SetPieceList(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static const map<string, LuaMatType>& GetMatNameMap()
{
    //stub method
}


static LuaMatType ParseMaterialType(const string& matName)
{
    //stub method
}


static LuaObjectMaterial* GetObjectMaterial(CSolidObject* obj, const string& matName)
{
    //stub method
}


/******************************************************************************/

static void ParseShader(lua_State* L, int index, LuaMatShader& shader)
{
    //stub method
}


static void ParseTexture(lua_State* L, int index, LuaMatTexture& texUnit) {
	if (index < 0)
		index = lua_gettop(L) + index + 1;

	if (lua_isstring(L, index)) {
		LuaOpenGLUtils::ParseTextureImage(L, texUnit, lua_tostring(L, index));
		texUnit.enable = true;
		return;
	}

	if (!lua_istable(L, index))
		return;

	const int table = (index > 0) ? index : (lua_gettop(L) + index + 1);

	for (lua_pushnil(L); lua_next(L, table) != 0; lua_pop(L, 1)) {
		if (!lua_israwstring(L, -2))
			continue;

		const string key = StringToLower(lua_tostring(L, -2));

		if (key == "tex") {
			LuaOpenGLUtils::ParseTextureImage(L, texUnit, lua_tostring(L, -1));
			texUnit.enable = true;
			continue;
		}

		if (key == "enable") {
			texUnit.enable = lua_isboolean(L, -1) && lua_toboolean(L, -1);
			continue;
		}
	}
}

static GLuint ParseDisplayList(lua_State* L, int index)
{
    //stub method
}

static LuaMatRef ParseMaterial(lua_State* L, int index, LuaMatType matType) {
	if (!lua_istable(L, index))
		return LuaMatRef();

	LuaMaterial mat(matType);
	mat.Parse(L, index, &ParseShader, &ParseTexture, &ParseDisplayList);
	mat.Finalize();
	return (luaMatHandler.GetRef(mat));
}


/******************************************************************************/
/******************************************************************************/

int LuaObjectRenderingImpl::GetMaterial(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

int LuaObjectRenderingImpl::SetMaterial(lua_State* L)
{
    //stub method
}


int LuaObjectRenderingImpl::SetMaterialLastLOD(lua_State* L)
{
    //stub method
}


int LuaObjectRenderingImpl::SetMaterialDisplayLists(lua_State* L)
{
    //stub method
}


/******************************************************************************/
/******************************************************************************/

static int SetObjectLuaDraw(lua_State* L, CSolidObject* obj)
{
    //stub method
}


int LuaObjectRenderingImpl::SetUnitLuaDraw(lua_State* L)
{
    //stub method
}

int LuaObjectRenderingImpl::SetFeatureLuaDraw(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

static void PrintObjectLOD(const CSolidObject* obj, int lod)
{
    //stub method
}


int LuaObjectRenderingImpl::Debug(lua_State* L)
{
    //stub method
}

/******************************************************************************/
/******************************************************************************/

