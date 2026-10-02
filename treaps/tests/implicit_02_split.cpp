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
    implicit_treap::SplitResult empty = implicit_treap::split(nullptr, 0);
    EXPECT_TRUE(empty.left == nullptr);
    EXPECT_TRUE(empty.right == nullptr);

    implicit_treap::Node* root = make_sequence();
    implicit_treap::SplitResult middle = implicit_treap::split(root, 2);
    EXPECT_EQ(implicit_values(middle.left), (std::vector<int>{10, 20}));
    EXPECT_EQ(implicit_values(middle.right), (std::vector<int>{30, 40}));
    EXPECT_TRUE(valid_implicit_metadata(middle.left));
    EXPECT_TRUE(valid_implicit_metadata(middle.right));
    implicit_treap::destroy(middle.left);
    implicit_treap::destroy(middle.right);

    root = make_sequence();
    implicit_treap::SplitResult before_all = implicit_treap::split(root, 0);
    EXPECT_TRUE(before_all.left == nullptr);
    EXPECT_EQ(implicit_values(before_all.right), (std::vector<int>{10, 20, 30, 40}));
    implicit_treap::destroy(before_all.left);
    implicit_treap::destroy(before_all.right);
}
