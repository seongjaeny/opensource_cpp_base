cmake_minimum_required(VERSION 3.30)
project(cpp_base)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(CODE_COVERAGE "Enable coverage reporting" ON)
if(CODE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
        add_link_options(-fprofile-instr-generate)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options(--coverage)
        add_link_options(--coverage)
    endif()
endif()

enable_testing()

add_executable(cpp_base
        src/main.cpp
)

target_link_libraries(cpp_base PRIVATE components)

add_subdirectory(src)
add_subdirectory(tests)
