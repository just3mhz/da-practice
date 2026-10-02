cmake_minimum_required(VERSION 3.16)
project(treap_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

include(FetchContent)

find_package(GTest CONFIG QUIET)
if(NOT GTest_FOUND)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(treap_tests
    src/cartesian_tree.cpp
    src/implicit_cartesian_tree.cpp
    tests/ordinary_01_basics.cpp
    tests/ordinary_02_split.cpp
    tests/ordinary_03_merge.cpp
    tests/ordinary_04_insert.cpp
    tests/ordinary_05_erase.cpp
    tests/implicit_01_aggregates.cpp
    tests/implicit_02_split.cpp
    tests/implicit_03_merge.cpp
    tests/implicit_04_insert_at.cpp
    tests/implicit_05_erase.cpp
    tests/implicit_06_range_sum.cpp
    tests/implicit_07_reverse.cpp
)

target_include_directories(treap_tests PRIVATE include tests)
target_link_libraries(treap_tests PRIVATE GTest::gtest_main)
target_compile_options(treap_tests PRIVATE -Wall -Wextra -Wpedantic)

if(ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(treap_tests PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(treap_tests PRIVATE -fsanitize=address,undefined)
endif()

enable_testing()
include(GoogleTest)
gtest_discover_tests(treap_tests DISCOVERY_TIMEOUT 30)
