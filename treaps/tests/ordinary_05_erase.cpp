#include "cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

TEST(Ordinary05, EraseKeys) {
    treap::Node* root = nullptr;
    root = treap::insert(root, 5, 100);
    root = treap::insert(root, 2, 60);
    root = treap::insert(root, 8, 70);
    root = treap::insert(root, 1, 20);
    root = treap::insert(root, 3, 30);

    root = treap::erase(root, 1);
    EXPECT_EQ(ordinary_values(root), (std::vector<int>{2, 3, 5, 8}));
    EXPECT_TRUE(valid_ordinary(root));

    root = treap::erase(root, 5);
    EXPECT_EQ(ordinary_values(root), (std::vector<int>{2, 3, 8}));
    EXPECT_TRUE(valid_ordinary(root));

    treap::Node* old_root = root;
    root = treap::erase(root, 42);
    EXPECT_TRUE(root == old_root);
    EXPECT_EQ(ordinary_values(root), (std::vector<int>{2, 3, 8}));

    root = treap::erase(root, 2);
    root = treap::erase(root, 3);
    root = treap::erase(root, 8);
    EXPECT_TRUE(root == nullptr);
    root = treap::erase(root, 8);
    EXPECT_TRUE(root == nullptr);

    treap::destroy(root);
}
