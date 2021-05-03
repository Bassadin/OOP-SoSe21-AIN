//
// Created by basti on 03.05.2021.
//

#include <cstdio>
#include <iostream>
#include "main.h"

namespace operatoren_06 {
    class Point {
    private:
        const int x, y;

        static int *make_pair(int x, int y) {
            int *result = new int[2]{x, y};
            return result;
        }

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
}

int main() {
    std::cout << "starting..." << std::endl;

    operatoren_06::Point p1(2, 3);
    operatoren_06::Point p2(6, 10);

    auto p3 = 23 * p2;

    std::cout << p3.getX() << std::endl;

    std::cout << "terminating..." << std::endl;
    return 0;
}