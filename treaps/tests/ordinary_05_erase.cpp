#include "cartesian_tree.h"
#include "test_support.h"
#include "tree_helpers.h"

int main() {
    treap::Node* root = nullptr;
    treap::insert(root, 5, 100);
    treap::insert(root, 2, 60);
    treap::insert(root, 8, 70);
    treap::insert(root, 1, 20);
    treap::insert(root, 3, 30);

    EXPECT_TRUE(treap::erase(root, 1));
    EXPECT_VECTOR(ordinary_values(root), 2, 3, 5, 8);
    EXPECT_TRUE(valid_ordinary(root));

    EXPECT_TRUE(treap::erase(root, 5));
    EXPECT_VECTOR(ordinary_values(root), 2, 3, 8);
    EXPECT_TRUE(valid_ordinary(root));

    EXPECT_FALSE(treap::erase(root, 42));
    EXPECT_VECTOR(ordinary_values(root), 2, 3, 8);

    EXPECT_TRUE(treap::erase(root, 2));
    EXPECT_TRUE(treap::erase(root, 3));
    EXPECT_TRUE(treap::erase(root, 8));
    EXPECT_TRUE(root == nullptr);
    EXPECT_FALSE(treap::erase(root, 8));

    treap::destroy(root);
    return test::finish();
}
