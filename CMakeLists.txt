cmake_minimum_required(VERSION 3.14)
project(lodestone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(lodestone 
    src/main.cpp
    src/simulator/simulator.cpp
)

# auto fetch GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# test executable
enable_testing()
add_executable(lodestone_tests
    tests/test_simulator.cpp
    src/simulator/simulator.cpp
)
target_include_directories(lodestone_tests PRIVATE ${CMAKE_SOURCE_DIR}/inc)
target_link_libraries(lodestone_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lodestone_tests)

#[[
auto fetch GLFW (https://github.com/glfw/glfw)
only require the library itself, exclude other GLFW clutter
]]
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CAHCE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.5
)
FetchContent_MakeAvailable(glfw)

target_include_directories(lodestone PRIVATE 
    ${CMAKE_SOURCE_DIR}/inc
)

target_link_libraries(lodestone PRIVATE glfw)
