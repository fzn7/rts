# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/rts/spring-104.0.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/rts/spring-104.0.1

# Include any dependencies generated for this target.
include rts/lib/7z/CMakeFiles/7zip.dir/depend.make

# Include the progress variables for this target.
include rts/lib/7z/CMakeFiles/7zip.dir/progress.make

# Include the compile flags for this target's objects.
include rts/lib/7z/CMakeFiles/7zip.dir/flags.make

rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o: rts/lib/7z/7zAlloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zAlloc.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zAlloc.c

rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zAlloc.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zAlloc.c > CMakeFiles/7zip.dir/7zAlloc.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zAlloc.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zAlloc.c -o CMakeFiles/7zip.dir/7zAlloc.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o


rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o: rts/lib/7z/7zBuf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zBuf.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zBuf.c

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zBuf.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zBuf.c > CMakeFiles/7zip.dir/7zBuf.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zBuf.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zBuf.c -o CMakeFiles/7zip.dir/7zBuf.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o


rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o: rts/lib/7z/7zBuf2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zBuf2.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zBuf2.c

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zBuf2.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zBuf2.c > CMakeFiles/7zip.dir/7zBuf2.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zBuf2.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zBuf2.c -o CMakeFiles/7zip.dir/7zBuf2.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o


rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o: rts/lib/7z/7zCrc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zCrc.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zCrc.c

rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zCrc.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zCrc.c > CMakeFiles/7zip.dir/7zCrc.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zCrc.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zCrc.c -o CMakeFiles/7zip.dir/7zCrc.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o


rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o: rts/lib/7z/7zCrcOpt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zCrcOpt.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zCrcOpt.c

rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zCrcOpt.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zCrcOpt.c > CMakeFiles/7zip.dir/7zCrcOpt.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zCrcOpt.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zCrcOpt.c -o CMakeFiles/7zip.dir/7zCrcOpt.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o


rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o: rts/lib/7z/7zDec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zDec.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zDec.c

rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zDec.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zDec.c > CMakeFiles/7zip.dir/7zDec.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zDec.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zDec.c -o CMakeFiles/7zip.dir/7zDec.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o


rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o: rts/lib/7z/7zIn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zIn.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zIn.c

rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zIn.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zIn.c > CMakeFiles/7zip.dir/7zIn.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zIn.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zIn.c -o CMakeFiles/7zip.dir/7zIn.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o


rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o: rts/lib/7z/CpuArch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/CpuArch.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/CpuArch.c

rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/CpuArch.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/CpuArch.c > CMakeFiles/7zip.dir/CpuArch.c.i

rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/CpuArch.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/CpuArch.c -o CMakeFiles/7zip.dir/CpuArch.c.s

rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o


rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o: rts/lib/7z/LzmaDec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/LzmaDec.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/LzmaDec.c

rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/LzmaDec.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/LzmaDec.c > CMakeFiles/7zip.dir/LzmaDec.c.i

rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/LzmaDec.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/LzmaDec.c -o CMakeFiles/7zip.dir/LzmaDec.c.s

rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o


rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o: rts/lib/7z/Lzma2Dec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/Lzma2Dec.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/Lzma2Dec.c

rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/Lzma2Dec.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/Lzma2Dec.c > CMakeFiles/7zip.dir/Lzma2Dec.c.i

rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/Lzma2Dec.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/Lzma2Dec.c -o CMakeFiles/7zip.dir/Lzma2Dec.c.s

rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o


rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o: rts/lib/7z/Bra.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/Bra.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/Bra.c

rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/Bra.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/Bra.c > CMakeFiles/7zip.dir/Bra.c.i

rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/Bra.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/Bra.c -o CMakeFiles/7zip.dir/Bra.c.s

rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o


rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o: rts/lib/7z/Bra86.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/Bra86.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/Bra86.c

rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/Bra86.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/Bra86.c > CMakeFiles/7zip.dir/Bra86.c.i

rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/Bra86.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/Bra86.c -o CMakeFiles/7zip.dir/Bra86.c.s

rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o


rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o: rts/lib/7z/Bcj2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/Bcj2.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/Bcj2.c

rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/Bcj2.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/Bcj2.c > CMakeFiles/7zip.dir/Bcj2.c.i

rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/Bcj2.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/Bcj2.c -o CMakeFiles/7zip.dir/Bcj2.c.s

rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o


rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o: rts/lib/7z/Ppmd7.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/Ppmd7.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/Ppmd7.c

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/Ppmd7.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/Ppmd7.c > CMakeFiles/7zip.dir/Ppmd7.c.i

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/Ppmd7.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/Ppmd7.c -o CMakeFiles/7zip.dir/Ppmd7.c.s

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o


rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o: rts/lib/7z/Ppmd7Dec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/Ppmd7Dec.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/Ppmd7Dec.c

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/Ppmd7Dec.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/Ppmd7Dec.c > CMakeFiles/7zip.dir/Ppmd7Dec.c.i

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/Ppmd7Dec.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/Ppmd7Dec.c -o CMakeFiles/7zip.dir/Ppmd7Dec.c.s

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o


rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o: rts/lib/7z/7zFile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zFile.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zFile.c

rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zFile.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zFile.c > CMakeFiles/7zip.dir/7zFile.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zFile.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zFile.c -o CMakeFiles/7zip.dir/7zFile.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o


rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o: rts/lib/7z/CMakeFiles/7zip.dir/flags.make
rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o: rts/lib/7z/CMakeFiles/7zip.dir/includes_C.rsp
rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o: rts/lib/7z/7zStream.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/7zip.dir/7zStream.c.o   -c /home/pi/rts/spring-104.0.1/rts/lib/7z/7zStream.c

rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/7zip.dir/7zStream.c.i"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/rts/spring-104.0.1/rts/lib/7z/7zStream.c > CMakeFiles/7zip.dir/7zStream.c.i

rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/7zip.dir/7zStream.c.s"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && /home/pi/emsdk-portable/emscripten/1.37.1/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/rts/spring-104.0.1/rts/lib/7z/7zStream.c -o CMakeFiles/7zip.dir/7zStream.c.s

rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o.requires:

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o.requires

rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o.provides: rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o.requires
	$(MAKE) -f rts/lib/7z/CMakeFiles/7zip.dir/build.make rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o.provides.build
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o.provides

rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o.provides.build: rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o


# Object files for target 7zip
7zip_OBJECTS = \
"CMakeFiles/7zip.dir/7zAlloc.c.o" \
"CMakeFiles/7zip.dir/7zBuf.c.o" \
"CMakeFiles/7zip.dir/7zBuf2.c.o" \
"CMakeFiles/7zip.dir/7zCrc.c.o" \
"CMakeFiles/7zip.dir/7zCrcOpt.c.o" \
"CMakeFiles/7zip.dir/7zDec.c.o" \
"CMakeFiles/7zip.dir/7zIn.c.o" \
"CMakeFiles/7zip.dir/CpuArch.c.o" \
"CMakeFiles/7zip.dir/LzmaDec.c.o" \
"CMakeFiles/7zip.dir/Lzma2Dec.c.o" \
"CMakeFiles/7zip.dir/Bra.c.o" \
"CMakeFiles/7zip.dir/Bra86.c.o" \
"CMakeFiles/7zip.dir/Bcj2.c.o" \
"CMakeFiles/7zip.dir/Ppmd7.c.o" \
"CMakeFiles/7zip.dir/Ppmd7Dec.c.o" \
"CMakeFiles/7zip.dir/7zFile.c.o" \
"CMakeFiles/7zip.dir/7zStream.c.o"

# External object files for target 7zip
7zip_EXTERNAL_OBJECTS =

rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/build.make
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/objects1.rsp
rts/lib/7z/lib7zip.a: rts/lib/7z/CMakeFiles/7zip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/rts/spring-104.0.1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking C static library lib7zip.a"
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && $(CMAKE_COMMAND) -P CMakeFiles/7zip.dir/cmake_clean_target.cmake
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/7zip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
rts/lib/7z/CMakeFiles/7zip.dir/build: rts/lib/7z/lib7zip.a

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/build

rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zAlloc.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zBuf.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zBuf2.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zCrc.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zCrcOpt.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zDec.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zIn.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/CpuArch.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/LzmaDec.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/Lzma2Dec.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/Bra.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/Bra86.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/Bcj2.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/Ppmd7Dec.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zFile.c.o.requires
rts/lib/7z/CMakeFiles/7zip.dir/requires: rts/lib/7z/CMakeFiles/7zip.dir/7zStream.c.o.requires

.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/requires

rts/lib/7z/CMakeFiles/7zip.dir/clean:
	cd /home/pi/rts/spring-104.0.1/rts/lib/7z && $(CMAKE_COMMAND) -P CMakeFiles/7zip.dir/cmake_clean.cmake
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/clean

rts/lib/7z/CMakeFiles/7zip.dir/depend:
	cd /home/pi/rts/spring-104.0.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/rts/spring-104.0.1 /home/pi/rts/spring-104.0.1/rts/lib/7z /home/pi/rts/spring-104.0.1 /home/pi/rts/spring-104.0.1/rts/lib/7z /home/pi/rts/spring-104.0.1/rts/lib/7z/CMakeFiles/7zip.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rts/lib/7z/CMakeFiles/7zip.dir/depend
