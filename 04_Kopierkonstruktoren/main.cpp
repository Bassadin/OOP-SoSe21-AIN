//
// Created by basti on 20.04.2021.
//

#include <iostream>
#include "main.h"

namespace hfu {

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
}

int main() {
    std::cout << "starting..." << std::endl;
    hfu::Point p = hfu::Point(47, 11);
    hfu::Point p_copy = p;
    p_copy.setX(23);
    std::cout << p.getX() << " " << p_copy.getX() << std::endl;
    std::cout << "terminating..." << std::endl;
    return 0;
}