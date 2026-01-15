#ifndef USER_H
#define USER_H

#include <iostream>
#include <list>

using namespace std;

class User
{
  public:
    inline User(int _id) : id(_id){};
    inline list<User>& GetFriends()
    {
        return friends;
    }
    inline void AddFriend(User user)
    {
        friends.push_back(user);
    }

    inline bool operator==(User& other)
    {
        return (other.id == id);
    }

    bool isFriendWith(User* user)
    {
        list<User>::iterator i;
        for (i = user->GetFriends().begin(); i != user->GetFriends().end(); ++i)
        {
            if (*i == *user)
            {
                return true;
            }
        }

        return false;
    }

  private:
    int id;
    list<User> friends;
};

#endif