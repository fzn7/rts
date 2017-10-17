// TODO: Substitue CGround with your actual class name
float CGround::GetApproximateHeight(float x, float z, bool synced){}
float CGround::GetApproximateHeight(float x, float z){}
float CGround::GetApproximateHeightUnsafe(int x, int z, bool synced){}
float CGround::GetApproximateHeightUnsafe(int x, int z){}
float CGround::GetHeightAboveWater(float x, float z, bool synced){}
float CGround::GetHeightAboveWater(float x, float z){}
float CGround::GetHeightReal(float x, float z, bool synced){}
float CGround::GetHeightReal(float x, float z){}
float CGround::GetOrigHeight(float x, float z){}
float CGround::GetSlope(float x, float z, bool synced){}
float CGround::GetSlope(float x, float z){}
q(const).float3 CGround::GetNormal(float x, float z, bool synced){}
q(const).float3 CGround::GetNormal(float x, float z){}
q(const).float3 CGround::GetNormalAboveWater(float x, float z, bool synced){}
q(const).float3 CGround::GetNormalAboveWater(float x, float z){}
float3 CGround::GetSmoothNormal(float x, float z, bool synced){}
float3 CGround::GetSmoothNormal(float x, float z){}
float CGround::LineGroundCol(float3 from, float3 to, bool synced){}
float CGround::LineGroundCol(float3 from, float3 to){}
float CGround::LineGroundCol(const float3 pos, const float3 dir, float len, bool synced){}
float CGround::LineGroundCol(const float3 pos, const float3 dir, float len){}
float CGround::LinePlaneCol(const float3 pos, const float3 dir, float len, float hgt){}
float CGround::LineGroundWaterCol(const float3 pos, const float3 dir, float len, bool testWater, bool synced){}
float CGround::LineGroundWaterCol(const float3 pos, const float3 dir, float len, bool testWater){}
float CGround::TrajectoryGroundCol(float3 from, const float3 & flatdir, float length, float linear, float quadratic){}
int CGround::GetSquare(const float3 & pos){}
