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

vector<int> knotHash(string x) {
    vector<int> in;
    for(auto& c : x) in.push_back((int) c);
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

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            denseHash[i] ^= t[i*16+j];
        }
    }

    return denseHash;
}

int main() {
    ifstream in("in14.txt");
    string key;
    in >> key;
    key += '-';
    vector<vector<int> > memory;
    for (int i = 0; i < 128; i++) {
        memory.push_back(knotHash(key + to_string(i)));
    }

    int count = 0;
    for (auto& a : memory) {
        for (auto& b : a) {
            while (b > 0) {
                if (b % 2 == 1) count++;
                b /= 2;
            }
        }
    }
    cout << count;
}