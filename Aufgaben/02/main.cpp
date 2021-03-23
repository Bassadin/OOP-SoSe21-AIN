//
// Created by basti on 23.03.2021.
//

#include <iostream>
#include <cassert>
#include <cmath>

namespace aufgabe_02 {
    bool is_digit(char c) {
        return c >= '0' && c <= '9';
    }

    bool is_sign(char c, int *sign) { // * -> Nimmt pointer als Argument
        if (c == '+') {
            *sign = 1;
        } else if (c == '-') {
            *sign = -1;
        } else {
            return false;
        }
        return true;
    }

    int parse_int(const std::string &text) {
        int signMultiplicator = 1;

        if (!(aufgabe_02::is_sign(text[0], &signMultiplicator) || aufgabe_02::is_digit(text[0]))) {
            throw std::invalid_argument("First char is not a sign or a digit");
        };

        int solution = 0;
        for (int i = text.length() - 1; i >= (aufgabe_02::is_digit(text[0]) ? 0 : 1); i--) {
            if (!is_digit(text[i])) {
                throw std::invalid_argument("Char at pos " + std::to_string(i) + " is not a digit");
            }
            int numberValue = text[i] - '0'; // 48 -> ASCII-Null (0)
            solution += numberValue * pow(10, text.length() - i - 1);
        }

        return solution * signMultiplicator;
    }

    int parse_int_pointer(const std::string *text) {
        return(parse_int(*text));
    }
}

void is_digit_test() {
    assert(!aufgabe_02::is_digit('r'));
    assert(!aufgabe_02::is_digit('!'));
    assert(!aufgabe_02::is_digit('('));
    assert(aufgabe_02::is_digit('3'));
    assert(aufgabe_02::is_digit('9'));
}

void is_sign_test() {
    int sign = 23;
    assert(aufgabe_02::is_sign('-', &sign)); // & -> Variable als Pointer
    assert(sign == -1);
}

void parse_int_test() {
    assert(aufgabe_02::parse_int("-1234") == -1234);
    assert(aufgabe_02::parse_int("+1234") == 1234);
    assert(aufgabe_02::parse_int("+9001") == 9001);
    assert(aufgabe_02::parse_int("+0") == 0);
    assert(aufgabe_02::parse_int("-0") == 0);
    try {
        assert(aufgabe_02::parse_int("+13/2") == 345326); //Non-digit in number
        assert(false);
    } catch (...) {}
}

void parse_int_pointer_test() {
    std::string test_string = "+1232";
    assert(aufgabe_02::parse_int_pointer(&test_string) == 1232);
}

int main() {
    printf("Beginning...\n");

    is_digit_test();
    is_sign_test();
    parse_int_test();
    parse_int_pointer_test();

    printf("Tests successful...\n");

}