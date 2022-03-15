//
// Created by Antonio on 3/14/2022.
//

#include "Point.h"

Point::Point() {
//    std::cout << "[Point] : Constructor\n";
    x = 0;
    y = 0;
}

Point::Point(int a, int b) {
//    std::cout << "[Point] : Assigned Constructor\n";
    this->x = a;
    this->y = b;
}

Point::Point(const Point &point) {
//    std::cout << "[Point] : Copy Constructor\n";
    this->x = point.x;
    this->y = point.y;
}

Point& Point::operator=(const Point& point){
//    std::cout << "[Point] : operator=\n";
    if(this != &point){
        this->x = point.x;
        this->y = point.y;
    }
    return *this;
}

Point::~Point() = default;
//{
//    std::cout << "[Point] : destructor\n";
//};

double Point::getX() const {
//    std::cout << "[Point] : X Getter\n";
    return this->x;
}

double Point::getY() const {
//    std::cout << "[Point] : Y Getter\n";
    return this->y;
}

void Point::setX(double a) {
//    std::cout << "[Point] : X Setter\n";
    this->x = a;
}

void Point::setY(double b) {
//    std::cout << "[Point] : Y Setter\n";
    this->y = b;
}

std::ostream &operator<<(std::ostream &os, Point &point) {
//    std::cout << "[Point] : operator<<\n";
    os << "(" << point.x << ", " << point.y << ")\n";
    return os;
}

std::istream &operator>>(std::istream &is, Point &point) {
//    std::cout << "[Point] : operator>>\n";
    double x, y;
    std::cout << "x= "; is >> x;
    point.x = x;
    std::cout << "y= "; is >> y;
    point.y = y;
    return is;
}

bool operator==(const Point &point1, const Point &point2) {
    return ((point1.x == point2.x) && (point1.y == point2.y));
}
