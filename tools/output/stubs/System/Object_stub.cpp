/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */


#include "System/Object.h"
#include "System/creg/STL_Set.h"
#include "System/Log/ILog.h"
#include "System/Platform/CrashHandler.h"


CR_BIND(CObject, )

CR_REG_METADATA(CObject, (
	CR_MEMBER(sync_id),

	CR_MEMBER(detached),

	CR_IGNORED(listening), //handled in Serialize
	CR_IGNORED(listeners), //handled in Serialize

	CR_SERIALIZER(Serialize),
	CR_POSTLOAD(PostLoad)
	))

Threading::AtomicCounterInt64 CObject::cur_sync_id(0);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CObject::CObject() : detached(false), listeners(), listening()
{
    //stub method
}


CObject::~CObject()
{
    //stub method
}

#ifdef USING_CREG
void CObject::Serialize(creg::ISerializer* ser)
{
    //stub method
}

void CObject::PostLoad()
{
    //stub method
}

#endif //USING_CREG

void CObject::DependentDied(CObject* obj)
{
    //stub method
}

// NOTE that we can be listening to a single object from several different places,
// however objects are responsible for not adding the same dependence more than once,
// and preferably try to delete the dependence asap in order not to waste memory
void CObject::AddDeathDependence(CObject* obj, DependenceType dep)
{
    //stub method
}


void CObject::DeleteDeathDependence(CObject* obj, DependenceType dep)
{
    //stub method
}
