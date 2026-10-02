#include "cartesian_tree.h"
#include <gtest/gtest.h>

TEST(Ordinary01, NodeContainsAndDestroy) {
    treap::Node* root = new treap::Node(5, 100);
    root->left = new treap::Node(2, 50);
    root->right = new treap::Node(8, 40);

    EXPECT_EQ(root->key, 5);
    EXPECT_EQ(root->priority, 100u);
    EXPECT_TRUE(root->left != nullptr);
    EXPECT_TRUE(root->right != nullptr);

    EXPECT_TRUE(treap::contains(root, 5));
    EXPECT_TRUE(treap::contains(root, 2));
    EXPECT_TRUE(treap::contains(root, 8));
    EXPECT_FALSE(treap::contains(root, 7));
    EXPECT_FALSE(treap::contains(nullptr, 1));

    treap::destroy(root);
}
