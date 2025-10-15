# Install script for directory: /home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/xtl" TYPE FILE FILES
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xany.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xbasic_fixed_string.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xbase64.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xclosure.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xcompare.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xcomplex.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xcomplex_sequence.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xspan.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xspan_impl.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xdynamic_bitset.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xfunctional.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xhalf_float.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xhalf_float_impl.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xhash.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xhierarchy_generator.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xiterator_base.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xjson.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xmasked_value_meta.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xmasked_value.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xmeta_utils.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xmultimethods.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xoptional_meta.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xoptional.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xoptional_sequence.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xplatform.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xproxy_wrapper.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xsequence.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xsystem.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xtl_config.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xtype_traits.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xvariant.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xvariant_impl.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/include/xtl/xvisitor.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/xtl" TYPE FILE FILES
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/xtlConfig.cmake"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/xtlConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtl/xtlTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtl/xtlTargets.cmake"
         "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/CMakeFiles/Export/2fc63ec57839ed115fc15a5438bb5aec/xtlTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtl/xtlTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtl/xtlTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/xtl" TYPE FILE FILES "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/CMakeFiles/Export/2fc63ec57839ed115fc15a5438bb5aec/xtlTargets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" TYPE FILE FILES "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/xtl.pc")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/tylerk/falcon-dev/falcon-core/packaging/xtl/src/xtl-0.7.5/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
