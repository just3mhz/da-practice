#include "cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

treap::Node* make_tree() {
    treap::Node* root = new treap::Node(5, 100);
    root->left = new treap::Node(2, 60);
    root->right = new treap::Node(8, 70);
    root->left->left = new treap::Node(1, 20);
    root->left->right = new treap::Node(3, 30);
    return root;
}

TEST(Ordinary02, SplitByKey) {
    treap::SplitResult empty = treap::split(nullptr, 5);
    EXPECT_TRUE(empty.left == nullptr);
    EXPECT_TRUE(empty.right == nullptr);

    treap::Node* root = make_tree();
    treap::SplitResult middle = treap::split(root, 5);
    EXPECT_EQ(ordinary_values(middle.left), (std::vector<int>{1, 2, 3}));
    EXPECT_EQ(ordinary_values(middle.right), (std::vector<int>{5, 8}));
    EXPECT_TRUE(valid_ordinary(middle.left));
    EXPECT_TRUE(valid_ordinary(middle.right));
    treap::destroy(middle.left);
    treap::destroy(middle.right);

    root = make_tree();
    treap::SplitResult before_all = treap::split(root, -10);
    EXPECT_TRUE(before_all.left == nullptr);
    EXPECT_EQ(ordinary_values(before_all.right), (std::vector<int>{1, 2, 3, 5, 8}));
    treap::destroy(before_all.left);
    treap::destroy(before_all.right);
}
