// TODO: Substitue CglExtra with your actual class name
void CglExtra::SurfaceCircleFunc(const float3 & center, float radius, unsigned int res){}
void CglExtra::SurfaceSquareFunc(const float3 & center, float xsize, float zsize){}
SurfaceCircleFunc CglExtra::glSurfaceCircle(){}
SurfaceSquareFunc CglExtra::glSurfaceSquare(){}
void CglExtra::glBallisticCircle(const float3 & center, float radius, const CWeapon * weapon, unsigned int resolution, float slope){}
void CglExtra::glBallisticCircle(const float3 & center, float radius, const CWeapon * weapon, unsigned int resolution){}
void CglExtra::setSurfaceCircleFunc(SurfaceCircleFunc func){}
void CglExtra::setSurfaceSquareFunc(SurfaceSquareFunc func){}
void CglExtra::DrawVolumeFunc(const void * data){}
void CglExtra::glDrawVolume(DrawVolumeFunc drawFunc, const void * data){}
void CglExtra::glWireCube(unsigned int * listID){}
void CglExtra::glWireCylinder(unsigned int * listID, unsigned int numDivs, float zSize){}
void CglExtra::glWireSphere(unsigned int * listID, unsigned int numRows, unsigned int numCols){}
