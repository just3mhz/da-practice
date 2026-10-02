#include "implicit_cartesian_tree.h"
#include "test_support.h"
#include "tree_helpers.h"

int main() {
    implicit_treap::Node* root = nullptr;
    implicit_treap::insert(root, 0, 10, 20);
    implicit_treap::insert(root, 1, 20, 80);
    implicit_treap::insert(root, 2, 30, 50);
    implicit_treap::insert(root, 3, 40, 30);

    EXPECT_EQ(implicit_treap::erase(root, 1), 20);
    EXPECT_VECTOR(implicit_values(root), 10, 30, 40);
    EXPECT_EQ(implicit_treap::erase(root, 0), 10);
    EXPECT_EQ(implicit_treap::erase(root, 1), 40);
    EXPECT_VECTOR(implicit_values(root), 30);
    EXPECT_EQ(implicit_treap::size(root), 1);
    EXPECT_TRUE(valid_implicit_metadata(root));

    EXPECT_EQ(implicit_treap::erase(root, 0), 30);
    EXPECT_TRUE(root == nullptr);
    implicit_treap::destroy(root);

    return test::finish();
}
