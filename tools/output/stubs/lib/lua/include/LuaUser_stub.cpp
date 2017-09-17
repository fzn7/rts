#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "lib/streflop/streflop_cond.h"
#include <array>
#include <boost/cstdint.hpp>
#include <boost/thread.hpp>
#include <map>

#include "Game/GameVersion.h"
#include "Lua/LuaHandle.h"
#include "LuaInclude.h"
#include "System/Log/ILog.h"
#include "System/Platform/Threading.h"
#include "System/Threading/SpringMutex.h"
#include "System/myMath.h"
#if (!defined(DEDICATED) && !defined(UNITSYNC) && !defined(BUILDING_AI))
#include "System/Misc/SpringTime.h"
#endif

///////////////////////////////////////////////////////////////////////////
// Custom Lua Mutexes

static std::map<lua_State*, spring::recursive_mutex*> mutexes;
static std::map<lua_State*, bool> coroutines;

static spring::recursive_mutex*
GetLuaMutex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaCreateMutex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaDestroyMutex(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaLinkMutex(lua_State* L_parent, lua_State* L_child)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaMutexLock(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaMutexUnlock(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
LuaMutexYield(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////
//

const char*
spring_lua_getName(lua_State* L)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

///////////////////////////////////////////////////////////////////////////
// Custom Memory Allocator
//
// these track allocations across all states
static Threading::AtomicCounterInt64 totalBytesAlloced = 0;
static Threading::AtomicCounterInt64 totalNumLuaAllocs = 0;
static Threading::AtomicCounterInt64 totalLuaAllocTime = 0;

static const unsigned int maxAllocedBytes = 768u * 1024u * 1024u;
static const char* maxAllocFmtStr =
  "%s: cannot allocate more memory! (%u bytes already used, %u bytes maximum)";

void*
spring_lua_alloc(void* ud, void* ptr, size_t osize, size_t nsize)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
spring_lua_alloc_get_stats(SLuaInfo* info)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
spring_lua_alloc_update_stats(bool clear)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

    //////////////////////////////////////////////////////////
    ////// Custom synced float to string
    //////////////////////////////////////////////////////////

#ifdef WIN32
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
static inline int
sprintf64(char* dst, boost::int64_t x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#pragma GCC diagnostic pop
#else
static inline int
sprintf64(char* dst, long int x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
static inline int
sprintf64(char* dst, long long int x)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
#endif

// excluding mantissa, a float has a rest int-precision of: 2^24 = 16,777,216
// int numbers in that range are 100% exact, and don't suffer float precision
// issues
static constexpr int MAX_PRECISE_DIGITS_IN_FLOAT =
  std::numeric_limits<float>::digits10;
static constexpr auto SPRING_FLOAT_MAX = std::numeric_limits<float>::max();
static constexpr auto SPRING_INT64_MAX =
  std::numeric_limits<boost::int64_t>::max();

static constexpr std::array<double, 11> v = { 1,   1e1, 1e2, 1e3, 1e4, 1e5,
                                              1e6, 1e7, 1e8, 1e9, 1e10 };

static constexpr inline double
Pow10d(unsigned i)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static const inline int
FastLog10(const float f)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static constexpr inline int
GetDigitsInStdNotation(const int log10)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline int
PrintIntPart(char* buf, float f, const bool carrierBit = false)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline int
PrintFractPart(char* buf, float f, int digits, int precision)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

static inline bool
HandleRounding(float* fractF,
               int log10,
               int charsInStdNotation,
               int nDigits,
               bool scienceNotation,
               int precision)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
spring_lua_ftoa(float f, char* buf, int precision)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
spring_lua_format(float f, const char* fmt, char* buf)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}
