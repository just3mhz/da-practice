#include "cartesian_tree.h"

// TODO: дополните вершину полями key, priority, left и right.
struct CartesianTree::Node {
};

CartesianTree::CartesianTree(unsigned int seed)
    : root_(nullptr), size_(0), random_state_(seed) {
}

CartesianTree::~CartesianTree() {
    clear();
}

bool CartesianTree::empty() const {
    return root_ == nullptr;
}

int CartesianTree::size() const {
    return size_;
}

bool CartesianTree::contains(int key) const {
    (void)key;
    return false;  // TODO
}

bool CartesianTree::insert(int key) {
    (void)key;
    return false;  // TODO
}

bool CartesianTree::erase(int key) {
    (void)key;
    return false;  // TODO
}

std::vector<int> CartesianTree::values() const {
    return {};  // TODO
}

void CartesianTree::clear() {
    // TODO
}

unsigned int CartesianTree::next_priority() {
    (void)random_state_;
    return 0;  // TODO: сгенерировать новый псевдослучайный приоритет
}

void CartesianTree::split(Node* tree, int key, Node*& left, Node*& right) {
    (void)tree;
    (void)key;
    left = nullptr;
    right = nullptr;
    // TODO
}

CartesianTree::Node* CartesianTree::merge(Node* left, Node* right) {
    (void)left;
    (void)right;
    return nullptr;  // TODO
}

CartesianTree::Node* CartesianTree::erase_node(Node* tree, int key, bool& erased) {
    (void)tree;
    (void)key;
    erased = false;
    return nullptr;  // TODO
}

void CartesianTree::collect_values(const Node* tree, std::vector<int>& result) {
    (void)tree;
    (void)result;
    // TODO
}

void CartesianTree::destroy(Node* tree) {
    (void)tree;
    // TODO
}
