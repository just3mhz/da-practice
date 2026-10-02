#ifndef IMPLICIT_CARTESIAN_TREE_H
#define IMPLICIT_CARTESIAN_TREE_H

#include <vector>

class ImplicitCartesianTree {
public:
    explicit ImplicitCartesianTree(unsigned int seed = 987654321u);
    ~ImplicitCartesianTree();

    ImplicitCartesianTree(const ImplicitCartesianTree&) = delete;
    ImplicitCartesianTree& operator=(const ImplicitCartesianTree&) = delete;

    bool empty() const;
    int size() const;

    // Допустимы позиции от 0 до size() включительно.
    // Для остальных позиций бросает std::out_of_range.
    void insert(int index, int value);

    // Удаляет элемент и возвращает его значение.
    // Для индекса вне [0, size()) бросает std::out_of_range.
    int erase(int index);

    // Для индекса вне [0, size()) бросает std::out_of_range.
    int at(int index);

    // Сумма на полуинтервале [left, right). Пустой отрезок разрешён.
    // Для left < 0, left > right или right > size() бросает std::out_of_range.
    long long range_sum(int left, int right);

    // Разворот полуинтервала [left, right). Пустой отрезок разрешён.
    // Для left < 0, left > right или right > size() бросает std::out_of_range.
    void reverse(int left, int right);

    std::vector<int> values();
    void clear();

private:
    struct Node;

    Node* root_;
    unsigned int random_state_;

    unsigned int next_priority();
    static int node_size(const Node* tree);
    static long long node_sum(const Node* tree);
    static void update(Node* tree);
    static void push(Node* tree);
    static void split(Node* tree, int left_count, Node*& left, Node*& right);
    static Node* merge(Node* left, Node* right);
    static void collect_values(Node* tree, std::vector<int>& result);
    static void destroy(Node* tree);
    static void check_index(int index, int size);
    static void check_range(int left, int right, int size);
};

#endif
