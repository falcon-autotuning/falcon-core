# This is a standalone script, run via: cmake -P cmake/bootstrap-vcpkg.cmake
# Always uses local project vcpkg for isolation

if(NOT DEFINED VCPKG_ROOT)
  set(VCPKG_ROOT "${CMAKE_SOURCE_DIR}/vcpkg")
  message(STATUS "Using local project vcpkg: ${VCPKG_ROOT}")
endif()

if(NOT DEFINED VCPKG_INSTALLED_DIR)
  set(VCPKG_INSTALLED_DIR "${CMAKE_SOURCE_DIR}/vcpkg_installed")
endif()

set(VCPKG_BOOTSTRAP_SCRIPT "${VCPKG_ROOT}/bootstrap-vcpkg.sh")
if(WIN32)
  set(VCPKG_BOOTSTRAP_SCRIPT "${VCPKG_ROOT}/bootstrap-vcpkg.bat")
endif()

set(VCPKG_EXECUTABLE "${VCPKG_ROOT}/vcpkg")
if(WIN32)
  set(VCPKG_EXECUTABLE "${VCPKG_ROOT}/vcpkg.exe")
endif()

# Clone vcpkg if needed
if(NOT EXISTS "${VCPKG_ROOT}")
  message(STATUS "Cloning vcpkg to ${VCPKG_ROOT}...")
  execute_process(
    COMMAND git clone https://github.com/microsoft/vcpkg.git "${VCPKG_ROOT}"
    RESULT_VARIABLE GIT_RESULT
  )
  if(NOT GIT_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to clone vcpkg")
  endif()
endif()

# Bootstrap vcpkg if needed
if(NOT EXISTS "${VCPKG_EXECUTABLE}")
  message(STATUS "Bootstrapping vcpkg...")
  execute_process(
    COMMAND "${VCPKG_BOOTSTRAP_SCRIPT}"
    WORKING_DIRECTORY "${VCPKG_ROOT}"
    RESULT_VARIABLE BOOTSTRAP_RESULT
  )
  if(NOT BOOTSTRAP_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to bootstrap vcpkg")
  endif()
endif()

message(STATUS "✓ vcpkg executable found at: ${VCPKG_EXECUTABLE}")

# Clone my-vcpkg-triplets if needed (for custom triplets like x64-win-llvm, x64-linux-clang)
set(VCPKG_OVERLAY_TRIPLETS_DIR "${CMAKE_SOURCE_DIR}/my-vcpkg-triplets")
if(NOT EXISTS "${VCPKG_OVERLAY_TRIPLETS_DIR}")
  message(STATUS "Cloning my-vcpkg-triplets to ${VCPKG_OVERLAY_TRIPLETS_DIR}...")
  execute_process(
    COMMAND git clone https://github.com/Neumann-A/my-vcpkg-triplets.git "${VCPKG_OVERLAY_TRIPLETS_DIR}"
    RESULT_VARIABLE GIT_RESULT
  )
  if(NOT GIT_RESULT EQUAL 0)
    message(FATAL_ERROR "Failed to clone my-vcpkg-triplets")
  endif()
endif()

message(STATUS "✓ vcpkg triplets found at: ${VCPKG_OVERLAY_TRIPLETS_DIR}")

# Read CMakePresets.json to extract triplet for the given preset
# If no PRESET is specified, default to linux-clang-release
if(NOT DEFINED PRESET)
  if(DEFINED ENV{PRESET})
    set(PRESET "$ENV{PRESET}")
  else()
    set(PRESET "linux-clang-release")
  endif()
endif()

message(STATUS "Reading preset '${PRESET}' from CMakePresets.json...")

# Read and parse CMakePresets.json to find VCPKG_TARGET_TRIPLET
file(READ "${CMAKE_SOURCE_DIR}/CMakePresets.json" PRESETS_JSON)

# Extract the triplet value for this preset using regex
string(REGEX MATCH "\"name\": \"${PRESET}\"[^}]*\"VCPKG_TARGET_TRIPLET\": \"([^\"]+)\"" _ "${PRESETS_JSON}")

if(CMAKE_MATCH_1)
  set(VCPKG_TARGET_TRIPLET "${CMAKE_MATCH_1}")
  message(STATUS "✓ Found triplet from preset: ${VCPKG_TARGET_TRIPLET}")
else()
  # Fallback if preset not found or triplet not specified
  if(WIN32)
    set(VCPKG_TARGET_TRIPLET "x64-win-llvm")
  else()
    set(VCPKG_TARGET_TRIPLET "x64-linux-dynamic")
  endif()
  message(STATUS "⚠ Could not find triplet in preset, using default: ${VCPKG_TARGET_TRIPLET}")
endif()

# Extract CMAKE_C_COMPILER
string(REGEX MATCH "\"name\": \"${PRESET}\"[^}]*\"CMAKE_C_COMPILER\": \"([^\"]+)\"" _ "${PRESETS_JSON}")
if(CMAKE_MATCH_1)
  set(CMAKE_C_COMPILER "${CMAKE_MATCH_1}")
  message(STATUS "✓ Found C compiler: ${CMAKE_C_COMPILER}")
endif()

# Extract CMAKE_CXX_COMPILER
string(REGEX MATCH "\"name\": \"${PRESET}\"[^}]*\"CMAKE_CXX_COMPILER\": \"([^\"]+)\"" _ "${PRESETS_JSON}")
if(CMAKE_MATCH_1)
  set(CMAKE_CXX_COMPILER "${CMAKE_MATCH_1}")
  message(STATUS "✓ Found CXX compiler: ${CMAKE_CXX_COMPILER}")
endif()

# Load and configure NuGet credentials if available
set(NUGET_CREDENTIALS_FILE "${CMAKE_SOURCE_DIR}/.nuget-credentials")
set(VCPKG_BINARY_SOURCES "")
if(EXISTS "${NUGET_CREDENTIALS_FILE}")
  message(STATUS "Loading NuGet credentials from ${NUGET_CREDENTIALS_FILE}")

  # Read and parse KEY=VALUE pairs
  file(STRINGS "${NUGET_CREDENTIALS_FILE}" CREDENTIAL_LINES)
  foreach(LINE ${CREDENTIAL_LINES})
    if(NOT LINE MATCHES "^#" AND NOT LINE STREQUAL "")
      string(REGEX MATCH "^([^=]+)=(.*)$" _ "${LINE}")
      if(CMAKE_MATCH_1)
        set(${CMAKE_MATCH_1} "${CMAKE_MATCH_2}")
      endif()
    endif()
  endforeach()

  # Configure NuGet if credentials are complete
  if(DEFINED FEED_URL AND DEFINED NUGET_API_KEY AND DEFINED FEED_NAME AND DEFINED USERNAME)
    message(STATUS "Setting up NuGet authentication for vcpkg binary caching...")

    execute_process(
      COMMAND "${VCPKG_EXECUTABLE}" fetch nuget
      OUTPUT_VARIABLE NUGET_EXE
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    if(UNIX)
      execute_process(COMMAND mono "${NUGET_EXE}" sources remove -Name "${FEED_NAME}" ERROR_QUIET)
      execute_process(
        COMMAND mono "${NUGET_EXE}" sources add -Name "${FEED_NAME}" -Source "${FEED_URL}" -Username "${USERNAME}" -Password "${NUGET_API_KEY}"
        RESULT_VARIABLE NUGET_RESULT
      )
    else()
      execute_process(COMMAND "${NUGET_EXE}" sources remove -Name "${FEED_NAME}" ERROR_QUIET)
      execute_process(
        COMMAND "${NUGET_EXE}" sources add -Name "${FEED_NAME}" -Source "${FEED_URL}" -Username "${USERNAME}" -Password "${NUGET_API_KEY}"
        RESULT_VARIABLE NUGET_RESULT
      )
    endif()

    if(NUGET_RESULT EQUAL 0)
      message(STATUS "✓ NuGet authentication configured")
      set(VCPKG_BINARY_SOURCES "nuget,${FEED_URL},readwrite")
    else()
      message(WARNING "Failed to configure NuGet source")
    endif()
  else()
    message(STATUS "NuGet credentials not fully configured, skipping binary caching")
  endif()
else()
  message(STATUS "No .nuget-credentials file found, skipping NuGet setup (local-only build)")
endif()

# Install vcpkg dependencies
message(STATUS "Installing vcpkg dependencies for triplet: ${VCPKG_TARGET_TRIPLET}...")

# Build the install command
set(VCPKG_INSTALL_CMD
  "${VCPKG_EXECUTABLE}" install
  --triplet=${VCPKG_TARGET_TRIPLET}
  --vcpkg-root=${VCPKG_ROOT}
)

# Conditionally add overlay ports if the directory exists
if(EXISTS "${CMAKE_SOURCE_DIR}/ports")
  message(STATUS "Using overlay ports from: ${CMAKE_SOURCE_DIR}/ports")
  list(APPEND VCPKG_INSTALL_CMD --overlay-ports=${CMAKE_SOURCE_DIR}/ports)
endif()

# Always add overlay triplets (my-vcpkg-triplets)
message(STATUS "Using overlay triplets from: ${VCPKG_OVERLAY_TRIPLETS_DIR}")
list(APPEND VCPKG_INSTALL_CMD --overlay-triplets=${VCPKG_OVERLAY_TRIPLETS_DIR})

# Add binary sources if configured
if(DEFINED VCPKG_BINARY_SOURCES)
  list(APPEND VCPKG_INSTALL_CMD --binarysource=${VCPKG_BINARY_SOURCES})
endif()

# Add feature flags for binary caching
list(APPEND VCPKG_INSTALL_CMD --feature-flags=binarycaching)

# Set environment variables for vcpkg compiler detection
set(ENV{CC} "${CMAKE_C_COMPILER}")
set(ENV{CXX} "${CMAKE_CXX_COMPILER}")

# Run vcpkg install
execute_process(
  COMMAND ${VCPKG_INSTALL_CMD}
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  RESULT_VARIABLE VCPKG_INSTALL_RESULT
)

if(NOT VCPKG_INSTALL_RESULT EQUAL 0)
  message(FATAL_ERROR "Failed to install vcpkg dependencies")
endif()

message(STATUS "✓ vcpkg bootstrap and dependency installation complete")
