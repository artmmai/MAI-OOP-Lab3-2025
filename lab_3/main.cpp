#include <iostream>
#include "include/array.h"
#include "include/pentagon.h"
#include "include/hexagon.h"
#include "include/octagon.h"

int main() {
    Array figures;

    // === Создание фигур и добавление в массив ===
    Pentagon* p1 = new Pentagon();
    Hexagon* h1 = new Hexagon();
    Octagon* o1 = new Octagon();

    std::cout << "Введите координаты 5 вершин Pentagon:" << std::endl;
    std::cin >> *p1;

    std::cout << "Введите координаты 6 вершин Hexagon:" << std::endl;
    std::cin >> *h1;

    std::cout << "Введите координаты 8 вершин Octagon:" << std::endl;
    std::cin >> *o1;

    figures.push_back(p1);
    figures.push_back(h1);
    figures.push_back(o1);

    // === Вывод всех фигур ===
    std::cout << "\nВсе фигуры в массиве:\n";
    figures.printAll();

    // === Удаление фигуры по индексу ===
    std::cout << "\nУдаляем фигуру с индексом 1 (Hexagon)...\n";
    figures.remove(1);

    std::cout << "\nФигуры после удаления:\n";
    figures.printAll();

    // === Вычисление общей площади ===
    double total = figures.totalArea();
    std::cout << "\nОбщая площадь всех фигур: " << total << std::endl;

    // === Очистка массива ===
    figures.clear();

    std::cout << "\nМассив очищен. Размер: " << figures.getSize() << std::endl;

    return 0;
}
