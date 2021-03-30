//
// Created by basti on 30.03.2021.
//

#include <iostream>

class Point {
private:
    int x, y;

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
};

int main() {
    std::cout << "Starting..." << std::endl;

    Point point;

    point.setX(3);
    int x = point.getX();

    std::cout << x << std::endl;

    std::cout << "Terminating..." << std::endl;

    return 0;
}
