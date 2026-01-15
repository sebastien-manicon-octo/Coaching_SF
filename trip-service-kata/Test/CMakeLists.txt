include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(TripServiceKata_test
    TripServiceTest.cpp
)
target_link_libraries(TripServiceKata_test
        TripServiceKataLib
        gtest
        gtest_main
        gmock
)

include(GoogleTest)
gtest_discover_tests(TripServiceKata_test)
