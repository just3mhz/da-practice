#pragma once

namespace implicit_treap {

struct Node {
    int value;
    unsigned int priority;
    Node* left = nullptr;
    Node* right = nullptr;
    int subtree_size = 1;
    long long subtree_sum;
    bool reversed = false;

    Node(int value, unsigned int priority)
        : value(value), priority(priority), subtree_sum(value) {
    }
};

int size(const Node* root);
long long sum(const Node* root);
void update(Node* root);
void push(Node* root);

// Первые left_count элементов переходят в left, остальные — в right.
void split(Node* root, int left_count, Node*& left, Node*& right);
Node* merge(Node* left, Node* right);

// Требование: 0 <= index <= size(root).
Node* insert(Node* root, int index, int value, unsigned int priority);

// Требование: 0 <= index < size(root).
int at(Node* root, int index);
Node* erase(Node* root, int index);

// Требование: 0 <= left <= right <= size(root).
long long range_sum(Node* root, int left, int right);
Node* reverse(Node* root, int left, int right);

void destroy(Node* root);

}  // namespace implicit_treap
