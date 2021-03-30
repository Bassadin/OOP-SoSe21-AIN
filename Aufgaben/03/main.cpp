//
// Created by basti on 30.03.2021.
//

#include <cassert>
#include <iostream>
#include "Date.h"

void date_test() {
    Date date19970111;
    date19970111.init(1997, 01, 11);
    assert(date19970111.get_year() == 1997);
    assert(date19970111.get_month() == 01);
    assert(date19970111.get_day() == 11);

    try {
        Date date_invalid_day;
        date_invalid_day.init(2000, 01, 69);
        assert(false);
    }
    catch (...) {}

    try {
        Date date_invalid_month;
        date_invalid_month.init(2000, 222, 10);
        assert(false);
    }
    catch (...) {}
}

int main() {
    std::cout << "Starting..." << std::endl;

    date_test();

    std::cout << "Terminating..." << std::endl;
    return 0;
}
