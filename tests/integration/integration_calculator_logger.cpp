#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Calculator.h"
#include "Logger.h"

class MockNotifier {
public:
    MOCK_METHOD(bool, notify, (int result, int threshold), (const));
};

TEST(IntegrationTest, CalculatorLoggerMockNotifier) {
    Calculator calc(0);
    Logger logger;
    MockNotifier mockNotifier;

    int a = 15, b = 7;
    int result = calc.subtract(a, b); // 15 - 7 = 8

    logger.log("Subtraction result: " + std::to_string(result));

    EXPECT_CALL(mockNotifier, notify(result, 10))
        .Times(1)
        .WillOnce(::testing::Return(result > 10));

    bool notified = mockNotifier.notify(result, 10);
    EXPECT_FALSE(notified); // 8 < 10，return false

    const auto& logs = logger.getLogs();
    ASSERT_EQ(logs.size(), 1);
    EXPECT_NE(logs[0].find("8"), std::string::npos);
}
