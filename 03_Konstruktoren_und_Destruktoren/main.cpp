#include <cmath>
#include <iostream>

class Point
{
private:
    int x, y;

    int squared_delta(int v, int w)
    {
        return pow(v - w, 2);
    }

public:
    Point(int x, int y) {
        setX(x);
        setY(y);
    }

    int getX()
    {
        return x;
    }

    void setX(int x)
    {
        this->x = x;
    }

    int getY()
    {
        return y;
    }

    void setY(int y)
    {
        this->y = y;
    }

    double distance(Point &other)
    {
        double squared_delta_x = squared_delta(other.getX(), getX());
        double squared_delta_y = squared_delta(other.getY(), getY());
        return sqrt(squared_delta_x + squared_delta_y);
    }
};

int main()
{
    std::cout << "starting..." << std::endl;

    Point point(47, 11);
    std::cout << point.getX() << " " << point.getY() << std::endl;


    std::cout << "terminating..." << std::endl;
}