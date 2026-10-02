#include "implicit_cartesian_tree.h"
#include "test_support.h"

#include <climits>

void test_implicit_cartesian_tree() {
    std::cout << "ImplicitCartesianTree\n";

    // constructor, empty(), size(), values()
    ImplicitCartesianTree sequence(42);
    EXPECT_TRUE(sequence.empty());
    EXPECT_EQ(sequence.size(), 0);
    EXPECT_EMPTY_VECTOR(sequence.values());

    // insert(): вставка в начало, середину и конец.
    sequence.insert(0, 10);       // [10]
    sequence.insert(1, 30);       // [10, 30]
    sequence.insert(1, 20);       // [10, 20, 30]
    sequence.insert(0, 5);        // [5, 10, 20, 30]
    EXPECT_FALSE(sequence.empty());
    EXPECT_EQ(sequence.size(), 4);
    EXPECT_VECTOR(sequence.values(), 5, 10, 20, 30);
    EXPECT_OUT_OF_RANGE(sequence.insert(-1, 0));
    EXPECT_OUT_OF_RANGE(sequence.insert(5, 0));
    EXPECT_VECTOR(sequence.values(), 5, 10, 20, 30);

    // at(): чтение всех позиций и проверка неверных индексов.
    EXPECT_EQ(sequence.at(0), 5);
    EXPECT_EQ(sequence.at(2), 20);
    EXPECT_EQ(sequence.at(3), 30);
    EXPECT_OUT_OF_RANGE(sequence.at(-1));
    EXPECT_OUT_OF_RANGE(sequence.at(4));

    // range_sum(): весь массив, часть массива и пустой отрезок.
    EXPECT_EQ(sequence.range_sum(0, 4), 65LL);
    EXPECT_EQ(sequence.range_sum(1, 3), 30LL);
    EXPECT_EQ(sequence.range_sum(2, 2), 0LL);
    EXPECT_OUT_OF_RANGE(sequence.range_sum(-1, 2));
    EXPECT_OUT_OF_RANGE(sequence.range_sum(3, 2));
    EXPECT_OUT_OF_RANGE(sequence.range_sum(0, 5));

    // reverse(): обычный, пустой и полный отрезки.
    sequence.reverse(1, 4);       // [5, 30, 20, 10]
    EXPECT_VECTOR(sequence.values(), 5, 30, 20, 10);
    EXPECT_EQ(sequence.range_sum(1, 3), 50LL);
    sequence.reverse(2, 2);
    EXPECT_VECTOR(sequence.values(), 5, 30, 20, 10);
    sequence.reverse(0, 4);       // [10, 20, 30, 5]
    EXPECT_VECTOR(sequence.values(), 10, 20, 30, 5);
    EXPECT_OUT_OF_RANGE(sequence.reverse(-1, 2));
    EXPECT_OUT_OF_RANGE(sequence.reverse(3, 2));
    EXPECT_OUT_OF_RANGE(sequence.reverse(2, 5));

    // Ленивый разворот должен учитываться до полного обхода values().
    ImplicitCartesianTree lazy_sequence(17);
    lazy_sequence.insert(0, 1);
    lazy_sequence.insert(1, 2);
    lazy_sequence.insert(2, 3);
    lazy_sequence.insert(3, 4);
    lazy_sequence.reverse(0, 4);       // [4, 3, 2, 1]
    EXPECT_EQ(lazy_sequence.range_sum(0, 2), 7LL);
    EXPECT_EQ(lazy_sequence.at(0), 4);
    lazy_sequence.reverse(1, 4);       // [4, 1, 2, 3]
    lazy_sequence.insert(2, 9);        // [4, 1, 9, 2, 3]
    EXPECT_EQ(lazy_sequence.erase(3), 2);
    EXPECT_VECTOR(lazy_sequence.values(), 4, 1, 9, 3);

    // Сумма действительно хранится в long long, а не в int.
    ImplicitCartesianTree large_values;
    large_values.insert(0, INT_MAX);
    large_values.insert(1, INT_MAX);
    large_values.insert(2, -INT_MAX);
    EXPECT_EQ(large_values.range_sum(0, 2), 4294967294LL);
    EXPECT_EQ(large_values.range_sum(0, 3), 2147483647LL);

    // erase(): возвращает удалённое значение и склеивает оставшиеся части.
    EXPECT_EQ(sequence.erase(1), 20);
    EXPECT_VECTOR(sequence.values(), 10, 30, 5);
    EXPECT_EQ(sequence.erase(2), 5);
    EXPECT_VECTOR(sequence.values(), 10, 30);
    EXPECT_OUT_OF_RANGE(sequence.erase(-1));
    EXPECT_OUT_OF_RANGE(sequence.erase(2));

    // clear(): очищает дерево и допускает повторное использование.
    sequence.clear();
    EXPECT_TRUE(sequence.empty());
    EXPECT_EQ(sequence.size(), 0);
    EXPECT_EMPTY_VECTOR(sequence.values());
    sequence.clear();
    sequence.insert(0, 99);
    EXPECT_EQ(sequence.at(0), 99);

    // destructor: выход из области видимости проверяется также санитайзером.
    {
        ImplicitCartesianTree temporary;
        temporary.insert(0, 1);
        temporary.insert(1, 2);
    }
}
