#include "implicit_cartesian_tree.h"
#include "tree_helpers.h"
#include <gtest/gtest.h>

TEST(Implicit04, InsertAndAccess) {
    implicit_treap::Node* root = nullptr;
    root = implicit_treap::insert(root, 0, 10, 20);
    root = implicit_treap::insert(root, 1, 30, 50);
    root = implicit_treap::insert(root, 1, 20, 80);
    root = implicit_treap::insert(root, 0, 5, 40);

    EXPECT_EQ(implicit_values(root), (std::vector<int>{5, 10, 20, 30}));
    EXPECT_EQ(implicit_treap::size(root), 4);
    EXPECT_EQ(implicit_treap::at(root, 0), 5);
    EXPECT_EQ(implicit_treap::at(root, 2), 20);
    EXPECT_EQ(implicit_treap::at(root, 3), 30);
    EXPECT_TRUE(valid_implicit_metadata(root));

    implicit_treap::destroy(root);
}
