//
// Created by basti on 30.03.2021.
//

#include <cmath>

class Point {
private:
    int x, y;

    int squared_delta(int v, int w);

public:
    int getX();

    void setX(int x);

    int getY();

    void setY(int y);

    double distance(Point &other);
};