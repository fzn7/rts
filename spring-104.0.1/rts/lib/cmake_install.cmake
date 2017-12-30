# Install script for directory: /home/pi/rts/spring-104.0.1/rts/lib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RELWITHDEBINFO")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/pi/rts/spring-104.0.1/rts/lib/lua/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/luasocket/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/7z/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/minizip/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/headlessStubs/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/streflop/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/gflags/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/assimp/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/rg-etc1/cmake_install.cmake")
  include("/home/pi/rts/spring-104.0.1/rts/lib/squish/cmake_install.cmake")

endif()

