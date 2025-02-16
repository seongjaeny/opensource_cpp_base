#include <gtest/gtest.h>
#include "Calculator.h"
#include "Logger.h"
#include "Notifier.h"

TEST(EndToEndTest, CalculationLogAndNotification) {
    Calculator calc(0);
    Logger logger;
    Notifier notifier;

    int x = 8, y = 4;

    int addResult = calc.add(x, y);       // 8 + 4 = 12
    int subResult = calc.subtract(x, y);  // 8 - 4 = 4
    int mulResult = Calculator::multiply(x, y); // 8 * 4 = 32

    // log
    logger.log("Addition result: " + std::to_string(addResult));
    logger.log("Subtraction result: " + std::to_string(subResult));
    logger.log("Multiplication result: " + std::to_string(mulResult));

    // Notifier
    bool notifiedAdd = notifier.notify(addResult, 10);
    bool notifiedSub = notifier.notify(subResult, 10);
    bool notifiedMul = notifier.notify(mulResult, 10);

    EXPECT_TRUE(notifiedAdd);  // 12 > 10，notify
    EXPECT_FALSE(notifiedSub); // 4 < 10
    EXPECT_TRUE(notifiedMul);  // 32 > 10，notify

    const auto& logs = logger.getLogs();
    ASSERT_EQ(logs.size(), 3);
    EXPECT_NE(logs[0].find("12"), std::string::npos);
    EXPECT_NE(logs[1].find("4"), std::string::npos);
    EXPECT_NE(logs[2].find("32"), std::string::npos);
}
