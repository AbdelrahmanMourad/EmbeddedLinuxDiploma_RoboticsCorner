
using namespace ::testing;

// #include <gtest_demo/gtest.h> // read on cyber-dojo
#include "calculator.h"

TEST(Calculator, add_with_positive_nums)
{
    Calculator calc_obj;              // Create object of class calculator.
    ASSERT_EQ(3, calc_obj.add(1, 2)); // Assert that {1+2=3}
}

TEST(Calculator, add_with_negative_nums)
{
    Calculator calc_obj;              // Create object of class calculator.
    ASSERT_EQ(1, calc_obj.add(3, -2)); // Assert that {1+2=3}
}