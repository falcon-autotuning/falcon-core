cmake_minimum_required(VERSION 3.20)

project(falcon-core
  VERSION 1.2.12
  LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ============================================================================
# Build Options & vcpkg Feature Integration
# ============================================================================
# This option now defaults to OFF. When a user installs this package with the
# 'c-api' feature enabled (e.g., `vcpkg install falcon-core[c-api]`), vcpkg
# will automatically turn this ON by passing `-DFALCON_CORE_BUILD_C_API=ON`
# to CMake. This is the core of vcpkg feature integration.
option(FALCON_CORE_BUILD_C_API "Build optional C99 wrapper API" OFF)

# Keep other options for local development
option(BUILD_TESTS "Build tests" OFF)
option(USE_CCACHE "Enable ccache or sccache if available" ON)
option(ENABLE_PCH "Enable precompiled headers" ON)


# ============================================================================
# Platform & Compiler Adjustments
# ============================================================================
if(WIN32)
  add_compile_definitions(NOMINMAX _CRT_SECURE_NO_WARNINGS)
endif()

if(USE_CCACHE)
  find_program(SCCACHE_PROGRAM sccache)
  if(SCCACHE_PROGRAM)
    message(STATUS "Using sccache: ${SCCACHE_PROGRAM}")
    set(CMAKE_C_COMPILER_LAUNCHER ${SCCACHE_PROGRAM})
    set(CMAKE_CXX_COMPILER_LAUNCHER ${SCCACHE_PROGRAM})
  else()
    find_program(CCACHE_PROGRAM ccache)
    if(CCACHE_PROGRAM)
      message(STATUS "Using ccache: ${CCACHE_PROGRAM}")
      set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
      set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
    endif()
  endif()
endif()

# ============================================================================
# Find Dependencies
# ============================================================================
find_package(cereal   CONFIG REQUIRED)
find_package(xtl      CONFIG REQUIRED)
find_package(xtensor  CONFIG REQUIRED)
find_package(xsimd    CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(Boost    CONFIG REQUIRED COMPONENTS filesystem system uuid)
find_package(Threads         REQUIRED)
find_package(hdf5     CONFIG REQUIRED COMPONENTS HL CXX szip zlib)


# ============================================================================
# C++ Core Library (falcon-core)
# ============================================================================
file(GLOB_RECURSE CPP_SOURCES "src/cpp/*.cpp")
add_library(falcon-core SHARED ${CPP_SOURCES})
set_target_properties(falcon-core PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
)
# Allows conditional control over template instatntiation and symbol export in headers
target_compile_definitions(falcon-core PRIVATE FALCON_CORE_BUILDING_LIBRARY)

target_include_directories(falcon-core
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(falcon-core
  PUBLIC
    Boost::filesystem
    Boost::uuid
    xtensor
  PRIVATE
    xsimd
    hdf5::hdf5-shared
    hdf5::hdf5_cpp-shared
    Boost::system
    xtl
    yaml-cpp::yaml-cpp
    cereal::cereal
    Threads::Threads
)
if(WIN32)
  # Use COMDAT folding to automatically merge identical template instantiations
  target_compile_options(falcon-core PRIVATE /bigobj)
  target_link_options(falcon-core PRIVATE /OPT:ICF /OPT:REF)
  message(STATUS "Windows detected: /OPT:ICF enabled for COMDAT folding")
endif()

# ============================================================================
# C API Wrapper Library (falcon-core-c-api)
# ============================================================================
# This entire block is conditional. It only runs if the feature is enabled.
if(FALCON_CORE_BUILD_C_API)
  file(GLOB_RECURSE C_SOURCES "src/c/*.cpp" "src/c/*.c")
  add_library(falcon-core-c-api SHARED ${C_SOURCES})
  set_target_properties(falcon-core-c-api PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
  )

  target_include_directories(falcon-core-c-api
    PUBLIC
      # The C-API needs the same include directories
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
      $<INSTALL_INTERFACE:include>
  )

  target_link_libraries(falcon-core-c-api PUBLIC falcon-core)
  if(WIN32)
    # Use COMDAT folding to automatically merge identical template instantiations
    target_compile_options(falcon-core-c-api PRIVATE /bigobj)
    target_link_options(falcon-core-c-api PRIVATE /OPT:ICF /OPT:REF)
    message(STATUS "Windows detected: /OPT:ICF enabled for COMDAT folding")
  endif()

endif()

# ============================================================================
# Testing
# ============================================================================
if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# ============================================================================
# Installation & vcpkg Export
# ============================================================================
include(CMakePackageConfigHelpers)
include(GNUInstallDirs) # Use standard install directories

# Install headers into a subdirectory to avoid name collisions
install(DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Create an export set for all targets
install(TARGETS falcon-core
  EXPORT falcon-core-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Only install the C-API target if it was built
if(FALCON_CORE_BUILD_C_API)
  install(TARGETS falcon-core-c-api
    EXPORT falcon-core-targets # Add to the SAME export set
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
endif()

# Generate and install the `falcon-core-targets.cmake` file
install(EXPORT falcon-core-targets
  FILE falcon-core-targets.cmake
  NAMESPACE falcon-core::
  DESTINATION ${CMAKE_INSTALL_DATADIR}/falcon-core
)

# Generate the version file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/falcon-core-config-version.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

set(FALCON_CORE_C_API_CONFIG "")
if(FALCON_CORE_BUILD_C_API)
  # If the C-API is being built, we add a check for the 'c-api' component.
  # A consumer can then use find_package(falcon-core COMPONENTS c-api)
  set(FALCON_CORE_C_API_CONFIG "check_required_components(falcon-core-c-api)")
endif()

configure_package_config_file(
  cmake/falcon-core-config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/falcon-core-config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/falcon-core
)
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/falcon-core-config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/falcon-core-config-version.cmake"
  DESTINATION ${CMAKE_INSTALL_DATADIR}/falcon-core
)
configure_file(
  cmake/falcon-core.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/falcon-core.pc
  @ONLY
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/falcon-core.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)
if(FALCON_CORE_BUILD_C_API)
  configure_file(
    cmake/falcon-core-c-api.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/falcon-core-c-api.pc
    @ONLY
  )
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/falcon-core-c-api.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
  )
endif()
