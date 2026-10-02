#include "implicit_cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

implicit_treap::Node* make_sequence() {
    implicit_treap::Node* root = new implicit_treap::Node(20, 100);
    root->left = new implicit_treap::Node(10, 60);
    root->right = new implicit_treap::Node(30, 80);
    root->right->right = new implicit_treap::Node(40, 40);
    recalculate_for_test(root);
    return root;
}

TEST(Implicit02, SplitByPosition) {
    implicit_treap::Node* left = nullptr;
    implicit_treap::Node* right = nullptr;
    implicit_treap::split(nullptr, 0, left, right);
    EXPECT_TRUE(left == nullptr);
    EXPECT_TRUE(right == nullptr);

    implicit_treap::Node* root = make_sequence();
    implicit_treap::split(root, 2, left, right);
    EXPECT_EQ(implicit_values(left), (std::vector<int>{10, 20}));
    EXPECT_EQ(implicit_values(right), (std::vector<int>{30, 40}));
    EXPECT_TRUE(valid_implicit_metadata(left));
    EXPECT_TRUE(valid_implicit_metadata(right));
    implicit_treap::destroy(left);
    implicit_treap::destroy(right);

    root = make_sequence();
    implicit_treap::split(root, 0, left, right);
    EXPECT_TRUE(left == nullptr);
    EXPECT_EQ(implicit_values(right), (std::vector<int>{10, 20, 30, 40}));
    implicit_treap::destroy(left);
    implicit_treap::destroy(right);
}
