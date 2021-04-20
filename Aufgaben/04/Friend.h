//
// Created by basti on 13.04.2021.
//

#ifndef OOP_FRIEND_H
#define OOP_FRIEND_H

namespace hfu {
    class Friends {
    private:
        const std::string *names;
        int size;

        static int validate_array_size(int newSize, std::string newNames[]);

        static std::string *copy_array(std::string *string_array_to_copy, int copy_length);

    public:
        Friends(std::string *names, int size);

        Friends();

        const std::string &name(int v);

        const std::string *getNames() const;

        const int &getSize() const;
    };
}

#endif //OOP_FRIEND_H
