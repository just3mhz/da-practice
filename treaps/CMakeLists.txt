cmake_minimum_required(VERSION 3.16)
project(treap_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

enable_testing()

function(add_stage name test_file implementation)
    add_executable(${name} ${test_file} ${implementation})
    target_include_directories(${name} PRIVATE include tests)
    target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic)

    if(ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        target_compile_options(${name} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
        target_link_options(${name} PRIVATE -fsanitize=address,undefined)
    endif()

    add_test(NAME ${name} COMMAND ${name})
endfunction()

add_stage(ordinary_01_basics tests/ordinary_01_basics.cpp src/cartesian_tree.cpp)
add_stage(ordinary_02_split tests/ordinary_02_split.cpp src/cartesian_tree.cpp)
add_stage(ordinary_03_merge tests/ordinary_03_merge.cpp src/cartesian_tree.cpp)
add_stage(ordinary_04_insert tests/ordinary_04_insert.cpp src/cartesian_tree.cpp)
add_stage(ordinary_05_erase tests/ordinary_05_erase.cpp src/cartesian_tree.cpp)

add_stage(implicit_01_aggregates tests/implicit_01_aggregates.cpp src/implicit_cartesian_tree.cpp)
add_stage(implicit_02_split tests/implicit_02_split.cpp src/implicit_cartesian_tree.cpp)
add_stage(implicit_03_merge tests/implicit_03_merge.cpp src/implicit_cartesian_tree.cpp)
add_stage(implicit_04_insert_at tests/implicit_04_insert_at.cpp src/implicit_cartesian_tree.cpp)
add_stage(implicit_05_erase tests/implicit_05_erase.cpp src/implicit_cartesian_tree.cpp)
add_stage(implicit_06_range_sum tests/implicit_06_range_sum.cpp src/implicit_cartesian_tree.cpp)
add_stage(implicit_07_reverse tests/implicit_07_reverse.cpp src/implicit_cartesian_tree.cpp)
