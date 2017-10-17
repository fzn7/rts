// TODO: Substitue CTraceRay with your actual class name
CPlasmaRepulser CTraceRay::rep(){}
float CTraceRay::dist(){}
float CTraceRay::TraceRay::TraceRay(const float3 & pos, const float3 & dir, float traceLength, int traceFlags, const CUnit * owner, CUnit &* hitUnit, CFeature &* hitFeature, CollisionQuery * hitColQuery){}
float CTraceRay::TraceRay::TraceRay(const float3 & pos, const float3 & dir, float traceLength, int traceFlags, const CUnit * owner, CUnit &* hitUnit, CFeature &* hitFeature){}
float CTraceRay::TraceRay::TraceRay(const float3 & pos, const float3 & dir, float traceLength, int traceFlags, int allyTeam, const CUnit * owner, CUnit &* hitUnit, CFeature &* hitFeature, CollisionQuery * hitColQuery){}
void CTraceRay::TraceRay::TraceRayShields(const CWeapon * emitter, const float3 & start, const float3 & dir, float length, std::vector<(TraceRay::SShieldDist)> & hitShields){}
float CTraceRay::TraceRay::GuiTraceRay(const float3 & start, const float3 & dir, const float length, const CUnit * exclude, const CUnit &* hitUnit, const CFeature &* hitFeature, bool useRadar, bool groundOnly, bool ignoreWater){}
float CTraceRay::TraceRay::GuiTraceRay(const float3 & start, const float3 & dir, const float length, const CUnit * exclude, const CUnit &* hitUnit, const CFeature &* hitFeature, bool useRadar, bool groundOnly){}
float CTraceRay::TraceRay::GuiTraceRay(const float3 & start, const float3 & dir, const float length, const CUnit * exclude, const CUnit &* hitUnit, const CFeature &* hitFeature, bool useRadar){}
bool CTraceRay::TraceRay::TestCone(const float3 & from, const float3 & dir, float length, float spread, int allyteam, int traceFlags, CUnit * owner){}
bool CTraceRay::TraceRay::TestTrajectoryCone(const float3 & from, const float3 & dir, float length, float linear, float quadratic, float spread, int allyteam, int traceFlags, CUnit * owner){}
