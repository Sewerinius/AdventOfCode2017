#include <iostream>

using namespace std;

bool compLast16Bits(unsigned long long x, unsigned long long y) {
    return (x & 65535) == (y & 65535);
}

int main() {
    unsigned long long a, b, counter = 0;
    a = 516; b = 190;
    for(unsigned int i = 0; i < 5000000; i++) {
        do a = (a * 16807) % 2147483647l;
        while (a % 4 != 0);
        do b = (b * 48271) % 2147483647l;
        while (b % 8 != 0);
        if(compLast16Bits(a, b)) counter++;
    }
    cout << counter;
}
