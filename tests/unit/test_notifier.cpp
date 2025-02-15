#include <gtest/gtest.h>

#include "Notifier.h"

TEST(NotifierTest, NotifyWhenExceedsThreshold) {
    Notifier notifier;
    EXPECT_TRUE(notifier.notify(10.0, 5.0));
    EXPECT_FALSE(notifier.notify(3.0, 5.0));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
