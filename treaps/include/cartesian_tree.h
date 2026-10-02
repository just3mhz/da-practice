#pragma once

namespace treap {

struct Node {
    int key;
    unsigned int priority;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int key, unsigned int priority) : key(key), priority(priority) {
    }
};

bool contains(const Node* root, int key);

struct SplitResult {
    Node* left = nullptr;
    Node* right = nullptr;
};

// Делит дерево на ключи < key и ключи >= key.
// Владение всеми узлами переходит к полям результата.
SplitResult split(Node* root, int key);

// Требование: все ключи left меньше всех ключей right.
Node* merge(Node* left, Node* right);

// Одинаковые ключи второй раз не добавляются.
Node* insert(Node* root, int key, unsigned int priority);

// Если ключа нет, возвращает прежний корень.
Node* erase(Node* root, int key);

void destroy(Node* root);

}  // namespace treap
