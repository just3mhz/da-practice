#include "cartesian_tree.h"
#include "test_support.h"

void test_cartesian_tree() {
    std::cout << "CartesianTree\n";

    // constructor, empty(), size(), values()
    CartesianTree tree(42);
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
    EXPECT_EMPTY_VECTOR(tree.values());

    // insert(), contains(): порядок вставки не должен влиять на порядок ключей.
    EXPECT_TRUE(tree.insert(5));
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(8));
    EXPECT_TRUE(tree.insert(-3));
    EXPECT_FALSE(tree.empty());
    EXPECT_EQ(tree.size(), 4);
    EXPECT_TRUE(tree.contains(2));
    EXPECT_FALSE(tree.contains(7));
    EXPECT_VECTOR(tree.values(), -3, 2, 5, 8);

    // insert(): одинаковые ключи не хранятся дважды.
    EXPECT_FALSE(tree.insert(5));
    EXPECT_EQ(tree.size(), 4);
    EXPECT_VECTOR(tree.values(), -3, 2, 5, 8);

    // erase(): удаление существующего и отсутствующего ключа.
    EXPECT_TRUE(tree.erase(5));
    EXPECT_FALSE(tree.contains(5));
    EXPECT_EQ(tree.size(), 3);
    EXPECT_VECTOR(tree.values(), -3, 2, 8);
    EXPECT_FALSE(tree.erase(100));
    EXPECT_EQ(tree.size(), 3);

    // erase(): дерево остаётся рабочим после удаления всех элементов.
    EXPECT_TRUE(tree.erase(-3));
    EXPECT_TRUE(tree.erase(8));
    EXPECT_TRUE(tree.erase(2));
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);

    // clear(): очищает дерево и допускает повторное использование.
    tree.insert(10);
    tree.insert(20);
    tree.clear();
    EXPECT_TRUE(tree.empty());
    EXPECT_EQ(tree.size(), 0);
    EXPECT_EMPTY_VECTOR(tree.values());
    tree.clear();
    EXPECT_TRUE(tree.insert(15));
    EXPECT_TRUE(tree.contains(15));

    // destructor: выход из области видимости проверяется также санитайзером.
    {
        CartesianTree temporary;
        temporary.insert(1);
        temporary.insert(2);
    }
}
