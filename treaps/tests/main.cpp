#include "test_support.h"

#include <iostream>

void test_cartesian_tree();
void test_implicit_cartesian_tree();

int main() {
    test_cartesian_tree();
    test_implicit_cartesian_tree();

    if (test::failures == 0) {
        std::cout << "All tests passed\n";
        return 0;
    }

    std::cerr << test::failures << " test assertion(s) failed\n";
    return 1;
}
