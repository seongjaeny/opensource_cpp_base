#include <gtest/gtest.h>

#include "Calculator.h"
#include "Logger.h"

TEST(IntegrationTest, CalculatorAndLogger) {
    Calculator calc;
    Logger logger;

    double a = 15.0, b = 7.0;
    double result = calc.subtract(a, b);  // 15 - 7 = 8

    logger.log("Subtraction result: " + std::to_string(result));

    const auto& logs = logger.getLogs();
    ASSERT_EQ(logs.size(), 1);
    EXPECT_NE(logs[0].find("8"), std::string::npos);
}
