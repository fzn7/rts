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

# Utility rule file for install-spring.

# Include the progress variables for this target.
include rts/builds/CMakeFiles/install-spring.dir/progress.make

install-spring: rts/builds/CMakeFiles/install-spring.dir/build.make

.PHONY : install-spring

# Rule to build all files generated by this target.
rts/builds/CMakeFiles/install-spring.dir/build: install-spring

.PHONY : rts/builds/CMakeFiles/install-spring.dir/build

rts/builds/CMakeFiles/install-spring.dir/clean:
	cd /home/pi/rts/spring-104.0.1/rts/builds && $(CMAKE_COMMAND) -P CMakeFiles/install-spring.dir/cmake_clean.cmake
.PHONY : rts/builds/CMakeFiles/install-spring.dir/clean

rts/builds/CMakeFiles/install-spring.dir/depend:
	cd /home/pi/rts/spring-104.0.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/rts/spring-104.0.1 /home/pi/rts/spring-104.0.1/rts/builds /home/pi/rts/spring-104.0.1 /home/pi/rts/spring-104.0.1/rts/builds /home/pi/rts/spring-104.0.1/rts/builds/CMakeFiles/install-spring.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : rts/builds/CMakeFiles/install-spring.dir/depend

