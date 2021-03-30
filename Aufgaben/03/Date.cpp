//
// Created by basti on 30.03.2021.
//

#include <stdexcept>
#include "Date.h"

void Date::init(unsigned int year, unsigned int month, unsigned int day) {
    if (month == 0 || month > 12)
        throw std::invalid_argument("month must be between 1 and 12");

    if (day == 0 || day > 31)
        throw std::invalid_argument("day must be between 1 and 31");

    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}