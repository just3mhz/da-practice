# Декартово дерево и неявное декартово дерево

Проект разбит на небольшие этапы. После каждого этапа можно запустить только относящийся к нему тест. Следующий тест предполагает, что предыдущие этапы уже реализованы.

В интерфейсе нет владеющих классов, генераторов случайных чисел и сложных правил копирования. Корень — обычный указатель `Node*`, приоритет передаётся явно, алгоритмы оформлены свободными функциями.

## Сборка

```bash
cmake -S . -B build
cmake --build build
```

При первом запуске CMake скачает GoogleTest 1.18.0 и проверит SHA-256 архива. Следующие сборки используют локальный кэш каталога `build`.

Все тесты собираются в один исполняемый файл. GoogleTest регистрирует каждый этап в CTest отдельно. Запуск одного этапа:

```bash
ctest --test-dir build -R Ordinary02 --output-on-failure
```

Запуск всех уже написанных этапов, например первых трёх:

```bash
ctest --test-dir build -R "Ordinary0[1-3]" --output-on-failure
```

## Обычное декартово дерево

| Этап | Что реализовать | Команда |
| --- | --- | --- |
| 1 | `Node`, `contains`, `destroy` | `ctest --test-dir build -R Ordinary01` |
| 2 | `split` | `ctest --test-dir build -R Ordinary02` |
| 3 | `merge` | `ctest --test-dir build -R Ordinary03` |
| 4 | `insert` | `ctest --test-dir build -R Ordinary04` |
| 5 | `erase` | `ctest --test-dir build -R Ordinary05` |

Инварианты: дерево поиска по `key`, max-куча по `priority`. Повторная вставка ключа ничего не меняет.

## Неявное декартово дерево

| Этап | Что реализовать | Команда |
| --- | --- | --- |
| 1 | `Node`, `size`, `sum`, `update`, `destroy` | `ctest --test-dir build -R Implicit01` |
| 2 | `split` | `ctest --test-dir build -R Implicit02` |
| 3 | `merge` | `ctest --test-dir build -R Implicit03` |
| 4 | `insert`, `at` | `ctest --test-dir build -R Implicit04` |
| 5 | `erase` | `ctest --test-dir build -R Implicit05` |
| 6 | `range_sum` | `ctest --test-dir build -R Implicit06` |
| 7 | `push`, `reverse` | `ctest --test-dir build -R Implicit07` |

Все индексы в тестах корректны. Отрезки полуинтервальные: `[left, right)`. Например, `[1, 4)` содержит позиции `1`, `2`, `3`.

## Владение памятью

- каждый созданный узел принадлежит ровно одному дереву;
- `split` возвращает структуру с двумя новыми корнями;
- `merge` собирает два дерева в одно;
- старый корень после `split` и отдельные корни после `merge` использовать нельзя;
- в конце вызовите `destroy(root)`, чтобы удалить все узлы.

Для дополнительной проверки памяти:

```bash
cmake -S . -B build-asan -DENABLE_SANITIZERS=ON
cmake --build build-asan
ctest --test-dir build-asan --output-on-failure
```
