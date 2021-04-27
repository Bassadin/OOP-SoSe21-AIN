//
// Created by basti on 26.04.2021.
//

#include <cstdio>
#include <string>
#include <iostream>
#include "main.h"

namespace Destruktoren_05 {
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

        ~Point() {
            puts("dtor call");
        }

        Point(const Point &other) : Point(other.x, other.y) {
            puts("in copy ctr");
        }

        Point &add(const Point &other) const {
            Point *result = new Point(x + other.x, y + other.y);
            return *result;
        }

        Point operator+(const Point &other) const {
            return Point(x+other.x, y+other.y);
        }

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }
    };

    class Segment {
        Point p1, p2;
    public:
        Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2) {}
    };
}

int main() {
    Destruktoren_05::Point p1(4, 7);
    Destruktoren_05::Point p2(1, 1);
    Destruktoren_05::Point p3 = p1+p2; //Same as p3 = p1.operator+(p2);
    std::cout << p3.getX() << std::endl;
    std::cout << "terminating..." << std::endl;

    return 0;
}