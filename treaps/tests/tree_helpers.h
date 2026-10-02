#pragma once

#include "cartesian_tree.h"
#include "implicit_cartesian_tree.h"

#include <climits>
#include <vector>

inline void collect_ordinary(const treap::Node* root, std::vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    collect_ordinary(root->left, result);
    result.push_back(root->key);
    collect_ordinary(root->right, result);
}

inline std::vector<int> ordinary_values(const treap::Node* root) {
    std::vector<int> result;
    collect_ordinary(root, result);
    return result;
}

inline bool valid_ordinary(const treap::Node* root,
                           long long low = LLONG_MIN,
                           long long high = LLONG_MAX) {
    if (root == nullptr) {
        return true;
    }
    if (root->key <= low || root->key >= high) {
        return false;
    }
    if (root->left != nullptr && root->left->priority > root->priority) {
        return false;
    }
    if (root->right != nullptr && root->right->priority > root->priority) {
        return false;
    }
    return valid_ordinary(root->left, low, root->key) &&
           valid_ordinary(root->right, root->key, high);
}

inline int recalculate_for_test(implicit_treap::Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int left_size = recalculate_for_test(root->left);
    int right_size = recalculate_for_test(root->right);
    root->subtree_size = 1 + left_size + right_size;
    return root->subtree_size;
}

inline void collect_implicit(implicit_treap::Node* root, std::vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    collect_implicit(root->left, result);
    result.push_back(root->value);
    collect_implicit(root->right, result);
}

inline std::vector<int> implicit_values(implicit_treap::Node* root) {
    std::vector<int> result;
    collect_implicit(root, result);
    return result;
}

inline bool valid_implicit_metadata(implicit_treap::Node* root) {
    if (root == nullptr) {
        return true;
    }
    if (!valid_implicit_metadata(root->left) || !valid_implicit_metadata(root->right)) {
        return false;
    }
    if (root->left != nullptr && root->left->priority > root->priority) {
        return false;
    }
    if (root->right != nullptr && root->right->priority > root->priority) {
        return false;
    }
    int expected_size = 1;
    if (root->left != nullptr) {
        expected_size += root->left->subtree_size;
    }
    if (root->right != nullptr) {
        expected_size += root->right->subtree_size;
    }
    return root->subtree_size == expected_size;
}
