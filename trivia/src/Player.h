//
// Created by sebastien-manicon on 09/12/2025.
//

#ifndef TRIVIA_PLAYER_H
#define TRIVIA_PLAYER_H
#include <bits/basic_string.h>


class Player {
public:
    explicit Player(const std::string &name) : name_(name) {
    }

    [[nodiscard]] std::string getName() const {
        return name_;
    }
private:
    const std::string &name_;
};


#endif //TRIVIA_PLAYER_H