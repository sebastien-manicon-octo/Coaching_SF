//
// Created by sebastien-manicon on 21/10/2025.
//

#include <list>
#include <gtest/gtest.h>
#include "FooBarQix.h"


class NotDivisibleNumber : public testing::TestWithParam<int> {
};

INSTANTIATE_TEST_SUITE_P(, NotDivisibleNumber, testing::Values(1, 2, 4, 8));

TEST_P(NotDivisibleNumber,
       Should_return_number_itself_when_the_number_is_not_divisible_by_3_5_or_7_and_does_not_contain_3_5_or_7) {
    int input = GetParam();

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, to_string(input));
}

class NumberDivisibleByOrContains3 : public testing::TestWithParam<int> {
};

INSTANTIATE_TEST_SUITE_P(DivisibleBy3, NumberDivisibleByOrContains3, testing::Values(6, 9, 18, 24));
INSTANTIATE_TEST_SUITE_P(Contains3, NumberDivisibleByOrContains3, testing::Values(13, 23, 83));

TEST_P(NumberDivisibleByOrContains3,
       Should_return_Foo_when_the_number_is_divisable_by_3_only_and_not_by_5_or_7_and_does_not_contain_3_5_or_7) {
    int input = GetParam();

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "Foo");
}

class NumberDivisibleByOrContains5 : public testing::TestWithParam<int> {
};

INSTANTIATE_TEST_SUITE_P(DivisibleBy5, NumberDivisibleByOrContains5, testing::Values(10, 20, 40, 80));
INSTANTIATE_TEST_SUITE_P(Contains5, NumberDivisibleByOrContains5, testing::Values(58, 158));

TEST_P(NumberDivisibleByOrContains5,
       Should_return_Bar_when_the_number_is_divisable_by_5_only_and_not_by_5_or_7_and_does_not_contain_3_5_or_7) {
    int input = GetParam();

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "Bar");
}

class NumberDivisibleByOrContains7 : public testing::TestWithParam<int> {
};

INSTANTIATE_TEST_SUITE_P(DivisibleBy5, NumberDivisibleByOrContains7, testing::Values(14, 28, 49));
INSTANTIATE_TEST_SUITE_P(Contains5, NumberDivisibleByOrContains7, testing::Values(17, 47));

TEST_P(NumberDivisibleByOrContains7,
       Should_return_Qix_when_the_number_is_divisable_by_or_contains_7_only_and_not_divisible_by_3_5_and_does_not_contain_3_5) {
    int input = GetParam();

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "Qix");
}

TEST(FooBarQix, should_return_FooFoo_when_3_because_it_is_divisible_by_3_and_contains_3) {
    int input = 3;

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "FooFoo");
}

TEST(FooBarQix, should_return_BarBar_when_5_because_it_is_divisible_by_5_and_contains_5) {
    int input = 5;

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "BarBar");
}

TEST(FooBarQix, should_return_QixQix_when_7_because_it_is_divisible_by_7_and_contains_5) {
    int input = 7;

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "QixQix");
}

TEST(FooBarQix, should_return_FooBarBar_when_15_is_given_because_it_is_divisible_by_3_and_5_and_contains_5) {
    int input = 15;

    string actual = convertFooBarQix(input);

    ASSERT_EQ(actual, "FooBarBar");
}
