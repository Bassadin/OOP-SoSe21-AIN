#include <iostream>
#include <math.h>
#include <cassert>

double to_double(int integer, int fractional) {
    if (fractional < 0) throw std::invalid_argument("invalid arg");;
    int digits_amount = 1;

    double temp = fractional;

    while (temp > 10) {
        temp /= 10;
        digits_amount++;
    }

    if (integer < 0 ) {
        return integer - ((double)fractional / pow(10, digits_amount));
    }
    else {
        return integer + ((double)fractional / pow(10, digits_amount));
    }

}

int main() {
    std::cout.precision(17);
    
    std::cout << "Beginning tests" << std::endl;

    assert(to_double(5,15) == 5.15);
    assert(to_double(-5,15) == -5.15);
    assert(to_double(-5,155634567) == -5.155634567);
    assert(to_double(5,15563456) == 5.15563456);
    assert(to_double(6,00000001) == 6.1);

    try
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    std::cout << "Tests passed" << std::endl;

    return 0;
}
