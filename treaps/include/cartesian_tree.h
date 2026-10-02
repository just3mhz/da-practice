#ifndef CARTESIAN_TREE_H
#define CARTESIAN_TREE_H

#include <vector>

class CartesianTree {
public:
    explicit CartesianTree(unsigned int seed = 123456789u);
    ~CartesianTree();

    CartesianTree(const CartesianTree&) = delete;
    CartesianTree& operator=(const CartesianTree&) = delete;

    bool empty() const;
    int size() const;
    bool contains(int key) const;

    // Возвращает true, если новый ключ был добавлен.
    bool insert(int key);

    // Возвращает true, если ключ был найден и удалён.
    bool erase(int key);

    // Возвращает все ключи по возрастанию.
    std::vector<int> values() const;

    void clear();

private:
    struct Node;

    Node* root_;
    int size_;
    unsigned int random_state_;

    unsigned int next_priority();
    static void split(Node* tree, int key, Node*& left, Node*& right);
    static Node* merge(Node* left, Node* right);
    static Node* erase_node(Node* tree, int key, bool& erased);
    static void collect_values(const Node* tree, std::vector<int>& result);
    static void destroy(Node* tree);
};

#endif
