include(GoogleTest)

# C++ tests
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
add_test(NAME falcon-core-cpp_tests COMMAND falcon-core-cpp_tests)
add_executable(integration_serialize_connection cpp/integration_serialize_connection.cpp)
set_target_properties(integration_serialize_connection PROPERTIES
    UNITY_BUILD OFF  # Don't use unity build for standalone programs
    BUILD_RPATH "${CMAKE_BINARY_DIR}"
    INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
    BUILD_WITH_INSTALL_RPATH FALSE
    SKIP_BUILD_RPATH FALSE
  )
if(WIN32)
  set_target_properties(integration_serialize_connection PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
    )
endif()
target_link_libraries(integration_serialize_connection
  PRIVATE
    falcon-core
)

# Deserialization integration test
add_executable(integration_deserialize_connection cpp/integration_deserialize_connection.cpp)
set_target_properties(integration_deserialize_connection PROPERTIES
    UNITY_BUILD OFF  # Don't use unity build for standalone programs
    BUILD_RPATH "${CMAKE_BINARY_DIR}"
    INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib"
    BUILD_WITH_INSTALL_RPATH FALSE
    SKIP_BUILD_RPATH FALSE
  )
if(WIN32)
  set_target_properties(integration_deserialize_connection PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
    )
endif()
target_link_libraries(integration_deserialize_connection
  PRIVATE
    falcon-core
)

add_test(NAME serialize_deserialize_cpp
  COMMAND ${BUILD_DIR}/integration_serialize_connection --output test.json --name MyGate --type PlungerGate
)
add_test(NAME deserialize_cpp
  COMMAND ${BUILD_DIR}/integration_deserialize_connection --input test.json --name MyGate --type PlungerGate
)
message(STATUS "Integration test executables: integration_serialize_connection, integration_deserialize_connection")

# C API tests (only if feature is enabled)
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
  add_test(NAME falcon-core-c-api_tests COMMAND falcon-core-c-api_tests)
  # ---- Integration Tests for Cross-Platform Serialization (C-API) ----
  message(STATUS "Setting up C-API cross-platform serialization integration tests")

  # C-API Serialization integration test
  add_executable(integration_serialize_connection_c c/integration_serialize_connection.c)
  set_target_properties(integration_serialize_connection_c PROPERTIES
    UNITY_BUILD OFF  # Don't use unity build for standalone programs
  )
  if(WIN32)
    set_target_properties(integration_serialize_connection_c PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    )
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
  target_link_libraries(integration_serialize_connection_c
    PRIVATE
      falcon-core-c-api
  )

  # C-API Deserialization integration test
  add_executable(integration_deserialize_connection_c c/integration_deserialize_connection.c)
  set_target_properties(integration_deserialize_connection_c PROPERTIES
    UNITY_BUILD OFF  # Don't use unity build for standalone programs
  )
  if(WIN32)
    set_target_properties(integration_deserialize_connection_c PROPERTIES
      WINDOWS_EXPORT_ALL_SYMBOLS OFF
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    )
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
  target_link_libraries(integration_deserialize_connection_c
    PRIVATE
      falcon-core-c-api
  )

  add_test(NAME serialize_deserialize_c
  COMMAND ${C_API_BUILD_DIR}/integration_serialize_connection_c --output test.json --name MyGate --type PlungerGate
)
  add_test(NAME deserialize_c
  COMMAND ${C_API_BUILD_DIR}/integration_deserialize_connection_c --input test.json --name MyGate --type PlungerGate
)
  message(STATUS "C-API Integration test executables: integration_serialize_connection_c, integration_deserialize_connection_c")
endif()

