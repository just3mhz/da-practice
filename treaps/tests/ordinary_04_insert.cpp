#include "cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

TEST(Ordinary04, InsertKeys) {
    treap::Node* root = nullptr;
    root = treap::insert(root, 5, 20);
    root = treap::insert(root, 2, 80);
    root = treap::insert(root, 8, 50);
    root = treap::insert(root, -3, 40);

    EXPECT_EQ(ordinary_values(root), (std::vector<int>{-3, 2, 5, 8}));
    EXPECT_TRUE(valid_ordinary(root));
    EXPECT_TRUE(treap::contains(root, -3));

    treap::Node* old_root = root;
    root = treap::insert(root, 5, 1000);
    EXPECT_EQ(ordinary_values(root), (std::vector<int>{-3, 2, 5, 8}));
    EXPECT_TRUE(root == old_root);
    EXPECT_TRUE(valid_ordinary(root));

    treap::destroy(root);
}
