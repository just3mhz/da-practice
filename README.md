# Практические занятия

Каждое занятие лежит в собственном каталоге и является самостоятельным CMake-проектом.

## Занятия

- [`treaps/`](treaps/) — декартово дерево и неявное декартово дерево.
- [`red_black_trees/`](red_black_trees/) — красно-чёрное дерево.

В ветке `main` находятся материалы для студентов. Эталонная реализация декартовых деревьев хранится в ветке `codex/treap-solution`.

## Проверка занятия

```bash
cmake -S treaps -B build/treaps
cmake --build build/treaps
ctest --test-dir build/treaps --output-on-failure
```

На `main` тесты собираются и ожидаемо падают на заглушках. В ветке решения те же тесты должны проходить полностью.

Для красно-чёрного дерева команды аналогичны:

```bash
cmake -S red_black_trees -B build/red_black_trees
cmake --build build/red_black_trees
ctest --test-dir build/red_black_trees --output-on-failure
```
