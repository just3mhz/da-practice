#ifndef CARTESIAN_TREE_H
#define CARTESIAN_TREE_H

namespace treap {

struct Node {
    int key;
    unsigned int priority;
    Node* left;
    Node* right;

    Node(int key, unsigned int priority);
};

bool contains(const Node* root, int key);

// Делит дерево на ключи < key и ключи >= key.
// Владение всеми узлами переходит к left и right.
void split(Node* root, int key, Node*& left, Node*& right);

// Требование: все ключи left меньше всех ключей right.
Node* merge(Node* left, Node* right);

// Одинаковые ключи второй раз не добавляются.
void insert(Node*& root, int key, unsigned int priority);

// Возвращает true, если ключ был найден и удалён.
bool erase(Node*& root, int key);

// Удаляет все узлы и записывает в root nullptr.
void destroy(Node*& root);

}  // namespace treap

#endif
