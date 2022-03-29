//
// Created by Antonio on 3/24/2022.
//

#include "point_operations.h"
#include <cmath>

double calculateDistanceBetweenPoints(const Point A, const Point B) {
    return sqrt(pow(A.getX() - B.getX(), 2.0) + pow((A.getY() - B.getY()), 2.0));
}
