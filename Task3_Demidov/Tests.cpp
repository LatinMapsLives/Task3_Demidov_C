#include "RedBlackTree.h"
#include "Tests.h"
#include <iostream>
#include <string>

void testInt() {
    std::cout << "=== Тест с числами ===" << std::endl;
    RedBlackTree<int> tree;

    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);

    std::cout << "Элементы дерева: ";
    tree.print();

    std::cout << "Содержит 40: " << (tree.has(40) ? "Да" : "Нет") << std::endl;
    std::cout << "Содержит 90: " << (tree.has(90) ? "Да" : "Нет") << std::endl;
    std::cout << std::endl;
}

void testString() {
    std::cout << "=== Тест с автомобилями ===" << std::endl;
    RedBlackTree<std::string> tree;

    tree.add("BMW");
    tree.add("Audi");
    tree.add("Mercedes");
    tree.add("Toyota");
    tree.add("Honda");
    tree.add("Ford");

    std::cout << "Марки автомобилей: ";
    tree.print();

    std::cout << "Есть Audi: " << (tree.has("Audi") ? "Да" : "Нет") << std::endl;
    std::cout << "Есть Ferrari: " << (tree.has("Ferrari") ? "Да" : "Нет") << std::endl;
    std::cout << std::endl;
}

void testSpecialCases() {
    std::cout << "=== Граничные случаи ===" << std::endl;

    RedBlackTree<int> emptyTree;
    std::cout << "Пустое дерево содержит 5: " << (emptyTree.has(5) ? "Да" : "Нет") << std::endl;

    std::cout << "Добавляем число 10" << std::endl;
    emptyTree.add(10);
    std::cout << "Содержит число 10: " << (emptyTree.has(10) ? "Да" : "Нет") << std::endl;

    std::cout << "Добавляем числа 100, 90, 80, 70" << std::endl;
    RedBlackTree<int> reverseTree;
    reverseTree.add(100);
    reverseTree.add(90);
    reverseTree.add(80);
    reverseTree.add(70);

    std::cout << "Обратный порядок: ";
    reverseTree.print();
}