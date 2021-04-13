//
// Created by basti on 30.03.2021.
//

#include "Person.h"

namespace hfu {
    std::string Person::check_firstname(std::string firstname) {
        if (firstname.empty()) {
            throw std::invalid_argument("first name is empty");
        }
        return firstname;
    }

    std::string Person::check_lastname(std::string lastname) {
        if (lastname.empty()) {
            throw std::invalid_argument("last name is empty");
        }
        return lastname;
    }

    Person::Person(const std::string &first_name, const std::string &last_name, const Date &birthday) :
            first_name(check_firstname(first_name)),
            last_name(check_lastname(last_name)),
            birthday(birthday) {}

    const std::string &Person::get_first_name() const {
        return first_name;
    }

    const std::string &Person::get_last_name() const {
        return last_name;
    }

    const Date &Person::get_born() const {
        return birthday;
    }

    bool Person::compare(const Person &other) const {
        return this->get_last_name() < other.get_last_name();
    }
}