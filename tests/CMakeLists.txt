# tests/CMakeLists.txt
find_package(GTest CONFIG REQUIRED)

#get_target_property(GTEST_INCLUDES GTest::gtest INTERFACE_INCLUDE_DIRECTORIES)
#message(STATUS "GTest include directories: ${GTEST_INCLUDES}")

include_directories(${GTEST_INCLUDES})

add_subdirectory(unit)
add_subdirectory(integration)
add_subdirectory(endtoend)
