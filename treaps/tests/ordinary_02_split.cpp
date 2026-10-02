#include "cartesian_tree.h"
#include "test_support.h"
#include "tree_helpers.h"

treap::Node* make_tree() {
    treap::Node* root = new treap::Node(5, 100);
    root->left = new treap::Node(2, 60);
    root->right = new treap::Node(8, 70);
    root->left->left = new treap::Node(1, 20);
    root->left->right = new treap::Node(3, 30);
    return root;
}

int main() {
    treap::Node* left = nullptr;
    treap::Node* right = nullptr;

    treap::split(nullptr, 5, left, right);
    EXPECT_TRUE(left == nullptr);
    EXPECT_TRUE(right == nullptr);

    treap::Node* root = make_tree();
    treap::split(root, 5, left, right);
    EXPECT_VECTOR(ordinary_values(left), 1, 2, 3);
    EXPECT_VECTOR(ordinary_values(right), 5, 8);
    EXPECT_TRUE(valid_ordinary(left));
    EXPECT_TRUE(valid_ordinary(right));
    treap::destroy(left);
    treap::destroy(right);

    root = make_tree();
    treap::split(root, -10, left, right);
    EXPECT_TRUE(left == nullptr);
    EXPECT_VECTOR(ordinary_values(right), 1, 2, 3, 5, 8);
    treap::destroy(left);
    treap::destroy(right);

    return test::finish();
}
