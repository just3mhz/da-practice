#include "cartesian_tree.h"

namespace treap {


bool contains(const Node* root, int key) {
    Node const* curent = root;
    while (curent) {
        if (curent->key > key) {
            curent = curent->left;
        } else if (curent->key == key) {
            return true;
        } else {
            curent = curent->right;
        }
    }
    return false;
}
// struct Node {
//     int key;
//     unsigned int priority;
//     Node* left = nullptr;
//     Node* right = nullptr;

//     Node(int key, unsigned int priority) : key(key), priority(priority) {
//     }
// };
SplitResult split(Node* root, int key) {
    if (!root) return {
        .left = nullptr, .right = nullptr
    };

    if (root->key >= key) {
        SplitResult res = split(root->left, key);
        root->left = res.right;
        return {.left = res.left, .right = root};
    } else if (root->key < key) {
        SplitResult res = split(root-> right, key);
        root->right = res.left;
        return {.left = root, .right = res.right};
    }

    return {};  // TODO
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (right->priority > left->priority ){
        right->left = merge(left, right->left);
        return right;
    } else {
        left->right = merge(left->right, right);
        return left;
    }
    return left;
}

Node* insert(Node* root, int key, unsigned int priority) {
    if (contains(root, key)) return root;
    auto [L, R] = split(root, key);
    Node* node = new Node(key, priority);
    return merge(merge(L, node), R);
}

Node* erase(Node* root, int key) {
    if (!root) return nullptr;
    if (root->key > key) {
        root->left = erase(root->left, key);
    } else if (root->key == key) {
        Node* tmp = merge(root->left, root->right);
        delete root;
        return tmp;
    } else {
        root->right = erase(root->right, key);
    }
    return root;  // TODO
}

void destroy(Node* /*root*/) {
    // TODO
}

}  // namespace treap
