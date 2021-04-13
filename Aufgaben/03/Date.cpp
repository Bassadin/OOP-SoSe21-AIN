//
// Created by basti on 30.03.2021.
//

#include <map>
#include "Date.h"

namespace hfu {
    void Date::init(unsigned int year, unsigned int month, unsigned int day) {
        if (month == 0 || month > 12)
            throw std::invalid_argument("month must be between 1 and 12");

        bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

        std::map<unsigned int, unsigned int> month_day_map = {
                {1,  31},
                {2,  isLeapYear ? 29 : 28},
                {3,  31},
                {4,  30},
                {5,  31},
                {6,  30},
                {7,  31},
                {8,  31},
                {9,  30},
                {10, 31},
                {11, 30},
                {12, 31},
        };

        if (day == 0 || day > month_day_map[month])
            throw std::invalid_argument("day number 0 or too large");

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
}