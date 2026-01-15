include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(ApprovalTests
        GIT_REPOSITORY https://github.com/approvals/ApprovalTests.cpp.git
        GIT_TAG master)

FetchContent_MakeAvailable(ApprovalTests)

add_executable(
        trivia_test
        GameTest.cpp
)

target_link_libraries(
        trivia_test
        GTest::gtest_main
        ApprovalTests::ApprovalTests
        trivialib
)

include(GoogleTest)
gtest_discover_tests(trivia_test)