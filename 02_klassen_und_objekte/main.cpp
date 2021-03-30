//
// Created by basti on 30.03.2021.
//

#include <iostream>
#include <cmath>

class Point {
private:
    int x, y;

    int squared_delta(int v, int w) {
        return pow(v - w, 2);
    }

public:
    int getX() {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

    double distance(Point &other) {
        double squared_delta_x = squared_delta(other.getX(), getX());
        double squared_delta_y = squared_delta(other.getY(), getY());
        return sqrt(squared_delta_x + squared_delta_y);
    }
};

int main() {
    std::cout << "Starting..." << std::endl;

    Point point;

    //Simple field values
    std::cout << "--- simple field values ---" << std::endl;
    point.setX(3);
    point.setY(5);
    int x = point.getX();

    std::cout << x << std::endl;

    //Distance
    std::cout << "--- distance ---" << std::endl;
    Point other_point;
    other_point.setX(10);
    other_point.setY(-4);


    std::cout << point.distance(other_point) << std::endl;

    std::cout << "Terminating..." << std::endl;

    return 0;
}
