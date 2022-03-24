//
// Created by Antonio on 3/24/2022.
//

#ifndef LAB4_IOMODULES_H
#define LAB4_IOMODULES_H

#include "../classes/Triangle.h"
#include "../TriangleRepository/TriangleRepository.h"

/**
 * Reads and integer and returns it.
 * @return: The read integer.
 */
int read();

/**
 * Prints all triangles inside a TriangleRepository.
 * @param tr: A Reference to a TriangleRepository.
 */
void printTriangles(TriangleRepository &tr, int position = -1);

/**
 * Adds as many triangles as the user needs to TriangleRepository.
 * @param tr: A TriangleRepository reference.
 * @param length: A constant giving how many triangles should be added to TriangleRepository.
 */
void readTriangles(TriangleRepository &tr, int length);
#endif //LAB4_IOMODULES_H
