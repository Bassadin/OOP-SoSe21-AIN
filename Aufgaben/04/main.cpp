#include <iostream>
#include <cassert>
#include <array>

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

    Friends() : names(nullptr), size(0) {}

    const std::string name(int v) {
        return names[v];
    }

    const std::string *getNames() const {
        return names;
    }

    int getSize() const {
        return size;
    }
};

void test_normal_constructor() {
    std::string names[2] = {"Donald", "Daisy"};
    Friends friends(names, 2);
    assert(friends.getSize() == 2);
    assert(friends.name(0) == "Donald");
    assert(friends.name(1) == "Daisy");
}

void test_empty_constructor() {
    Friends no_friends = Friends();
    assert(no_friends.getSize() == 0);
    assert(no_friends.getNames() == nullptr);
}

void test_subtask_d() {
    try {
        std::string names[0] = {};
        Friends friends(names, -2);
        assert(false);
    }
    catch (...) {}
}

void test_subtask_e() {
    std::string names[2] = {"Donald", "Daisy"};
    Friends friends(names, 2);
    assert(friends.name(0) == "Donald");
    names[0] = "Mickey";
    assert(friends.name(0) == "Donald");
}

int main() {
    std::cout << "Tests starting" << std::endl;

    test_normal_constructor();
    test_empty_constructor();
    test_subtask_d();
    test_subtask_e();

    std::cout << "All tests successful!" << std::endl;

    return 0;
}