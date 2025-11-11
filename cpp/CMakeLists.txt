cmake_minimum_required(VERSION 3.20)
project(FalconCore LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
option(USE_VCPKG "Use vcpkg for dependencies" ON)
set(BOOST_FILESYSTEM_TARGET Boost::filesystem)
if(USE_VCPKG)
  # Don't add manual include dirs or link dirs; vcpkg toolchain handles it
  set(VCPKG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include")
  set(VCPKG_RPATH
      "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux-dynamic/debug/lib;${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux-dynamic/lib"
  )
  set(HDF5_TARGET hdf5::hdf5-shared)
  set(HDF5_CPP_TARGET hdf5::hdf5_cpp-shared)
  set(BOOST_SYSTEM_TARGET Boost::system)
  set(BOOST_UUID_TARGET Boost::uuid)
else()
  set(HDF5_TARGET hdf5-shared)
  set(HDF5_CPP_TARGET hdf5_cpp-shared)
endif()
set(CPP_LIB_NAME
    "${CPP_TARGET}"
    CACHE STRING "ChangeMe")
if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(cereal CONFIG REQUIRED)
get_target_property(CEREAL_INCLUDE_DIR cereal::cereal
                    INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "cereal include dir: ${CEREAL_INCLUDE_DIR}")

find_package(xtl CONFIG REQUIRED)
get_target_property(XTL_INCLUDE_DIR xtl INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "xtl include dir: ${XTL_INCLUDE_DIR}")

find_package(xtensor CONFIG REQUIRED)
get_target_property(XTENSOR_INCLUDE_DIR xtensor INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "xtensor include dir: ${XTENSOR_INCLUDE_DIR}")

find_package(xsimd CONFIG REQUIRED)
get_target_property(XSIMD_INCLUDE_DIR xsimd INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "xsimd include dir: ${XSIMD_INCLUDE_DIR}")

find_package(yaml-cpp CONFIG REQUIRED)
get_target_property(YAML_CPP_INCLUDE_DIR yaml-cpp::yaml-cpp
                    INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "yaml-cpp include dir: ${YAML_CPP_INCLUDE_DIR}")
if(USE_VCPKG)
  find_package(hdf5 CONFIG REQUIRED)
  get_target_property(HDF5_INCLUDE_DIR ${HDF5_TARGET}
                    INTERFACE_INCLUDE_DIRECTORIES)
  message(STATUS "hdf5 include dir: ${HDF5_INCLUDE_DIR}")
endif()

find_package(Boost REQUIRED COMPONENTS filesystem)
get_target_property(BOOST_INCLUDE_DIR ${BOOST_FILESYSTEM_TARGET}
                    INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "Boost filesystem include dir: ${BOOST_INCLUDE_DIR}")
if(USE_VCPKG)
  find_package(Boost REQUIRED COMPONENTS system uuid)
  get_target_property(BOOST_INCLUDE_DIR ${BOOST_SYSTEM_TARGET}
                      INTERFACE_INCLUDE_DIRECTORIES)
  message(STATUS "Boost system include dir: ${BOOST_INCLUDE_DIR}")
  get_target_property(BOOST_INCLUDE_DIR ${BOOST_UUID_TARGET}
                      INTERFACE_INCLUDE_DIRECTORIES)
  message(STATUS "Boost uuid include dir: ${BOOST_INCLUDE_DIR}")
endif()

file(GLOB_RECURSE FALCON_CORE_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
add_library(${CPP_LIB_NAME} SHARED ${FALCON_CORE_SOURCES})
target_include_directories(
  ${CPP_LIB_NAME}
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>
         $<$<BOOL:${USE_VCPKG}>:${VCPKG_INCLUDE_DIR}>)
target_link_libraries(
  ${CPP_LIB_NAME}
  PUBLIC ${BOOST_FILESYSTEM_TARGET}
         ${BOOST_SYSTEM_TARGET}
         ${BOOST_UUID_TARGET}
         xtl
         xtensor
         xsimd
         yaml-cpp::yaml-cpp
         ${HDF5_TARGET}
         ${HDF5_CPP_TARGET}
         cereal::cereal)
target_link_libraries(${CPP_LIB_NAME} PUBLIC yaml-cpp::yaml-cpp)

# ---- Optional test build ----
option(BUILD_TESTS "Build and enable C++ tests" ON)

if(BUILD_TESTS)
  find_package(GTest CONFIG REQUIRED)
  message(STATUS "Setting up C++ tests")
  enable_testing()
  file(GLOB RUN_TESTS_SOURCES tests/test_*.cpp)
  add_executable(falcon_core_cpp_run_tests ${RUN_TESTS_SOURCES})
  set_target_properties(
    falcon_core_cpp_run_tests
    PROPERTIES BUILD_RPATH "$<$<BOOL:${USE_VCPKG}>:${VCPKG_RPATH}>"
               INSTALL_RPATH "$<$<BOOL:${USE_VCPKG}>:${VCPKG_RPATH}>"
               SKIP_BUILD_RPATH FALSE
               SKIP_INSTALL_RPATH FALSE
               BUILD_WITH_INSTALL_RPATH FALSE)
  if(USE_VCPKG)
    target_link_libraries(
      falcon_core_cpp_run_tests
      PRIVATE GTest::gtest_main Boost::filesystem Boost::system
              yaml-cpp::yaml-cpp ${CPP_LIB_NAME})
  else()

    target_link_libraries(
      falcon_core_cpp_run_tests PRIVATE GTest::gtest_main Boost::filesystem
                                        yaml-cpp::yaml-cpp ${CPP_LIB_NAME})
  endif()
  target_link_libraries(falcon_core_cpp_run_tests PUBLIC yaml-cpp::yaml-cpp)
  include(GoogleTest)
  gtest_discover_tests(falcon_core_cpp_run_tests)
endif()
