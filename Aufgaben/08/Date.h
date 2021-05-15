//
// Created by basti on 30.03.2021.
//

#ifndef OOP_DATE_H
#define OOP_DATE_H

#include <iostream>

namespace hfu {
    class Date {
    private:
        int year, month, day;
        static unsigned int checkDay(unsigned int day, unsigned int month, unsigned int year);
        static unsigned int checkMonth(unsigned int month);
    public:
        Date(unsigned int year, unsigned int month, unsigned int day);

        int get_year() const;

        int get_month() const;

        int get_day() const;


        bool operator==(const Date &other) const;

        bool operator!=(const Date &other) const;
    };
}

#endif //OOP_DATE_H
