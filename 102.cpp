#include <iostream>
#include <vector>
#include <fstream>

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
    ifstream inStr("in10.txt"); inStr >> noskipws;
    vector<int> in;
    char c;
    while(inStr >> c) in.push_back((int) c);
    in.insert(in.end(), {17, 31, 73, 47, 23});

    int t[256];
    for (int i = 0; i < 256; i++) t[i] = i;

    int stepSize = 0, currentPos = 0;
    for(int i = 0; i < 64; i++) {
        for (int& length : in) {
            reverse(t, currentPos, length);
            currentPos += length + stepSize++;
            currentPos %= 256;
        }
    }

    vector<int> denseHash(16, 0);

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            denseHash[i] ^= t[i*16+j];
        }
    }

    cout << hex;
    for(int &h : denseHash) cout << h;
}