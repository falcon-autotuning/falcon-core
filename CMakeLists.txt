cmake_minimum_required(VERSION 3.20)
project(FalconCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# --- Dependencies ---
include(FetchContent)

# nlohmann/json
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)

# GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)


# --- C++ Library Target ---
add_library(falcon_core_cpp
    src/Jsonable.cpp
)
target_include_directories(falcon_core_cpp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${json_SOURCE_DIR}/include
)
target_link_libraries(falcon_core_cpp PRIVATE nlohmann_json::nlohmann_json)

# --- C++ Tests ---
enable_testing()
add_executable(run_tests
    tests/test_jsonable.cpp
)
target_link_libraries(run_tests
    GTest::gtest_main
    falcon_core_cpp
)

include(GoogleTest)
gtest_discover_tests(run_tests)
