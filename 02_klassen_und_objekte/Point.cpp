//
// Created by basti on 30.03.2021.
//

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