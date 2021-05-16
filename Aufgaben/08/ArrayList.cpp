//
// Created by basti on 13.04.2021.
//
#include <cassert>
#include <iostream>
#include "ArrayList.h"

namespace hfu_08 {
    template<typename T>
    int ArrayList<T>::validate_array_size(int newSize, T newEntries[]) {
        if (newSize < 0)
            throw std::invalid_argument("newSize is smaller then 0");
        if (newEntries != nullptr && newEntries->size() != (unsigned long) newSize) {
            //throw std::invalid_argument("newSize is not equal to the array's size");
        }
        return newSize;
    }

    template<typename T>
    T *ArrayList<T>::copy_array(T *array_to_copy, int copy_length) {
        if (array_to_copy == nullptr) {
            return array_to_copy;
        }

        auto *copiedArray = new std::string[copy_length];

        copyArrayToArray(copiedArray, array_to_copy, 0, copy_length - 1);

        return copiedArray;
    }

    template<typename T>
    ArrayList<T>::ArrayList(T *newEntries, int size) : entries(copy_array(newEntries, size)), size(validate_array_size(size, newEntries)) {}

    template<typename T>
    ArrayList<T>::ArrayList(const ArrayList &other) : ArrayList(other.getEntries(), other.getSize()) {
        std::cout << "In Friends copy ctr" << std::endl;
    }

    template<typename T>
    ArrayList<T>::ArrayList() : ArrayList::ArrayList(nullptr, 0) {}

    template<typename T>
    ArrayList<T>::~ArrayList() {
        delete[] entries;
        std::cout << "Friends dtr" << std::endl;
    }

    template<typename T>
    const T &ArrayList<T>::entryAtIndex(unsigned int v) const {
        //Nach Länge checken
        return entries[v];
    }

    template<typename T>
    T * ArrayList<T>::getEntries() const {
        return entries;
    }

    template<typename T>
    const int &ArrayList<T>::getSize() const {
        return size;
    }

    template<typename T>
    void ArrayList<T>::add(const char *entryToAdd) {
        T *newEntries = new T[this->getSize() + 1];

        if (getEntries() == nullptr) {
            newEntries[0] = entryToAdd;
        } else {
            copyArrayToArray(newEntries, getEntries(), 0, getSize() - 1);
            newEntries[getSize()] = entryToAdd;
        }

        delete[] entries;
        entries = newEntries;
        size++;
    }

    template<typename T>
    void
    ArrayList<T>::copyArrayToArray(T *array_target, T *array_source, int copy_from,
                                   int copy_to) {
        if (copy_from > copy_to) {
            throw std::invalid_argument("copy start size is larger than copy end size");
        }

        for (int i = copy_from; i <= copy_to; ++i) {
            array_target[i] = array_source[i];
        }
    }

    template<typename T>
    bool ArrayList<T>::operator==(const ArrayList &other) const {
        if (this->getSize() != other.getSize()) {
            return false;
        }
        for (int i = 0; i < this->getSize(); ++i) {
            if (entries[i] != other.entryAtIndex(i)) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    bool ArrayList<T>::operator!=(const ArrayList &other) const {
        return !(*this == other);
    }

    template<typename T>
    void ArrayList<T>::setEntries(T *newEntries) {
        this->entries = newEntries;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const ArrayList<T> &arrayList) {
        os << "(entries: ";

        for (int i = 0; i < arrayList.getSize(); ++i) {
            os << arrayList.entryAtIndex(i);
            if (i < arrayList.getSize() - 1) {
                os << ", ";
            }
        }

        os << "; size: " << arrayList.size << ")";
        return os;
    }

    template<typename T>
    ArrayList<T> &ArrayList<T>::operator=(const ArrayList &other) {
        if (this == &other) {
            return *this;
        }
        delete[] entries;
        entries = new std::string[size];
        setEntries(copy_array(other.entries, other.size));
        size = other.size;
        return *this;
    }

    template<typename T>
    T &ArrayList<T>::operator[](const unsigned int &index) {
        return entries[index];
    }

    template<typename T>
    const T &ArrayList<T>::operator[](const unsigned int &index) const {
        return entryAtIndex(index);
    }

}