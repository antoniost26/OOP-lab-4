//
// Created by Antonio on 3/14/2022.
//

#include "Triangle.h"
#include "../operations/point_operations.h"
#include <cmath>

Triangle::Triangle() {
    this->A = Point();
    this->B = Point();
    this->C = Point();
}

Triangle::Triangle(const Point X, const Point Y, const Point Z) {
    this->A = X;
    this->B = Y;
    this->C = Z;
}

Triangle::Triangle(const Triangle &triangle) {
    this->A = triangle.A;
    this->B = triangle.B;
    this->C = triangle.C;
}

Triangle &Triangle::operator=(const Triangle triangle) {
    if (this!= &triangle){
        this->A = triangle.A;
        this->B = triangle.B;
        this->C = triangle.C;
    }
    return *this;
}

Triangle::~Triangle() = default;

Point Triangle::getA() const {
    return this->A;
}

Point Triangle::getB() const {
    return this->B;
}

Point Triangle::getC() const {
    return this->C;
}

void Triangle::setA(const Point X) {
    this->A = X;
}

void Triangle::setB(const Point Y) {
    this->B = Y;
}

void Triangle::setC(const Point Z) {
    this->C = Z;
}

bool operator==(const Triangle &triangle1, const Triangle &triangle2) {
    return (triangle1.A == triangle2.A && triangle1.B == triangle2.B && triangle1.C == triangle2.C);
}

std::ostream &operator<<(std::ostream &os, Triangle &triangle) {
    os << "Triangle coordinates are A: " << triangle.A << ", B: " << triangle.B << ", C: " << triangle.C;
    return os;
}

std::istream &operator>>(std::istream &is, Triangle &triangle) {
    Point A, B, C;
    std::cout << "A:"; is >> A;
    triangle.A = A;
    std::cout << "B:"; is >> B;
    triangle.B = B;
    std::cout << "C:"; is >> C;
    triangle.C = C;
    return is;
}

double Triangle::getArea() {
    const double a = calculateDistanceBetweenPoints(this->B, this->C);
    const double b = calculateDistanceBetweenPoints(this->A, this->C);
    const double c = calculateDistanceBetweenPoints(this->A, this->B);
    const double semiPerimeter = this->getPerimeter()/2;
    return sqrt(semiPerimeter*(semiPerimeter-a)*(semiPerimeter-b)*(semiPerimeter-c));
}

double Triangle::getPerimeter() {
    const double a = calculateDistanceBetweenPoints(this->B, this->C);
    const double b = calculateDistanceBetweenPoints(this->A, this->C);
    const double c = calculateDistanceBetweenPoints(this->A, this->B);
    return a+b+c;
}
