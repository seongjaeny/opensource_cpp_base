cmake_minimum_required(VERSION 3.30)
project(cpp_base)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(CODE_COVERAGE "Enable coverage reporting" ON)
if(CODE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        add_compile_options(--coverage)
        add_link_options(--coverage)
    endif()
endif()

enable_testing()

add_executable(cpp_base
        src/utils/Calculator.cpp
        src/utils/Logger.cpp
        src/utils/Notifier.cpp
)

target_link_libraries(cpp_base PRIVATE components)

add_subdirectory(src)
add_subdirectory(tests)
