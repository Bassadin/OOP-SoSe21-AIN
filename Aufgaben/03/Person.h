//
// Created by basti on 30.03.2021.
//

#ifndef OOP_PERSON_H
#define OOP_PERSON_H

#include "Date.h"
#include <iostream>

namespace hfu {
    class Person {
    private:
        std::string first_name, last_name;
        Date birthday;

        std::string check_lastname(std::string lastname);
        std::string check_firstname(std::string firstname);
    public:
        Person(const std::string &_first_name, const std::string &_last_name, const Date &_birthday);

        const std::string &get_last_name() const;

        const std::string &get_first_name() const;

        const Date &get_born() const;

        bool compare(const Person &other) const;
    };
}

#endif //OOP_PERSON_H
