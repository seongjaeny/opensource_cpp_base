#include <gtest/gtest.h>

#include "Logger.h"
#include "Notifier.h"

TEST(IntegrationTest, LoggerAndNotifier) {
    // Notifier는 내부적으로 값이 임계치보다 크면 알림(true)으로 판단
    Notifier notifier;
    double threshold = 10.0;

    EXPECT_TRUE(notifier.notify(12.0, threshold));

    EXPECT_FALSE(notifier.notify(5.0, threshold));
}
