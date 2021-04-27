//
// Created by basti on 20.04.2021.
//

#include <iostream>
#include <cassert>
#include "../04/Friends.h"

namespace hfu_task5 {
    class Point {
    private:
        int x, y;

    public:
        Point(int x, int y) : x(x), y(y) {}

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }

        void setX(int x) {
            this->x = x;
        }

        void setY(int y) {
            this->y = y;
        }
    };

    class Segment {
    private:
        Point p1, p2;
    public:
        Segment(Point p1, Point p2): p1(p1), p2(p2){} //Nicht mit Referenzen, sondern mit Pass by Value arbeiten

        const Point &getP1() const {
            return p1;
        }

        const Point &getP2() const {
            return p2;
        }

        void setP1(Point &p1) {
            this->p1 = p1;
        }

        void setP2(const Point &p2) {
            this->p2 = p2;
        }
    };

    void test_task5_number2() {
        std::cout << "Test task 2 starting" << std::endl;
        std::string names[2] = {"Donald", "Daisy"};
        hfu::Friends friends1(names, 2);
        names[0] = "Dagobert";
        hfu::Friends friends2 = friends1;
        friends1.setNames(names);
        assert(friends2.name(0) == "Donald");
        std::cout << "Test task 2 ending" << std::endl;
    }

    void test_task5_number3_points() {
        std::cout << "Test task 3 (points) starting" << std::endl;
        Point p1(2, 4);
        Point p2(3, 6);
        Point p1Copy = p1;

        p1Copy.setX(99);
        assert(p1.getX() == 2);

        p1.setY(42);
        assert(p1Copy.getY() == 4);

        std::cout << "Test task 3 (points) finished" << std::endl;
    }

    void test_task5_number3_segments() {
        std::cout << "Test task 3 (segments) starting" << std::endl;
        Point p1(2, 4);
        Point p2(3, 6);

        Segment segment1(p1, p2);
        p1.setX(99);
        assert(segment1.getP1().getX() == 2);

        std::cout << "Test task 3 (segments) finished" << std::endl;
    }
}

int main() {
    std::cout << "Tests starting" << std::endl;

    hfu_task5::test_task5_number2();
    hfu_task5::test_task5_number3_points();
    hfu_task5::test_task5_number3_segments();

    std::cout << "All tests successful!" << std::endl;
    return 0;
}