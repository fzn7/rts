// TODO: Substitue CUnitScriptFactory with your actual class name
void CUnitScriptFactory::InitStatic(){}
CUnitScript CUnitScriptFactory::CreateScript(CUnit * unit, const UnitDef * udef){}
CUnitScript CUnitScriptFactory::CreateCOBScript(CUnit * unit, CCobFile * F){}
CUnitScript CUnitScriptFactory::CreateLuaScript(CUnit * unit, lua_State * L){}
