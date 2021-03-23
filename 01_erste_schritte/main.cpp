#include <iostream>
#include <math.h>

namespace hfu
{
    int abs(int v)
    {
        if (v < 0)
        {
            return -v;
        }
        return v;
    }

    int gcd(int v, int w)
    {
        if (v == 0 && w == 0)
        {
            throw std::invalid_argument("both arguments are 0");
        }

        while (w != 0)
        {
            int tmp = w;
            w = v % w;
            v = tmp;
        }
        return std::abs(v);
    }
}

int main()
{
    printf("starting...\n");

    int a = 6;
    int b = 4;

    int gcd = hfu::gcd(a, b);

    printf("a=%d b=%d gcd=%d\n", a, b, gcd);

    printf("terminating...\n");
}