#include "implicit_cartesian_tree.h"
#include "test_support.h"

#include <climits>

int main() {
    implicit_treap::Node* root = nullptr;
    implicit_treap::insert(root, 0, INT_MAX, 20);
    implicit_treap::insert(root, 1, -5, 80);
    implicit_treap::insert(root, 2, 7, 50);
    implicit_treap::insert(root, 3, INT_MAX, 30);

    EXPECT_EQ(implicit_treap::range_sum(root, 0, 4), 4294967296LL);
    EXPECT_EQ(implicit_treap::range_sum(root, 1, 3), 2LL);
    EXPECT_EQ(implicit_treap::range_sum(root, 2, 3), 7LL);
    EXPECT_EQ(implicit_treap::range_sum(root, 2, 2), 0LL);

    implicit_treap::destroy(root);
    return test::finish();
}
