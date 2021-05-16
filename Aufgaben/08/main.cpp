//
// Created by basti on 11.05.2021.
//

#include <cassert>

#include "ArrayList.h"
#include <sstream>
#include "Date.h"

namespace aufgabe_08 {
    template<typename T>
    bool find(T inputArray[], int length, T key) {
        for (int i = 0; i < length; ++i) {
            if (inputArray[i] == key)
                return true;
        }
        return false;
    }

    void test_task_01aandb() {
        std::cout << "start test task 1a and b..." << std::endl;

        int testArray[] = {1, 2, 3, 4, 5};

        assert(find(testArray, 5, 4) == true);
        assert(find(testArray, 5, 6) == false);

        std::cout << "end test task 1a and b..." << std::endl;
    }

    void test_task_01c() {
        std::cout << "start test task 1c..." << std::endl;

        hfu::Date date1(2021, 1, 1);
        hfu::Date date2(2020, 12, 31);
        hfu::Date date3(2019, 12, 24);
        hfu::Date date4(1989, 11, 9);
        hfu::Date dates[] = {date1, date2, date3};
        for (int i = 0; i < 3; i++) {
            assert(find(dates, 3, dates[i]));
        }
        assert(!find(dates, 3, date4));

        std::cout << "end test task 1c..." << std::endl;
    }

    void test_normal_constructor_Friends() {
        std::string names[2] = {"Donald", "Daisy"};
        hfu_08::Friends friends(names, 2);
        assert(friends.getSize() == 2);
        assert(friends.entryAtIndex(0) == "Donald");
        assert(friends.entryAtIndex(1) == "Daisy");
    }

    void test_02_b_01() {
        std::cout << "Task 02b 01 Test Start" << std::endl;

        std::string names[2] = {"Donald", "Daisy"};
        hfu_08::Friends friends(names, 2);

        //Stream Operator Test
        std::ostringstream testStream;
        testStream << friends;
        assert(testStream.str() == "(entries: Donald, Daisy; size: 2)");

        std::cout << "Task 02b 01 Test End" << std::endl;
    }

    void test_02_b_02() {
        std::cout << "Task 02b 02 Test Start" << std::endl;

        std::string names[2] = {"Donald", "Daisy"};
        hfu_08::Friends friends(names, 2);

        hfu_08::Friends otherFriends;
        //Assignment operator
        otherFriends = friends;

        otherFriends.add("Gustav");

        assert(otherFriends.getSize() == 3);

        //Also test adding to empty Friends object while we're at it
        hfu_08::Friends noFriends;
        noFriends.add("Gustav");
        assert(noFriends.getSize() == 1);
        assert(noFriends.entryAtIndex(0) == "Gustav");

        std::cout << "Task 02b 02 Test End" << std::endl;
    }

    void test_02_b_03() {
        std::cout << "Task 02b 03 Test Start" << std::endl;

        std::string names[2] = {"Donald", "Daisy"};
        hfu_08::Friends friends(names, 2);

        assert(friends[1] == "Daisy");

        std::cout << "Task 02b 03 Test End" << std::endl;
    }
}

int main() {
    std::cout << "starting..." << std::endl;

    aufgabe_08::test_task_01aandb();
    aufgabe_08::test_task_01c();
    aufgabe_08::test_normal_constructor_Friends();
    aufgabe_08::test_02_b_01();
    aufgabe_08::test_02_b_02();
    aufgabe_08::test_02_b_03();

    std::cout << "terminating..." << std::endl;
    return 0;
}
