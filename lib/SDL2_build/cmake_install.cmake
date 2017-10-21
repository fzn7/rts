# Install script for directory: /home/pi/rts/lib/SDL2

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
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/pi/rts/lib/SDL2_build/libSDL2.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/pi/rts/lib/SDL2_build/libSDL2main.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/home/pi/rts/lib/SDL2/include/SDL.h"
    "/home/pi/rts/lib/SDL2/include/SDL_assert.h"
    "/home/pi/rts/lib/SDL2/include/SDL_atomic.h"
    "/home/pi/rts/lib/SDL2/include/SDL_audio.h"
    "/home/pi/rts/lib/SDL2/include/SDL_bits.h"
    "/home/pi/rts/lib/SDL2/include/SDL_blendmode.h"
    "/home/pi/rts/lib/SDL2/include/SDL_clipboard.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_android.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_iphoneos.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_macosx.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_minimal.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_pandora.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_psp.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_windows.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_winrt.h"
    "/home/pi/rts/lib/SDL2/include/SDL_config_wiz.h"
    "/home/pi/rts/lib/SDL2/include/SDL_copying.h"
    "/home/pi/rts/lib/SDL2/include/SDL_cpuinfo.h"
    "/home/pi/rts/lib/SDL2/include/SDL_egl.h"
    "/home/pi/rts/lib/SDL2/include/SDL_endian.h"
    "/home/pi/rts/lib/SDL2/include/SDL_error.h"
    "/home/pi/rts/lib/SDL2/include/SDL_events.h"
    "/home/pi/rts/lib/SDL2/include/SDL_filesystem.h"
    "/home/pi/rts/lib/SDL2/include/SDL_gamecontroller.h"
    "/home/pi/rts/lib/SDL2/include/SDL_gesture.h"
    "/home/pi/rts/lib/SDL2/include/SDL_haptic.h"
    "/home/pi/rts/lib/SDL2/include/SDL_hints.h"
    "/home/pi/rts/lib/SDL2/include/SDL_joystick.h"
    "/home/pi/rts/lib/SDL2/include/SDL_keyboard.h"
    "/home/pi/rts/lib/SDL2/include/SDL_keycode.h"
    "/home/pi/rts/lib/SDL2/include/SDL_loadso.h"
    "/home/pi/rts/lib/SDL2/include/SDL_log.h"
    "/home/pi/rts/lib/SDL2/include/SDL_main.h"
    "/home/pi/rts/lib/SDL2/include/SDL_messagebox.h"
    "/home/pi/rts/lib/SDL2/include/SDL_mouse.h"
    "/home/pi/rts/lib/SDL2/include/SDL_mutex.h"
    "/home/pi/rts/lib/SDL2/include/SDL_name.h"
    "/home/pi/rts/lib/SDL2/include/SDL_opengl.h"
    "/home/pi/rts/lib/SDL2/include/SDL_opengl_glext.h"
    "/home/pi/rts/lib/SDL2/include/SDL_opengles.h"
    "/home/pi/rts/lib/SDL2/include/SDL_opengles2.h"
    "/home/pi/rts/lib/SDL2/include/SDL_opengles2_gl2.h"
    "/home/pi/rts/lib/SDL2/include/SDL_opengles2_gl2ext.h"
    "/home/pi/rts/lib/SDL2/include/SDL_opengles2_gl2platform.h"
    "/home/pi/rts/lib/SDL2/include/SDL_opengles2_khrplatform.h"
    "/home/pi/rts/lib/SDL2/include/SDL_pixels.h"
    "/home/pi/rts/lib/SDL2/include/SDL_platform.h"
    "/home/pi/rts/lib/SDL2/include/SDL_power.h"
    "/home/pi/rts/lib/SDL2/include/SDL_quit.h"
    "/home/pi/rts/lib/SDL2/include/SDL_rect.h"
    "/home/pi/rts/lib/SDL2/include/SDL_render.h"
    "/home/pi/rts/lib/SDL2/include/SDL_revision.h"
    "/home/pi/rts/lib/SDL2/include/SDL_rwops.h"
    "/home/pi/rts/lib/SDL2/include/SDL_scancode.h"
    "/home/pi/rts/lib/SDL2/include/SDL_shape.h"
    "/home/pi/rts/lib/SDL2/include/SDL_stdinc.h"
    "/home/pi/rts/lib/SDL2/include/SDL_surface.h"
    "/home/pi/rts/lib/SDL2/include/SDL_system.h"
    "/home/pi/rts/lib/SDL2/include/SDL_syswm.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_assert.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_common.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_compare.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_crc32.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_font.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_fuzzer.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_harness.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_images.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_log.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_md5.h"
    "/home/pi/rts/lib/SDL2/include/SDL_test_random.h"
    "/home/pi/rts/lib/SDL2/include/SDL_thread.h"
    "/home/pi/rts/lib/SDL2/include/SDL_timer.h"
    "/home/pi/rts/lib/SDL2/include/SDL_touch.h"
    "/home/pi/rts/lib/SDL2/include/SDL_types.h"
    "/home/pi/rts/lib/SDL2/include/SDL_version.h"
    "/home/pi/rts/lib/SDL2/include/SDL_video.h"
    "/home/pi/rts/lib/SDL2/include/begin_code.h"
    "/home/pi/rts/lib/SDL2/include/close_code.h"
    "/home/pi/rts/lib/SDL2_build/include/SDL_config.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/pi/rts/lib/SDL2_build/sdl2.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/pi/rts/lib/SDL2_build/sdl2-config")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/aclocal/sdl2.m4")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/share/aclocal" TYPE FILE FILES "/home/pi/rts/lib/SDL2/sdl2.m4")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/pi/rts/lib/SDL2_build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
