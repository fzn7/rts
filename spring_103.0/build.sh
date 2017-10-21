emconfigure cmake . \
-DCMAKE_TOOLCHAIN_FILE=Emscripten.cmake \
-DAI_TYPES=NONE\
-DBoost_USE_STATIC_LIBS=ON \
-DBoost_INCLUDE_DIR=/home/pi/rts/lib/boost_1_65_1 \
-DBoost_LIBRARY_DIR=/home/pi/rts/lib/chronotext-boost/dist/emscripten/lib \
-DZLIB_INCLUDE_DIR=/home/pi/rts/lib/zlib/build/include \
-DZLIB_LIBRARY=/home/pi/rts/lib/zlib/build/lib \
-DSDL2_INCLUDE_DIR=/home/pi/rts/lib/SDL2_build/build/include \
-DSDL2_LIBRARY=/home/pi/rts/lib/SDL2_build/build/lib/libSDL2.a \
-DNO_SOUND=TRUE

emconfigure cmake . \
-DCUSTOM_COMPILER_DEFINITIONS=-msse

make engineSim
