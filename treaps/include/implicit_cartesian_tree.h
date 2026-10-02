#ifndef IMPLICIT_CARTESIAN_TREE_H
#define IMPLICIT_CARTESIAN_TREE_H

namespace implicit_treap {

struct Node {
    int value;
    unsigned int priority;
    Node* left;
    Node* right;
    int subtree_size;
    long long subtree_sum;
    bool reversed;

    Node(int value, unsigned int priority);
};

int size(const Node* root);
long long sum(const Node* root);
void update(Node* root);
void push(Node* root);

// Первые left_count элементов переходят в left, остальные — в right.
void split(Node* root, int left_count, Node*& left, Node*& right);
Node* merge(Node* left, Node* right);

// Требование: 0 <= index <= size(root).
void insert(Node*& root, int index, int value, unsigned int priority);

// Требование: 0 <= index < size(root).
int at(Node* root, int index);
int erase(Node*& root, int index);

// Требование: 0 <= left <= right <= size(root).
long long range_sum(Node*& root, int left, int right);
void reverse(Node*& root, int left, int right);

// Удаляет все узлы и записывает в root nullptr.
void destroy(Node*& root);

}  // namespace implicit_treap

#endif
