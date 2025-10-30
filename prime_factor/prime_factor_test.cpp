//
// Created by sebastien-manicon on 28/10/2025.
//

#include "gtest/gtest.h"

// 2 -> 2
// 3 -> 3
// 5 -> 5
// 7 -> 7

// 4 -> 2, 2
// 9 -> 3, 3
// 25 -> 5, 5

// 6 -> 3, 2

// 8 -> 2, 2, 2

using namespace std;

vector<int> prime(int input);
//Recursivity
vector<int> prime(int input, int diviser, vector<int> answer);


vector<int> prime(int input) {
//    vector<int> primes;
//    for (int i=2; i <= input; i++) {
//        while(input % i == 0) {
//            primes.push_back(i);
//            input /= i;
//        }
//    }
//    return primes;

    return prime(input, 2, vector<int>());
}

vector<int> prime(int input, int diviser, vector<int> answer) {
    while(input % diviser == 0) {
        answer.push_back(diviser);
        input /= diviser;
    }

    return input == 1 ? answer : prime(input, diviser + 1, answer);
}


class PrimeNumber : public ::testing::TestWithParam<int> {};
INSTANTIATE_TEST_CASE_P(, PrimeNumber, testing::Values(2, 3, 5, 7));
TEST_P(PrimeNumber, should_return_number_itself_when_the_number_is_prime) {
    auto input = GetParam();
    vector<int> actual = prime(input);
    EXPECT_EQ(actual, vector({input}));
}

TEST_P(PrimeNumber, should_return_number_itself_twice_when_the_number_is_prime_square) {
    auto input = GetParam();
    vector<int> actual = prime(input * input);
    EXPECT_EQ(actual, vector({input, input}));
}

TEST(PrimeFactor, should_return_3_2_when_input_is_6) {
    auto input = 6;
    vector<int> actual = prime(input);
    EXPECT_EQ(actual, vector({2, 3}));
}

TEST(PrimeFactor, should_return_2_2_2_when_input_is_8) {
    auto input = 8;
    vector<int> actual = prime(input);
    EXPECT_EQ(actual, vector({2, 2, 2}));
}