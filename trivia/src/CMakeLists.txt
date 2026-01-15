add_library(trivialib
        Game.cpp)

add_executable(trivia
    GameRunner.cpp
        Player.cpp
        Repository.h
)

target_link_libraries(trivia
    trivialib
)