/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/*
 * creg - Code compoment registration system
 * Classes for serialization of registrated class instances
 */

#define LOG_SECTION_CREG_SERIALIZER "CregSerializer"

#include "creg_cond.h"
#include "Serializer.h"

#include "System/Log/ILog.h"
#include "System/Platform/byteorder.h"
#include "System/Exceptions.h"

#include <fstream>
#include <assert.h>
#include <stdexcept>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <boost/cstdint.hpp>

using namespace creg;
using std::string;
using std::map;
using std::vector;

LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_CREG_SERIALIZER)

//
#define CREG_PACKAGE_FILE_ID "CRPK"

// File format structures
struct PackageHeader
{
    //stub method
}

static void WriteZStr(std::ostream& file, const std::string& str)
{
    //stub method
}

void WriteVarSizeUInt(std::ostream* stream, unsigned int val)
{
    //stub method
}

void ReadVarSizeUInt(std::istream* stream, unsigned int* buf)
{
    //stub method
}

//-------------------------------------------------------------------------
// Base output serializer
//-------------------------------------------------------------------------
COutputStreamSerializer::COutputStreamSerializer()
{
    //stub method
}

bool COutputStreamSerializer::IsWriting()
{
    //stub method
}

COutputStreamSerializer::ObjectRef* COutputStreamSerializer::FindObjectRef(void* inst, creg::Class* objClass, bool isEmbedded)
{
    //stub method
}

void COutputStreamSerializer::SerializeObject(Class* c, void* ptr, ObjectRef* objr)
{
    //stub method
}

void COutputStreamSerializer::SerializeObjectInstance(void* inst, creg::Class* objClass)
{
    //stub method
}

void COutputStreamSerializer::SerializeObjectPtr(void** ptr, creg::Class* objClass)
{
    //stub method
}

void COutputStreamSerializer::Serialize(void* data, int byteSize)
{
    //stub method
}

void COutputStreamSerializer::SerializeInt(void* data, int byteSize)
{
    //stub method
}


struct COutputStreamSerializer::ClassRef
{
    //stub method
}

//-------------------------------------------------------------------------
// CInputStreamSerializer
//-------------------------------------------------------------------------

CInputStreamSerializer::CInputStreamSerializer()
	: stream(NULL)
{
    //stub method
}

CInputStreamSerializer::~CInputStreamSerializer()
{
    //stub method
}

bool CInputStreamSerializer::IsWriting()
{
    //stub method
}

void CInputStreamSerializer::SerializeObject(Class* c, void* ptr)
{
    //stub method
}

void CInputStreamSerializer::Serialize(void* data, int byteSize)
{
    //stub method
}

void CInputStreamSerializer::SerializeInt(void* data, int byteSize)
{
    //stub method
}

void CInputStreamSerializer::SerializeObjectPtr(void** ptr, creg::Class* cls)
{
    //stub method
}

// Serialize an instance of an object embedded into another object
void CInputStreamSerializer::SerializeObjectInstance(void* inst, creg::Class* cls)
{
    //stub method
}

void CInputStreamSerializer::AddPostLoadCallback(void (*cb)(void*), void* ud)
{
    //stub method
}

void CallPostLoad(creg::Class* c, creg::Class* oc, void* obj)
{
    //stub method
}

void CInputStreamSerializer::LoadPackage(std::istream* s, void*& root, creg::Class*& rootCls)
{
    //stub method
}

ISerializer::~ISerializer() {
}
