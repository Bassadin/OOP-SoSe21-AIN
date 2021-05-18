//
// Created by basti on 18.05.2021.
//

#include <iostream>
#include <array>
#include <vector>
#include <set>

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

    void arrayExample() {
        std::cout << "-------------------" << std::endl;
        std::cout << "std::array example" << std::endl;

        std::array<container_08::Point, 2> points = {container_08::Point(47,11), container_08::Point(23,42)};
        std::cout << points[0] << std::endl; //Ganz üblicher Zugriff
        std::cout << points[3] << std::endl; //Man kann immer noch out of bounds gehen...
        //std::cout << points.at(3) << std::endl; //Außer mit at() !
        std::cout << points.size() << std::endl;

        auto morePoints = points;
        points[0] = container_08::Point(0 ,0);
        std::cout << morePoints[0] << std::endl; //Keine Veränderung -> Deep copy!

        std::cout << "-------------------" << std::endl;
    }

    void vectorExample() {
        std::cout << "-------------------" << std::endl;
        std::cout << "std::vector example" << std::endl;

        std::vector<container_08::Point> points;

        for (int i = 0; i < 5; ++i) {
            points.push_back(Point(i,i));
            std::cout << "Size: " << points.size() << ", Capacity: " << points.capacity() << std::endl;
        }

        points.push_back(Point(47, 11));
        std::cout << points[0] << std::endl;
        std::cout << points.size() << std::endl;

        std::cout << "-------------------" << std::endl;
    }

    void setExample() {
        std::cout << "-------------------" << std::endl;
        std::cout << "std::set example" << std::endl;

        std::set<int> numbers;
        for (int i = 10; i != 1; i--) {
            numbers.insert(i);
        }
        std::cout << numbers.size() << std::endl;

        std::set<Point> points;
        points.insert(Point(47, 11));

        std::cout << "-------------------" << std::endl;
    }
}

int main() {
    std::cout << "starting..." << std::endl;

    container_08::arrayExample();
    container_08::vectorExample();
    container_08::setExample();

    std::cout << "terminating..." << std::endl;
    return 0;
}