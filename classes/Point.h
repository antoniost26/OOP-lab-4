//
// Created by Antonio on 3/14/2022.
//
#include <iostream>

#ifndef LAB4_POINT_H
#define LAB4_POINT_H

class Point {
private:
    double x;
    double y;
public:
    /**
     * Default constructor, assigns value 0 to both axes
     */
    Point();

    /**
     * Assigned constructor, assigns value a to x and b to y;
     * @param a = point on X axes
     * @param b = point on Y axes
     */
    Point(int a, int b);

    /**
     * Copy constructor, creates a Point using values from another Point
     * @param point = a Point
     */
    Point(const Point& point);

    /**
     * Create a new Point (equal to a given Point)
     * @param point = a Point
     * @return = a new Point (equal to var point)
     */
    Point& operator=(const Point& point);

    /**
     *  Deconstructor
     */
    ~Point();

    /**
     * Getter for the value from OX axis
     * @return value of x
     */
    double getX() const;

    /**
     *  Getter for the value from OY axis
     * @return value of y
     */
    double getY() const;

    /**
     *  Setter for the value on OX axis
     * @param a = the value that will be set on the OX axis
     */
    void setX(double a);

    /**
     *  Setter for the value on OY axis
     * @param b = the value that will be set on the OY axis
     */
    void setY(double b);

    /**
     * Checks whether a point has the same values on OX and OY axes
     * @param point1 = a Point
     * @param point2 = a Point
     * @return true if they have the same values, false otherwise
     */
    friend bool operator==(const Point& point1, const Point& point2);
    /**
     * IO Operator >>, loads a point from an input stream
     * @param os = an input stream
     * @param point = a Point
     * @return the output stream
     */
    friend std::ostream& operator<<(std::ostream &os, Point &point);

    /**
     * IO Operator >>, saves a Point into an output stream
     * @param is = an output stream
     * @param point = a Point
     * @return = an input stream (with information of a Point)
     */
    friend std::istream& operator>>(std::istream &is, Point &point);
};

#endif //LAB4_POINT_H
