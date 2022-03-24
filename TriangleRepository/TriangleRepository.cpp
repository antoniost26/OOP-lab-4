//
// Created by Antonio on 3/24/2022.
//

#include "TriangleRepository.h"

void TriangleRepository::resize() {
    auto* newTriangles = new Triangle[this->capacity*2];
    for (int i=0; i < length; i++) {
        newTriangles[i] = this->triangles[i];
    }
    this->capacity*=2;
    delete[] this->triangles;
    this->triangles = newTriangles;
}

TriangleRepository::TriangleRepository(TriangleRepository &tr) {
    this->capacity = tr.capacity;
    this->triangles = new Triangle[tr.getLength()];
    this->length = tr.getLength();
    this->triangles = tr.triangles;
}

int TriangleRepository::getLength() {
    return this->length;
}

void TriangleRepository::add(Triangle t) {
    if (length == capacity) {
        this->resize();
    }

    triangles[length++] = t;
}

int TriangleRepository::remove(Triangle t) {
    int pos = search(t);
    if (pos > -1) {
        for (int i = pos; i < length-1; i++) {
            this->triangles[i] = this->triangles[i+1];
        }
        length--;
        return 1;
    }
    return 0;
}

int TriangleRepository::search(Triangle t) {
    for (int i=0; i<length; i++) {
        if (this->triangles[i] == t) {
            return i;
        }
    }
    return -1;
}

bool TriangleRepository::ifExist(Triangle t) {
    if (this->search(t) > -1) {
        return true;
    }
    return false;
}

Triangle TriangleRepository::getTriangle(int position) {
    return (position >=0 && position < length)
    ?this->triangles[position]
    :throw std::invalid_argument("Position must be lower than length and greater or equal to 0.");
}

TriangleRepository::~TriangleRepository() {
    delete[] this->triangles;
}

TriangleRepository::TriangleRepository() {
        this->capacity = 10;
        this->triangles = new Triangle[capacity];
        this->length = 0;
}
