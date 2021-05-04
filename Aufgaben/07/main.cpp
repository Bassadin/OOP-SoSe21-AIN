//
// Created by basti on 04.05.2021.
//

#include <iostream>
#include <cassert>
#include <sstream>
#include "Vector3D.h"
#include "../04/Friends.h"

namespace task_07 {
    void test_01_b() {
        //Noch nicht fertig! #TODO
        std::cout << "Task 01b Test Start" << std::endl;

        hfu::Vector3D vec1(1, 2, 3);
        hfu::Vector3D vec2(2, 4, 6);
        hfu::Vector3D vec3 = vec1;

        //Destruktor wird nicht gebraucht, weil keine Daten auf dem Heap erstellt werden

        //Kopierkonstruktor wird nicht gebraucht, weil der default ausreicht
        assert(vec3.getX() == 1);
        assert(vec3.getY() == 2);
        assert(vec3.getZ() == 3);

        //Zuweisungsoperator ??? Mach der Sinn, wenn Attribute eh const sind?
        //vec2 = vec1;

        //assert(vec2.getX() == 1);
        //assert(vec2.getY() == 2);
        //assert(vec2.getZ() == 3);

        /*
        Vergleichoperatoren erachte ich bein einem 3D-Vektor als nicht sinnvoll,
        da man höchstens die einzelnen Komponenten vergleichen könnte
        */

        std::cout << "Task 01b Test End" << std::endl;
    }

    void test_01_c() {

        std::cout << "Task 01c Test Start" << std::endl;

        hfu::Vector3D vec1(1, 2, 3);
        hfu::Vector3D vec2(2, 4, 6);

        //Subtract operator test
        hfu::Vector3D vecAdd = vec1 + vec2;
        assert(vecAdd.getX() == 3);
        assert(vecAdd.getY() == 6);
        assert(vecAdd.getZ() == 9);

        //Add operator test
        hfu::Vector3D vecSub = vec1 - vec2;
        assert(vecSub.getX() == -1);
        assert(vecSub.getY() == -2);
        assert(vecSub.getZ() == -3);

        //Stream Operator Test
        std::ostringstream testStream;
        testStream << vecAdd;
        assert(testStream.str() == "(x: 3 y: 6 z: 9)");

        std::cout << "Task 01c Test End" << std::endl;
    }

    void test_01_d() {

        std::cout << "Task 01d Test Start" << std::endl;

        hfu::Vector3D vec1(1, 2, 3);
        float factor = 1.5;

        //Scalar multiplication
        hfu::Vector3D vecScalarMultiplier = factor * vec1;

        assert(vecScalarMultiplier.getX() == 1.5);
        assert(vecScalarMultiplier.getY() == 3);
        assert(vecScalarMultiplier.getZ() == 4.5);

        //Scalar multiplication the other way around and equality operators
        hfu::Vector3D otherVecScalarMultiplier = vec1 * factor;
        assert(vecScalarMultiplier == otherVecScalarMultiplier);

        std::cout << "Task 01d Test End" << std::endl;
    }

    void test_01_e() {
        std::cout << "Task 01e Test Start" << std::endl;

        hfu::Vector3D vec1(2, 2, 4);
        hfu::Vector3D vec2(1.5, 3, 2.5);

        float vecMultiplicationResult = vec1 * vec2;
        assert(vecMultiplicationResult == 19);

        std::cout << "Task 01e Test End" << std::endl;
    }

    void test_02_a() {
        std::cout << "Task 02a Test Start" << std::endl;

        std::string names[2] = {"Donald", "Daisy"};
        hfu::Friends friends(names, 2);

        //Stream Operator Test
        std::ostringstream testStream;
        testStream << friends;
        assert(testStream.str() == "(names: Donald, Daisy; size: 2)");

        std::cout << "Task 02a Test End" << std::endl;
    }

    void test_02_b() {
        std::cout << "Task 02b Test Start" << std::endl;

        std::string names[2] = {"Donald", "Daisy"};
        hfu::Friends friends(names, 2);

        hfu::Friends otherFriends;
        //Assignment operator
        otherFriends = friends;

        otherFriends.add("Gustav");

        assert(otherFriends.getSize() == 3);

        //Also test adding to empty Friends object while we're at it
        hfu::Friends noFriends;
        noFriends.add("Gustav");
        assert(noFriends.getSize() == 1);
        assert(noFriends.name(0) == "Gustav");

        std::cout << "Task 02b Test End" << std::endl;
    }

    void test_02_c() {
        std::cout << "Task 02c Test Start" << std::endl;

        std::string names[2] = {"Donald", "Daisy"};
        hfu::Friends friends(names, 2);

        assert(friends[1] == "Daisy");

        std::cout << "Task 02c Test End" << std::endl;
    }
}

int main() {
    std::cout << "Starting..." << std::endl;

    task_07::test_01_b();
    task_07::test_01_c();
    task_07::test_01_d();
    task_07::test_01_e();
    task_07::test_02_a();
    task_07::test_02_b();
    task_07::test_02_c();

    std::cout << "Terminating..." << std::endl;
    return 0;
}