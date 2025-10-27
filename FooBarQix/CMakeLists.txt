cmake_minimum_required(VERSION 4.0)
project(FooBarQix)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(FooBarQix FooBarQix.cpp)
add_executable(FooBarQixTest FooBarQixTest.cpp
        FooBarQix.h)

target_link_libraries(
        FooBarQixTest
        GTest::gtest_main
        FooBarQix
)
enable_testing()
include(GoogleTest)
gtest_discover_tests(FooBarQixTest)
