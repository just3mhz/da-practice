#include "cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

TEST(Ordinary03, MergeOrderedTrees) {
    EXPECT_TRUE(treap::merge(nullptr, nullptr) == nullptr);

    treap::Node* only = new treap::Node(1, 10);
    EXPECT_TRUE(treap::merge(nullptr, only) == only);
    treap::destroy(only);

    treap::Node* left = new treap::Node(3, 100);
    left->left = new treap::Node(1, 30);
    treap::Node* right = new treap::Node(7, 90);
    right->left = new treap::Node(5, 20);
    right->right = new treap::Node(9, 40);

    treap::Node* root = treap::merge(left, right);
    EXPECT_EQ(ordinary_values(root), (std::vector<int>{1, 3, 5, 7, 9}));
    EXPECT_TRUE(valid_ordinary(root));
    treap::destroy(root);
}
