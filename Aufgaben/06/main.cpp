//
// Created by basti on 27.04.2021.
//

#include <iostream>
#include <cassert>
#include "../04/Friends.h"

namespace task_06 {
    void test_task_01() {
        std::cout << "Task 01 Test Start" << std::endl;

        std::string names[2] = {"Donald", "Daisy"};
        hfu::Friends friends(names, 2);
        friends.add("Gustav");
        assert(friends.name(2) == "Gustav");

        std::cout << "Task 01 Test End" << std::endl;
    }

    void test_task_02() {
        std::cout << "Task 02 Test Start" << std::endl;

        std::cout << "Implicit dtr:" << std::endl;
        {
            std::string names[2] = {"Donald", "Daisy"};
            hfu::Friends friends(names, 2);
        }

        std::cout << "Explicit dtr:" << std::endl;
        std::string names[2] = {"Donald", "Daisy"};
        hfu::Friends *friends = new hfu::Friends(names, 2);
        delete friends;

        std::cout << "Task 02 Test End" << std::endl;
    }

    void test_task_03() {
        std::cout << "Task 03 Test Start" << std::endl;

        std::string names1[2] = {"Donald", "Daisy"};
        hfu::Friends friends1(names1, 2);

        std::string names2[2] = {"Donald", "Daisy"};
        hfu::Friends friends2(names2, 2);

        std::string names3[3] = {"Dagobert", "Daisy", "Daniel"};
        hfu::Friends friends3(names3, 2);

        assert(friends1 == friends2);
        assert(friends1 != friends3);

        std::cout << "Task 03 Test End" << std::endl;
    }
}

int main() {
    std::cout << "Start" << std::endl;

    task_06::test_task_01();
    task_06::test_task_02();
    task_06::test_task_03();

    std::cout << "End" << std::endl;
    return 0;
}