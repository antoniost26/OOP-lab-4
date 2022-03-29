//
// Created by Antonio on 3/24/2022.
//

#include "TriangleRepository.h"

//void TriangleRepository::resize() {
//    auto* newTriangles = new Triangle[this->capacity*2];
//    for (int i=0; i < length; i++) {
//        newTriangles[i] = this->triangles[i];
//    }
//    this->capacity*=2;
//    delete[] this->triangles;
//    this->triangles = newTriangles;
//}

TriangleRepository::TriangleRepository(TriangleRepository &tr) {
//    this->capacity = tr.capacity;
    for (auto it: tr.triangles) {
        this->triangles.insert(std::pair<int, Triangle>(it.first, it.second));
    }
    this->triangles = tr.triangles;
    this->index = tr.index;
}

unsigned long long TriangleRepository::getSize() {
    return this->triangles.size();
}

void TriangleRepository::add(Triangle t) {
    this->triangles.insert(std::pair<int, Triangle>(index++, t));
}

int TriangleRepository::remove(Triangle t) {
    int pos = search(t);
    if (pos > -1) {
        this->triangles.erase(pos);
        return 1;
    }
    return 0;
}

int TriangleRepository::search(Triangle t) {
    for (auto it: this->triangles) {
        if (it.second == t) {
            return it.first;
        }
    }
    return -1;
}

Triangle TriangleRepository::getTriangle(int position) {
    return this->triangles.at(position);
}

TriangleRepository::TriangleRepository() : triangles{}, index{1} {}

MAP TriangleRepository::getTriangles() {
    return this->triangles;
}

Triangle TriangleRepository::getLargestTriangle() {
    int maxArea = 0, maxIndex = 0;
    for (auto it: this->triangles) {
        if (it.second.getArea() > maxArea) {
            maxArea = it.second.getArea();
            maxIndex = it.first;
        }
    }
    return this->getTriangle(maxIndex);
}

MAP TriangleRepository::getTrianglesInFirstQuadrant() {
    MAP firstQuadrantTriangles;
    for (auto it: this->triangles) {
        if (it.second.getA().isInFirstQuadron() && it.second.getB().isInFirstQuadron() &&
            it.second.getC().isInFirstQuadron()) {
            firstQuadrantTriangles.insert(PAIR(it.first, it.second));
        }
    }
    return firstQuadrantTriangles;
}

MAP TriangleRepository::getLongestSequenceOfEqualTriangles() {
    MAP trianglesSequence, tempTriangles;
    tempTriangles.insert(
            PAIR(this->triangles.begin()->first, this->triangles.begin()->second));
    int lastIndex = this->triangles.begin()->first;

    for (auto it: this->triangles) {
        if (it.first != this->triangles.begin()->first) {
            if (it.second == this->getTriangle(lastIndex)) {
                tempTriangles.insert(PAIR(it.first, it.second));
            } else {
                if (tempTriangles.size() > trianglesSequence.size()) {
                    trianglesSequence.clear();
                    trianglesSequence = tempTriangles;
                }
                tempTriangles.clear();
                tempTriangles.insert(PAIR(it.first, it.second));
            }
            lastIndex = it.first;
        }
    }
    if (tempTriangles.size() > trianglesSequence.size()) {
        trianglesSequence.clear();
        trianglesSequence = tempTriangles;
    }
    return trianglesSequence.size() > 1 ? trianglesSequence : MAP();
}

TriangleRepository::~TriangleRepository() {
    this->triangles.clear();
}
