//
// Created by Antonio on 3/24/2022.
//

#include <iostream>
#include "menu.h"
#include "../TriangleRepository/TriangleRepository.h"
#include "../UIModules/IOModules.h"

void showMenu() {
    std::cout << "--Main Menu--\n";
    std::cout << "Selecteaza una dintre urmatoarele:\n";
    std::cout << "1 - Citirea sirului de triunghiuri.\n";
    std::cout << "2 - Afisarea sirului de triunghiuri.\n";
    std::cout << "3 - Afisarea unui triunghiu pentru un index dat.\n";
    std::cout << "4 - Afisarea celui mai mare triunghi (in functie de arie).\n";
    std::cout << "5 - Afisarea tuturor triunghiurilor situate in cadranul 1.\n";
    std::cout << "6 - Afisarea celei mai lungi secvente de triunghiuri egale.\n";
    std::cout << "0 - Iesire\n";
    std::cout << "Selectie: ";
}

void runMenu() {
    int choice;
    TriangleRepository tr;
    do {
        showMenu();
        choice = read();
        switch (choice) {
            case 1: {
                readTriangles(tr);
                break;
            }
            case 2: {
                printTrianglesFromRepository(tr);
                break;
            }
            case 3: {
                printTriangleFromRepository(tr);
                break;
            }
            case 4: {
                printLargestTriangle(tr);
                break;
            }
            case 5: {
                printTrianglesInFirstQuadrant(tr);
                break;
            }
            case 6: {
                printLongestEqualTriangleSequence(tr);
                break;
            }
            case 0:
                std::cout << "Iesire..";
                break;
            default:
                std::cout << "Optiune gresita, reincercati. \n";
                break;
        }
    } while (choice != 0);
}