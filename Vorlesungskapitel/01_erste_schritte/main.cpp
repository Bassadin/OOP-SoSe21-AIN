#include <iostream>
#include <math.h>
#include <cassert>

namespace hfu {
    int abs(int v) {
        if (v < 0) {
            return -v;
        }
        return v;
    }

    int gcd(int v, int w) {
        if (v == 0 && w == 0) {
            throw std::invalid_argument("both arguments are 0");
        }

        while (w != 0) {
            int tmp = w;
            w = v % w;
            v = tmp;
        }
        return std::abs(v);
    }

    void blank(std::string &text, unsigned int position) {
        if (position >= text.length())
            throw std::invalid_argument("position is out of string range");
        text[position] = ' ';
    }

    void swap(int &a, int &b) {
        int a_temp = a;
        a = b;
        b = a_temp;
    }

    bool is_binary(const std::string &text) {
        for (int i = 0; i < (int) (text.length()); i++) {
            if (text[i] != '0' && text[i] != '1') {
                return false;
            }
        }
        return true;
    }
}

int main() {
    printf("XXX starting... XXX\n");

    //is_binary example
    std::cout << "--- is_binary() ---" << std::endl;

    assert(hfu::is_binary("10111011"));

    //gcd example
    std::cout << "--- gcd() ---" << std::endl;

    int a = 6;
    int b = 4;
    int gcd = hfu::gcd(a, b);

    printf("a=%d b=%d gcd=%d\n", a, b, gcd);

    //replace example
    std::cout << "--- replace() ---" << std::endl;

    std::string *text_pointer = new std::string("Hello HFU...");
    hfu::blank(*text_pointer, 3);

    std::cout << *text_pointer << std::endl;

    //replace example
    std::cout << "--- swap() ---" << std::endl;
    int v = 42;
    int w = 69;
    hfu::swap(v, w);

    std::cout << v << ", " << w << std::endl;

    printf("XXX terminating... XXX\n");
}