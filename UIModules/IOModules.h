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
 * Print triangles from a given map<int, Triangle>.
 * @param triangles: A map<int, Triangle>.
 * @param position: A given position in map.
 */
void printTriangles(MAP triangles, int position = -1);

/**
 * Adds as many triangles as the user needs to TriangleRepository.
 * @param tr: A TriangleRepository reference.
 * @param length: A constant giving how many triangles should be added to TriangleRepository.
 */
void readTriangles(TriangleRepository &tr);

/**
 * Gets and prints largest triangle from a TriangleRepository.
 * @param tr: A TriangleRepository.
 */
void printLargestTriangle(TriangleRepository tr);

/**
 * Gets and prints all triangles in first quadron.
 * @param tr: A TriangleRepository.
 */
void printTrianglesInFirstQuadrant(TriangleRepository tr);

/**
 * Prints a triangle from a given index in the TriangleRepository.
 * @param tr: A TriangleRepository.
 */
void printTriangleFromRepository(TriangleRepository tr);

/**
 * Waits until user enters an input.
 */
void wait();

/**
 * Prints triangles from a TriangleRepository.
 * @param tr: A TriangleRepository.
 * @param position: *optional* a given position of triangle.
 */
void printTrianglesFromRepository(TriangleRepository tr);

/**
 * Prints longest sequence of equal triangles from a repository.
 * @param tr: A TriangleRepository.
 */
void printLongestEqualTriangleSequence(TriangleRepository tr);

#endif //LAB4_IOMODULES_H
