//
// Created by Antonio on 3/24/2022.
//

#include "IOModules.h"
#include <iostream>

int read() {
    int x;
    std::cin >> x;
    return x;
}

void readTriangles(TriangleRepository &tr, int length) {
    for (int i=0; i<length; i++) {
        Triangle t;
        std::cin >> t;
        tr.add(t);
    }
}

void printTriangles(TriangleRepository &tr, int position) {
    if (position >= 0) {
        try {
            Triangle ABC = tr.getTriangle(position);
            std::cout << position+1 << ") " << ABC << "\n";
        }
        catch (std::invalid_argument& e) {
            std::cerr << e.what() << "\n";
        };
    } else {
        for (int i = 0; i < tr.getLength(); i++) {
            Triangle ABC = tr.getTriangle(i);
            std::cout << i+1 << ") " << ABC << "\n";
        }
    }
}