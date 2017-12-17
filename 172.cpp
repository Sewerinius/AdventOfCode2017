#include <iostream>
#include <vector>

using namespace std;

const int stepSize = 394;

int main() {
    int afterZero;
    int pos = 0;
    for (int i = 1; i <= 50000000; i++) {
        pos += stepSize;
        pos %= i;
        if (pos == 0) afterZero = i;
        pos++;
    }
    cout << afterZero;
}
