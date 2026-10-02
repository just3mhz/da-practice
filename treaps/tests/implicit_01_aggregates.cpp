#include "implicit_cartesian_tree.h"
#include <gtest/gtest.h>

TEST(Implicit01, AggregatesAndDestroy) {
    EXPECT_EQ(implicit_treap::size(nullptr), 0);

    implicit_treap::Node* root = new implicit_treap::Node(10, 100);
    EXPECT_EQ(root->value, 10);
    EXPECT_EQ(root->priority, 100u);
    EXPECT_EQ(root->subtree_size, 1);
    EXPECT_FALSE(root->reversed);

    root->left = new implicit_treap::Node(-2, 30);
    root->right = new implicit_treap::Node(3, 40);
    implicit_treap::update(root);
    EXPECT_EQ(implicit_treap::size(root), 3);

    implicit_treap::destroy(root);
}
