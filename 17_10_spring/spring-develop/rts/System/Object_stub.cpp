#include <iostream>
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#include "System/Object.h"
#include "System/Log/ILog.h"
#include "System/Platform/CrashHandler.h"
#include "System/creg/STL_Set.h"

CR_BIND(CObject, )

CR_REG_METADATA(CObject,
                (CR_MEMBER(sync_id),

                 CR_MEMBER(detached),

                 CR_IGNORED(listening), // handled in Serialize
                 CR_IGNORED(listeners), // handled in Serialize

                 CR_SERIALIZER(Serialize),
                 CR_POSTLOAD(PostLoad)))

Threading::AtomicCounterInt64 CObject::cur_sync_id(0);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CObject::CObject()
  : detached(false)
  , listeners()
  , listening()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

CObject::~CObject()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#ifdef USING_CREG
void
CObject::Serialize(creg::ISerializer* ser)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CObject::PostLoad()
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

#endif // USING_CREG

void
CObject::DependentDied(CObject* obj)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void CObject::AddDeathDependence(CObject* obj, DependenceType dep)
{
	 //stub method
    std::cout << __FUNCTION__ << std::endl;
}

void
CObject::DeleteDeathDependence(CObject* obj, DependenceType dep)
{
    //stub method
    std::cout << __FUNCTION__ << std::endl;
}
