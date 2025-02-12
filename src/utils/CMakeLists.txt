add_library(components
        Calculator.cpp
        Logger.cpp
        Notifier.cpp
)

target_include_directories(components PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
