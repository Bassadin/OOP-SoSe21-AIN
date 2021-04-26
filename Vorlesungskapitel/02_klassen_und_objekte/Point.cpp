//
// Created by basti on 30.03.2021.
//

#include <cmath>
#include "Point.h"

int Point::squared_delta(int v, int w) {
    return pow(v - w, 2);
}


int Point::getX() {
    return x;
}

void Point::setX(int x) {
    this->x = x;
}

int Point::getY() {
    return y;
}

void Point::setY(int y) {
    this->y = y;
}

double Point::distance(Point &other) {
    double squared_delta_x = squared_delta(other.getX(), getX());
    double squared_delta_y = squared_delta(other.getY(), getY());
    return sqrt(squared_delta_x + squared_delta_y);
}