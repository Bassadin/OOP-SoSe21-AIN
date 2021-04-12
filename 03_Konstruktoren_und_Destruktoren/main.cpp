#include <cmath>
#include <iostream>

class Point {
private:
    const int *coordinates;

    int squared_delta(int v, int w) {
        return pow(v - w, 2);
    }

    int *make_pair(int x, int y) {
        return new int[2]{x, y};
    }

public:
    Point(int x, int y) : coordinates(make_pair(x, y)) {
        std::cout << "in ctor..." << std::endl;
    }

    Point() : Point(0, 0) {}

    int getX() const {
        return coordinates[0];
    }

    int getY() const {
        return coordinates[1];
    }

    double distance(Point &other) {
        double squared_delta_x = squared_delta(other.getX(), getX());
        double squared_delta_y = squared_delta(other.getY(), getY());
        return sqrt(squared_delta_x + squared_delta_y);
    }
};

class Segment {
private:
    Point p1 = Point(0, 0), p2 = Point(0, 0);
public:
    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2) {

    }

    const Point getP1() const {
        return p1;
    }

    const Point getP2() const {
        return p2;
    }
};

int main() {
    std::cout << "starting..." << std::endl;

    auto test_segment = Segment(Point(23, 42), Point(12, 34));
    std::cout << test_segment.getP1().getX() << std::endl;


    std::cout << "terminating..." << std::endl;
}