//
// Created by basti on 13.04.2021.
//

#ifndef OOP_FRIENDS_H
#define OOP_FRIENDS_H

#include <ostream>

namespace hfu {
    class Friends {
    private:
        std::string *names;
        int size;

        static int validate_array_size(int newSize, std::string newNames[]);

        static std::string *copy_array(std::string *string_array_to_copy, int copy_length);

    public:

        Friends(std::string *names, int size);

        Friends();

        ~Friends();

        Friends(const Friends &other);

        const std::string &name(unsigned int v) const;

        std::string *getNames() const;

        const int &getSize() const;

        void add(const char *nameStringToAdd);

        bool operator==(const Friends &other) const;

        bool operator!=(const Friends &other) const;

        void setNames(std::string *names);

        friend std::ostream &operator<<(std::ostream &os, const Friends &friends);

        Friends &operator=(const Friends &other);

        std::string &operator[](const unsigned int &index);

        const std::string& operator[](const unsigned int &index) const;

        static void copyArrayToArray(std::string *array_target, std::string *array_source, int copy_from, int copy_to);
    };
}

#endif //OOP_FRIENDS_H
