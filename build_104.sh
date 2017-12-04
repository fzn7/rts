#set current working directory
working_dir=`pwd`
#force copy gl headers
cp -r emscriptenGl/* ~/emsdk-portable/emscripten

cd spring-104.0.1
rm CMakeCache.txt

emconfigure cmake . \
-DCMAKE_TOOLCHAIN_FILE=Emscripten.cmake \
-DAI_TYPES=NONE\
-DBoost_USE_STATIC_LIBS=ON \
-DBoost_INCLUDE_DIR=$working_dir/lib/boost_1_65_1 \
-DBoost_LIBRARY_DIR=$working_dir/lib/chronotext-boost/dist/emscripten/lib \
-DZLIB_INCLUDE_DIR=$working_dir/lib/zlib/build/include \
-DZLIB_LIBRARY=$working_dir/lib/zlib/build/lib \
-DSDL2_INCLUDE_DIR=$working_dir/lib/SDL2_build/build/include \
-DSDL2_LIBRARY=$working_dir/lib/SDL2_build/build/lib/libSDL2.a \
-DNO_SOUND=TRUE

emconfigure cmake . \
-DCUSTOM_COMPILER_DEFINITIONS=-msse

emconfigure cmake . --graphviz=spring-build-graph.dot

make clean
#make spring-dedicated
make spring-dedicated2
