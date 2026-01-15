#ifndef TRIPSERVICE_CPP
#define TRIPSERVICE_CPP

#include "TripService.h"
#include "TripDAO.h"
#include "UserSession.h"
#include <iostream>
#include <list>

using namespace std;

UserSession* UserSession::oneUserSession = 0;

TripService::TripService() : TripService(new TripDAOProxy())
{
}

TripService::TripService(TripDAOProxy* tripDAO) : trip_dao(tripDAO)
{
}

list<Trip> TripService::GetTripsByUser(User* user) const
{
    return GetTripsByUser(user, UserSession::GetInstance()->GetLoggedUser());
}

list<Trip> TripService::GetTripsByUser(User* user, User* loggedUser) const
{
    if (!loggedUser)
    {
        throw "UserNotLoggedInException";
    }

    return user->isFriendWith(loggedUser)
        ? trip_dao->FindTripsByUser(user)
        : throw "UserNotFriendException" ;
}

void TripService::BuildCheck()
{
    cout << "Built and runnable!" << endl;
}

#endif