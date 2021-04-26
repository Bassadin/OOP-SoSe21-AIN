//
// Created by basti on 30.03.2021.
//

#include <iostream>
#include <cmath>
#include "Point.h"

int main() {
    std::cout << "Starting..." << std::endl;

    Point point;

    //Simple field values
    std::cout << "--- simple field values ---" << std::endl;
    point.setX(3);
    point.setY(5);
    int x = point.getX();

    std::cout << x << std::endl;

    //Distance
    std::cout << "--- distance ---" << std::endl;
    Point other_point;
    other_point.setX(10);
    other_point.setY(-4);


    std::cout << point.distance(other_point) << std::endl;

    std::cout << "Terminating..." << std::endl;

    return 0;
}
