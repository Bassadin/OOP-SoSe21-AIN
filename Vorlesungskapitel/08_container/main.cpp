//
// Created by basti on 18.05.2021.
//

#include <iostream>
#include <array>

namespace container_08 {
    class Point {
    private:
        int x, y;
    public:
        Point(int x = 0, int y = 0) :
                x(x), y(y) {
        }

        Point(const Point &other) : Point(other.getX(), other.getY()) {}

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }

        friend std::ostream &operator<<(std::ostream &os, const Point &point) {
            os << "x: " << point.x << " y: " << point.y;
            return os;
        }
    };
}

int main() {
    std::cout << "starting..." << std::endl;

    std::array<container_08::Point, 2> points;
    std::cout << points[0] << std::endl; //Ganz üblicher Zugriff
    std::cout << points[3] << std::endl; //Man kann immer noch out of bounds gehen...
    //std::cout << points.at(3) << std::endl; //Außer mit at() !
    std::cout << points.size() << std::endl;

    std::cout << "terminating..." << std::endl;
    return 0;
}