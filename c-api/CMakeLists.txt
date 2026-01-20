cmake_minimum_required(VERSION 3.14)
project(FalconCoreCAPI LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(FALCON_CORE_DEV "Dev mode generates coverage and testing" OFF)
option(USE_VCPKG "Use vcpkg for dependencies" ON)

# Path to the core C++ project (cpp/)
# If your layout is repo_root/{cpp,c-api}, this default is correct.
set(CORE_ROOT "${CMAKE_CURRENT_LIST_DIR}/../cpp" CACHE PATH "Path to FalconCore C++ source root")

set(C_API_TARGET "falcon_core_c_api")
set(C_API_LIB_NAME "${C_API_TARGET}" CACHE STRING "ChangeMe")

if(FALCON_CORE_DEV)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# ---- Policy for Boost wrapper (same as cpp) ----
if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

# ---- Build core first so falcon_core_cpp exists ----
add_subdirectory(${CORE_ROOT} ${CMAKE_BINARY_DIR}/falcon_core_cpp_build)

# ---- Dependencies (if your C-API actually uses these directly) ----
find_package(cereal CONFIG REQUIRED)
find_package(xtl CONFIG REQUIRED)
find_package(xtensor CONFIG REQUIRED)
find_package(xsimd CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(hdf5 CONFIG REQUIRED)

# Select HDF5 targets safely for static vs shared triplets
set(HDF5_TARGET "")
set(HDF5_CPP_TARGET "")

if(TARGET hdf5::hdf5-shared)
  set(HDF5_TARGET hdf5::hdf5-shared)
elseif(TARGET hdf5::hdf5-static)
  set(HDF5_TARGET hdf5::hdf5-static)
elseif(TARGET hdf5::hdf5)
  set(HDF5_TARGET hdf5::hdf5)
else()
  message(FATAL_ERROR "No HDF5 CMake target found (expected hdf5::hdf5-static or hdf5::hdf5-shared).")
endif()

if(TARGET hdf5::hdf5_cpp-shared)
  set(HDF5_CPP_TARGET hdf5::hdf5_cpp-shared)
elseif(TARGET hdf5::hdf5_cpp-static)
  set(HDF5_CPP_TARGET hdf5::hdf5_cpp-static)
elseif(TARGET hdf5::hdf5_cpp)
  set(HDF5_CPP_TARGET hdf5::hdf5_cpp)
else()
  message(STATUS "No HDF5 C++ target found; proceeding without HDF5 C++ link target.")
endif()

# Boost
find_package(Boost REQUIRED COMPONENTS filesystem)
if(USE_VCPKG)
  find_package(Boost REQUIRED COMPONENTS system uuid)
endif()

# ---- C-API library ----
file(GLOB_RECURSE C_API_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

if(WIN32)
  add_library(${C_API_LIB_NAME} STATIC ${C_API_SOURCES})
else()
  add_library(${C_API_LIB_NAME} SHARED ${C_API_SOURCES})
endif()

# Handle large object files on MinGW or using MSVC
if(MINGW)
  target_compile_options(${C_API_LIB_NAME} PRIVATE -Wa,-mbig-obj)
endif()

if (MSVC)
  set_source_files_properties(
    src/math/AnalyticFunction.cpp
    PROPERTIES COMPILE_OPTIONS "/bigobj"
  )
  add_compile_options(/Zc:__cplusplus)
endif()



target_include_directories(
  ${C_API_LIB_NAME}
  PUBLIC $<BUILD_INTERFACE:${CORE_ROOT}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
         $<INSTALL_INTERFACE:include>)

target_link_libraries(
  ${C_API_LIB_NAME}
  PUBLIC falcon_core_cpp
         Boost::filesystem
         yaml-cpp::yaml-cpp
         ${HDF5_TARGET}
         cereal::cereal)

if(USE_VCPKG)
  target_link_libraries(${C_API_LIB_NAME} PUBLIC Boost::system Boost::uuid)
endif()

if(HDF5_CPP_TARGET)
  target_link_libraries(${C_API_LIB_NAME} PUBLIC ${HDF5_CPP_TARGET})
endif()

# Output dirs (don’t force .so on Windows)
set_target_properties(
  ${C_API_LIB_NAME}
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# ---- Optional tests ----
if(FALCON_CORE_DEV)
  find_package(GTest CONFIG REQUIRED)
  enable_testing()

  file(GLOB RUN_TESTS_SOURCES tests/test_*.cpp)
  add_executable(falcon_core_c_api_run_tests ${RUN_TESTS_SOURCES})
  target_link_libraries(falcon_core_c_api_run_tests PRIVATE GTest::gtest_main ${C_API_LIB_NAME})

  if(WIN32)
    add_test(NAME falcon_core_c_api_run_tests COMMAND falcon_core_c_api_run_tests)
  else()
    include(GoogleTest)
    gtest_discover_tests(falcon_core_c_api_run_tests)
  endif()
endif()
