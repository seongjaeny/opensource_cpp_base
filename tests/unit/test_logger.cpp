#include <gtest/gtest.h>

#include "Logger.h"

TEST(LoggerTest, LogMessage) {
    Logger logger;
    logger.log("Test log");
    const auto& logs = logger.getLogs();
    ASSERT_EQ(logs.size(), 1);
    EXPECT_EQ(logs[0], "Test log");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
