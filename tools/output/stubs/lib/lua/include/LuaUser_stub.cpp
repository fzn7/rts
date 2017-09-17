/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include <map>
#include <array>
#include <boost/cstdint.hpp>
#include <boost/thread.hpp>
#include "lib/streflop/streflop_cond.h"

#include "LuaInclude.h"
#include "Game/GameVersion.h"
#include "Lua/LuaHandle.h"
#include "System/myMath.h"
#include "System/Platform/Threading.h"
#include "System/Threading/SpringMutex.h"
#include "System/Log/ILog.h"
#if (!defined(DEDICATED) && !defined(UNITSYNC) && !defined(BUILDING_AI))
	#include "System/Misc/SpringTime.h"
#endif


///////////////////////////////////////////////////////////////////////////
// Custom Lua Mutexes

static std::map<lua_State*, spring::recursive_mutex*> mutexes;
static std::map<lua_State*, bool> coroutines;

static spring::recursive_mutex* GetLuaMutex(lua_State* L)
{
    //stub method
}



void LuaCreateMutex(lua_State* L)
{
    //stub method
}


void LuaDestroyMutex(lua_State* L)
{
    //stub method
}


void LuaLinkMutex(lua_State* L_parent, lua_State* L_child)
{
    //stub method
}


void LuaMutexLock(lua_State* L)
{
    //stub method
}


void LuaMutexUnlock(lua_State* L)
{
    //stub method
}


void LuaMutexYield(lua_State* L)
{
    //stub method
}


///////////////////////////////////////////////////////////////////////////
//

const char* spring_lua_getName(lua_State* L)
{
    //stub method
}


///////////////////////////////////////////////////////////////////////////
// Custom Memory Allocator
//
// these track allocations across all states
static Threading::AtomicCounterInt64 totalBytesAlloced = 0;
static Threading::AtomicCounterInt64 totalNumLuaAllocs = 0;
static Threading::AtomicCounterInt64 totalLuaAllocTime = 0;

static const unsigned int maxAllocedBytes = 768u * 1024u*1024u;
static const char* maxAllocFmtStr = "%s: cannot allocate more memory! (%u bytes already used, %u bytes maximum)";


void* spring_lua_alloc(void* ud, void* ptr, size_t osize, size_t nsize)
{
    //stub method
}

void spring_lua_alloc_get_stats(SLuaInfo* info)
{
    //stub method
}

void spring_lua_alloc_update_stats(bool clear)
{
    //stub method
}

//////////////////////////////////////////////////////////
////// Custom synced float to string
//////////////////////////////////////////////////////////

#ifdef WIN32
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
static inline int sprintf64(char* dst, boost::int64_t x) { return sprintf(dst, "%I64d", x); }
#pragma GCC diagnostic pop
#else
static inline int sprintf64(char* dst, long int x)      { return sprintf(dst, "%ld", x); }
static inline int sprintf64(char* dst, long long int x) { return sprintf(dst, "%lld", x); }
#endif

// excluding mantissa, a float has a rest int-precision of: 2^24 = 16,777,216
// int numbers in that range are 100% exact, and don't suffer float precision issues
static constexpr int MAX_PRECISE_DIGITS_IN_FLOAT = std::numeric_limits<float>::digits10;
static constexpr auto SPRING_FLOAT_MAX = std::numeric_limits<float>::max();
static constexpr auto SPRING_INT64_MAX = std::numeric_limits<boost::int64_t>::max();

static constexpr std::array<double, 11> v = {
	1, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10
};


static constexpr inline double Pow10d(unsigned i)
{
    //stub method
}


static const inline int FastLog10(const float f)
{
    //stub method
}


static constexpr inline int GetDigitsInStdNotation(const int log10)
{
    //stub method
}



static inline int PrintIntPart(char* buf, float f, const bool carrierBit = false)
{
    //stub method
}


static inline int PrintFractPart(char* buf, float f, int digits, int precision)
{
    //stub method
}


static inline bool HandleRounding(float* fractF, int log10, int charsInStdNotation, int nDigits, bool scienceNotation, int precision)
{
    //stub method
}


void spring_lua_ftoa(float f, char* buf, int precision)
{
    //stub method
}


void spring_lua_format(float f, const char* fmt, char* buf)
{
    //stub method
}
