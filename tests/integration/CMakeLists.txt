find_package(GTest REQUIRED)

add_executable(integration_calculator_logger integration_calculator_logger.cpp)
target_link_libraries(integration_calculator_logger
        PRIVATE
        components
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
        pthread
)

add_executable(integration_logger_notifier integration_logger_notifier.cpp)
target_link_libraries(integration_logger_notifier
        PRIVATE
        components
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
        pthread
)

add_test(NAME IntegrationCalcLoggerTest COMMAND integration_calculator_logger)
add_test(NAME IntegrationLoggerNotifierTest COMMAND integration_logger_notifier)
