//
// Created by sebastien-manicon on 09/12/2025.
//

#include "gtest/gtest.h"
#include "../src/Game.h"

#define APPROVALS_GOOGLETEST
#include "ApprovalTests.hpp"

TEST(trivia, goldenmaster) {
    srand(42);

    ostringstream os;
    cout.rdbuf(os.rdbuf());

    for (int i = 1; i <= 1000; i++) {
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

    ApprovalTests::Approvals::verify(os.str());
}