//
// Created by basti on 03.05.2021.
//

#include <cstdio>
#include <iostream>
#include "main.h"

namespace operatoren_06 {
    class Point {
    private:
        int x, y;
    public:
        Point(int x, int y) :
                x(x), y(y) {

        }

        Point &add(const Point &other) const {
            Point *result = new Point(x + other.x, y + other.y);
            return *result;
        }

        Point operator+(const Point &other) const {
            return Point(x + other.x, y + other.y);
        }

        Point operator-(const Point &other) const {
            return Point(x - other.x, y - other.y);
        }

        Point operator*(int factor) const {
            return Point(x * factor, y * factor);
        }

        bool operator==(const Point &other) const {
            if (this == &other) {
                return true;
            }
            return x == other.getX() && y == other.getY();
        }

        bool operator!=(const Point &other) const {
            return !(*this == other);
        }

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }
    };

    Point operator*(int factor, const Point &point) {
        return point * factor;
    }

    //Warum hier friend verwenden statt Getter?
    std::ostream& operator<<(std::ostream& out, const Point& point){
        out << "(" << point.getX() << ", " << point.getY() << ")";
        return out;
    }
}

int main() {
    std::cout << "starting..." << std::endl;

    operatoren_06::Point p1(2, 3);
    operatoren_06::Point p2(6, 10);
    std::cout << p1 << std::endl;

    p1=p2;

    if (p1 == p2) {
        std::cout << "Points are equal" << std::endl;
    }

    std::cout << "terminating..." << std::endl;
    return 0;
}