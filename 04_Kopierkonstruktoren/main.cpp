//
// Created by basti on 20.04.2021.
//

#include <iostream>
#include "main.h"

namespace kopierkonstruktoren_03 {

    class Point {
    private:
        int *coordinates;

        static int *make_pair(int x, int y) {
            int *result = new int[2]{x, y};
            return result;
        }

    public:
        Point(int x, int y) : coordinates(make_pair(x, y)) {}
        Point(const Point &other): Point(other.getX(), other.getY()){
            std::cout << "in copy ctr" << std::endl;
        }
        // Syntax for deleting copy constructor
        //Point(const Point &other)=delete;
        int getX() const {
            return coordinates[0];
        }

        int getY() const {
            return coordinates[1];
        }

        void setX(int x) {
            coordinates[0] = x;
        }

        void setY(int y) {
            coordinates[1] = y;
        }
    };

    class Segment {
    private:
        Point p1, p2;
    public:
        Segment(const Point &p1, const Point &p2): p1(p1), p2(p2){}

        const Point &getP1() const {
            return p1;
        }
    };
}

void dump (kopierkonstruktoren_03::Point p) {
    std::cout << p.getX() << " " << p.getY() << std::endl;
}

kopierkonstruktoren_03::Point sum(kopierkonstruktoren_03::Point p, kopierkonstruktoren_03::Point q) {
    kopierkonstruktoren_03::Point result = kopierkonstruktoren_03::Point(p.getX()+q.getX(), p.getY()+q.getY());
    return result;
}

int main() {
    std::cout << "starting..." << std::endl;
    kopierkonstruktoren_03::Point p(47,11);
    kopierkonstruktoren_03::Point q(23,42);
    p=q; //Nur Zuweisung, deshalb kein Kopierkonstruktor!

    std::cout << "dump:" << std::endl;
    dump(p); // ruft Kopierkonstruktor auf, da mit pass-by-value gearbeitet wird

    std::cout << "sum:" << std::endl;
    std::cout << sum(p, q).getX() << std::endl;

    std::cout << "terminating..." << std::endl;
    return 0;
}