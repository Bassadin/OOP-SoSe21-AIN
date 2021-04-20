//
// Created by basti on 20.04.2021.
//

#include <iostream>
#include "main.h"

namespace hfu {

    class Point {
    private:
        int x, y;
    public:
        Point(int x, int y) : x(x), y(y) {}

        int getX() const {
            return x;
        }

        void setX(int x) {
            Point::x = x;
        }
    };
}

int main() {
    std::cout << "starting..." << std::endl;
    hfu::Point p = hfu::Point(47, 11);
    hfu::Point p_copy = p;
    p.setX(23);
    std::cout << p.getX() << " " << p_copy.getX() << std::endl;
    std::cout << "terminating..." << std::endl;
    return 0;
}