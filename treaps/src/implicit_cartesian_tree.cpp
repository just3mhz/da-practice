#include "implicit_cartesian_tree.h"
#include <stdexcept>
#include <algorithm>

namespace implicit_treap {

int size(const Node* root) {
    if (!root) {
        return 0;
    }

    return root->subtree_size;
}

long long sum(const Node* root) {
    if (!root) {
        return 0;
    }

    return root->subtree_sum;
}

void update(Node* root) {
    if (!root) {
        return;
    }

    root->subtree_size = size(root->left) + size(root->right) + 1;
    root->subtree_sum = sum(root->left) + sum(root->right) + root->value;
}

void push(Node* root) {
    if (!root) {
        return;
    }

    if (root->reversed) {
        if (root->right) {
            root->right->reversed = !root->right->reversed;
        }
        if (root->left) {
            root->left->reversed = !root->left->reversed;
        }
        std::swap(root->right, root->left);
        root->reversed = false;
    }

    if (root->lazy_add) {
        const auto apply = [](Node* node, int delta) {
            if (node) {
                node->value += delta;
                node->subtree_sum += node->subtree_size * delta;
                node->lazy_add = delta;
            }
        };
        apply(root->right, root->lazy_add);
        apply(root->left, root->lazy_add);
        root->lazy_add = 0;
    }
}

SplitResult split(Node* root, int index) {
    if (!root) {
        return {};
    }

    push(root);

    int left_size = size(root->left);

    if (left_size >= index) {
        auto [left, right] = split(root->left, index);
        root->left = right;
        update(root);
        return {
            .left = left,
            .right = root,
        };
    }

    auto [left, right] = split(root->right, index - left_size - 1);
    root->right = left;
    update(root);
    return {
        .left = root,
        .right = right,
    };
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (right->priority > left->priority ){
        push(right);
        right->left = merge(left, right->left);
        update(right);
        return right;
    } else {
        push(left);
        left->right = merge(left->right, right);
        update(left);
        return left;
    }
    return left;
}

Node* insert(Node* root, int index, int value, unsigned int priority) {
    auto* node = new Node(value, priority);

    auto [left, right] = split(root, index);
    return merge(merge(left, node), right);
}

int at(Node* root, int index) {
    while (root) {
        int left_size = size(root->left);

        if (left_size > index) {
            push(root);
            root = root->left;
        } else if (left_size < index) {
            index = index - left_size - 1;
            push(root);
            root = root->right;
        } else {
            return root->value;
        }
    }
    throw std::out_of_range("Index is out of range");
}

Node* erase(Node* root, int index) {
    auto [left, rightWithIndex] = split(root, index);
    auto [element, right] = split(rightWithIndex, 1);

    if (element) {
        delete element;
    }

    return merge(left, right);
}

long long range_sum(Node* root, int left, int right) {
    auto [leftTree, rightTreeWithMiddle] = split(root, left);
    auto [middleTree, rightTree] = split(rightTreeWithMiddle, right - left);


    long long result = 0; 
    if (middleTree) {
        result = middleTree->subtree_sum;
    }

    merge(merge(leftTree, middleTree), rightTree);

    return result;
}

Node* reverse(Node* root, int left, int right) {
    auto [leftTree, rightTreeWithMiddle] = split(root, left);
    auto [middleTree, rightTree] = split(rightTreeWithMiddle, right - left);

    if (middleTree) {
        middleTree->reversed = !middleTree->reversed;
    }

    return merge(merge(leftTree, middleTree), rightTree);
}

Node* range_add(Node* root, int left, int right, int delta) {
    auto [leftTree, rightTreeWithMiddle] = split(root, left);
    auto [middleTree, rightTree] = split(rightTreeWithMiddle, right - left);

    if (middleTree) {
        middleTree->lazy_add = delta;
        middleTree->value += delta;
        middleTree->subtree_sum += middleTree->subtree_size * delta;
    }

    return merge(merge(leftTree, middleTree), rightTree);
}

void destroy(Node* root) {
    if (!root) {
        return;
    }

    destroy(root->left);
    destroy(root->right);
    delete root;
}

}  // namespace implicit_treap
