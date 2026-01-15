#ifndef TRIPDAO_H
#define TRIPDAO_H

#include "../cmake-build-debug/_deps/googletest-src/googlemock/include/gmock/gmock-function-mocker.h"
#include "Trip.h"
#include "User.h"

#include <iostream>
#include <memory>

using namespace std;

class TripDAO
{
  public:
    inline static list<Trip> FindTripsByUser(User* user)
    {
        throw "TripDAO should not be invoked on an unit test.";
    }
};

class TripDAOInterface
{
public:
    virtual list<Trip> FindTripsByUser(User* user) = 0;
};

class TripDAOProxy : public TripDAOInterface
{
    public:
    list<Trip> FindTripsByUser(User* user) override
    {
        return TripDAO::FindTripsByUser(user);
    }
};

class Object {};

class ObjectRepository
{
  public:
    virtual Object getById(int id) = 0;
    virtual void saveIt(Object) = 0;
};

class ObjectThirdPart
{
    virtual void publish(Object) = 0;
};

class RealObjectThirdPart : public ObjectThirdPart
{
    void publish(Object) override;
};

class SqlObjectRepository : public ObjectRepository
{
    public:
    SqlObjectRepository(string user, string password);
    Object getById(int id) override;
    void saveIt(Object) override;
};

string myFunctionService(ObjectRepository repo, ObjectThirdPart tp, int id)
{
    Object obj = repo.getById(id);
    obj.doThingOnIt();
    tp.publish(obj);
}

string myFunction(int id)
{
    unique_ptr<ObjectRepository> repo = std::make_unique<SqlObjectRepository>("", "");
    unique_ptr<ObjectThirdPart> obj = std::make_unique<RealObjectThirdPart>();
    return myFunctionService(repo, obj, id);
}



//Tests

class ObjectRepositoryMock : public ObjectRepository
{
    public:
    MOCK_METHOD(Object, getById, (int), override);
};


TEST(Object, shou)
{
    ObjectRepositoryMock repo;
    ObjectThirdPart tp;

    auto ret = myFunctionService(repo, tp, 1);

}


string myFunction(int id)
{
    auto res = sql("user", "password", "select *");

    for (auto r : res)
    {

    }
}

#endif