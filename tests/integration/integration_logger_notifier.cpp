#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Logger.h"
#include "Notifier.h"

class MockCalculator {
public:
    MOCK_METHOD(int, add, (int x, int y), (const));
    MOCK_METHOD(int, subtract, (int x, int y), (const));
    MOCK_METHOD(int, multiply, (int x, int y), (const));
};

TEST(IntegrationTest, LoggerNotifierMockCalculator) {
    Logger logger;
    Notifier notifier;
    MockCalculator mockCalculator;

    int x = 10, y = 5;

    EXPECT_CALL(mockCalculator, add(x, y))
        .Times(1)
        .WillOnce(::testing::Return(15));

    EXPECT_CALL(mockCalculator, subtract(x, y))
        .Times(1)
        .WillOnce(::testing::Return(5));

    EXPECT_CALL(mockCalculator, multiply(x, y))
        .Times(1)
        .WillOnce(::testing::Return(50));

    int addResult = mockCalculator.add(x, y);
    int subResult = mockCalculator.subtract(x, y);
    int mulResult = mockCalculator.multiply(x, y);

    logger.log("Addition result: " + std::to_string(addResult));
    logger.log("Subtraction result: " + std::to_string(subResult));
    logger.log("Multiplication result: " + std::to_string(mulResult));

    bool notifiedAdd = notifier.notify(addResult, 10);
    bool notifiedSub = notifier.notify(subResult, 10);
    bool notifiedMul = notifier.notify(mulResult, 10);

    EXPECT_TRUE(notifiedAdd);  // 15 > 10，notify
    EXPECT_FALSE(notifiedSub); // 5 < 10
    EXPECT_TRUE(notifiedMul);  // 50 > 10，notify

    const auto& logs = logger.getLogs();
    ASSERT_EQ(logs.size(), 3);
    EXPECT_NE(logs[0].find("15"), std::string::npos);
    EXPECT_NE(logs[1].find("5"), std::string::npos);
    EXPECT_NE(logs[2].find("50"), std::string::npos);
}
