//
// Created by basti on 30.03.2021.
//

#include <cassert>
#include <iostream>
#include "Date.h"
#include "Person.h"

void sort(Person *person_array, int size) {

    for (int n = size; n > 1; --n) {
        for (int i = 0; i < n - 1; ++i) {
            if (person_array[i + 1].compare(person_array[i])) {
                auto temp = person_array[i + 1];

                person_array[i + 1] = person_array[i];
                person_array[i] = temp;
            }
        }
    }

}

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
    std::cout << " -> Date tests successful!" << std::endl;
}

void person_test() {
    Person test_person_1;
    Date test_person_a_date;
    test_person_a_date.init(1997, 01, 11);
    test_person_1.init("Bastian", "Hodapp", test_person_a_date);
    assert(test_person_1.get_first_name() == "Bastian");
    assert(test_person_1.get_born().get_year() == 1997);
    assert(test_person_1.get_born().get_month() == 01);

    try {
        Person test_person_empty_name;
        Date test_person_empty_name_date;
        test_person_empty_name_date.init(1997, 01, 11);
        test_person_1.init("", "", test_person_empty_name_date);
        assert(false);
    }
    catch (...) {}

    // Comparison
    Person comparison_test_person_1, comparison_test_person_2;
    Date comparison_test_birthdate;
    comparison_test_birthdate.init(1997, 01, 11);
    comparison_test_person_1.init("Albert", "Affe", comparison_test_birthdate);
    comparison_test_person_2.init("Albert", "Banane", comparison_test_birthdate);
    assert(comparison_test_person_1.compare(comparison_test_person_2));


    std::cout << " -> Person tests successful!" << std::endl;
}

void sort_test() {
    Person sort_test_person_1, sort_test_person_2, sort_test_person_3;
    Date sort_test_birthdate;
    sort_test_birthdate.init(1997, 01, 11);

    sort_test_person_1.init("Albert", "Bonobo", sort_test_birthdate);
    sort_test_person_2.init("Albert", "Cola", sort_test_birthdate);
    sort_test_person_3.init("Albert", "Affe", sort_test_birthdate);

    Person sort_person_array[3] = {sort_test_person_1, sort_test_person_2, sort_test_person_3};
    sort(sort_person_array, 3);

    for (int i = 0; i < 3; i++) {
        std::cout << sort_person_array[i].get_last_name() << std::endl;
    }

    std::cout << " -> Sort tests successful!" << std::endl;
}



int main() {
    std::cout << "Starting..." << std::endl;

    date_test();
    person_test();
    sort_test();

    std::cout << "Terminating..." << std::endl;
    return 0;
}
