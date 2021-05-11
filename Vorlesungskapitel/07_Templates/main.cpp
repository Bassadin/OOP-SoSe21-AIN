//
// Created by basti on 11.05.2021.
//

#include <iostream>
#include <memory>

namespace templates_07 {
    class Point {
    private:
        int x, y;
    public:
        Point(int x, int y) :
                x(x), y(y) {

        }

        ~Point() {
            std::cout << "In Point dtor" << std::endl;
        }

        int getX() const {
            return x;
        }

        int getY() const {
            return y;
        }
    };

    template<typename T>
    const T &minimum(const T &t1, const T &t2) {
        if (t1 < t2) return t1;
        return t2;
    }

    template<>
    const char &minimum(const char &c1, const char &c2) {
        if (tolower(c1) < tolower(c2)) return c1;
        return c2;
    }

    template<typename T>
    class Stack {
    private:
        const int capacity;
        int size;
        std::unique_ptr<T[]> data;
    public:
        Stack(int capacity) : capacity(capacity), size(0), data(std::make_unique<T[]>(capacity)) {}

        bool pop(T &v) {
            if (size == 0) return false;
            size--;
            v = data[size];
            return true;
        }

        bool push(const T &v) {
            if (capacity == size) return false;
            data[size] = v;
            size++;
            return true;
        }
    };
}


int main() {
    std::cout << "starting..." << std::endl;


    std::cout << "terminating..." << std::endl;
    return 0;
}
