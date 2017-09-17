#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "TerrainBase.h"
#include "TerrainTexture.h"
#include "Terrain.h"

#include "TerrainTextureGLSL.h"
#include "Rendering/GL/FBO.h"
#include "Rendering/GlobalRendering.h"
#include "System/bitops.h"
#include "System/Util.h"
#include "System/Log/ILog.h"
#include "System/Exceptions.h"
#include "System/FileSystem/DataDirsAccess.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileQueryFlags.h"

#include <fstream>
#include <list>
#include <assert.h>

namespace terrain {

static void ShowInfoLog(GLhandleARB handle)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}




struct Shader {
	std::list<std::string> texts;
	GLhandleARB handle;

	Shader() { handle = 0; }

	void AddFile(const std::string& file)
	{
		CFileHandler fh(file);
		if (!fh.FileExists())
			throw content_error("Can not load shader " + file);

		std::string text;
		text.resize(fh.FileSize());
		fh.Read(&text[0], text.length());

		texts.push_back(text);
	}

	void Build(GLenum shaderType)
	{
		handle = glCreateShaderObjectARB(shaderType);

		std::vector<GLint> lengths(texts.size());
		std::vector<const GLcharARB*> strings(texts.size());
		int index = 0;
		for (std::list<std::string>::iterator i = texts.begin(); i != texts.end(); ++i, index++) {
			lengths[index] = i->length();
			strings[index] = i->c_str();
		}

//		if (shaderType == GL_FRAGMENT_SHADER_ARB)
//			DebugOutput(shaderType);

		glShaderSourceARB(handle, strings.size(), &strings.front(), &lengths.front());
		glCompileShaderARB(handle);

		// Check compile status and show info log if failed
		GLint isCompiled;
		glGetObjectParameterivARB(handle, GL_OBJECT_COMPILE_STATUS_ARB, &isCompiled);
		if (!isCompiled)
		{
			WriteToFile("sm3_failed_shader.glsl");
			ShowInfoLog(handle);

			std::string errMsg = "Failed to build ";
			throw std::runtime_error(errMsg + (shaderType == GL_VERTEX_SHADER_ARB ? "vertex shader" : "fragment shader"));
		}
	}
	void DebugOutput(GLenum shaderType)
	{
		char fn[20];
		if (shaderType == GL_FRAGMENT_SHADER_ARB) {
			static int fpc = 0;
			sprintf(fn, "shader%dfp.txt", fpc++);
		} else {
			static int vpc = 0;
			sprintf(fn, "shader%dvp.txt", vpc++);
		}
		WriteToFile(fn);
	}
	void WriteToFile(const char* fn)
	{
		std::string n = dataDirsAccess.LocateFile(fn, FileQueryFlags::WRITE);

		FILE* f = fopen(n.c_str(), "w");

		if (f) {
			for (std::list<std::string>::iterator i=texts.begin();i!=texts.end();++i)
				fputs(i->c_str(), f);
			fclose(f);
		}
	}
};




static int closest_pot(int i)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// A framebuffer enabled as texture
class BufferTexture : public BaseTexture
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



ShaderBuilder::TexReq  ShaderBuilder::CalcStagesTexReq(const std::vector<ShaderDef::Stage>& stages, uint index) const {
	TextureUsage usage;

	while (index < stages.size()) {
		const ShaderDef::Stage& stage = stages[index];
		BaseTexture* texture = stage.source;
		TextureUsage tmpUsage;

		usage.AddTextureRead(-1, texture);
		usage.AddTextureCoordRead(-1, texture);

		if (stage.operation == ShaderDef::Alpha) {
			// next operation is blend (alpha is autoinserted before blend)
			assert(index < stages.size()-1 && stages[index+1].operation == ShaderDef::Blend);
			const ShaderDef::Stage& blendStage = stages[index+1];

			usage.AddTextureRead(-1, blendStage.source);
			usage.AddTextureCoordRead(-1, blendStage.source);

			index++;
		}
		index++;
	}

	TexReq rq;
		rq.coords = usage.coordUnits.size();
		rq.units = usage.texUnits.size();
	return rq;
}

