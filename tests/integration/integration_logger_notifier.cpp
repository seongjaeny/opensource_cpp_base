#include <gtest/gtest.h>
#include "Logger.h"
#include "Notifier.h"

TEST(IntegrationTest, LoggerAndNotifier) {
    Notifier notifier;
    double threshold = 10.0;

    EXPECT_TRUE(notifier.notify(12.0, threshold));

    EXPECT_FALSE(notifier.notify(5.0, threshold));
}
