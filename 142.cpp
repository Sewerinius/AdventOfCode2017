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

void markGroup(vector<vector<bool> >& t, int x, int y) {
    t[x][y] = 0;
    if(x > 0 && t[x-1][y]) markGroup(t, x-1, y);
    if(x < 127 && t[x+1][y]) markGroup(t, x+1, y);
    if(y > 0 && t[x][y-1]) markGroup(t, x, y-1);
    if(y < 127 && t[x][y+1]) markGroup(t, x, y+1);
}

int main() {
    ifstream in("in14.txt");
    string key;
    in >> key;
    key += '-';
    vector<vector<bool> > memory;
    for (int i = 0; i < 128; i++) {
        vector<int> hash = knotHash(key + to_string(i));
        vector<bool> line(128, 0);
        for(int j = 1; j <= 16; j++) {
            int k = 1;
            while(hash[j-1] > 0) {
                line[j*8 - k++] = hash[j-1] % 2;
                hash[j-1] /= 2;
            }
        }
        memory.push_back(line);
    }

    int count = 0;
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            if(memory[i][j]) {
                count++;
                markGroup(memory, i, j);
            }
        }
    }

    cout << count;

}
