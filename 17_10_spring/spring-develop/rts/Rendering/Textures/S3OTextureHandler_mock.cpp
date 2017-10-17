// TODO: Substitue CS3OTextureHandler with your actual class name
void CS3OTextureHandler::LoadTexture(S3DModel * model){}
void CS3OTextureHandler::PreloadTexture(S3DModel * model, bool invertAxis, bool invertAlpha){}
void CS3OTextureHandler::PreloadTexture(S3DModel * model, bool invertAxis){}
void CS3OTextureHandler::PreloadTexture(S3DModel * model){}
unsigned int CS3OTextureHandler::LoadAndCacheTexture(const S3DModel * model, unsigned int texNum, bool invertAxis, bool invertAlpha, bool preloadCall){}
unsigned int CS3OTextureHandler::InsertTextureMat(const S3DModel * model){}
spring::unsynced_map<(std::string,CS3OTextureHandler::CachedS3OTex)> CS3OTextureHandler::TextureCache(){}
spring::unsynced_map<(std::string,CBitmap)> CS3OTextureHandler::BitmapCache(){}
spring::unsynced_map<(std::uint64_t,unsigned int)> CS3OTextureHandler::TextureTable(){}
CS3OTextureHandler::TextureCache CS3OTextureHandler::textureCache(){}
CS3OTextureHandler::TextureTable CS3OTextureHandler::textureTable(){}
CS3OTextureHandler::BitmapCache CS3OTextureHandler::bitmapCache(){}
spring::mutex CS3OTextureHandler::cacheMutex(){}
std::vector<(CS3OTextureHandler::S3OTexMat)> CS3OTextureHandler::textures(){}
CS3OTextureHandler CS3OTextureHandler::texturehandlerS3O(){}
