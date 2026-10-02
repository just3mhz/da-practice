cmake_minimum_required(VERSION 3.16)
project(treap_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

add_executable(treap_tests
    src/cartesian_tree.cpp
    src/implicit_cartesian_tree.cpp
    tests/main.cpp
    tests/test_cartesian_tree.cpp
    tests/test_implicit_cartesian_tree.cpp
)

target_include_directories(treap_tests PRIVATE include tests)
target_compile_options(treap_tests PRIVATE -Wall -Wextra -Wpedantic)

if(ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(treap_tests PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(treap_tests PRIVATE -fsanitize=address,undefined)
endif()

enable_testing()
add_test(NAME all_treap_tests COMMAND treap_tests)
