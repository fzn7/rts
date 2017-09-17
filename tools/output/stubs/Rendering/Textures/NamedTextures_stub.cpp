#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

// must be included before streflop! else we get streflop/cmath resolve
// conflicts in its hash implementation files
#include <boost/unordered_map.hpp>
#include <mutex>
#include <vector>

#include "NamedTextures.h"

#include "Bitmap.h"
#include "Rendering/GL/myGL.h"
#include "Rendering/GlobalRendering.h"
#include "System/Log/ILog.h"
#include "System/Threading/SpringMutex.h"
#include "System/TimeProfiler.h"
#include "System/bitops.h"
#include "System/type2.h"

#ifdef _MSC_VER
#include <map>
// only way to compile unordered_map with MSVC appears to require inclusion of
// math.h instead of streflop, and that cannot be done here because it gives
// rise to other conflicts
typedef std::map<std::string, CNamedTextures::TexInfo> TEXMAP;
#else
typedef boost::unordered_map<std::string, CNamedTextures::TexInfo> TEXMAP;
#endif

namespace CNamedTextures {

static TEXMAP texMap;
static std::vector<std::string> texWaiting;
static spring::recursive_mutex mutex;

/******************************************************************************/

void
Init()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Kill()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

static bool
Load(const std::string& texName, unsigned int texID)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
Bind(const std::string& texName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

void
Update()
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

bool
Free(const std::string& texName)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

const TexInfo*
GetInfo(const std::string& texName, const bool forceLoad)
{
    //stub method
    std::cout << _FUNCTION_ << std::endl;
}

/******************************************************************************/

} // namespace CNamedTextures
