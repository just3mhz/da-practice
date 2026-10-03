cmake_minimum_required(VERSION 3.16)
project(treap_practice LANGUAGES CXX)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)
option(ENABLE_COVERAGE "Enable LLVM source-based code coverage" OFF)

if(ENABLE_SANITIZERS AND ENABLE_COVERAGE)
    message(FATAL_ERROR "ENABLE_SANITIZERS and ENABLE_COVERAGE cannot be enabled together")
endif()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.18.0.zip
    URL_HASH SHA256=63b9c77751a5b8f492486005f67533fdc58682b67476fcb91650be5958d5195a
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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
    tests/implicit_08_range_add.cpp
)

target_include_directories(treap_tests PRIVATE include tests)
target_link_libraries(treap_tests PRIVATE GTest::gtest_main)
target_compile_options(treap_tests PRIVATE -Wall -Wextra -Wpedantic)

if(ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(treap_tests PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(treap_tests PRIVATE -fsanitize=address,undefined)
endif()

if(ENABLE_COVERAGE)
    if(NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(FATAL_ERROR "ENABLE_COVERAGE requires Clang")
    endif()

    target_compile_options(treap_tests PRIVATE
        -O0
        -g
        -fprofile-instr-generate
        -fcoverage-mapping
    )
    target_link_options(treap_tests PRIVATE -fprofile-instr-generate)

    get_filename_component(CLANG_BIN_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)
    find_program(LLVM_COV_EXECUTABLE NAMES llvm-cov HINTS "${CLANG_BIN_DIR}")
    find_program(LLVM_PROFDATA_EXECUTABLE NAMES llvm-profdata HINTS "${CLANG_BIN_DIR}")
    if(NOT LLVM_COV_EXECUTABLE OR NOT LLVM_PROFDATA_EXECUTABLE)
        message(FATAL_ERROR "llvm-cov and llvm-profdata must be available next to Clang or in PATH")
    endif()

    set(COVERAGE_DIR "${CMAKE_BINARY_DIR}/coverage")
    set(COVERAGE_RAW "${COVERAGE_DIR}/treap_tests.profraw")
    set(COVERAGE_DATA "${COVERAGE_DIR}/treap_tests.profdata")
    set(COVERAGE_HTML_DIR "${COVERAGE_DIR}/html")
    set(COVERAGE_IGNORE_REGEX ".*/tests/.*")

    add_custom_target(coverage
        COMMAND "${CMAKE_COMMAND}" -E rm -rf "${COVERAGE_DIR}"
        COMMAND "${CMAKE_COMMAND}" -E make_directory "${COVERAGE_DIR}"
        COMMAND "${CMAKE_COMMAND}" -E env
            "LLVM_PROFILE_FILE=${COVERAGE_RAW}"
            "$<TARGET_FILE:treap_tests>" --gtest_brief=1
        COMMAND "${LLVM_PROFDATA_EXECUTABLE}" merge -sparse
            "${COVERAGE_RAW}" -o "${COVERAGE_DATA}"
        COMMAND "${LLVM_COV_EXECUTABLE}" report "$<TARGET_FILE:treap_tests>"
            "-instr-profile=${COVERAGE_DATA}"
            "-ignore-filename-regex=${COVERAGE_IGNORE_REGEX}"
        COMMAND "${LLVM_COV_EXECUTABLE}" show "$<TARGET_FILE:treap_tests>"
            "-instr-profile=${COVERAGE_DATA}"
            "-ignore-filename-regex=${COVERAGE_IGNORE_REGEX}"
            -format=html
            "-output-dir=${COVERAGE_HTML_DIR}"
        COMMAND "${CMAKE_COMMAND}" -E echo
            "HTML coverage report: ${COVERAGE_HTML_DIR}/index.html"
        DEPENDS treap_tests
        USES_TERMINAL
    )
endif()

enable_testing()
include(GoogleTest)
gtest_discover_tests(treap_tests DISCOVERY_TIMEOUT 30)
