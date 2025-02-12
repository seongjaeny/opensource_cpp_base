add_executable(e2e_test e2e_test.cpp)
target_link_libraries(e2e_test PRIVATE components GTest::gtest GTest::gtest_main)

add_test(NAME EndToEndTest COMMAND e2e_test)