#include <iostream>
#include "include/array.h"
#include "include/pentagon.h"
#include "include/hexagon.h"
#include "include/octagon.h"

void printMenu() {
    std::cout << "\n=== MENU ===\n"
              << "1. Add Pentagon\n"
              << "2. Add Hexagon\n"
              << "3. Add Octagon\n"
              << "4. Remove Figure by index\n"
              << "5. Print all figures\n"
              << "6. Total area\n"
              << "7. Exit\n"
              << "============\n"
              << "Choose option: ";
}

int main() {
    Array arr;
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            auto *p = new Pentagon();
            std::cout << "Enter 5 points (x y):\n";
            std::cin >> *p;
            if (!p->isCorrect()) {
                std::cout << "Invalid pentagon!\n";
                delete p;
            } else {
                arr.push_back(p);
                std::cout << "Pentagon added.\n";
            }
        }
        else if (choice == 2) {
            auto *h = new Hexagon();
            std::cout << "Enter 6 points (x y):\n";
            std::cin >> *h;
            if (!h->isCorrect()) {
                std::cout << "Invalid hexagon!\n";
                delete h;
            } else {
                arr.push_back(h);
                std::cout << "Hexagon added.\n";
            }
        }
        else if (choice == 3) {
            auto *o = new Octagon();
            std::cout << "Enter 8 points (x y):\n";
            std::cin >> *o;
            if (!o->isCorrect()) {
                std::cout << "Invalid octagon!\n";
                delete o;
            } else {
                arr.push_back(o);
                std::cout << "Octagon added.\n";
            }
        }
        else if (choice == 4) {
            if (arr.empty()) {
                std::cout << "Array is empty!\n";
                continue;
            }
            size_t idx;
            std::cout << "Enter index: ";
            std::cin >> idx;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid index input!\n";
                continue;
            }
            try {
                arr.remove(idx);
                std::cout << "Removed.\n";
            } catch (...) {
                std::cout << "Invalid index.\n";
            }
        }
        else if (choice == 5) {
            if (arr.empty()) {
                std::cout << "No figures to print.\n";
            } else {
                arr.printAll();
            }
        }
        else if (choice == 6) {
            std::cout << "Total area: " << arr.totalArea() << "\n";
        }
        else if (choice == 7) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Unknown command!\n";
        }
    }

    return 0;
}
