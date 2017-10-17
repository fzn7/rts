/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef _MOVE_TYPE_FACTORY_H_
#define _MOVE_TYPE_FACTORY_H_

//#include <emscripten/bind.h>

class AMoveType;
class CUnit;
struct UnitDef;

class MoveTypeFactory {
public:
	static AMoveType* GetMoveType(CUnit*, const UnitDef*);
};

/*using namespace emscripten;
// Binding code
EMSCRIPTEN_BINDINGS(my_module) {
 class_<MoveTypeFactory>("MoveTypeFactory")
    .class_function("GetMoveType", &MoveTypeFactory::GetMoveType, allow_raw_pointers())
    ;
}*/

#endif
