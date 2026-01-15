add_library(trivialib
    Game.cpp
)

add_executable(trivia
        GameRunner.cpp
        Player.cpp
        Player.h
)

target_link_libraries(
        trivia
        trivialib
)