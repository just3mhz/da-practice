#include "implicit_cartesian_tree.h"

namespace implicit_treap {

Node::Node(int node_value, unsigned int node_priority)
    : value(0),
      priority(0),
      left(nullptr),
      right(nullptr),
      subtree_size(0),
      subtree_sum(0),
      reversed(false) {
    (void)node_value;
    (void)node_priority;
    // TODO: сохранить value, priority и агрегаты одиночной вершины.
}

int size(const Node* root) {
    (void)root;
    return 0;  // TODO
}

long long sum(const Node* root) {
    (void)root;
    return 0;  // TODO
}

void update(Node* root) {
    (void)root;
    // TODO
}

void push(Node* root) {
    (void)root;
    // TODO
}

void split(Node* root, int left_count, Node*& left, Node*& right) {
    (void)root;
    (void)left_count;
    left = nullptr;
    right = nullptr;
    // TODO
}

Node* merge(Node* left, Node* right) {
    (void)right;
    return left;  // TODO
}

void insert(Node*& root, int index, int value, unsigned int priority) {
    (void)root;
    (void)index;
    (void)value;
    (void)priority;
    // TODO
}

int at(Node* root, int index) {
    (void)root;
    (void)index;
    return 0;  // TODO
}

int erase(Node*& root, int index) {
    (void)root;
    (void)index;
    return 0;  // TODO
}

long long range_sum(Node*& root, int left, int right) {
    (void)root;
    (void)left;
    (void)right;
    return 0;  // TODO
}

void reverse(Node*& root, int left, int right) {
    (void)root;
    (void)left;
    (void)right;
    // TODO
}

void destroy(Node*& root) {
    (void)root;
    // TODO
}

}  // namespace implicit_treap
