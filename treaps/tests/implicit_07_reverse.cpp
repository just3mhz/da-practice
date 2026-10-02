#include "implicit_cartesian_tree.h"
#include "test_support.h"
#include "tree_helpers.h"

int main() {
    implicit_treap::Node* root = nullptr;
    implicit_treap::insert(root, 0, 1, 10);
    implicit_treap::insert(root, 1, 2, 40);
    implicit_treap::insert(root, 2, 3, 80);
    implicit_treap::insert(root, 3, 4, 30);
    implicit_treap::insert(root, 4, 5, 20);

    implicit_treap::reverse(root, 1, 4);  // [1, 4, 3, 2, 5]
    EXPECT_EQ(implicit_treap::at(root, 1), 4);
    EXPECT_EQ(implicit_treap::range_sum(root, 1, 3), 7LL);

    implicit_treap::reverse(root, 0, 5);  // [5, 2, 3, 4, 1]
    implicit_treap::insert(root, 2, 9, 90);
    EXPECT_EQ(implicit_treap::erase(root, 4), 4);
    EXPECT_VECTOR(implicit_values(root), 5, 2, 9, 3, 1);

    implicit_treap::reverse(root, 2, 2);
    EXPECT_VECTOR(implicit_values(root), 5, 2, 9, 3, 1);
    EXPECT_TRUE(valid_implicit_metadata(root));

    implicit_treap::destroy(root);
    return test::finish();
}
