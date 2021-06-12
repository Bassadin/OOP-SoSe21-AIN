//
// Created by basti on 09.06.2021.
//

#include <iostream>
#include <array>

class Point {
public:
    virtual int getX() const = 0;

    virtual int getY() const = 0;

    bool operator==(const Point &other) const {
        return getX() == other.getX() && getY() == other.getY();
    }

    bool operator!=(const Point &other) const {
        return !(other == *this);
    }
};

class SimplePoint : public Point {
private:
    int x, y;
public:
    int getX() const override {
        return x;
    }

    int getY() const override {
        return y;
    }

    SimplePoint(int x, int y): x(x), y(y){}
};

class ArrayPoint : public Point {
private:
    std::array<int, 2> coordinates;
public:
    int getX() const override {
        return coordinates[0];
    }

    int getY() const override {
        return coordinates[1];
    }

    ArrayPoint(int x, int y): coordinates{x, y}{}
};

int main() {
    std::cout << "starting..." << std::endl;

    const Point& testPoint = SimplePoint(2, 3);
    const Point& arrayPoint =  ArrayPoint(2, 3);
    if (testPoint == arrayPoint) {
        std::cout << "same..." << std::endl;
    } else {
        std::cout << "different..." << std::endl;
    }

    std::cout << "terminating..." << std::endl;

    return 0;
}