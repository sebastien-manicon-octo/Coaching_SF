set(
        SOURCES
        Trip.h
        TripDAO.h
        TripService.h
        TripService.cpp
        User.h
        UserSession.h
)

add_library(TripServiceKataLib "${SOURCES}")

add_executable(TripServiceKata main.cpp)
target_link_libraries(TripServiceKata
        TripServiceKataLib
)

