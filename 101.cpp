#include <iostream>

using namespace std;

void reverse(int t[], int begin, int length) {
    int end = (begin + length - 1) % 256;
    length /= 2;
    while(length--) {
        int tmp = t[begin];
        t[begin] = t[end];
        t[end] = tmp;

        begin++;
        begin %= 256;
        end--;
        if(end < 0) end += 256;
    }
}

int main() {
    int in[] = {88,88,211,106,141,1,78,254,2,111,77,255,90,0,54,205};
    int t[256];
    for (int i = 0; i < 256; i++) t[i] = i;

    int stepSize = 0, currentPos = 0;
    for (int& length : in) {
        reverse(t, currentPos, length);
        currentPos += length + stepSize++;
        currentPos %= 256;
    }
    cout << t[0] * t[1];
}