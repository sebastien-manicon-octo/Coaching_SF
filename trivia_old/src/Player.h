//
// Created by sebastien-manicon on 28/11/2025.
//

#ifndef TRIVIA_PLAYER_H
#define TRIVIA_PLAYER_H
#include <string>


class Player {
public:
    Player(std::string name):name(name), place(0) {}

    std::string getName() {return name;}
    int getPlace() {return place;}

private:
    std::string name;
    int place;
};


#endif //TRIVIA_PLAYER_H
