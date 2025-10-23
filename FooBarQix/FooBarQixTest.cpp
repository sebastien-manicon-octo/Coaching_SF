//
// Created by sebastien-manicon on 21/10/2025.
//

#include <gtest/gtest.h>

using namespace std;

string convertFooBarQix(int input) {
    if (input % 3 == 0)
        return "Foo";

    return to_string(input);
}

class FooBarQix : public ::testing::TestWithParam<int> {
};

INSTANTIATE_TEST_SUITE_P(
    EvenNumbers, // Instance name (any string)
    FooBarQix, // Test suite name
    ::testing::Values(1, 2, 4, 8) // List of parameter values
);

TEST_P(FooBarQix, Should_return_number_itself_when_the_number_is_not_divisible_by_3_5_or_7_and_does_not_contain_3_5_or_7) {
    int input =  GetParam();

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, to_string(input));
}

// Should_return_Foo_when_the_number_is_divisable_by_only_3_and_not_by_5_or_7_and_does_not_contain_3_5_or_7

TEST(FooBarQix, Should_return_Foo_when_6_is_given_to_FooBarQix) {
    int input = 6;

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "Foo");
}


TEST(FooBarQix, Should_return_Foo_when_9_is_given_to_FooBarQix) {
    int input = 9;

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "Foo");
}