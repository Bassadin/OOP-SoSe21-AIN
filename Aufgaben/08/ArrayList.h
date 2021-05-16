//
// Created by basti on 13.04.2021.
//

#ifndef OOP_ARRAYLIST_H
#define OOP_ARRAYLIST_H

#include <ostream>

namespace hfu_08 {
    template <typename T> class ArrayList {
    private:
        T *entries;
        int size{};

        static int validate_array_size(int newSize, T newEntries[]);

        static T *copy_array(T *array_to_copy, int copy_length);

    public:

        ArrayList(T *newEntries, int size);

        ArrayList();

        ~ArrayList();

        ArrayList(const ArrayList &other);

        const T & entryAtIndex(unsigned int v) const;

        T * getEntries() const;

        const int &getSize() const;

        void add(const char *entryToAdd);

        bool operator==(const ArrayList &other) const;

        bool operator!=(const ArrayList &other) const;

        void setEntries(T *newEntries);

        template<class TT>
        friend std::ostream &operator<<(std::ostream &os, const ArrayList<TT> &arrayList);

        ArrayList &operator=(const ArrayList &other);

        T &operator[](const unsigned int &index);

        const T& operator[](const unsigned int &index) const;

        static void copyArrayToArray(T *array_target, T *array_source, int copy_from, int copy_to);
    };

    template class ArrayList<std::string>;
    typedef ArrayList<std::string> Friends;
}

#endif //OOP_FRIENDS_H
