//
// Created by basti on 11.05.2021.
//

#include <iostream>

template<typename T>
const T &minimum(const T &t1, const T &t2) {
    if (t1 < t2) return t1;
    return t2;
}

int main() {
    std::cout << "starting..." << std::endl;

    std::cout << minimum(47, 11) << std::endl;

    std::cout << "terminating..." << std::endl;
    return 0;
}
