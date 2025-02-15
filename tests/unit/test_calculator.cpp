#include <gtest/gtest.h>
#include "Calculator.h"

TEST(CalculatorTest, Add) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.add(2.0, 3.0), 5.0);
}

TEST(CalculatorTest, Subtract) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.subtract(5.0, 3.0), 2.0);
}

TEST(CalculatorTest, Multiply) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.multiply(2.0, 3.0), 6.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
