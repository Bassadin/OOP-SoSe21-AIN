//
// Created by basti on 30.03.2021.
//

#include "Person.h"
namespace hfu {
    void Person::init(const std::string &first_name, const std::string &last_name, const Date &birthday) {
        if (first_name.empty()) {
            throw std::invalid_argument("first name is empty");
        }
        if (last_name.empty()) {
            throw std::invalid_argument("last name is empty");
        }

        this->first_name = first_name;
        this->last_name = last_name;
        this->birthday = birthday;
    }

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