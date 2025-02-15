#include <gtest/gtest.h>

#include "Calculator.h"
#include "Logger.h"
#include "Notifier.h"

TEST(EndToEndTest, CalculationLogAndNotification) {
    Calculator calc;
    Logger logger;
    Notifier notifier;

    double a = 6.0, b = 5.0;
    double result = calc.add(a, b);

    logger.log("Addition result: " + std::to_string(result));

    bool notified = notifier.notify(result, 10.0);
    EXPECT_TRUE(notified);

    const auto& logs = logger.getLogs();
    ASSERT_EQ(logs.size(), 1);
    EXPECT_NE(logs[0].find("11"), std::string::npos);
}
