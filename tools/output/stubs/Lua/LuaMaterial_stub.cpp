#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "LuaMaterial.h"

#include "LuaHandle.h"
#include "LuaOpenGL.h"

#include "Game/Camera.h"
#include "Game/GlobalUnsynced.h" // randVector
#include "Rendering/GlobalRendering.h" // drawFrame
#include "Rendering/ShadowHandler.h"
#include "Rendering/UnitDrawerState.hpp"
#include "Rendering/Env/ISky.h"
#include "Sim/Objects/SolidObject.h"
#include "Sim/Misc/GlobalSynced.h" // simFrame
#include "System/Log/ILog.h"
#include "System/Util.h"


LuaMatHandler LuaMatHandler::handler;
LuaMatHandler& luaMatHandler = LuaMatHandler::handler;


/******************************************************************************/
/******************************************************************************/
//
//  Helper
//

static const char* GlUniformTypeToString(const GLenum uType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
//  LuaObjectMaterial
//

bool LuaObjectMaterial::SetLODCount(unsigned int count)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


bool LuaObjectMaterial::SetLastLOD(unsigned int lod)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
//  LuaMatShader
//

void LuaMatShader::Finalize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaMatShader::Compare(const LuaMatShader& a, const LuaMatShader& b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatShader::Execute(const LuaMatShader& prev, bool deferredPass) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatShader::Print(const string& indent, bool isDeferred) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




/******************************************************************************/
/******************************************************************************/
//
//  LuaMaterial
//

const LuaMaterial LuaMaterial::defMat;

void LuaMaterial::Parse(
	lua_State* L,
	const int tableIdx,
	std::function<void(lua_State*, int, LuaMatShader&)> ParseShader,
	std::function<void(lua_State*, int, LuaMatTexture&)> ParseTexture,
	std::function<GLuint(lua_State*, int)> ParseDisplayList
) {
	for (lua_pushnil(L); lua_next(L, tableIdx) != 0; lua_pop(L, 1)) {
		if (!lua_israwstring(L, -2))
			continue;

		const std::string key = StringToLower(lua_tostring(L, -2));

		// uniforms
		if (key.find("uniforms") != std::string::npos) {
			if (!lua_istable(L, -1))
				continue;

			if (key.find("standard") != std::string::npos) {
				uniforms[LuaMatShader::LUASHADER_PASS_FWD].Parse(L, lua_gettop(L));
				continue;
			}
			if (key.find("deferred") != std::string::npos) {
				uniforms[LuaMatShader::LUASHADER_PASS_DFR].Parse(L, lua_gettop(L));
				continue;
			}

			// fallback
			uniforms[LuaMatShader::LUASHADER_PASS_FWD].Parse(L, lua_gettop(L));
			continue;
		}

		// shaders
		if (key.find("shader") != std::string::npos) {
			if (key.find("standard") != std::string::npos) {
				ParseShader(L, -1, shaders[LuaMatShader::LUASHADER_PASS_FWD]);
				continue;
			}
			if (key.find("deferred") != std::string::npos) {
				ParseShader(L, -1, shaders[LuaMatShader::LUASHADER_PASS_DFR]);
				continue;
			}

			// fallback
			ParseShader(L, -1, shaders[LuaMatShader::LUASHADER_PASS_FWD]);
			continue;
		}

		// textures
		if (key.substr(0, 7) == "texunit") {
			if (key.size() < 8)
				continue;

			if (key[7] == 's') {
				// "texunits" = {[0] = string|table, ...}
				if (!lua_istable(L, -1))
					continue;

				const int texTable = lua_gettop(L);

				for (lua_pushnil(L); lua_next(L, texTable) != 0; lua_pop(L, 1)) {
					if (!lua_israwnumber(L, -2))
						continue;

					const unsigned int texUnit = lua_toint(L, -2);

					if (texUnit >= LuaMatTexture::maxTexUnits)
						continue;

					ParseTexture(L, -1, textures[texUnit]);
				}
			} else {
				// "texunitX" = string|table
				const unsigned int texUnit = atoi(key.c_str() + 7);

				if (texUnit >= LuaMatTexture::maxTexUnits)
					continue;

				ParseTexture(L, -1, textures[texUnit]);
			}

			continue;
		}

		// dlists
		if (key == "prelist") {
			preList = ParseDisplayList(L, -1);
			continue;
		}
		if (key == "postlist") {
			postList = ParseDisplayList(L, -1);
			continue;
		}

		// misc
		if (key == "order") {
			order = luaL_checkint(L, -1);
			continue;
		}
		if (key == "culling") {
			if (lua_isnumber(L, -1))
				cullingMode = (GLenum)lua_tonumber(L, -1);

			continue;
		}

		if (key == "usecamera") {
			useCamera = lua_isboolean(L, -1) && lua_toboolean(L, -1);
			continue;
		}

		LOG_L(L_WARNING, "LuaMaterial: incorrect key \"%s\"", key.c_str());
	}
}


void LuaMaterial::Finalize()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMaterial::Execute(const LuaMaterial& prev, bool deferredPass) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaMaterial::ExecuteInstance(bool deferredPass, const CSolidObject* o, const float2 alpha) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


int LuaMaterial::Compare(const LuaMaterial& a, const LuaMaterial& b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



int LuaMatUniforms::Compare(const LuaMatUniforms& a, const LuaMatUniforms& b)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const char* GetMatTypeName(LuaMatType type)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMaterial::Print(const string& indent) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}





/******************************************************************************/
/******************************************************************************/
//
//  LuaMatUniforms
//

std::unordered_map<LuaMatUniforms::IUniform*, std::string> LuaMatUniforms::GetUniformsAndStandardName()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


std::unordered_map<std::string, LuaMatUniforms::IUniform*> LuaMatUniforms::GetUniformsAndPossibleNames()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatUniforms::AutoLink(LuaMatShader* shader)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatUniforms::Validate(LuaMatShader* s)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatUniforms::Parse(lua_State* L, const int tableIdx)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaMatUniforms::Execute() const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaMatUniforms::ExecuteInstance(const CSolidObject* o, const float2 alpha) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaMatUniforms::Print(const string& indent, bool isDeferred) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}






/******************************************************************************/
/******************************************************************************/
//
//  LuaMatRef
//

LuaMatRef::LuaMatRef(LuaMatBin* _bin)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


LuaMatRef::~LuaMatRef()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatRef::Reset()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


LuaMatRef& LuaMatRef::operator=(const LuaMatRef& mr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


LuaMatRef::LuaMatRef(const LuaMatRef& mr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatRef::AddUnit(CSolidObject* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void LuaMatRef::AddFeature(CSolidObject* o)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



/******************************************************************************/
/******************************************************************************/
//
//  LuaMatBin
//

void LuaMatBin::Ref()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatBin::UnRef()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatBin::Print(const string& indent) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/
//
//  LuaMatHandler
//

LuaMatHandler::LuaMatHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


LuaMatHandler::~LuaMatHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


LuaMatRef LuaMatHandler::GetRef(const LuaMaterial& mat)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatHandler::ClearBins(LuaObjType objType, LuaMatType matType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatHandler::ClearBins(LuaObjType objType)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatHandler::FreeBin(LuaMatBin* bin)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatHandler::PrintBins(const string& indent, LuaMatType type) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void LuaMatHandler::PrintAllBins(const string& indent) const
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


/******************************************************************************/
/******************************************************************************/

float LuaObjectMaterialData::GLOBAL_LOD_FACTORS[LUAOBJ_LAST] = {1.0f, 1.0f};

