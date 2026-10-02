#include "implicit_cartesian_tree.h"

#include <stdexcept>

// TODO: дополните вершину полями value, priority, left, right,
// subtree_size, subtree_sum и reversed.
struct ImplicitCartesianTree::Node {
};

ImplicitCartesianTree::ImplicitCartesianTree(unsigned int seed)
    : root_(nullptr), random_state_(seed) {
}

ImplicitCartesianTree::~ImplicitCartesianTree() {
    clear();
}

bool ImplicitCartesianTree::empty() const {
    return root_ == nullptr;
}

int ImplicitCartesianTree::size() const {
    return node_size(root_);
}

void ImplicitCartesianTree::insert(int index, int value) {
    (void)index;
    (void)value;
    // TODO
}

int ImplicitCartesianTree::erase(int index) {
    (void)index;
    return 0;  // TODO
}

int ImplicitCartesianTree::at(int index) {
    (void)index;
    return 0;  // TODO
}

long long ImplicitCartesianTree::range_sum(int left, int right) {
    (void)left;
    (void)right;
    return 0;  // TODO
}

void ImplicitCartesianTree::reverse(int left, int right) {
    (void)left;
    (void)right;
    // TODO
}

std::vector<int> ImplicitCartesianTree::values() {
    return {};  // TODO
}

void ImplicitCartesianTree::clear() {
    // TODO
}

unsigned int ImplicitCartesianTree::next_priority() {
    (void)random_state_;
    return 0;  // TODO: сгенерировать новый псевдослучайный приоритет
}

int ImplicitCartesianTree::node_size(const Node* tree) {
    (void)tree;
    return 0;  // TODO
}

long long ImplicitCartesianTree::node_sum(const Node* tree) {
    (void)tree;
    return 0;  // TODO
}

void ImplicitCartesianTree::update(Node* tree) {
    (void)tree;
    // TODO
}

void ImplicitCartesianTree::push(Node* tree) {
    (void)tree;
    // TODO
}

void ImplicitCartesianTree::split(Node* tree, int left_count, Node*& left, Node*& right) {
    (void)tree;
    (void)left_count;
    left = nullptr;
    right = nullptr;
    // TODO
}

ImplicitCartesianTree::Node* ImplicitCartesianTree::merge(Node* left, Node* right) {
    (void)left;
    (void)right;
    return nullptr;  // TODO
}

void ImplicitCartesianTree::collect_values(Node* tree, std::vector<int>& result) {
    (void)tree;
    (void)result;
    // TODO
}

void ImplicitCartesianTree::destroy(Node* tree) {
    (void)tree;
    // TODO
}

void ImplicitCartesianTree::check_index(int index, int size) {
    (void)index;
    (void)size;
    // TODO
}

void ImplicitCartesianTree::check_range(int left, int right, int size) {
    (void)left;
    (void)right;
    (void)size;
    // TODO
}
