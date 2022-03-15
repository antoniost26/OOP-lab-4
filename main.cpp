#include <iostream>
#include "tests/tests.h"
#include "classes/Point.h"
#include "classes/Triangle.h"

int main() {
    runTests();
    Triangle A = Triangle(Point(), Point(), Point());
    A.toString();
    return 0;
}