void ShaderBuilder::TexReq::GetFromGL() {
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS_ARB, &units);
	glGetIntegerv(GL_MAX_TEXTURE_COORDS_ARB, &coords);
}

ShaderBuilder::ShaderBuilder(RenderSetup* rs): renderSetup(rs) {
	shadingMethod = SM_DiffuseSP;
	buffer = 0;
}

std::string ShaderBuilder::GenTextureRead(int tu, int tc) {
	char tcstr[6];
	sprintf(tcstr,"%d", tc);
	return "texture2D(" + texUsage.texUnits[tu]->name + ", gl_TexCoord[" + tcstr + "].st)";
}



NodeGLSLShader* ShaderBuilder::EndPass(ShaderDef* sd, const std::string &operations, uint passIndex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void ShaderBuilder::AddPPDefines(ShaderDef* sd, Shader& shader, uint passIndex)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void ShaderBuilder::BuildFragmentShader(NodeGLSLShader* ns, uint passIndex, const std::string& operations, ShaderDef* sd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void ShaderBuilder::BuildVertexShader(NodeGLSLShader* ns, uint passIndex, ShaderDef* sd)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



bool ShaderBuilder::ProcessStage(std::vector<ShaderDef::Stage>& stages, uint &index, std::string& opstr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void ShaderBuilder::Build(ShaderDef* shaderDef) {
	texUsage = TextureUsage();
	shadingMethod = CalculateShadingMethod(shaderDef);

	switch (shadingMethod) {
		case SM_DiffuseSP: {
			std::string opstr;
			for (uint stage = 0; stage < shaderDef->stages.size(); )
				ProcessStage(shaderDef->stages, stage, opstr);
			EndPass(shaderDef, opstr);
			break;
		}

		case SM_DiffuseBumpmapSP: {
			std::string diffusecode, bumpmapcode;

			for (uint stage = 0; stage < shaderDef->stages.size(); )
				ProcessStage(shaderDef->stages, stage, diffusecode);

			for (uint stage = 0; stage < shaderDef->normalMapStages.size(); )
				ProcessStage(shaderDef->normalMapStages, stage, bumpmapcode);

			EndPass(shaderDef, diffusecode + "vec4 diffuse = color;\n" + bumpmapcode);
			break;
		}

		case SM_DiffuseBumpmapMP: {
			std::string diffusecode, bumpmapcode;

			for (uint stage = 0; stage < shaderDef->stages.size(); )
				ProcessStage(shaderDef->stages, stage, diffusecode);


			NodeGLSLShader* diffusePass = EndPass(shaderDef, diffusecode, 0);

			// multipass: let the diffuse pass render to the buffer
			// at this point nodeShader=0 and texUsage is empty
			if (!buffer) {
				buffer = new BufferTexture;
			}
			diffusePass->renderBuffer = buffer;
			// add texture read operation to second pass
			texUsage.AddTextureRead(-1, buffer);


			for (uint stage = 0; stage < shaderDef->normalMapStages.size(); )
				ProcessStage(shaderDef->normalMapStages, stage, bumpmapcode);

			EndPass(shaderDef, bumpmapcode, 1);

			break;
		}

		case SM_Impossible:
			throw content_error("Map has too many layers for bumpmapping on this hardware");
	}
}


NodeGLSLShader::NodeGLSLShader()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

NodeGLSLShader::~NodeGLSLShader()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void NodeGLSLShader::BindTSM(Vector3* buf, uint vertexSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void NodeGLSLShader::UnbindTSM()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void NodeGLSLShader::Setup(NodeSetupParams& params) {
	/*
	if (renderBuffer) { // use a offscreen rendering buffer
		renderBuffer->framebuffer.Bind();
		glViewport(0, 0, renderBuffer->width, renderBuffer->height);
	}
	*/

	glUseProgramObjectARB(program);
	for (size_t a = 0; a < texUnits.size(); a++) {
		glActiveTextureARB(GL_TEXTURE0_ARB + a);

		GLenum target;
		if (texUnits[a]->IsRect())
			target = GL_TEXTURE_RECTANGLE_ARB;
		else
			target = GL_TEXTURE_2D;

		if (texUnits[a]->id)
			glBindTexture(target, texUnits[a]->id);
		glEnable(target);
	}
	for (size_t a = 0; a < texCoordGen.size(); a++) {
		glActiveTextureARB(GL_TEXTURE0_ARB + a);
		texCoordGen[a]->SetupTexGen();
	}
	glActiveTextureARB(GL_TEXTURE0_ARB);

	if (wsLightDirLocation >= 0 && params.wsLightDir)
		glUniform3fARB(wsLightDirLocation, params.wsLightDir->x, params.wsLightDir->y, params.wsLightDir->z);
	if (wsEyePosLocation >= 0 && params.wsEyePos)
		glUniform3fARB(wsEyePosLocation, params.wsEyePos->x, params.wsEyePos->y, params.wsEyePos->z);

	if (params.shadowMapParams) {
		if (shadowMapLocation >= 0) {
			glUniform1i(shadowMapLocation, texUnits.size());
			shadowHandler->SetupShadowTexSampler(GL_TEXTURE0 + texUnits.size() /*, params.shadowMapParams->shadowMap*/);
		}

		ShadowMapParams& smp = *params.shadowMapParams;
		if (shadowMatrixLocation >= 0) glUniformMatrix4fvARB(shadowMatrixLocation, 1, GL_TRUE, smp.shadowMatrix);
		if (shadowParamsLocation >= 0) glUniform4fARB(shadowParamsLocation, smp.f_a, smp.f_b, smp.mid[0], smp.mid[1]);
	}
}

void NodeGLSLShader::Cleanup() {
	for (size_t a = 0; a < texUnits.size(); a++) {
		glActiveTextureARB(GL_TEXTURE0_ARB + a);
		glBindTexture(texUnits[a]->IsRect()? GL_TEXTURE_RECTANGLE_ARB : GL_TEXTURE_2D, 0);
		glDisable(texUnits[a]->IsRect()? GL_TEXTURE_RECTANGLE_ARB : GL_TEXTURE_2D);
	}

	glActiveTextureARB(GL_TEXTURE0_ARB);
	glUseProgramObjectARB(0);
}




std::string NodeGLSLShader::GetDebugDesc()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

uint NodeGLSLShader::GetVertexDataRequirements()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
void NodeGLSLShader::GetTextureUnits(BaseTexture* tex, int &imageUnit, int& coordUnit)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLSLShaderHandler::GLSLShaderHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

GLSLShaderHandler::~GLSLShaderHandler()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



void GLSLShaderHandler::EndTexturing() {
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	if (curShader) {
		curShader->Cleanup();
		curShader = NULL;
	}
}

void GLSLShaderHandler::BeginTexturing() {
}



void GLSLShaderHandler::BeginPass(const std::vector<Blendmap*>& blendmaps, const std::vector<TiledTexture*>& textures, int pass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool GLSLShaderHandler::SetupShader(IShaderSetup* ps, NodeSetupParams& params)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void GLSLShaderHandler::BeginBuild()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}


void GLSLShaderHandler::EndBuild()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void GLSLShaderHandler::BuildNodeSetup(ShaderDef* shaderDef, RenderSetup* renderSetup)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}



int GLSLShaderHandler::MaxTextureUnits() {
	GLint n;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS_ARB, &n);
	return n;
}

int GLSLShaderHandler::MaxTextureCoords() {
	GLint n;
	glGetIntegerv(GL_MAX_TEXTURE_COORDS_ARB, &n);
	return n;
}



SimpleCopyShader::SimpleCopyShader(BufferTexture* buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

SimpleCopyShader::~SimpleCopyShader()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void SimpleCopyShader::Setup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void SimpleCopyShader::Cleanup()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

}
