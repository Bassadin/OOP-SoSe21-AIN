#include <iostream>
#include <cassert>
#include "Friend.cpp"

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