//
// Created by sebastien-manicon on 15/12/2025.
//

#include <utility>

#include "../TripService/TripService.h"

#include "../TripService/UserSession.h"
#include "../cmake-build-debug/_deps/googletest-src/googlemock/include/gmock/gmock-function-mocker.h"

#include "gtest/gtest.h"

#define EXPECT_STRING_EXCEPTION(statement, stringException)                                                            \
    EXPECT_THROW(                                                                                                      \
        {                                                                                                              \
            try                                                                                                        \
            {                                                                                                          \
                do                                                                                                     \
                {                                                                                                      \
                    statement;                                                                                         \
                } while (false);                                                                                       \
            }                                                                                                          \
            catch (const char* e)                                                                                      \
            {                                                                                                          \
                EXPECT_STREQ(stringException, e);                                                                      \
                throw;                                                                                                 \
            }                                                                                                          \
        },                                                                                                             \
        const char*);

void EXPECT_STRING_EXCEPTION2(function<void()> f, string stringException)
{
    EXPECT_THROW(
        try { f(); } catch (const char* e) {
            EXPECT_STREQ(stringException.c_str(), e);
            throw;
        },
        const char*);
}

static User* NOT_LOGGED_USER = nullptr;

TEST(tripservice, should_user_be_logged_in)
{
    shared_ptr<TripService> tripService = make_shared<TripService>();
    // EXPECT_STRING_EXCEPTION({ tripService->GetTripsByUser(nullptr); }, "UserNotLoggedInException");
    EXPECT_STRING_EXCEPTION2([tripService]() { tripService->GetTripsByUser(new User(10), NOT_LOGGED_USER); }, "UserNotLoggedInException");
}

TEST(tripservice, should_not_return_trip_when_logged_user_user_is_not_friend_with_the_user)
{
    auto NO_FRIEND_WITH_LOGGED_USER = new User(10);
    NO_FRIEND_WITH_LOGGED_USER->AddFriend(User(11));
    auto LOGGER_USER = new User(0);

    shared_ptr<TripService> tripService = make_shared<TripService>();
    auto trips = tripService->GetTripsByUser(NO_FRIEND_WITH_LOGGED_USER, LOGGER_USER);
    ASSERT_EQ(trips, list<Trip>());
}

class TripDAO_mock : public TripDAOProxy
{
    public:
    MOCK_METHOD(list<Trip>, FindTripsByUser, (User* user), (override));
};

TEST(tripservice, Sould_return_trip_when_user_is_friend_with_logged_user)
{
    auto LOGGER_USER = new User(0);
    auto FRIEND_WITH_LOGGED_USER = new User(10);
    FRIEND_WITH_LOGGED_USER->AddFriend(*LOGGER_USER);

    TripDAO_mock tripDAO_mock;
    EXPECT_CALL(tripDAO_mock, FindTripsByUser)
    .WillRepeatedly(testing::Return(list<Trip>()));

    shared_ptr<TripService> tripService = make_shared<TripService>(&tripDAO_mock);
    auto trips = tripService->GetTripsByUser(FRIEND_WITH_LOGGED_USER, LOGGER_USER);
    ASSERT_EQ(trips, list<Trip>());
}