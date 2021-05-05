//
// Created by basti on 13.04.2021.
//
#include <cassert>
#include <iostream>
#include "Friends.h"

namespace hfu {
    int Friends::validate_array_size(int newSize, std::string newNames[]) {
        if (newSize < 0)
            throw std::invalid_argument("newSize is smaller then 0");
        if (newNames != nullptr && newNames->size() != (unsigned long) newSize) {
            //throw std::invalid_argument("newSize is not equal to the array's size");
        }
        return newSize;
    }

    std::string *Friends::copy_array(std::string *string_array_to_copy, int copy_length) {
        if (string_array_to_copy == nullptr) {
            return string_array_to_copy;
        }

        std::string *copiedArray = new std::string[copy_length];

        copyArrayToArray(copiedArray, string_array_to_copy, 0, copy_length - 1);

        return copiedArray;
    }

    Friends::Friends(std::string *names, int size) : names(copy_array(names, size)),
                                                     size(validate_array_size(size, names)) {}

    Friends::Friends(const Friends &other) : Friends(other.getNames(), other.getSize()) {
        std::cout << "In Friends copy ctr" << std::endl;
    }

    Friends::Friends() : Friends::Friends(nullptr, 0) {}

    Friends::~Friends() {
        delete[] names;
        std::cout << "Friends dtr" << std::endl;
    }

    const std::string &Friends::name(unsigned int v) const {
        //Nach Länge checken
        return names[v];
    }

    std::string *Friends::getNames() const {
        return names;
    }

    const int &Friends::getSize() const {
        return size;
    }

    void Friends::add(const char *nameStringToAdd) {
        std::string *newNames = new std::string[this->getSize() + 1];

        if (getNames() == nullptr) {
            newNames[0] = nameStringToAdd;
        } else {
            copyArrayToArray(newNames, getNames(), 0, getSize() - 1);
            newNames[getSize()] = nameStringToAdd;
        }

        delete[] names;
        names = newNames;
        size++;
    }

    void
    Friends::copyArrayToArray(std::string *array_target, std::string *array_source, int copy_from, int copy_to) {
        if (copy_from > copy_to) {
            throw std::invalid_argument("copy start size is larger than copy end size");
        }

        for (int i = copy_from; i <= copy_to; ++i) {
            array_target[i] = array_source[i];
        }
    }

    bool Friends::operator==(const Friends &other) const {
        if (this->getSize() != other.getSize()) {
            return false;
        }
        for (int i = 0; i < this->getSize(); ++i) {
            if (names[i] != other.name(i)) {
                return false;
            }
        }
        return true;
    }

    bool Friends::operator!=(const Friends &other) const {
        return !(*this == other);
    }

    void Friends::setNames(std::string *names) {
        Friends::names = names;
    }

    std::ostream &operator<<(std::ostream &os, const Friends &friends) {
        os << "(names: ";

        for (int i = 0; i < friends.getSize(); ++i) {
            os << friends.name(i);
            if (i < friends.getSize() - 1) {
                os << ", ";
            }
        }

        os << "; size: " << friends.size << ")";
        return os;
    }

    Friends &Friends::operator=(const Friends &other) {
        if (this == &other) {
            return *this;
        }
        delete[] names;
        names = new std::string[size];
        setNames(copy_array(other.names, other.size));
        size = other.size;
        return *this;
    }

    std::string &Friends::operator[](const unsigned int &index) {
        return names[index];
    }

    const std::string& Friends::operator[](const unsigned int &index) const {
        return name(index);
    }
}