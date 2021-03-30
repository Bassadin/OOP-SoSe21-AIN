//
// Created by basti on 30.03.2021.
//

#include "Person.h"

void Person::init(const std::string& _first_name, const std::string& _last_name, const Date& _birthday) {
    if (_first_name == "") {
        throw std::invalid_argument("first name is empty");
    }
    if (_last_name == "") {
        throw std::invalid_argument("last name is empty");
    }

    this->first_name = _first_name;
    this->last_name = _last_name;
    this->birthday = _birthday;
}

const std::string &Person::get_first_name() const {
    return first_name;
}

const std::string &Person::get_last_name() const {
    return last_name;
}

const Date & Person::get_born() const {
    return birthday;
}

bool Person::compare(const Person &other) const {
    return this->get_last_name() < other.get_last_name();
}