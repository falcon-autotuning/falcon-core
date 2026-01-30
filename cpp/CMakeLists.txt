cmake_minimum_required(VERSION 3.20)
project(FalconCore LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CPP_TARGET "falcon_core_cpp")
option(FALCON_CORE_DEV "Dev mode generates coverage and testing" OFF)
set(BATCH_SIZE 4)
if(FALCON_CORE_DEV)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# Detect compiler and set coverage flags
if(CMAKE_C_COMPILER_ID MATCHES "Clang")
  if(FALCON_CORE_DEV)
    message("Clang detected. In dev mode so coverage will be built.")
    set(C_FLAGS "-O0 -fprofile-instr-generate -fcoverage-mapping")
  else()
    message("Clang detected.")
    set(C_FLAGS "-Oz")
  endif()
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
  message("GNU detected. In dev mode so coverage will be built.")
  set(C_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
else()
  message("GNU detected.")
  set(C_FLAGS "-Oz")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if(FALCON_CORE_DEV)
    set(CPP_FLAGS "-g -O0 -fprofile-instr-generate -fcoverage-mapping")
  else()
    set(CPP_FLAGS "-g -Oz")
  endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CPP_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
else()
  set(CPP_FLAGS "-g -Oz")
endif()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ${CPP_FLAGS}")
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  message("Ccache was found. Making use of caching.")
  set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
  set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif()
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
# Make linker flag conditional
if(NOT WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=lld")
endif()

# Handling VCPKG support
option(USE_VCPKG "Use vcpkg for dependencies" ON)
set(BOOST_FILESYSTEM_TARGET Boost::filesystem)
if(USE_VCPKG)
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

find_package(hdf5 CONFIG REQUIRED)
get_target_property(HDF5_INCLUDE_DIR ${HDF5_TARGET}
                    INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "hdf5 include dir: ${HDF5_INCLUDE_DIR}")

find_package(Boost REQUIRED COMPONENTS filesystem)
get_target_property(BOOST_INCLUDE_DIR ${BOOST_FILESYSTEM_TARGET}
                    INTERFACE_INCLUDE_DIRECTORIES)

find_package(Threads REQUIRED)
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
# Windows-specific settings
if(WIN32)
  # Don't use CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS - we control exports manually
  set_target_properties(${CPP_LIB_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS
                                                   OFF)
endif()
if(WIN32)
  # Windows: Disable Unity Build to avoid duplicate symbol errors
  set_target_properties(${CPP_LIB_NAME} PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS OFF
    UNITY_BUILD ON
    UNITY_BUILD_BATCH_SIZE ${BATCH_SIZE}
  )
  message(STATUS "Windows detected: Unity Build DISABLED for ${CPP_LIB_NAME}")
else()
  # Linux/macOS: Keep Unity Build enabled for faster compilation
  set_target_properties(${CPP_LIB_NAME} PROPERTIES
    UNITY_BUILD ON
    UNITY_BUILD_BATCH_SIZE ${BATCH_SIZE}
  )
  message(STATUS "Unix detected: Unity Build ENABLED for ${CPP_LIB_NAME}")
endif()
target_include_directories(
  ${CPP_LIB_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                         $<INSTALL_INTERFACE:include>)
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
         cereal::cereal
         Threads::Threads)
target_link_libraries(${CPP_LIB_NAME} PUBLIC yaml-cpp::yaml-cpp)
# target_link_options(${CPP_LIB_NAME} PRIVATE /FORCE:MULTIPLE)

# ---- Optional test build ----
if(FALCON_CORE_DEV)
  find_package(GTest CONFIG REQUIRED)
  message(STATUS "Setting up C++ tests")
  enable_testing()
  file(GLOB RUN_TESTS_SOURCES tests/*.cpp)
  add_executable(falcon_core_cpp_run_tests ${RUN_TESTS_SOURCES})
  if(WIN32)
    # Windows: Disable Unity Build to avoid duplicate symbol errors
    set_target_properties(falcon_core_cpp_run_tests PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS OFF
    UNITY_BUILD ON
    UNITY_BUILD_BATCH_SIZE ${BATCH_SIZE}
  )
    # Windows with DLLs and templates: inline methods in template classes cause duplicate
    # symbols because extern template doesn't fully suppress instantiation of inline methods.
    # Use /FORCE:MULTIPLE to allow the linker to resolve these identical duplicates.
    # Note: This is safe here because all duplicates are identical template instantiations.
    # The alternative would be to refactor all template classes to move method definitions
    # out of the class body, which would be a significant change to the codebase.
    target_link_options(falcon_core_cpp_run_tests PRIVATE /FORCE:MULTIPLE)
    message(STATUS "Windows detected: Unity Build DISABLED, /FORCE:MULTIPLE enabled for falcon_core_cpp_run_tests")
  else()
    # Linux/macOS: Keep Unity Build enabled for faster compilation
    set_target_properties(falcon_core_cpp_run_tests PROPERTIES
    UNITY_BUILD ON
    UNITY_BUILD_BATCH_SIZE ${BATCH_SIZE}
  )
    message(STATUS "Unix detected: Unity Build ENABLED for falcon_core_cpp_run_tests")
  endif()
  set_target_properties(
    falcon_core_cpp_run_tests
    PROPERTIES SKIP_BUILD_RPATH FALSE
               SKIP_INSTALL_RPATH FALSE
               BUILD_WITH_INSTALL_RPATH FALSE)
  target_compile_definitions(falcon_core_cpp_run_tests PRIVATE FALCON_CORE_USE_EXTERN_TEMPLATES)
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
