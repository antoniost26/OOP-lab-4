//
// Created by Antonio on 3/15/2022.
//
#include "tests.h"
#include "../classes/Point.h"
#include "../classes/Triangle.h"
#include "../TriangleRepository/TriangleRepository.h"
#include <cassert>

void testPoints() {
    Point A, B, C;
    A = Point(0, 13);
    B = A;
    C = Point(13, 12);
    assert(A == B);
    assert(!(A == C));

    assert(A.getX() == 0);
    assert(A.getY() == 13);
    A.setX(12.12);
    A.setY(16.13);
    assert(A.getX() == 12.12);
    assert(A.getY() == 16.13);

    assert(B.getX() == 0);
    assert(B.getY() == 13);
    B.setX(124.24);
    B.setY(12.412);
    assert(B.getX() == 124.24);
    assert(B.getY() == 12.412);

    assert(C.getX() == 13);
    assert(C.getY() == 12);
    C.setX(69);
    C.setY(420);
    assert(C.getX() == 69);
    assert(C.getY() == 420);

    Point D = Point();
    assert(D.getX() == 0);
    assert(D.getY() == 0);

    D = Point(A);
    assert(D.getX() == A.getX());
    assert(D.getY() == A.getY());

}

void testTriangles() {
    Triangle t1, t2;
    t1 = Triangle();

    assert(t1.getA() == Point(0, 0));
    assert(t1.getB() == Point(0, 0));
    assert(t1.getC() == Point(0, 0));

    t1.setA(Point(3, 4));
    assert(t1.getA() == Point(3, 4));
    t1.setB(Point(4, 2));
    assert(t1.getB() == Point(4, 2));
    t1.setC(Point(5, 2));
    assert(t1.getC() == Point(5, 2));

    t2 = Triangle(t1);
    assert(t2.getA() == Point(3, 4));
    assert(t2.getB() == Point(4, 2));
    assert(t2.getC() == Point(5, 2));

    t2 = Triangle();
    assert(t2.getA() == Point(0, 0));
    assert(t2.getB() == Point(0, 0));
    assert(t2.getC() == Point(0, 0));

    t2 = t1;
    assert(t2.getA() == Point(3, 4));
    assert(t2.getB() == Point(4, 2));
    assert(t2.getC() == Point(5, 2));

    assert(t1 == t2);

    Triangle t3 = Triangle();
    assert(!(t1 == t3));


}

void testTriangleRepository() {
    TriangleRepository tr;
    tr.add(Triangle(Point(1, 2), Point(1, 5), Point(3, 7)));
    tr.add(Triangle(Point(2, 2), Point(3, 5), Point(5, 6)));
    tr.add(Triangle(Point(1, 5), Point(21, 53), Point(41, 44)));
    tr.add(Triangle(Point(42, 31), Point(5, 6), Point(1, 6)));
    tr.add(Triangle(Point(2, 6), Point(3, 63), Point(13, 14)));

    assert(tr.getSize() == 5);
    tr.add(Triangle(Point(5, 6), Point(35, 63), Point(13, 14)));
    tr.add(Triangle(Point(2, 6), Point(3, 63), Point(14, 14)));
    tr.add(Triangle(Point(6, 6), Point(7, 63), Point(13, 14)));
    tr.add(Triangle(Point(2, 5), Point(3, 23), Point(41, 53)));
    tr.add(Triangle(Point(3, 8), Point(48, 63), Point(13, 14)));
    tr.add(Triangle(Point(6, 8), Point(1, 51), Point(12, 13)));
    tr.add(Triangle(Point(4, 6), Point(5, 13), Point(52, 11)));
    tr.add(Triangle(Point(2, 6), Point(3, 63), Point(13, 14)));
    assert(tr.getSize() == 13);
    tr.remove(Triangle(Point(2, 6), Point(3, 63), Point(13, 14)));
    assert(tr.getSize() == 12);
    tr.remove(Triangle(Point(4, 6), Point(5, 13), Point(52, 11)));
    assert(tr.getSize() == 11);
    tr.remove(Triangle(Point(6, 8), Point(1, 51), Point(12, 13)));
    assert(tr.getSize() == 10);
    tr.remove(Triangle(Point(5, 6), Point(35, 63), Point(13, 14)));
    assert(tr.getSize() == 9);

    assert(tr.getTriangle(4) == Triangle(Point(42, 31), Point(5, 6), Point(1, 6)));
    assert(tr.getTriangle(7) == Triangle(Point(2, 6), Point(3, 63), Point(14, 14)));

    assert(tr.search(Triangle(Point(2, 6), Point(3, 63), Point(14, 14))) == 7);
    assert(tr.search(Triangle(Point(), Point(), Point())) == -1);

    assert(tr.getLargestTriangle() == Triangle(Point(1, 5), Point(21, 53), Point(41, 44)));
    tr.add(Triangle(Point(30, 66), Point(89, 552), Point(55, 42)));
    assert(tr.getLargestTriangle() == Triangle(Point(30, 66), Point(89, 552), Point(55, 42)));

    assert(tr.getTrianglesInFirstQuadrant() == tr.getTriangles());
    tr.add(Triangle(Point(-1, 2), Point(1, 3), Point(3, 2)));
    MAP triangles = tr.getTriangles();
    triangles.erase(tr.search(Triangle(Point(-1, 2), Point(1, 3), Point(3, 2))));
    assert(tr.getTrianglesInFirstQuadrant() == triangles);
    assert(tr.getLongestSequenceOfEqualTriangles().empty());

    MAP triangles2;
    triangles2.insert(PAIR(16, Triangle(Point(30, 66), Point(89, 552), Point(55, 42))));
    triangles2.insert(PAIR(17, Triangle(Point(30, 66), Point(89, 552), Point(55, 42))));
    triangles2.insert(PAIR(18, Triangle(Point(30, 66), Point(89, 552), Point(55, 42))));
    tr.add(Triangle(Point(30, 66), Point(89, 552), Point(55, 42)));
    tr.add(Triangle(Point(30, 66), Point(89, 552), Point(55, 42)));
    tr.add(Triangle(Point(30, 66), Point(89, 552), Point(55, 42)));
    assert(tr.getLongestSequenceOfEqualTriangles() == triangles2);
}

void runTests() {
    testPoints();
    testTriangles();
    testTriangleRepository();
}

