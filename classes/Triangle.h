//
// Created by Antonio on 3/14/2022.
//
#include "Point.h"

#ifndef LAB4_TRIANGLE_H
#define LAB4_TRIANGLE_H


class Triangle {
private:
    Point A;
    Point B;
    Point C;
public:
    /**
     * Default constructor, assigns value 0 to all points
     */
    Triangle();


    /**
     * Assigned constructor, assigns values X to A, Y to B and Z to C
     * @param X = a Point
     * @param Y = a Point
     * @param Z = a Point
     */
    Triangle(const Point& X, const Point& Y, const Point& Z);


    /**
     * Copy constructor, creates a Triangle using values from another Triangle
     * @param triangle = a Triangle
     */
    Triangle(const Triangle& triangle);


    /**
     * Create a new Triangle (equal to a given Triangle)
     * @param triangle = a Triagle
     * @return = a new Triangle (equal to var triangle)
     */
    Triangle& operator=(const Triangle& triangle);


    /**
     *  Deconstructor
     */
    ~Triangle();


    /**
     *  Getter for the values from the Point A
     * @return values of x and y of Point A
     */
    Point getA() const;


    /**
     *  Getter for the values from the Point B
     * @return values of x and y of Point B
     */
    Point getB() const;


    /**
     *  Getter for the values from the Point C
     * @return values of x and y of Point C
     */
    Point getC() const;

    /**
     *  Setter for the point A
     * @param X = a Point which will be set to Point A
     */
    void setA(const Point& X);

    /**
     *  Setter for the point B
     * @param Y = a Point which will be set to Point B
     */
    void setB(const Point& Y);

    /**
     *  Setter for the point C
     * @param Z = a Point which will be set to Point C
     */
    void setC(const Point& Z);

    /**
     * Checks whether a triangle has the same values on A, B and C Points
     * @param triangle1 = a Triangle
     * @param triangle2 = a Triangle
     * @return true if they have the same values, false otherwise
     */
    friend bool operator==(const Triangle& triangle1, const Triangle& triangle2);

    /**
     * IO Operator >>, loads a Triangle from an input stream
     * @param os = an input stream
     * @param triangle = a Triangle
     * @return the output stream
     */
    friend std::ostream& operator<<(std::ostream &os, Triangle &triangle);

    /**
     * IO Operator >>, saves a Triangle into an output stream
     * @param is = an output stream
     * @param triangle = a Triangle
     * @return = an input stream (with information of a Point)
     */
    friend std::istream& operator>>(std::istream &is, Triangle &triangle);
};


#endif //LAB4_TRIANGLE_H
