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
    assert(A==B);
    assert(!(A==C));

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
    assert(t1.getB() == Point(0,0));
    assert(t1.getC() == Point(0,0));

    t1.setA(Point(3,4));
    assert(t1.getA() == Point(3,4));
    t1.setB(Point(4,2));
    assert(t1.getB() == Point(4,2));
    t1.setC(Point(5,2));
    assert(t1.getC() == Point(5,2));

    t2 = Triangle(t1);
    assert(t2.getA() == Point(3,4));
    assert(t2.getB() == Point(4,2));
    assert(t2.getC() == Point(5,2));

    t2 = Triangle();
    assert(t2.getA() == Point(0, 0));
    assert(t2.getB() == Point(0,0));
    assert(t2.getC() == Point(0,0));

    t2 = t1;
    assert(t2.getA() == Point(3,4));
    assert(t2.getB() == Point(4,2));
    assert(t2.getC() == Point(5,2));

    assert(t1 == t2);

    Triangle t3 = Triangle();
    assert(!(t1 == t3));


}

void testTrianglRepository() {
    TriangleRepository tr;
    tr.add(Triangle(Point(1,2), Point(1,5),Point(3,7)));
    tr.add(Triangle(Point(2,2), Point(3,5),Point(5,6)));
    tr.add(Triangle(Point(1,5), Point(21,53),Point(41,44)));
    tr.add(Triangle(Point(42,31), Point(5,6),Point(1,6)));
    tr.add(Triangle(Point(2,6), Point(3,63),Point(13,14)));
    assert(tr.getLength() == 5);
    tr.add(Triangle(Point(5,6), Point(35,63),Point(13,14)));
    tr.add(Triangle(Point(2,6), Point(3,63),Point(14,14)));
    tr.add(Triangle(Point(6,6), Point(7,63),Point(13,14)));
    tr.add(Triangle(Point(2,5), Point(3,23),Point(41,53)));
    tr.add(Triangle(Point(3,8), Point(48,63),Point(13,14)));
    tr.add(Triangle(Point(6,8), Point(1,51),Point(12,13)));
    tr.add(Triangle(Point(4,6), Point(5,13),Point(52,11)));
    tr.add(Triangle(Point(2,6), Point(3,63),Point(13,14)));
    assert(tr.getLength() == 13);
    tr.remove(Triangle(Point(2,6), Point(3,63),Point(13,14)));
    assert(tr.getLength() == 12);
    tr.remove(Triangle(Point(4,6), Point(5,13),Point(52,11)));
    assert(tr.getLength() == 11);
    tr.remove(Triangle(Point(6,8), Point(1,51),Point(12,13)));
    assert(tr.getLength() == 10);
    tr.remove(Triangle(Point(5,6), Point(35,63),Point(13,14)));
    assert(tr.getLength() == 9);
    assert(tr.getTriangle(3) == Triangle(Point(42,31), Point(5,6),Point(1,6)));
    assert(tr.getTriangle(4) == Triangle(Point(2,6), Point(3,63),Point(14,14)));
    assert(tr.ifExist(Triangle(Point(2,6), Point(3,63),Point(14,14))) == true);
    assert(tr.ifExist(Triangle(Point(), Point(), Point())) == false);
}

void runTests() {
    testPoints();
    testTriangles();
    testTrianglRepository();
}

