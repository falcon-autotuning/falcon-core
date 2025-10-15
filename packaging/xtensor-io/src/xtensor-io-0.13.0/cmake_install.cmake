# Install script for directory: /home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/xtensor-io" TYPE FILE FILES
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xaudio.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xchunk_store_manager.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xfile_array.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xgdal.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xhighfive.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/ximage.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_binary.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_blosc.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_aws_handler.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_disk_handler.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_gcs_handler.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_gdal_handler.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_gzip.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_zlib.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_file_wrapper.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_vsilfile_wrapper.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xio_stream_wrapper.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xnpz.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xtensor-io.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/xtensor_io_config.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/xtensor-io/thirdparty" TYPE DIRECTORY FILES "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/include/xtensor-io/thirdparty/zstr")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor-io" TYPE FILE FILES
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/xtensor-ioConfig.cmake"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/xtensor-ioConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor-io/xtensor-ioTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor-io/xtensor-ioTargets.cmake"
         "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/CMakeFiles/Export/20875277474d12afab36f9eab84bc618/xtensor-ioTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor-io/xtensor-ioTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor-io/xtensor-ioTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/xtensor-io" TYPE FILE FILES "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/CMakeFiles/Export/20875277474d12afab36f9eab84bc618/xtensor-ioTargets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/xtensor-io.pc")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/install_local_manifest.txt"
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
  file(WRITE "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor-io/src/xtensor-io-0.13.0/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
