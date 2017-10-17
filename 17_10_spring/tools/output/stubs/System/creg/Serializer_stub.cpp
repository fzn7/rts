#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

/*
 * creg - Code compoment registration system
 * Classes for serialization of registrated class instances
 */

#define LOG_SECTION_CREG_SERIALIZER "CregSerializer"

#include "Serializer.h"
#include "creg_cond.h"

#include "System/Exceptions.h"
#include "System/Log/ILog.h"
#include "System/Platform/byteorder.h"

#include <assert.h>
#include <boost/cstdint.hpp>
#include <fstream>
#include <map>
#include <stdexcept>
#include <string.h>
#include <string>
#include <vector>

using namespace creg;
using std::map;
using std::string;
using std::vector;

LOG_REGISTER_SECTION_GLOBAL(LOG_SECTION_CREG_SERIALIZER)

//
#define CREG_PACKAGE_FILE_ID "CRPK"

// File format structures
struct PackageHeader
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static void
WriteZStr(std::ostream& file, const std::string& str)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
WriteVarSizeUInt(std::ostream* stream, unsigned int val)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
ReadVarSizeUInt(std::istream* stream, unsigned int* buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//-------------------------------------------------------------------------
// Base output serializer
//-------------------------------------------------------------------------
COutputStreamSerializer::COutputStreamSerializer()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
COutputStreamSerializer::IsWriting()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

COutputStreamSerializer::ObjectRef*
COutputStreamSerializer::FindObjectRef(void* inst,
                                       creg::Class* objClass,
                                       bool isEmbedded)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
COutputStreamSerializer::SerializeObject(Class* c, void* ptr, ObjectRef* objr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
COutputStreamSerializer::SerializeObjectInstance(void* inst,
                                                 creg::Class* objClass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
COutputStreamSerializer::SerializeObjectPtr(void** ptr, creg::Class* objClass)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
COutputStreamSerializer::Serialize(void* data, int byteSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
COutputStreamSerializer::SerializeInt(void* data, int byteSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

struct COutputStreamSerializer::ClassRef
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

//-------------------------------------------------------------------------
// CInputStreamSerializer
//-------------------------------------------------------------------------

CInputStreamSerializer::CInputStreamSerializer()
  : stream(NULL)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
CInputStreamSerializer::IsWriting()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInputStreamSerializer::SerializeObject(Class* c, void* ptr)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInputStreamSerializer::Serialize(void* data, int byteSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInputStreamSerializer::SerializeInt(void* data, int byteSize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInputStreamSerializer::SerializeObjectPtr(void** ptr, creg::Class* cls)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Serialize an instance of an object embedded into another object
void
CInputStreamSerializer::SerializeObjectInstance(void* inst, creg::Class* cls)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInputStreamSerializer::AddPostLoadCallback(void (*cb)(void*), void* ud)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CallPostLoad(creg::Class* c, creg::Class* oc, void* obj)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CInputStreamSerializer::LoadPackage(std::istream* s,
                                    void*& root,
                                    creg::Class*& rootCls)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

ISerializer::~ISerializer() {}
