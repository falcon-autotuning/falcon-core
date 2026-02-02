cmake_minimum_required(VERSION 3.14)
project(FalconCoreCAPI LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# set(CMAKE_CXX_VISIBILITY_PRESET hidden)
# set(CMAKE_C_VISIBILITY_PRESET hidden)
# set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
set(C_API_LIB_NAME "falcon_core_c_api")
set(C_API_TARGET "falcon_core_c_api")
set(BATCH_SIZE 20)
option(FALCON_CORE_DEV "Dev mode generates coverage and testing" OFF)
if(FALCON_CORE_DEV)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

if(MSVC)
  set(COMPILER_IS_MSVC TRUE)
else()
  set(COMPILER_IS_MSVC FALSE)
endif()

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
  if(FALCON_CORE_DEV)
    message("Clang detected. In dev mode so coverage will be built.")
    if(COMPILER_IS_MSVC)
      # clang-cl / MSVC-style flags
      set(C_FLAGS "/Od -fprofile-instr-generate -fcoverage-mapping")
    else()
      # native Clang (POSIX flags)
      set(C_FLAGS "-O0 -fprofile-instr-generate -fcoverage-mapping")
    endif()
  else()
    message("Clang detected.")
    if(COMPILER_IS_MSVC)
      set(C_FLAGS "/O2")
    else()
      set(C_FLAGS "-Oz")
    endif()
  endif()
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
  message("GNU detected. In dev mode so coverage will be built.")
  set(C_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
else()
  # Fallback for other compilers
  if(COMPILER_IS_MSVC)
    set(C_FLAGS "/O2")
  else()
    set(C_FLAGS "-Oz")
  endif()
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if(FALCON_CORE_DEV)
    if(COMPILER_IS_MSVC)
      # Add debug info and coverage flags in MSVC syntax where appropriate
      set(CPP_FLAGS "/Zi /Od -fprofile-instr-generate -fcoverage-mapping")
    else()
      set(CPP_FLAGS "-g -O0 -fprofile-instr-generate -fcoverage-mapping")
    endif()
  else()
    if(COMPILER_IS_MSVC)
      set(CPP_FLAGS "/Zi /O2")
    else()
      set(CPP_FLAGS "-g -Oz")
    endif()
  endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  set(CPP_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
else()
  if(COMPILER_IS_MSVC)
    set(CPP_FLAGS "/Zi /O2")
  else()
    set(CPP_FLAGS "-g -Oz")
  endif()
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
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=lld")

option(USE_VCPKG "Use vcpkg for dependencies" ON)
set(BOOST_FILESYSTEM_TARGET Boost::filesystem)
if(USE_VCPKG)
  # Use the vcpkg toolchain (preferred) so we don't manually add include dirs.
  # But when a vcpkg_installed layout is inspected, choose the appropriate triplet
  if(WIN32)
    set(VCPKG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/include")
    set(RPATH "${CMAKE_SOURCE_DIR}/build/vcpkg_installed/x64-windows-dynamic/debug/lib;$<TARGET_FILE_DIR:${C_API_LIB_NAME}>;$<TARGET_FILE_DIR:GTest::gtest_main>;$<TARGET_FILE_DIR:GTest::gtest>")
  else()
    set(VCPKG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include")
    set(RPATH "${CMAKE_SOURCE_DIR}/build/vcpkg_installed/x64-linux-dynamic/debug/lib;$<TARGET_FILE_DIR:${C_API_LIB_NAME}>;$<TARGET_FILE_DIR:GTest::gtest_main>;$<TARGET_FILE_DIR:GTest::gtest>")
  endif()

  set(HDF5_TARGET hdf5::hdf5-shared)
  set(HDF5_CPP_TARGET hdf5::hdf5_cpp-shared)
  set(BOOST_SYSTEM_TARGET Boost::system)
  set(BOOST_UUID_TARGET Boost::uuid)
else()
  set(HDF5_TARGET hdf5-shared)
  set(HDF5_CPP_TARGET hdf5_cpp-shared)
  set(RPATH
      "$<TARGET_FILE_DIR:${C_API_LIB_NAME}>;$<TARGET_FILE_DIR:GTest::gtest_main>;$<TARGET_FILE_DIR:GTest::gtest>"
  )
endif()

set(C_API_LIB_NAME
    "${C_API_TARGET}"
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

file(GLOB_RECURSE C_API_SOURCES "src/*.cpp" "src/*.c")

add_library(${C_API_LIB_NAME} SHARED ${C_API_SOURCES})

# Platform-specific precompiled header handling
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include/falcon_core/Precompiled_c_api.h")
  target_precompile_headers(${C_API_LIB_NAME} PRIVATE
                            include/falcon_core/Precompiled_c_api.h)
endif()

set_target_properties(${C_API_LIB_NAME} PROPERTIES UNITY_BUILD ON)
set_target_properties(${C_API_LIB_NAME} PROPERTIES UNITY_BUILD_BATCH_SIZE
                                                   ${BATCH_SIZE})

# Windows-specific DLL settings
if(WIN32)
  set_target_properties(
    ${C_API_LIB_NAME}
    PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS OFF # We control exports manually via
                                              # FALCON_C_API
               PREFIX "" # No 'lib' prefix on Windows
               SUFFIX ".dll" # Explicit .dll extension
  )
else()
  set_target_properties(${C_API_LIB_NAME} PROPERTIES PREFIX "lib" SUFFIX ".so")
endif()

target_include_directories(
  ${C_API_LIB_NAME}
  PUBLIC $<BUILD_INTERFACE:${CORE_ROOT}/include>
         $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include>)

get_filename_component(CORE_BUILD_ABS "${CORE_ROOT}/build" ABSOLUTE)
target_link_libraries(${C_API_LIB_NAME} PUBLIC falcon_core_cpp)
add_subdirectory(${CORE_ROOT} ${CORE_ROOT}/build)
if(WIN32)
  target_link_options(${C_API_LIB_NAME} PRIVATE /FORCE:MULTIPLE)
endif()

set_target_properties(
  ${C_API_LIB_NAME}
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build"
             RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build" # For Windows
                                                                  # DLLs
             ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build") # For import
# libs

# ---- Optional test build ----
if(FALCON_CORE_DEV)
  find_package(GTest CONFIG REQUIRED)
  enable_testing()
  file(GLOB RUN_TESTS_SOURCES tests/*.cpp)
  add_executable(falcon_core_c_api_run_tests ${RUN_TESTS_SOURCES})
  target_link_directories(falcon_core_c_api_run_tests PRIVATE ${CORE_BUILD_ABS})

  if(WIN32)
    # Windows: Disable Unity Build to avoid duplicate symbol errors
    set_target_properties(falcon_core_c_api_run_tests PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
      UNITY_BUILD ON
      UNITY_BUILD_BATCH_SIZE ${BATCH_SIZE}
    )
    # Windows with DLLs and templates: inline methods in template classes cause duplicate
    # symbols because extern template doesn't fully suppress instantiation of inline methods.
    # Use /FORCE:MULTIPLE to allow the linker to resolve these identical duplicates.
    # Note: This is safe here because all duplicates are identical template instantiations.
    target_link_options(falcon_core_c_api_run_tests PRIVATE /FORCE:MULTIPLE)
    message(STATUS "Windows detected: /FORCE:MULTIPLE enabled for falcon_core_c_api_run_tests")
  else()
    set_target_properties(falcon_core_c_api_run_tests PROPERTIES
      UNITY_BUILD ON
      UNITY_BUILD_BATCH_SIZE ${BATCH_SIZE}
    )
  endif()

  set_target_properties(
    falcon_core_c_api_run_tests
    PROPERTIES SKIP_BUILD_RPATH FALSE
               SKIP_INSTALL_RPATH FALSE
               BUILD_WITH_INSTALL_RPATH FALSE)
  target_compile_definitions(falcon_core_c_api_run_tests PRIVATE FALCON_CORE_USE_EXTERN_TEMPLATES)

  if(USE_VCPKG)
    target_link_libraries(
      falcon_core_c_api_run_tests
      PRIVATE GTest::gtest_main Boost::filesystem Boost::system
              yaml-cpp::yaml-cpp ${C_API_LIB_NAME})
  else()
    target_link_libraries(
      falcon_core_c_api_run_tests PRIVATE GTest::gtest_main yaml-cpp::yaml-cpp
                                          ${C_API_LIB_NAME})
  endif()

  target_link_libraries(falcon_core_cpp_run_tests PUBLIC yaml-cpp::yaml-cpp)
  include(GoogleTest)
  gtest_discover_tests(falcon_core_c_api_run_tests)
endif()
