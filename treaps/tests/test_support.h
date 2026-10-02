#ifndef TEST_SUPPORT_H
#define TEST_SUPPORT_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace test {

inline int failures = 0;

inline void fail(const char* file, int line, const std::string& message) {
    ++failures;
    std::cerr << file << ':' << line << ": FAIL: " << message << '\n';
}

inline void expect_true(bool value, const char* expression, const char* file, int line) {
    if (!value) {
        fail(file, line, std::string("expected true: ") + expression);
    }
}

template <class Actual, class Expected>
void expect_equal(const Actual& actual, const Expected& expected,
                  const char* expression, const char* file, int line) {
    if (!(actual == expected)) {
        std::ostringstream message;
        message << expression << " (actual: " << actual << ", expected: " << expected << ')';
        fail(file, line, message.str());
    }
}

template <class Value>
std::string show_vector(const std::vector<Value>& values) {
    std::ostringstream result;
    result << '[';
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i != 0) {
            result << ", ";
        }
        result << values[i];
    }
    result << ']';
    return result.str();
}

template <class Value>
void expect_vector(const std::vector<Value>& actual, const std::vector<Value>& expected,
                   const char* file, int line) {
    if (actual != expected) {
        fail(file, line, "actual: " + show_vector(actual) + ", expected: " + show_vector(expected));
    }
}

}  // namespace test

#define EXPECT_TRUE(value) test::expect_true((value), #value, __FILE__, __LINE__)
#define EXPECT_FALSE(value) test::expect_true(!(value), "!(" #value ")", __FILE__, __LINE__)
#define EXPECT_EQ(actual, expected) test::expect_equal((actual), (expected), #actual " == " #expected, __FILE__, __LINE__)
#define EXPECT_VECTOR(actual, ...) test::expect_vector((actual), std::vector<int>{__VA_ARGS__}, __FILE__, __LINE__)
#define EXPECT_EMPTY_VECTOR(actual) test::expect_vector((actual), std::vector<int>{}, __FILE__, __LINE__)
#define EXPECT_OUT_OF_RANGE(statement)                                      \
    do {                                                                    \
        bool caught_expected_exception = false;                             \
        try {                                                               \
            statement;                                                      \
        } catch (const std::out_of_range&) {                                \
            caught_expected_exception = true;                              \
        } catch (...) {                                                     \
        }                                                                   \
        if (!caught_expected_exception) {                                   \
            test::fail(__FILE__, __LINE__,                                  \
                       "expected std::out_of_range: " #statement);          \
        }                                                                   \
    } while (false)

#endif
