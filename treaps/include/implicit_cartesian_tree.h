#pragma once

namespace implicit_treap {

struct Node {
    int value;
    unsigned int priority;
    Node* left = nullptr;
    Node* right = nullptr;
    int subtree_size = 1;
    bool reversed = false;

    Node(int value, unsigned int priority)
        : value(value), priority(priority) {
    }
};

int size(const Node* root);
void update(Node* root);
void push(Node* root);

struct SplitResult {
    Node* left = nullptr;
    Node* right = nullptr;
};

// Первые left_count элементов переходят в result.left, остальные — в result.right.
SplitResult split(Node* root, int left_count);
Node* merge(Node* left, Node* right);

// Требование: 0 <= index <= size(root).
Node* insert(Node* root, int index, int value, unsigned int priority);

// Требование: 0 <= index < size(root).
int at(Node* root, int index);
Node* erase(Node* root, int index);

// Требование: 0 <= left <= right <= size(root).
Node* reverse(Node* root, int left, int right);

void destroy(Node* root);

}  // namespace implicit_treap
