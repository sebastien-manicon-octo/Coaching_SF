#ifndef TRIPSERVICE_H
#define TRIPSERVICE_H

#include "Trip.h"
#include "TripDAO.h"
#include "User.h"
#include <iostream>
#include <list>

using namespace std;

class TripService
{
  public:
    TripService();
    explicit TripService(TripDAOProxy *tripDAO);
    virtual ~TripService() = default;
    list<Trip> GetTripsByUser(User* user) const;
    list<Trip> GetTripsByUser(User* user, User *loggedUser) const;
    void BuildCheck();
private:
    TripDAOProxy* trip_dao;
};

#endif