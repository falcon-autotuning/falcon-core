find_package(GTest CONFIG REQUIRED)

# Ensure bin directory exists
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Build the complete DLL search path for ctest
# Include all possible locations where DLLs might be
set(DLL_SEARCH_PATHS
  "${CMAKE_BINARY_DIR}/bin"
  "${CMAKE_BINARY_DIR}"
)

# Convert list to PATH string (semicolon-separated on Windows)
string(REPLACE ";" "\\;" TEST_PATH_ENV "${DLL_SEARCH_PATHS}")
# Append existing PATH
set(TEST_PATH_ENV "${TEST_PATH_ENV};$ENV{PATH}")

# ============================================================================
# C++ Tests
# ============================================================================

file(GLOB CPP_TEST_SOURCES "cpp/*.cpp")
list(REMOVE_ITEM CPP_TEST_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/cpp/integration_serialize_connection.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/cpp/integration_deserialize_connection.cpp"
)

add_executable(falcon-core-cpp_tests ${CPP_TEST_SOURCES})
target_link_libraries(falcon-core-cpp_tests
  PRIVATE
    falcon-core
    GTest::gtest_main
    yaml-cpp::yaml-cpp
)
set_target_properties(falcon-core-cpp_tests PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if(WIN32)
  set_target_properties(falcon-core-cpp_tests PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS OFF
  )
  target_link_options(falcon-core-cpp_tests PRIVATE /OPT:ICF /OPT:REF /FORCE:MULTIPLE)
  message(STATUS "Windows: Configured falcon-core-cpp_tests with linker options")
endif()

add_test(NAME falcon-core-cpp_tests COMMAND falcon-core-cpp_tests)

# Set environment for test to find DLLs
if(WIN32)
  set_tests_properties(falcon-core-cpp_tests PROPERTIES
    ENVIRONMENT "PATH=${TEST_PATH_ENV}"
  )
  message(STATUS "Test PATH for falcon-core-cpp_tests: ${TEST_PATH_ENV}")
endif()

# ============================================================================
# C++ Integration Tests
# ============================================================================

add_executable(integration_serialize_connection cpp/integration_serialize_connection.cpp)
set_target_properties(integration_serialize_connection PROPERTIES
  UNITY_BUILD OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
if(WIN32)
  set_target_properties(integration_serialize_connection PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS OFF
  )
  target_link_options(integration_serialize_connection PRIVATE /OPT:ICF /OPT:REF /FORCE:MULTIPLE)
endif()
target_link_libraries(integration_serialize_connection PRIVATE falcon-core)

add_executable(integration_deserialize_connection cpp/integration_deserialize_connection.cpp)
set_target_properties(integration_deserialize_connection PROPERTIES
  UNITY_BUILD OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
if(WIN32)
  set_target_properties(integration_deserialize_connection PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS OFF
  )
  target_link_options(integration_deserialize_connection PRIVATE /OPT:ICF /OPT:REF /FORCE:MULTIPLE)
endif()
target_link_libraries(integration_deserialize_connection PRIVATE falcon-core)

add_test(NAME serialize_deserialize_cpp
  COMMAND integration_serialize_connection --output test.json --name MyGate --type PlungerGate
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_test(NAME deserialize_cpp
  COMMAND integration_deserialize_connection --input test.json --name MyGate --type PlungerGate
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if(WIN32)
  set_tests_properties(serialize_deserialize_cpp deserialize_cpp PROPERTIES
    ENVIRONMENT "PATH=${TEST_PATH_ENV}"
  )
endif()

message(STATUS "C++ Integration test executables: integration_serialize_connection, integration_deserialize_connection")

# ============================================================================
# C API Tests (only if feature is enabled)
# ============================================================================

if(FALCON_CORE_BUILD_C_API)
  file(GLOB C_TEST_SOURCES "c/*.cpp" "c/*.c")
  list(REMOVE_ITEM C_TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/c/integration_serialize_connection.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/c/integration_deserialize_connection.c"
  )

  add_executable(falcon-core-c-api_tests ${C_TEST_SOURCES})
  target_link_libraries(falcon-core-c-api_tests
    PRIVATE
      falcon-core-c-api
      GTest::gtest_main
  )
  set_target_properties(falcon-core-c-api_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
  
  if(WIN32)
    set_target_properties(falcon-core-c-api_tests PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
    )
    target_link_options(falcon-core-c-api_tests PRIVATE /OPT:ICF /OPT:REF /FORCE:MULTIPLE)
  endif()

  add_test(NAME falcon-core-c-api_tests COMMAND falcon-core-c-api_tests)
  
  if(WIN32)
    set_tests_properties(falcon-core-c-api_tests PROPERTIES
      ENVIRONMENT "PATH=${TEST_PATH_ENV}"
    )
  endif()

  # ============================================================================
  # C API Integration Tests
  # ============================================================================

  add_executable(integration_serialize_connection_c c/integration_serialize_connection.c)
  set_target_properties(integration_serialize_connection_c PROPERTIES
    UNITY_BUILD OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
  if(WIN32)
    set_target_properties(integration_serialize_connection_c PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
    )
    target_link_options(integration_serialize_connection_c PRIVATE /OPT:ICF /OPT:REF /FORCE:MULTIPLE)
  else()
    set_target_properties(integration_serialize_connection_c PROPERTIES
      BUILD_RPATH "${CMAKE_BINARY_DIR}"
      INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
      BUILD_WITH_INSTALL_RPATH FALSE
      SKIP_BUILD_RPATH FALSE
    )
  endif()
  target_include_directories(integration_serialize_connection_c PRIVATE
    ${CMAKE_SOURCE_DIR}/include
  )
  target_link_libraries(integration_serialize_connection_c PRIVATE falcon-core-c-api)

  add_executable(integration_deserialize_connection_c c/integration_deserialize_connection.c)
  set_target_properties(integration_deserialize_connection_c PROPERTIES
    UNITY_BUILD OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
  if(WIN32)
    set_target_properties(integration_deserialize_connection_c PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
    )
    target_link_options(integration_deserialize_connection_c PRIVATE /OPT:ICF /OPT:REF /FORCE:MULTIPLE)
  else()
    set_target_properties(integration_deserialize_connection_c PROPERTIES
      BUILD_RPATH "${CMAKE_BINARY_DIR}"
      INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
      BUILD_WITH_INSTALL_RPATH FALSE
      SKIP_BUILD_RPATH FALSE
    )
  endif()
  target_include_directories(integration_deserialize_connection_c PRIVATE
    ${CMAKE_SOURCE_DIR}/include
  )
  target_link_libraries(integration_deserialize_connection_c PRIVATE falcon-core-c-api)

  add_test(NAME serialize_deserialize_c
    COMMAND integration_serialize_connection_c --output test.json --name MyGate --type PlungerGate
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )
  add_test(NAME deserialize_c
    COMMAND integration_deserialize_connection_c --input test.json --name MyGate --type PlungerGate
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )

  if(WIN32)
    set_tests_properties(serialize_deserialize_c deserialize_c PROPERTIES
      ENVIRONMENT "PATH=${TEST_PATH_ENV}"
    )
  endif()

  message(STATUS "C-API Integration test executables: integration_serialize_connection_c, integration_deserialize_connection_c")
endif()

enable_testing()
