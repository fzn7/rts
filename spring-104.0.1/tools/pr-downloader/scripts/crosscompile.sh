#!/bin/sh

set -e

export PREFIX=$(pwd)/mingwlibs
export MINGWHOST=i686-w64-mingw32
export MINGW32CXX=${MINGWHOST}-g++
export MINGW32CC=${MINGWHOST}-gcc
export MINGW32CPP=${MINGWHOST}-cpp
export MINGW32RC=${MINGWHOST}-windres
export MINGW32AR=${MINGWHOST}-ar
export MINGW32RANLIB=${MINGWHOST}-ranlib
export MINGW32RC=${MINGWHOST}-windres
export DOWNLOAD="wget -c"
export PARALLEL="8"
export ZLIBVER=1.2.7

echo "Using ${PREFIX} for mingwlibs"
if [ ! -s "$(pwd)/src/Downloader/IDownloader.h" ]; then
	echo "Please run this script from the root directory with scripts/crosscompile.sh."
	exit
fi

mkdir -p ${PREFIX}/include
mkdir -p ${PREFIX}/lib

if [ ! -s ${PREFIX}/lib/libz.a ]; then
	if [ ! -s zlib-${ZLIBVER}.tar.gz ]; then
		${DOWNLOAD} "http://prdownloads.sourceforge.net/libpng/zlib-${ZLIBVER}.tar.gz?download" -O zlib-${ZLIBVER}.tar.gz
	fi
	tar xifz zlib-${ZLIBVER}.tar.gz
	cd zlib-${ZLIBVER}
	export CC=${MINGW32CC}
	export CPP=${MINGW32CPP}
	export LDSHARED=${MINGW32CC}
	export AR="${MINGW32AR}"
	export RANLIB=${MINGW32RANLIB}
	./configure --prefix=${PREFIX}
	make install -j ${PARALLEL}
	#${CC} -shared -o zlib1.dll -Wl,--out-implib=libz.dll.a [!em]*.o
	#mkdir -p ../mingwlibs/dll
	#cp zlib1.dll ../mingwlibs/dll
	cp zlib.h ../mingwlibs/include
	cp zconf.h ../mingwlibs/include
	cd ..
fi

if [ ! -s ${PREFIX}/lib/libcurl.a ]; then
	export CC=${MINGW32CC}
	export CXX=${MINGW32CXX}
	wget -c http://curl.haxx.se/download/curl-7.24.0.tar.bz2
	tar xifj curl-7.24.0.tar.bz2
	cd curl-7.24.0
	./configure --host=${MINGWHOST} --prefix=${PREFIX} \
		--disable-ftp --disable-dict --disable-imap --disable-pop3 \
		--disable-smtp --disable-telnet --disable-tftp --disable-ldap \
		--disable-rtsp --disable-manual --disable-shared
	make install -j ${PARALLEL}
	cd ..
fi

rm -f CMakeCache.txt

if [ ! -s win32.cmake ]  ||  [ win32.cmake -ot $0 ]; then
echo Wrote win32.cmake
(
echo "SET(CMAKE_SYSTEM_NAME Windows)"
echo "SET(CMAKE_C_COMPILER $MINGW32CC)"
echo "SET(CMAKE_CXX_COMPILER $MINGW32CXX)"
echo "SET(CMAKE_FIND_ROOT_PATH /usr/$MINGWHOST)"
echo "SET(MINGWLIBS ./mingwlibs)"
echo "SET(CMAKE_RC_COMPILER $MINGW32RC)"
) >win32.cmake
fi

cmake . -DCMAKE_TOOLCHAIN_FILE=win32.cmake -DCMAKE_INSTALL_PREFIX=dist -G Ninja
ninja install

