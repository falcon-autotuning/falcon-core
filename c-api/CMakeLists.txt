cmake_minimum_required(VERSION 3.14)
project(FalconCoreCAPI VERSION 1.0.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Git version detection
find_package(Git QUIET)
set(FALCON_CORE_C_API_VERSION "${PROJECT_VERSION}")
set(FALCON_CORE_C_API_GIT_COMMIT "unknown")
set(FALCON_CORE_C_API_GIT_TAG "")

if(GIT_FOUND)
  execute_process(
    COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE FALCON_CORE_C_API_GIT_COMMIT
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    RESULT_VARIABLE GIT_COMMIT_RESULT)
  
  if(NOT GIT_COMMIT_RESULT EQUAL 0)
    set(FALCON_CORE_C_API_GIT_COMMIT "unknown")
  endif()
  
  execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --tags --exact-match HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    OUTPUT_VARIABLE FALCON_CORE_C_API_GIT_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    RESULT_VARIABLE GIT_TAG_RESULT)
  
  # If we're not on a tagged commit, check if we have tags at all
  if(NOT GIT_TAG_RESULT EQUAL 0)
    execute_process(
      COMMAND ${GIT_EXECUTABLE} describe --tags --abbrev=0 HEAD
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
      OUTPUT_VARIABLE FALCON_CORE_C_API_GIT_TAG
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
      RESULT_VARIABLE GIT_TAG_ABBREV_RESULT)
    
    if(NOT GIT_TAG_ABBREV_RESULT EQUAL 0)
      set(FALCON_CORE_C_API_GIT_TAG "")
    endif()
  endif()
endif()

message(STATUS "Falcon Core C-API Version: ${FALCON_CORE_C_API_VERSION}")
if(NOT FALCON_CORE_C_API_GIT_COMMIT STREQUAL "unknown")
  message(STATUS "Git commit: ${FALCON_CORE_C_API_GIT_COMMIT}")
endif()
if(FALCON_CORE_C_API_GIT_TAG)
  message(STATUS "Git tag: ${FALCON_CORE_C_API_GIT_TAG}")
else()
  message(STATUS "Git tag: (none found)")
endif()
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
set(C_API_LIB_NAME "falcon_core_c_api")
set(BATCH_SIZE 10)
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
  if(WIN32)
    set(VCPKG_INCLUDE_DIR "${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/include")
    set(RPATH "${CMAKE_BINARY_DIR}/build/vcpkg_installed/x64-windows-dynamic/debug/lib;$<TARGET_FILE_DIR:${C_API_LIB_NAME}>;$<TARGET_FILE_DIR:GTest::gtest_main>;$<TARGET_FILE_DIR:GTest::gtest>")
  else()
    set(VCPKG_INCLUDE_DIR "${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux-dynamic/include")
    set(RPATH "${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux-dynamic/debug/lib;$<TARGET_FILE_DIR:${C_API_LIB_NAME}>;$<TARGET_FILE_DIR:GTest::gtest_main>;$<TARGET_FILE_DIR:GTest::gtest>")
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
    "${C_API_LIB_NAME}"
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

# Import the pre-built falcon_core_cpp library
find_library(FALCON_CORE_CPP_LIB
  NAMES falcon_core_cpp libfalcon_core_cpp
  PATHS ${CORE_ROOT}/build
  NO_DEFAULT_PATH
  REQUIRED
)

# Create an imported target
add_library(falcon_core_cpp SHARED IMPORTED)
set_target_properties(falcon_core_cpp PROPERTIES
  IMPORTED_LOCATION ${FALCON_CORE_CPP_LIB}
  INTERFACE_INCLUDE_DIRECTORIES "${CORE_ROOT}/include"
)

# Link against it
target_link_libraries(${C_API_LIB_NAME} PUBLIC
  falcon_core_cpp
  ${HDF5_CPP_TARGET}
  ${HDF5_TARGET}
  yaml-cpp::yaml-cpp
  xtensor
  ${BOOST_FILESYSTEM_TARGET}
)
if(WIN32)
  target_link_options(${C_API_LIB_NAME} PRIVATE /FORCE:MULTIPLE)
  set_target_properties(falcon_core_cpp PROPERTIES
  IMPORTED_LOCATION ${CORE_ROOT}/build/falcon_core_cpp.dll
  IMPORTED_IMPLIB ${CORE_ROOT}/build/falcon_core_cpp.lib
  INTERFACE_INCLUDE_DIRECTORIES ${CORE_ROOT}/include
)
else()
  set_target_properties(falcon_core_cpp PROPERTIES
  IMPORTED_LOCATION ${CORE_ROOT}/build/libfalcon_core_cpp.so
  INTERFACE_INCLUDE_DIRECTORIES ${CORE_ROOT}/include
)
endif()

# Add version information
target_compile_definitions(
  ${C_API_LIB_NAME}
  PRIVATE
  FALCON_CORE_C_API_VERSION="${FALCON_CORE_C_API_VERSION}"
  FALCON_CORE_C_API_GIT_COMMIT="${FALCON_CORE_C_API_GIT_COMMIT}"
  FALCON_CORE_C_API_GIT_TAG="${FALCON_CORE_C_API_GIT_TAG}")

