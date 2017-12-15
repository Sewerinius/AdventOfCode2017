#include <iostream>

using namespace std;

bool compLast16Bits(unsigned long long x, unsigned long long y) {
    return (x & 65535) == (y & 65535);
}

int main() {
    unsigned long long a, b, counter = 0;
    a = 516; b = 190;
    for(unsigned int i = 0; i < 40000000; i++) {
        a = (a * 16807) % 2147483647l;
        b = (b * 48271) % 2147483647l;
        if(compLast16Bits(a, b)) counter++;
    }
    cout << counter;
}