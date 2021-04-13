//
// Created by basti on 30.03.2021.
//

#include <cassert>
#include <iostream>
#include "Date.h"
#include "Person.h"

namespace hfu {
    void sort(Person *person_array, int size) {
        for (int n = size; n > 1; --n) {
            for (int i = 0; i < n - 1; ++i) {
                if (person_array[i + 1].compare(person_array[i])) {
                    std::swap(person_array[i + 1], person_array[i]);
                }
            }
        }
    }

    void date_test() {
        Date date19970111(1997, 01, 11);
        assert(date19970111.get_year() == 1997);
        assert(date19970111.get_month() == 01);
        assert(date19970111.get_day() == 11);

        try {
            Date date_invalid_day(2000, 01, 69);
            assert(false);
        }
        catch (...) {}

        try {
            Date date_invalid_month(2000, 222, 10);
            assert(false);
        }
        catch (...) {}


        Date date_leap_day(2000, 2, 29);

        try {
            Date date_february_29_not_leap_year(1999, 2, 29);
            assert(false);
        }
        catch (...) {}

        try {
            Date date_november_31(2021, 11, 31);
            assert(false);
        }
        catch (...) {}

        std::cout << " -> Date tests successful!" << std::endl;
    }

    void person_test() {
        Date test_person_a_date(1997, 01, 11);
        Person test_person_1("Bastian", "Hodapp", test_person_a_date);
        assert(test_person_1.get_first_name() == "Bastian");
        assert(test_person_1.get_born().get_year() == 1997);
        assert(test_person_1.get_born().get_month() == 01);

        try {
            Date test_person_empty_name_date(1997, 01, 11);
            Person test_person_empty_name("", "", test_person_empty_name_date);
            assert(false);
        }
        catch (...) {}

        // Comparison
        Date comparison_test_birthdate(1997, 01, 11);
        Person comparison_test_person_1("Albert", "Affe", comparison_test_birthdate);
        Person comparison_test_person_2("Albert", "Banane", comparison_test_birthdate);
        assert(comparison_test_person_1.compare(comparison_test_person_2));


        std::cout << " -> Person tests successful!" << std::endl;
    }

    void sort_test() {
        Date sort_test_birthdate(1997, 01, 11);
        Person sort_test_person_1("Albert", "Bonobo", sort_test_birthdate);
        Person sort_test_person_2("Albert", "Cola", sort_test_birthdate);
        Person sort_test_person_3("Albert", "Affe", sort_test_birthdate);

        Person sort_person_array[3] = {sort_test_person_1, sort_test_person_2, sort_test_person_3};
        sort(sort_person_array, 3);

        assert(sort_person_array[0].get_last_name() == "Affe");
        assert(sort_person_array[1].get_last_name() == "Bonobo");
        assert(sort_person_array[2].get_last_name() == "Cola");

        std::cout << " -> Sort tests successful!" << std::endl;
    }

}

int main() {
    std::cout << "Starting..." << std::endl;

    hfu::date_test();
    hfu::person_test();
    hfu::sort_test();

    std::cout << "Terminating..." << std::endl;
    return 0;
}
