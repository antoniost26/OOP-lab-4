//
// Created by Antonio on 3/24/2022.
//

#ifndef LAB4_TRIANGLEREPOSITORY_H
#define LAB4_TRIANGLEREPOSITORY_H


#include "../classes/Triangle.h"

class TriangleRepository {
private:
    Triangle* triangles;
    int capacity;
    int length;
    void resize();
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
    int getLength();

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
     * Searches a triangle in the repository.
     * @param t: A triangle.
     * @return: Returns the triangle's position or -1 if it can't be found.
     */
    int search(const Triangle t);

    /**
     * Checks whether a triangle is in the repository.
     * @param t: A triangle.
     * @return: Returns true if a triangle was found, false otherwise.
     */
    bool ifExist(const Triangle t);

    /**
     * Returns a triangle from a given position.
     * @param position: Triangle's position.
     * @return: Returns the triangle if the position is valid, else throws an exception.
     */
    Triangle getTriangle(int position);
};


#endif //LAB4_TRIANGLEREPOSITORY_H
