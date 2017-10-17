#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "CpuID.h"
#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"
//#include <cstddef>
#ifdef _MSC_VER
#include <intrin.h>
#endif

#include <assert.h>
#include <boost/thread/thread.hpp>
#include <set>

namespace springproc {

#if defined(__GNUC__)
// function inlining breaks this
_noinline void
ExecCPUID(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#elif defined(_MSC_VER) && (_MSC_VER >= 1310)
void
ExecCPUID(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#else
// no-op on other compilers
void
ExecCPUID(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int* d)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
CpuId::~CpuId()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Function based on Figure 1 from Kuo_CpuTopology_rc1.rh1.final.pdf
void
CpuId::getIdsIntel()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CpuId::getMasksIntelLeaf11Enumerate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

// Implementing "Sub ID Extraction Parameters for x2APIC ID" from
// Kuo_CpuTopology_rc1.rh1.final.pdf

void
CpuId::getMasksIntelLeaf11()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CpuId::getMasksIntelLeaf1and4()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CpuId::getIdsIntelEnumerate()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

uint32_t
CpuId::getApicIdIntel()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CpuId::getIdsAmd()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CpuId::getCoreTotalNumber()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

int
CpuId::getPackageTotalNumber()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

uint64_t
CpuId::getAffinityMaskOfCore(int x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

uint64_t
CpuId::getAffinityMaskOfPackage(int x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
CpuId::setDefault()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
}
