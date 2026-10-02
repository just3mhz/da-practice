#include "implicit_cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

TEST(Implicit07, ReverseAndContinueEditing) {
    implicit_treap::Node* root = nullptr;
    root = implicit_treap::insert(root, 0, 1, 10);
    root = implicit_treap::insert(root, 1, 2, 40);
    root = implicit_treap::insert(root, 2, 3, 80);
    root = implicit_treap::insert(root, 3, 4, 30);
    root = implicit_treap::insert(root, 4, 5, 20);

    root = implicit_treap::reverse(root, 1, 4);  // [1, 4, 3, 2, 5]
    EXPECT_EQ(implicit_treap::at(root, 1), 4);
    EXPECT_EQ(implicit_treap::range_sum(root, 1, 3), 7LL);

    root = implicit_treap::reverse(root, 0, 5);  // [5, 2, 3, 4, 1]
    root = implicit_treap::insert(root, 2, 9, 90);
    root = implicit_treap::erase(root, 4);
    EXPECT_EQ(implicit_values(root), (std::vector<int>{5, 2, 9, 3, 1}));

    root = implicit_treap::reverse(root, 2, 2);
    EXPECT_EQ(implicit_values(root), (std::vector<int>{5, 2, 9, 3, 1}));
    EXPECT_TRUE(valid_implicit_metadata(root));

    implicit_treap::destroy(root);
}
