//
// Created by Antonio on 3/24/2022.
//

#include "IOModules.h"
#include <iostream>
#include <conio.h>

void wait() {
    std::cout << "Press any key to continue...";
    getch();
}

int read() {
    int x;
    std::cin >> x;
    return x;
}

void readTriangles(TriangleRepository &tr) {
    std::cout << "Introduceti numarul elementelor pe care doriti sa le adaugati: ";
    int length = read();

    for (int i = 0; i < length; i++) {
        Triangle t;
        std::cin >> t;
        tr.add(t);
    }
}

void printTriangles(MAP triangles, int position) {
    if (position >= 0) {
        try {
            Triangle ABC = triangles.at(position);
            std::cout << position << ") " << ABC << "\n";
        }
        catch (std::out_of_range &e) {
            std::cerr << "Nu exista nici un triunghi pentru indexul dat!" << "\n";
        }

    } else {
        if (!triangles.empty()) {
            for (auto &it : triangles) {
                Triangle ABC = it.second;
                std::cout << it.first << ") " << it.second << "\n";
            }
        } else {
            std::cout << "Nu exista niciun element!\n";
        }
    }
    wait();
}

void printLargestTriangle(TriangleRepository tr) {
    Triangle ABC = tr.getLargestTriangle();
    std::cout << ABC << '\n';
    wait();
}

void printTrianglesInFirstQuadrant(TriangleRepository tr) {
    std::cout << "Triunghiurile in primul cadran sunt: \n";
    printTriangles(tr.getTrianglesInFirstQuadrant());
}

void printTrianglesFromRepository(TriangleRepository tr) {
    std::cout << "Sirul triughirilor este: \n";
    printTriangles(tr.getTriangles(), -1);
}

void printTriangleFromRepository(TriangleRepository tr) {
    std::cout << "Dati indexul triunghiului: ";
    int position = read();
    printTriangles(tr.getTriangles(), position);
}

void printLongestEqualTriangleSequence(TriangleRepository tr) {
    printTriangles(tr.getLongestSequenceOfEqualTriangles());
}
