//
// Created by basti on 20.04.2021.
//

#include <iostream>
#include <cassert>
#include "../04/Friends.h"

namespace hfu_task5 {
    class Point {
    private:
        int *coordinates;

        static int *make_pair(int x, int y) {
            int *result = new int[2]{x, y};
            return result;
        }

    public:
        Point(int x, int y) : coordinates(make_pair(x, y)) {}
        Point(const Point &other): Point(other.getX(), other.getY()){}
        // Syntax for deleting copy constructor
        //Point(const Point &other)=delete;
        int getX() const {
            return coordinates[0];
        }

        int getY() const {
            return coordinates[1];
        }

        void setX(int x) {
            coordinates[0] = x;
        }

        void setY(int y) {
            coordinates[1] = y;
        }
    };

    class Segment {
    private:
        Point& p1, p2;
    public:
        Segment(Point &p1, Point &p2): p1(p1), p2(p2){}

        const Point &getP1() const {
            return p1;
        }

        const Point &getP2() const {
            return p2;
        }
    };

    void test_task5_number2() {
        std::string names[2] = {"Donald", "Daisy"};
        hfu::Friends friends1(names, 2);
        names[0] = "Dagobert";
        assert(friends1.name(0) == "Donald");
        hfu::Friends friends2 = friends1;
        assert(friends2.name(0) == "Donald");
    }
}

int main() {
    std::cout << "Tests starting" << std::endl;

    hfu_task5::test_task5_number2();

    std::cout << "All tests successful!" << std::endl;
    return 0;
}