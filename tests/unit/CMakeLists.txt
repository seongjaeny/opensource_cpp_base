add_executable(test_calculator test_calculator.cpp)
target_link_libraries(test_calculator PRIVATE components GTest::gtest GTest::gtest_main)

add_executable(test_logger test_logger.cpp)
target_link_libraries(test_logger PRIVATE components GTest::gtest GTest::gtest_main)

add_executable(test_notifier test_notifier.cpp)
target_link_libraries(test_notifier PRIVATE components GTest::gtest GTest::gtest_main)

add_test(NAME CalculatorTest COMMAND test_calculator)
add_test(NAME LoggerTest COMMAND test_logger)
add_test(NAME NotifierTest COMMAND test_notifier)