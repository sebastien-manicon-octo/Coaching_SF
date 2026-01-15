//
// Created by sebastien-manicon on 28/11/2025.
//

#define APPROVALS_GOOGLETEST
#include "ApprovalTests.hpp"
#include "../src/Game.h"
#include "gtest/gtest.h"

TEST(TestGame, goldenMaster) {
    srand(42);

    std::ostringstream oss;
    cout.rdbuf(oss.rdbuf());

    for (int i = 0; i < 1000; i++) {
        Game aGame;

        aGame.add("Chet");
        aGame.add("Pat");
        aGame.add("Sue");

        bool notAWinner = false;
        do
        {
            aGame.roll(rand() % 5 + 1);
            if (rand() % 9 == 7)
            {
                notAWinner = aGame.wrongAnswer();
            }
            else
            {
                notAWinner = aGame.wasCorrectlyAnswered();
            }
        } while (notAWinner);
    }

    ApprovalTests::Approvals::verify(oss.str());
}