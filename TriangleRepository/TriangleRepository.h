//
// Created by Antonio on 3/24/2022.
//

#ifndef LAB4_TRIANGLEREPOSITORY_H
#define LAB4_TRIANGLEREPOSITORY_H


#include "../classes/Triangle.h"
#include <map>

typedef std::map<int, Triangle> MAP;
typedef std::pair<const int, Triangle> PAIR;

class TriangleRepository {
private:
    MAP triangles;
    int index;
public:
    /**
     * Initializer constructor.
     */
    TriangleRepository();

    /**
     * Copy constructor.
     * @param tr: A Triangle Repository.
     */
    TriangleRepository(TriangleRepository &tr);

    /**
     * Destructor;
     */
    ~TriangleRepository();

    /**
     * Gets length of actual triangle entries. (Returns how many triangles there are in the repository)
     * @return: Length of repository.
     */
    unsigned long long getSize();

    /**
     * Adds a triangle into the repository.
     * @param t: A triangle.
     */
    void add(const Triangle t);

    /**
     * Removes a triangle from the repository.
     * @param t: A triangle.
     * @return: Returns 1 if delete was successful, 0 otherwise.
     */
    int remove(const Triangle t);

    /**
     * Searches a triangle in the repository. *note: can act as a "find" function, returning -1 if triangle doesn't exist.
     * @param t: A triangle.
     * @return: Returns the triangle's position or -1 if it can't be found.
     */
    int search(const Triangle t);

    /**
     * Returns a triangle from a given position.
     * @param position: Triangle's position.
     * @return: Returns the triangle if the position is valid, else throws an exception.
     */
    Triangle getTriangle(int position);

    /**
     * Returns a map containing all triangles.
     * @return: A map containing all triangles.
     */
    MAP getTriangles();

    /**
     * Returns the triangle with largest area from the repository.
     * @return: A triangle.
     */
    Triangle getLargestTriangle();

    /**
     * Returns all triangles situated in the first quadrant.
     * @return: A map<int, Triangle>.
     */
    MAP getTrianglesInFirstQuadrant();

    /**
     * Returns the longest sequence of equal triangles (by area).
     * @return: A map<int, Triangle>.
     */
    MAP getLongestSequenceOfEqualTriangles();
};


#endif //LAB4_TRIANGLEREPOSITORY_H
