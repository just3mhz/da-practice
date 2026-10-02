#include "implicit_cartesian_tree.h"
#include "test_support.h"
#include "tree_helpers.h"

int main() {
    EXPECT_TRUE(implicit_treap::merge(nullptr, nullptr) == nullptr);

    implicit_treap::Node* left = new implicit_treap::Node(2, 100);
    left->left = new implicit_treap::Node(1, 30);
    // Правый корень имеет больший приоритет: merge должен пройти ветви
    // выбора и правого, и левого корня.
    implicit_treap::Node* right = new implicit_treap::Node(4, 110);
    right->left = new implicit_treap::Node(3, 20);
    right->right = new implicit_treap::Node(5, 40);
    recalculate_for_test(left);
    recalculate_for_test(right);

    implicit_treap::Node* root = implicit_treap::merge(left, right);
    EXPECT_VECTOR(implicit_values(root), 1, 2, 3, 4, 5);
    EXPECT_EQ(implicit_treap::size(root), 5);
    EXPECT_EQ(implicit_treap::sum(root), 15LL);
    EXPECT_TRUE(valid_implicit_metadata(root));
    implicit_treap::destroy(root);

    return test::finish();
}
