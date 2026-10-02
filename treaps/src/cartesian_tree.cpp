#include "cartesian_tree.h"

namespace treap {

bool contains(const Node* /*root*/, int /*key*/) {
    return false;  // TODO
}

void split(Node* /*root*/, int /*key*/, Node*& left, Node*& right) {
    left = nullptr;
    right = nullptr;
    // TODO
}

Node* merge(Node* left, Node* /*right*/) {
    return left;  // TODO
}

Node* insert(Node* root, int /*key*/, unsigned int /*priority*/) {
    return root;  // TODO
}

Node* erase(Node* root, int /*key*/) {
    return root;  // TODO
}

void destroy(Node* /*root*/) {
    // TODO
}

}  // namespace treap
