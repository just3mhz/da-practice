#include "cartesian_tree.h"

namespace treap {

Node::Node(int node_key, unsigned int node_priority)
    : key(0), priority(0), left(nullptr), right(nullptr) {
    (void)node_key;
    (void)node_priority;
    // TODO: сохранить key и priority.
}

bool contains(const Node* root, int key) {
    (void)root;
    (void)key;
    return false;  // TODO
}

void split(Node* root, int key, Node*& left, Node*& right) {
    (void)root;
    (void)key;
    left = nullptr;
    right = nullptr;
    // TODO
}

Node* merge(Node* left, Node* right) {
    (void)right;
    return left;  // TODO
}

void insert(Node*& root, int key, unsigned int priority) {
    (void)root;
    (void)key;
    (void)priority;
    // TODO
}

bool erase(Node*& root, int key) {
    (void)root;
    (void)key;
    return false;  // TODO
}

void destroy(Node*& root) {
    (void)root;
    // TODO
}

}  // namespace treap
