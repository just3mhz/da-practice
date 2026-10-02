#include "implicit_cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

TEST(Implicit05, EraseByPosition) {
    implicit_treap::Node* root = nullptr;
    root = implicit_treap::insert(root, 0, 10, 20);
    root = implicit_treap::insert(root, 1, 20, 80);
    root = implicit_treap::insert(root, 2, 30, 50);
    root = implicit_treap::insert(root, 3, 40, 30);

    root = implicit_treap::erase(root, 1);
    EXPECT_EQ(implicit_values(root), (std::vector<int>{10, 30, 40}));
    root = implicit_treap::erase(root, 0);
    root = implicit_treap::erase(root, 1);
    EXPECT_EQ(implicit_values(root), (std::vector<int>{30}));
    EXPECT_EQ(implicit_treap::size(root), 1);
    EXPECT_TRUE(valid_implicit_metadata(root));

    root = implicit_treap::erase(root, 0);
    EXPECT_TRUE(root == nullptr);
    implicit_treap::destroy(root);
}
