//
// Created by basti on 13.04.2021.
//
#include <cassert>
#include <iostream>

class Friends {
private:
    const std::string *names;
    int size;

    int validate_array_size(int newSize, std::string newNames[]) {
        if (newSize < 0)
            throw std::invalid_argument("newSize is smaller then 0");
        if (newNames) {

        }
//        int arrSize = *(&length + 1) - length;
//        if (arrSize != newSize)
//            throw std::invalid_argument("newSize is not equal to length array newSize");
        return newSize;
    }

public:
    Friends(std::string *names, int size) : names(names), size(validate_array_size(size, names)) {}

    Friends() : Friends(nullptr, 0) {}

    const std::string &name(int v) {
        return names[v];
    }

    const std::string *getNames() const {
        return names;
    }

    const int &getSize() const {
        return size;
    }
};
