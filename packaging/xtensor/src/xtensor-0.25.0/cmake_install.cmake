# Install script for directory: /home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/xtensor" TYPE FILE FILES
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xaccessible.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xaccumulator.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xadapt.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xarray.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xassign.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xaxis_iterator.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xaxis_slice_iterator.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xblockwise_reducer.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xblockwise_reducer_functors.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xbroadcast.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xbuffer_adaptor.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xbuilder.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xchunked_array.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xchunked_assign.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xchunked_view.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xcomplex.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xcontainer.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xcsv.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xdynamic_view.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xeval.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xexception.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xexpression.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xexpression_holder.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xexpression_traits.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xfixed.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xfunction.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xfunctor_view.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xgenerator.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xhistogram.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xindex_view.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xinfo.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xio.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xiterable.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xiterator.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xjson.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xlayout.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xmanipulation.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xmasked_view.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xmath.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xmime.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xmultiindex_iterator.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xnoalias.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xnorm.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xnpy.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xoffset_view.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xoperation.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xoptional.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xoptional_assembly.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xoptional_assembly_base.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xoptional_assembly_storage.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xpad.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xrandom.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xreducer.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xrepeat.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xscalar.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xsemantic.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xset_operation.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xshape.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xslice.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xsort.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xstorage.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xstrided_view.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xstrided_view_base.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xstrides.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xtensor.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xtensor_config.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xtensor_forward.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xtensor_simd.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xutils.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xvectorize.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xview.hpp"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/include/xtensor/xview_utils.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor" TYPE FILE FILES
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/xtensorConfig.cmake"
    "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/xtensorConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor/xtensorTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor/xtensorTargets.cmake"
         "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/CMakeFiles/Export/0f2a327e949144b0b747c96acb1eb12f/xtensorTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor/xtensorTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor/xtensorTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/xtensor" TYPE FILE FILES "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/CMakeFiles/Export/0f2a327e949144b0b747c96acb1eb12f/xtensorTargets.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" TYPE FILE FILES "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/xtensor.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/xtensor.hpp")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/install_local_manifest.txt"
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
  file(WRITE "/home/tylerk/falcon-dev/falcon-core/packaging/xtensor/src/xtensor-0.25.0/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