set_target_properties(
  ${C_API_LIB_NAME}
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build"
             RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build" # For Windows
                                                                  # DLLs
             ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build") # For import
# libs

# Function to copy DLLs for a target
function(copy_runtime_dlls target_name)
  # Copy falcon_core_cpp.dll
  add_custom_command(TARGET ${target_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:falcon_core_cpp>"
      "$<TARGET_FILE_DIR:${target_name}>"
    COMMENT "Copying falcon_core_cpp.dll for ${target_name}"
  )

  # Copy falcon_core_c_api.dll
  add_custom_command(TARGET ${target_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "$<TARGET_FILE:${C_API_LIB_NAME}>"
      "$<TARGET_FILE_DIR:${target_name}>"
    COMMENT "Copying falcon_core_c_api.dll for ${target_name}"
  )

  # Copy vcpkg DLLs
  if(USE_VCPKG)
    # Determine vcpkg bin directory based on build type
    set(VCPKG_BIN_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/bin")
    set(VCPKG_DEBUG_BIN_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/debug/bin")

    # Copy from release bin for Release builds
    if(EXISTS "${VCPKG_BIN_DIR}")
      add_custom_command(TARGET ${target_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
          "${VCPKG_BIN_DIR}"
          "$<TARGET_FILE_DIR:${target_name}>"
        COMMENT "Copying vcpkg DLLs (release) for ${target_name}"
      )
    endif()

    # Also copy debug DLLs if they exist (for Debug builds)
    if(EXISTS "${VCPKG_DEBUG_BIN_DIR}")
      add_custom_command(TARGET ${target_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
          "${VCPKG_DEBUG_BIN_DIR}"
          "$<TARGET_FILE_DIR:${target_name}>"
        COMMENT "Copying vcpkg DLLs (debug) for ${target_name}"
      )
    endif()
  endif()
endfunction()

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

  include(GoogleTest)
  gtest_discover_tests(falcon_core_c_api_run_tests)

  # ---- Integration Tests for Cross-Platform Serialization (C-API) ----
  message(STATUS "Setting up C-API cross-platform serialization integration tests")

  # C-API Serialization integration test
  add_executable(integration_serialize_connection_c tests/integration_serialize_connection.c)
  set_target_properties(integration_serialize_connection_c PROPERTIES
    UNITY_BUILD OFF  # Don't use unity build for standalone programs
  )
  if(WIN32)
    set_target_properties(integration_serialize_connection_c PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    )
    target_link_options(integration_serialize_connection_c PRIVATE /FORCE:MULTIPLE)
  else()
    set_target_properties(integration_serialize_connection_c PROPERTIES
      BUILD_RPATH "${CMAKE_BINARY_DIR};${CORE_BUILD_ABS}"
      INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
      BUILD_WITH_INSTALL_RPATH FALSE
      SKIP_BUILD_RPATH FALSE
    )
  endif()
  target_include_directories(integration_serialize_connection_c PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CORE_ROOT}/include
  )
  target_link_libraries(integration_serialize_connection_c PRIVATE ${C_API_LIB_NAME})

  # C-API Deserialization integration test
  add_executable(integration_deserialize_connection_c tests/integration_deserialize_connection.c)
  set_target_properties(integration_deserialize_connection_c PROPERTIES
    UNITY_BUILD OFF  # Don't use unity build for standalone programs
  )
  if(WIN32)
    set_target_properties(integration_deserialize_connection_c PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    )
    target_link_options(integration_deserialize_connection_c PRIVATE /FORCE:MULTIPLE)
  else()
    set_target_properties(integration_deserialize_connection_c PROPERTIES
      BUILD_RPATH "${CMAKE_BINARY_DIR};${CORE_BUILD_ABS}"
      INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
      BUILD_WITH_INSTALL_RPATH FALSE
      SKIP_BUILD_RPATH FALSE
    )
  endif()
  target_include_directories(integration_deserialize_connection_c PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CORE_ROOT}/include
  )
  target_link_libraries(integration_deserialize_connection_c PRIVATE ${C_API_LIB_NAME})

  message(STATUS "C-API Integration test executables: integration_serialize_connection_c, integration_deserialize_connection_c")

  # ---- Windows: Copy DLLs to executable directory ----
  if(WIN32)
    message(STATUS "Configuring automatic DLL copying for Windows")

    # Apply to both integration test executables
    copy_runtime_dlls(integration_serialize_connection_c)
    copy_runtime_dlls(integration_deserialize_connection_c)
  endif()
endif()

# ---- Falcon Core Info Utility ----
# Command-line utility to display version information
add_executable(falcon_core_info ../utils/falcon_core_info.cpp)
target_link_libraries(falcon_core_info PRIVATE ${C_API_LIB_NAME})
target_include_directories(falcon_core_info PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CORE_ROOT}/include)

# Set output directory
set_target_properties(falcon_core_info PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")

if(WIN32)
  # Windows: Copy DLLs for the utility
  if(TARGET falcon_core_info)
    copy_runtime_dlls(falcon_core_info)
  endif()
endif()
