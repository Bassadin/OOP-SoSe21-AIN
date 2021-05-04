//
// Created by basti on 04.05.2021.
//

#include <iostream>
#include <cassert>
#include "Vector3D.h"

namespace task_07 {
    void test_01_b() {
        std::cout << "Task 01b Test Start" << std::endl;

        hfu::Vector3D vec1(1,2,3);
        hfu::Vector3D vec2(2,4,6);
        hfu::Vector3D vec3 = vec1;


        assert(vec3.getX() == 1);
        assert(vec3.getY() == 2);
        assert(vec3.getZ() == 3);

        vec2 = vec1;

        assert(vec2.getX() == 1);
        assert(vec2.getY() == 2);
        assert(vec2.getZ() == 3);

        std::cout << "Task 01b Test End" << std::endl;
    }
}

int main() {
    std::cout << "Starting..." << std::endl;

    task_07::test_01_b();

    std::cout << "Terminating..." << std::endl;
    return 0;
}