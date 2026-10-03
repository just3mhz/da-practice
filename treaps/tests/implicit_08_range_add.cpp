#include "implicit_cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

TEST(Implicit08, RangeAddAndContinueEditing) {
    implicit_treap::Node* root = nullptr;
    root = implicit_treap::insert(root, 0, 1, 10);
    root = implicit_treap::insert(root, 1, 2, 40);
    root = implicit_treap::insert(root, 2, 3, 80);
    root = implicit_treap::insert(root, 3, 4, 30);
    root = implicit_treap::insert(root, 4, 5, 20);

    root = implicit_treap::range_add(root, 1, 4, 10);  // [1, 12, 13, 14, 5]
    EXPECT_EQ(implicit_treap::range_sum(root, 0, 5), 45LL);
    EXPECT_EQ(implicit_treap::range_sum(root, 1, 4), 39LL);

    root = implicit_treap::reverse(root, 1, 4);  // [1, 14, 13, 12, 5]
    root = implicit_treap::range_add(root, 0, 5, -2);  // [-1, 12, 11, 10, 3]
    EXPECT_EQ(implicit_values(root), (std::vector<int>{-1, 12, 11, 10, 3}));

    root = implicit_treap::range_add(root, 2, 2, 100);
    root = implicit_treap::insert(root, 3, 7, 90);
    root = implicit_treap::erase(root, 1);
    EXPECT_EQ(implicit_values(root), (std::vector<int>{-1, 11, 7, 10, 3}));
    EXPECT_EQ(implicit_treap::range_sum(root, 0, 5), 30LL);
    EXPECT_TRUE(valid_implicit_metadata(root));

    implicit_treap::destroy(root);
}
