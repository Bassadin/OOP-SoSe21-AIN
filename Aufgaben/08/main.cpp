//
// Created by basti on 11.05.2021.
//

#include <iostream>
#include <cassert>
#include "Date.h"

namespace aufgabe_08 {
    template <typename T> bool find(T inputArray[], int length, T key) {
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

        hfu::Date date1(2021,1,1);
        hfu::Date date2(2020,12,31);
        hfu::Date date3(2019,12,24);
        hfu::Date date4(1989,11,9);
        hfu::Date dates[]={date1,date2,date3};
        for(int i=0;i<3;i++) {
            assert( find(dates, 3,dates[i]));
        }
        assert( !find(dates, 3,date4));

        std::cout << "end test task 1c..." << std::endl;
    }
}

int main() {
    std::cout << "starting..." << std::endl;

    aufgabe_08::test_task_01aandb();
    aufgabe_08::test_task_01c();

    std::cout << "terminating..." << std::endl;
    return 0;
}
