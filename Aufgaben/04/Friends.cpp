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
        for (int i = 0; i < copy_length; i++) {
            copiedArray[i] = string_array_to_copy[i];
        }
        return copiedArray;
    }

    Friends::Friends(std::string *names, int size) : names(copy_array(names, size)),
                                                     size(validate_array_size(size, names)) {}

    Friends::Friends(const Friends &other) : Friends(other.getNames(), other.getSize()) {
        std::cout << "In Friends copy ctr" << std::endl;
    }

    Friends::Friends() : Friends::Friends(nullptr, 0) {}

    Friends::~Friends(){
        delete[] names;
        std::cout << "Friends dtr" << std::endl;
    }

    const std::string &Friends::name(int v) const {
        if (v < 0)
            throw std::invalid_argument("v is smaller then 0");
        return names[v];
    }

    std::string *Friends::getNames() const {
        return names;
    }

    const int &Friends::getSize() const {
        return size;
    }


    void Friends::add(const char *nameStringToAdd) {
        std::string *newNames = new std::string[this->getSize()+1];

        for (int i = 0; i < getSize(); ++i) {
            newNames[i] = getNames()[i];
        }
        newNames[getSize()] = nameStringToAdd;
        delete[] names;
        names = newNames;
        size++;
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
}