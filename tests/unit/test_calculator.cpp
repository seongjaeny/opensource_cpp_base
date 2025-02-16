#include <gtest/gtest.h>
#include "Calculator.h"

TEST(CalculatorTest, Add) {
    Calculator calc(0);  // seed=0
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(-1, 1), 0);
    EXPECT_EQ(calc.add(0, 0), 0);
}

TEST(CalculatorTest, Subtract) {
    Calculator calc(0);
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(0, 5), -5);
    EXPECT_EQ(calc.subtract(3, 3), 0);
}

TEST(CalculatorTest, Multiply) {
    EXPECT_EQ(Calculator::multiply(2, 3), 6);
    EXPECT_EQ(Calculator::multiply(-2, 3), -6);
    EXPECT_EQ(Calculator::multiply(0, 3), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
