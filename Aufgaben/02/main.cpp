//
// Created by basti on 23.03.2021.
//

#include <iostream>
#include <cassert>
#include <cmath>

namespace aufgabe_02 {
    bool is_digit(char c) {
        int asciiValue = (int) c;
        return asciiValue >= 48 && asciiValue <= 57;
    }

    bool is_sign(char c, int *sign) { // * -> Nimmt pointer als Argument
        if (c == 43) {
            *sign = 1;
        } else if (c == 45) {
            *sign = -1;
        } else {
            return false;
        }
        return true;
    }

    int parse_int(const std::string &text) {
        int signMultiplicator;

        if (!aufgabe_02::is_sign(text[0], &signMultiplicator)) {
            throw std::invalid_argument("First char is not a sign");
        };

        int solution = 0;
        for (int i = text.length() - 1; i >= 1; i--) {
            if (!is_digit(text[i])) {
                throw std::invalid_argument("Char at pos " + std::to_string(i) + " is not a digit");
            }
            int numberValue = text[i] - 48; // 48 -> ASCII-Null (0)
            solution += numberValue * pow(10, text.length() - i - 1);
        }

        return solution * signMultiplicator;
    }

    void parse_int_pointer(const std::string &text, int *solution) {
        *solution = parse_int(text);
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
        assert(aufgabe_02::parse_int("9001") == 9001); //No sign
        assert(false);
    } catch (...) {}
    try {
        assert(aufgabe_02::parse_int("+13/2") == 345326); //Non-digit in number
        assert(false);
    } catch (...) {}
}

void parse_int_pointer_test() {
    int solution;
    aufgabe_02::parse_int_pointer("+1232", &solution);
    assert(solution == 1232);
}

int main() {
    printf("Beginning...\n");

    is_digit_test();
    is_sign_test();
    parse_int_test();
    parse_int_pointer_test();

    printf("Tests successful...\n");

}